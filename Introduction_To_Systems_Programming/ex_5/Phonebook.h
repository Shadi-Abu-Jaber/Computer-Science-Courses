#ifndef HOMEWORK5_PHONEBOOK_H
#define HOMEWORK5_PHONEBOOK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENG_LETTERS 26
#define Max_Len 11

typedef struct Contact {
    char *firstName;
    char *lastName;
    char *phoneNum;
    struct Contact *next;
} Contact;

void print_menu();

int is_valid_option(int option);

void option_1(Contact *phonebook[ENG_LETTERS],char *firstName, char *lastName, char *phoneNum);

void option_2(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName);

void option_3(Contact *phonebook[ENG_LETTERS], char *phoneNum);

void option_4(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName);

void option_5(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName);

void option_7(Contact *phonebook[ENG_LETTERS]);

void create_contact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, char *phoneNum);

void add_contact(Contact *phonebook[ENG_LETTERS], Contact *newContact, int letter_list);

int checkPhoneNumber(Contact *phonebook[ENG_LETTERS], char *phoneNum);

void printPhoneNum(Contact *phonebook[ENG_LETTERS], char *phoneNum);

int checkFullName(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, int letter_list);

void printFullName(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, int letter_list);

void deleteContact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName);

void update_contact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, char *newPhoneNum);

void arrayInitializing(Contact *phonebook[ENG_LETTERS]);

void print_list_in_reverse(Contact *list);

void print_phonebook(Contact *phonebook[ENG_LETTERS]);

void freeingListMemory(Contact *list);

#endif //HOMEWORK5_PHONEBOOK_H
