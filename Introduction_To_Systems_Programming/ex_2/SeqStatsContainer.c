/******************************************
* Student name: Shadi Abu Jaber
******************************************/

#include "SeqStatsContainer.h"

/******************************************************************************/
SeqStatsContainer *CreateSeqStatsContainer() {

    SeqStatsContainer *container = malloc(sizeof(SeqStatsContainer));
    if (!container) {
        printf("Failed To Allocate Memory!\n");
        exit(1);
    }

    container->seq_objects = calloc(1, sizeof(SeqStats *));
    if (!container->seq_objects) {
        printf("Failed To Allocate Memory!\n");
        exit(1);
    }

    container->num_seqs = 0;

    return container;
}

/******************************************************************************/
// function to allocate memory for strings
char *memory_allocation(int count) {
    char *ptr = calloc(count, sizeof(char));
    if (!ptr) {
        printf("Failed To Open File!\n");
        exit(1);
    }
    return ptr;
}

/******************************************************************************/
void add_seq_to_container(SeqStatsContainer **container, SeqStats *new_seq) {
    int i;
    // assigning new sequence in it's index
    (*container)->seq_objects[(*container)->num_seqs] = new_seq;
    int new_size = ++(*container)->num_seqs;
    // extending seq_objects by one more place
    SeqStats **new_seq_objects = realloc((*container)->seq_objects,
                                         (new_size + 1) * sizeof(SeqStats *));

    if (!new_seq_objects) {
        printf("Failed To Allocate Memory!\n");
        for (i = 0; i < (*container)->num_seqs - 1; i++) {
            free((*container)->seq_objects[i]);
        }
        free((*container)->seq_objects);
        exit(1);
    }

    (*container)->seq_objects = new_seq_objects;
}

/******************************************************************************/
int AddSeqsToSeqStatsContainer(SeqStatsContainer *container,char *file_name) {
    SeqStats *new_seq;
    char *line = memory_allocation(MAX_SEQ_LEN);
    char *seq_name = memory_allocation(MAX_SEQ_NAME_LEN);
    char *seq = memory_allocation(MAX_SEQ_LEN);
    char *seq_slice = memory_allocation(MAX_SEQ_LEN);

    FILE *file = fopen(file_name, "r");
    if (!file) {
        fprintf(stderr,"Failed To Open File!\n");
        exit(1);
    }

    while (fgets(line, MAX_SEQ_LEN, file) != NULL) {

        if (strcmp(line, "\n") == 0)
            continue;
        // if we find sequence
        if (line[0] == '>') {
            sscanf(line, ">%s", seq_name);
            while (fgets(line, MAX_SEQ_LEN, file) != NULL) {
                if (strcmp(line, "\n") == 0)
                    continue;
                // if we arrive the next sequence
                if (line[0] == '>') {
                    // before reading next sequence, add current sequence
                    new_seq = CreateSeqStats(seq_name, seq);
                    add_seq_to_container(&container, new_seq);
                    // after we added current sequence, read next sequence
                    sscanf(line, ">%s", seq_name);
                    strcpy(seq, "");
                    continue;
                }
                // reading each part of the sequence then concatenating
                sscanf(line, "%[^\n]", seq_slice);
                strcat(seq, seq_slice);
            }
            // adding last sequence
            new_seq = CreateSeqStats(seq_name, seq);
            add_seq_to_container(&container, new_seq);
        }
    }
    fclose(file);
    free(line);
    free(seq_name);
    free(seq);
    free(seq_slice);
    return container->num_seqs;
}

/******************************************************************************/
int NumSeqsInFile(char *file_name) {
    int seq_counter = 0;

    char *line = memory_allocation(MAX_SEQ_LEN);

    FILE *file = fopen(file_name, "r");
    if (!file) {
        fprintf(stderr,"Failed To Open File!\n");
        exit(1);
    }

    while (fgets(line, MAX_SEQ_LEN, file) != NULL) {
        if (line[0] == '>')
            seq_counter++;
    }

    fclose(file);
    free(line);
    return seq_counter;
}

/******************************************************************************/
int NumSeqsInSeqStatsContainer(SeqStatsContainer *container) {
    int num_seqs = container->num_seqs;
    return num_seqs;
}

/******************************************************************************/
SeqStats **GetSeqStats(SeqStatsContainer *container,int index) {
    int i;
    for (i = 0; i < container->num_seqs; i++) {
        if (i == index)
            return &container->seq_objects[i];
    }

    return NULL;
}

/******************************************************************************/
int get_number_of_bps(SeqStatsContainer *container) {
    int i;
    int seqs_num = container->num_seqs;
    int bps = 0;

    for (i = 0; i < seqs_num; i++) {
        bps += container->seq_objects[i]->length;
    }

    return bps;
}

/******************************************************************************/
