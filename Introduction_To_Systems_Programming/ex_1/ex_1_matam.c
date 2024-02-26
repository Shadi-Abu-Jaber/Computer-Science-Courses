#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned long str_length(const char *str);

void touppers(char *str);

bool is_dna(const char *str);

bool is_gene(char *str);

bool is_crispr_spacer(char *str);

bool is_legal_motif(char *str);

bool match_motif(char *s, int pos, char *motif);

int find_motif(char *s, int pos, char *motif);

void print_substr(char *s, int pos, unsigned long n);

void print_all_motifs(char *dnas, char *motif);

/******************************************************************************/
int main(void) {
    char dna[101];
    char motif[101];
    int input;
    int i = 0, j = 0;

    printf("Enter a DNA sequence: ");
    while ((input = getchar()) != '\n') {
        // to avoid illegal indexes
        if (i < sizeof(dna) - 1) {
            dna[i] = (char) input;
            i++;
        }
    }
    // to deal with the array as a string
    dna[i] = '\0';
    touppers(dna);

    if (is_dna(dna) == false) {
        printf("Error: the string is not a DNA sequence\n");
        return 0;
    }

    if (is_gene(dna) == true) {
        printf("The sequence is a gene\n");
    } else {
        printf("The sequence is not a gene\n");
    }

    if (is_crispr_spacer(dna) == true) {
        printf("The sequence is a CRISPR spacer\n");
    } else {
        printf("The sequence is not a CRISPR spacer\n");
    }

    printf("Enter a motif: ");
    while ((input = getchar()) != '\n') {
        // to avoid illegal indexes
        if (j < sizeof(motif) - 1) {
            motif[j] = (char) input;
            j++;
        }
    }
    // to deal with the array as a string
    motif[j] = '\0';
    touppers(motif);

    if (is_legal_motif(motif) == false) {
        printf("Error: the string is not a legal motif\n");
        return 0;
    }

    printf("Occurrences of the motif in the sequence:\n");
    print_all_motifs(dna, motif);

    return 0;
}

/******************************************************************************/
unsigned long str_length(const char *str) {
    unsigned long i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

/******************************************************************************/
void touppers(char *str) {
    int i;
    unsigned long str_len = str_length(str);
    for (i = 0; i < str_len; i++) {
        if (str[i] <= 'z' && str[i] >= 'a') {
            // difference between lower and upper chars is 32 according to ASCII
            str[i] -= ('a' - 'A');
        }
    }
}

/******************************************************************************/
bool is_dna(const char *str) {
    int i;
    unsigned long str_len = 0;

    // I could have called str_length, but you demanded not to call any function
    for (i = 0; str[i] != '\0'; i++) {
        str_len++;
    }

    if (str_len == 0)
        return false;

    for (i = 0; i < str_len; i++) {
        // if string contain any chars except of [A,C,G,T], string isn't a DNA
        if (str[i] != 'A' && str[i] != 'C' && str[i] != 'G' && str[i] != 'T')
            return false;
    }
    return true;
}

/******************************************************************************/
bool is_gene(char *str) {
    char last_3_chars[4];
    unsigned long i, j;
    unsigned long str_len = str_length(str);

    if (str_len % 3 != 0)
        return false;

    if (!(str[0] == 'A' && str[1] == 'T' && str[2] == 'G'))
        return false;

    // copying last 3 chars into array
    for (j = 0, i = str_len - 3; j < 3; j++, i++)
        last_3_chars[j] = str[i];

    // to deal with array as a string
    last_3_chars[3] = '\0';

    if ((strcmp(last_3_chars, "TAA") == 0) ||
        (strcmp(last_3_chars, "TAG") == 0) ||
        (strcmp(last_3_chars, "TGA") == 0))
        return true;

    return false;
}

/******************************************************************************/
bool is_crispr_spacer(char *str) {
    unsigned long i, j;
    unsigned long str_len = str_length(str);
    char reversed_array[str_len];

    if (str_len > 72 || str_len < 26)
        return false;

    // copy the reversed string into array
    for (j = 0, i = str_len - 1; j < str_len; i--, j++) {
        reversed_array[j] = str[i];
    }
    // comparing reversed str with original str to check palindrome
    for (j = 0, i = 0; i < str_len; i++, j++) {
        if (reversed_array[j] != str[i]) {
            return false;
        }
    }
    return true;
}

/******************************************************************************/
bool is_legal_motif(char *str) {
    int i;
    unsigned long str_len = str_length(str);

    if (str_len == 0)
        return false;

    for (i = 0; i < str_len; i++) {
        // if string contain any chars except of [A,C,G,T,*] it's illegal motif
        if (str[i] != 'A' && str[i] != 'C' && str[i] != 'G' && str[i] != 'T'
            && str[i] != '*') {
            return false;
        }
    }
    return true;
}

/******************************************************************************/
bool match_motif(char *s, int pos, char *motif) {
    int i, j;
    unsigned long s_len = str_length(s);
    unsigned long motif_len = str_length(motif);

    if (!is_dna(s))
        return false;
    // if pos is an illegal array index
    if (!(pos >= 0 && pos < s_len))
        return false;

    if (!(is_legal_motif(motif)))
        return false;

    for (i = pos, j = 0; j < motif_len; i++, j++) {
        if (motif[j] == '*') {
            // checking if '*' was used as wild card
            if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T') {
                return false;
            }
        } else {
            if (motif[j] != s[i])
                return false;
        }
    }
    return true;
}

/******************************************************************************/
int find_motif(char *s, int pos, char *motif) {
    int i, j, motif_index;
    unsigned long s_len = str_length(s);
    unsigned long motif_len = str_length(motif);

    if (!is_dna(s))
        return -1;

    // if pos is an illegal array index
    if (!(pos >= 0 && pos < s_len))
        return -1;

    if (!(is_legal_motif(motif)))
        return -1;

    for (i = pos, j = 0; j < motif_len; i++, j++) {
        if (match_motif(s, i, motif)) {
            // motif index starting from pos
            motif_index = i - pos;
            return motif_index;
        }
    }
    return -1;
}

/******************************************************************************/
void print_substr(char *s, int pos, unsigned long n) {
    int i, j;
    unsigned long s_len = str_length(s);

    // how many chars remained from pos to the end of s
    unsigned long remained_s = s_len - pos;

    if (remained_s <= 0)
        return;

    for (i = 0, j = pos; i < n; i++, j++) {
        // if we arrived index out of array bound (illegal index)
        if (j >= s_len)
            return;
        putchar(s[j]);
    }
}

/******************************************************************************/
void print_all_motifs(char *dnas, char *motif) {
    int i;
    unsigned long dna_len = str_length(dnas);
    unsigned long motif_len = str_length(motif);

    if (!is_dna(dnas))
        return;

    if (!(is_legal_motif(motif)))
        return;

    for (i = 0; i < dna_len; i++) {
        if (match_motif(dnas, i, motif)) {
            printf("%d\t", i);
            print_substr(dnas, i, motif_len);
            printf("\n");
        }
    }
}

/******************************************************************************/