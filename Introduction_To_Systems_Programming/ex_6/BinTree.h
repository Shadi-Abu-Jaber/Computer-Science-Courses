#ifndef UNTITLED4_BINTREE_H
#define UNTITLED4_BINTREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max_Age 120
#define Moshe_Max_Age 80
#define Max_Len 11
#define ROOT 1

typedef struct BinTree {
    int id;
    char *name;
    int age;
    char gender;
    void (*task)(void *val);
    void *action;
    struct BinTree *left;
    struct BinTree *right;
} BinTree;

void print_menu();

int is_time_for_freedom(void *node);

void free_people_of_moshe(void *node);

void child_task(void *val);

void moshe_task(void *val);

void add_child(BinTree **root, BinTree *newChild);

BinTree *new_child_was_born(BinTree **root);

void create_and_add_child(BinTree **root);

BinTree *find_replacement(BinTree *root);

BinTree *find_male_child(BinTree *root);

void delete_child(BinTree **root, int id);

int throw_into_the_nile(void *node);

BinTree *find_older_one(BinTree *root);

int delete_older_one(void *node);

void print_action_preorder(void *node);

void print_action_inorder(void *node);

void print_action_postorder(void *node);

int is_moshe_exist(BinTree *root);

int moshe_check(BinTree *root);

int find_moshe(void *node);

void print_tree_inorder(void *node);

void print_tree_preorder(void *node);

void print_tree_postorder(void *node);

void print_tree(void *node);

int count_all_jews(void *node);

int count_males_jews(void *node);

int count_females_jews(void *node);

void count_tree(void *node);

void increase_age(void *node);

int moshe_reached_eighty(void *node);

void generic_function(BinTree *root, void(*task)(void *));

int generic_int_function(BinTree *root, int(*task)(void *));

#endif
