#ifndef MATAM_HOMEWORK_2_SEQSTATS_H
#define MATAM_HOMEWORK_2_SEQSTATS_H
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_NAME_LEN 257
/******************************************************************************/
typedef struct {
    char name[MAX_SEQ_NAME_LEN];
    int length;
    int gc;
    int Ns;
} SeqStats;

/******************************************************************************/
int C_G_counter(const char *seq);

/******************************************************************************/
double C_and_G_percent(SeqStats *seq_stats);

/******************************************************************************/
int N_counter(const char *seq);

/******************************************************************************/
SeqStats *CreateSeqStats(char *seq_name, char *seq);

/******************************************************************************/
void DestroySeqStats(SeqStats *seq);

/******************************************************************************/
void CopySeqStats(SeqStats *seq1, SeqStats *seq2);

/******************************************************************************/
void SwitchSeqStats(SeqStats *seq1, SeqStats *seq2);

/******************************************************************************/
#endif //MATAM_HOMEWORK_2_SEQSTATS_H
