#include "SeqStats.h"

/******************************************************************************/
int C_G_counter(const char *seq) {
    int i = 0, counter = 0;

    while (seq[i] != '\0') {
        if (seq[i] == 'G' || seq[i] == 'C')
            counter++;
        i++;
    }

    return counter;
}

/******************************************************************************/
double C_and_G_percent(SeqStats *seq_stats) {
    // handle exception to prevent dividing by 0
    if (seq_stats->length == 0)
        return 0;
    double percent = ((double) seq_stats->gc / (double) seq_stats->length) * 100;
    return percent;
}

/******************************************************************************/
int N_counter(const char *seq) {
    int i = 0, counter = 0;

    while (seq[i] != '\0') {
        if (seq[i] == 'N')
            counter++;
        i++;
    }

    return counter;
}

/******************************************************************************/
SeqStats *CreateSeqStats(char *seq_name, char *seq) {
    int seq_len = (int) strlen(seq);
    int C_G_number = C_G_counter(seq);
    int N_number = N_counter(seq);

    SeqStats *new_seq = (SeqStats *) malloc(sizeof(SeqStats));
    if (!new_seq) {
        fprintf(stderr, "Failed To Allocate Memory!\n");
        fprintf(stderr, "File name is %s\n", __FILE__);
        fprintf(stderr, "Line is %d\n", __LINE__);
        exit(1);
    }

    if (strlen(seq_name) > MAX_SEQ_NAME_LEN) {
        printf("Sequence name '%s' is longer than 256 chars!!!\n", seq_name);
        exit(1);
    }
    strcpy(new_seq->name, seq_name);
    new_seq->length = seq_len;
    new_seq->gc = C_G_number;
    new_seq->Ns = N_number;

    return new_seq;
}

/******************************************************************************/
void DestroySeqStats(SeqStats *seq) {
    // there is no allocated memory in SeqStat to free :)
}

/******************************************************************************/
void CopySeqStats(SeqStats *seq1, SeqStats *seq2) {
    strcpy(seq1->name, seq2->name);
    seq1->length = seq2->length;
    seq1->gc = seq2->gc;
    seq1->Ns = seq2->Ns;
}

/******************************************************************************/
void SwitchSeqStats(SeqStats *seq1, SeqStats *seq2) {
    SeqStats *tmp_seq = (SeqStats *) malloc(sizeof(SeqStats));
    if (!tmp_seq) {
        fprintf(stderr, "Failed To Allocate Memory!\n");
        fprintf(stderr, "File name is %s\n", __FILE__);
        fprintf(stderr, "Line is %d\n", __LINE__);
        exit(1);
    }

    CopySeqStats(tmp_seq, seq1);
    CopySeqStats(seq1, seq2);
    CopySeqStats(seq2, tmp_seq);

    free(tmp_seq);
}

/******************************************************************************/
