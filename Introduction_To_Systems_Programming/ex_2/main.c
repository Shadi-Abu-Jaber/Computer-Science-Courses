/******************************************
* Student name: Shadi Abu Jaber
******************************************/

#include "SeqStatsContainer.h"

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "\nUsage: %s <file-path>\n", argv[0]);
        return 1;
    }

    int i;
    int bps;
    double C_G_percent;
    int total_number_of_seqs;

    SeqStats **current_seq = NULL;
    // initializing sequences stats container
    SeqStatsContainer *container = CreateSeqStatsContainer();

    // reading and processing files
    for (int j = 1; j < argc; ++j) {
        AddSeqsToSeqStatsContainer(container, argv[j]);
    }

    total_number_of_seqs = NumSeqsInSeqStatsContainer(container);
    bps = get_number_of_bps(container);
    printf("Number of sequences:\t%d\n", total_number_of_seqs);
    printf("Number of bps:      \t%d\n\n", bps);

    printf("#\tSeq\tLength\t%%G+C\tNs\n");
    for (i = 0; i < total_number_of_seqs; i++) {
        printf("%d\t", i + 1);
        current_seq = GetSeqStats(container, i);
        printf("%s\t", (*current_seq)->name);
        printf("%u\t", (*current_seq)->length);
        C_G_percent = C_and_G_percent((*current_seq));
        printf("%.1f\t", C_G_percent);
        printf("%u", (*current_seq)->Ns);
        printf("\n");
    }

    for (i = 0; i < total_number_of_seqs; i++) {
        free(container->seq_objects[i]);
    }

    free(container->seq_objects);
    free(container);

    return 0;
}
