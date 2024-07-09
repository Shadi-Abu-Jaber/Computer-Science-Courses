#ifndef MATAM_HOMEWORK_2_SEQSTATSCONTAINER_H
#define MATAM_HOMEWORK_2_SEQSTATSCONTAINER_H
/******************************************************************************/
#include "SeqStats.h"

#define MAX_SEQ_LEN 10000001
/******************************************************************************/
typedef struct {
    SeqStats **seq_objects;
    int num_seqs;
} SeqStatsContainer;

/******************************************************************************/
SeqStatsContainer *CreateSeqStatsContainer();

/******************************************************************************/
char *memory_allocation(int count);

/******************************************************************************/
void add_seq_to_container(SeqStatsContainer **container, SeqStats *new_seq);

/******************************************************************************/
int AddSeqsToSeqStatsContainer(SeqStatsContainer *container,char *file_name);

/******************************************************************************/
int NumSeqsInFile(char *file_name);

/******************************************************************************/
int NumSeqsInSeqStatsContainer(SeqStatsContainer *container);

/******************************************************************************/
SeqStats **GetSeqStats(SeqStatsContainer *container,int index);

/******************************************************************************/
int get_number_of_bps(SeqStatsContainer *container);

/******************************************************************************/
#endif //MATAM_HOMEWORK_2_SEQSTATSCONTAINER_H
