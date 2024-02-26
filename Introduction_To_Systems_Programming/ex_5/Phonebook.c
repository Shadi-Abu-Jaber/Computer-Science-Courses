#include "Phonebook.h"

/******************************************************************************/
void print_menu() {
    printf("Welcome to the phone book manager!\n");
    printf("Choose an option:\n");
    printf("1. Add a new contact to the phone book.\n");
    printf("2. Delete a contact from the phone book.\n");
    printf("3. Find a contact in the phone book by phone number.\n");
    printf("4. Find a contact in the phone book by name.\n");
    printf("5. Update phone number for a contact.\n");
    printf("6. Print phone book.\n");
    printf("7. Exit.\n");
}

/******************************************************************************/

int is_valid_option(int option) {
    while (option < 1 || option > 7) {
        printf("Wrong option, try again:\n");
        scanf("%d", &option);
    }
    return option;
}

/******************************************************************************/

void option_1(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, char *phoneNum) {
    int letter_list = lastName[0] - 'A';
    int is_name_exist = checkFullName(phonebook, firstName, lastName, letter_list);
    //if the name is already exists
    if (is_name_exist) {
        printf("The addition of the contact has failed,"
               " since the contact %s %s already exists!"
               "\n", firstName, lastName);
        return;
    }

    int is_num_exist = checkPhoneNumber(phonebook, phoneNum);
    //if the number is already exists
    if (is_num_exist) {
        printf("The addition of the contact has failed, since"
               " the phone number %s already exists!\n", phoneNum);
        return;
    }

    //creating new contact then adding it to the phonebook
    create_contact(phonebook, firstName, lastName, phoneNum);
}

/******************************************************************************/

void option_2(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName) {
    int letter_list = lastName[0] - 'A';
    char yn, enter;
    int is_name_exist = checkFullName(phonebook, firstName, lastName, letter_list);
    // if the contact was found in phonebook
    if (is_name_exist) {
        printf("Are you sure? (y/n) ");
        scanf("%c%c", &enter, &yn);
        if (yn == 'Y' || yn == 'y') {
            deleteContact(phonebook, firstName, lastName);
            printf("The contact has been deleted successfully!\n");
        } else {
            printf("The deletion of the contact has been "
                   "canceled.\n");
        }
    } else {
        printf("The deletion of the contact has failed!\n");
    }

}

/******************************************************************************/

void option_3(Contact *phonebook[ENG_LETTERS], char *phoneNum) {
    // if the contact was found in phonebook
    int is_num_exist = checkPhoneNumber(phonebook, phoneNum);
    if (is_num_exist) {
        printPhoneNum(phonebook, phoneNum);
    } else {
        printf("No contact with a phone number %s was "
               "found in the phone book\n", phoneNum);
    }
}

/******************************************************************************/

void option_4(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName) {
    int letter_list = lastName[0] - 'A';
    int is_name_exist = checkFullName(phonebook, firstName, lastName, letter_list);
    // if the contact was found in phonebook
    if (is_name_exist) {
        printFullName(phonebook, firstName, lastName, letter_list);
    } else {
        printf("No contact with a name %s %s was "
               "found in the phone book\n", firstName, lastName);
    }
}

/******************************************************************************/

void option_5(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName) {
    int letter_list = lastName[0] - 'A';
    char phoneNum[Max_Len];
    int is_name_exist = checkFullName(phonebook, firstName, lastName, letter_list);
    int is_num_exist = checkPhoneNumber(phonebook, phoneNum);
    // if the contact was found in phonebook
    if (is_name_exist) {
        printFullName(phonebook, firstName, lastName, letter_list);
        printf("Enter the new phone number: ");
        scanf("%s", phoneNum);
        // if the number is already exists
        if (is_num_exist) {
            printf("The update of the contact has failed, since"
                   " the phone number %s already exists!\n", phoneNum);
            return;
        }
            // update the contact
        else {
            update_contact(phonebook, firstName, lastName, phoneNum);
        }
    }
        //if the wanted contact was not found
    else {
        printf("No contact with a name %s %s was "
               "found in the phone book\n", firstName, lastName);
    }
}

/******************************************************************************/

void option_7(Contact *phonebook[ENG_LETTERS]) {
    int i;
    //free the dynamic memory
    for (i = 0; i < ENG_LETTERS; ++i) {
        if (phonebook[i] != NULL) {
            freeingListMemory(phonebook[i]);
        }
    }
}

/******************************************************************************/

void add_contact(Contact *phonebook[ENG_LETTERS], Contact *newContact, int letter_list) {
    //if the list is empty
    if (phonebook[letter_list] == NULL) {
        phonebook[letter_list] = newContact;
    } else {
        Contact *curr_contact = phonebook[letter_list];
        // going all the way to the end of the list
        while (curr_contact->next != NULL) {
            curr_contact = curr_contact->next;
        }
        curr_contact->next = newContact;
    }
}

/******************************************************************************/

void create_contact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, char *phoneNum) {

    Contact *newContact = (Contact *) malloc(sizeof(Contact));
    if (newContact == NULL) {
        printf("The addition of the contact has failed!\n");
        return;
    }

    newContact->firstName = (char *) malloc(sizeof(char) * Max_Len);
    if (newContact->firstName == NULL) {
        printf("The addition of the contact has failed!\n");
        free(newContact);
        return;
    }
    strcpy(newContact->firstName, firstName);

    newContact->lastName = (char *) malloc(sizeof(char) * Max_Len);
    if (newContact->lastName == NULL) {
        printf("The addition of the contact has failed!\n");
        free(newContact->firstName);
        free(newContact);
        return;
    }
    strcpy(newContact->lastName, lastName);

    newContact->phoneNum = (char *) malloc(sizeof(char) * Max_Len);
    if (newContact->phoneNum == NULL) {
        printf("The addition of the contact has failed!\n");
        free(newContact->lastName);
        free(newContact->firstName);
        free(newContact);
        return;
    }
    strcpy(newContact->phoneNum, phoneNum);

    newContact->next = NULL;
    int letter_list = lastName[0] - 'A';
    add_contact(phonebook, newContact, letter_list);
    printf("The contact has been added successfully!\n");
}

/******************************************************************************/

int checkPhoneNumber(Contact *phonebook[ENG_LETTERS], char *phoneNum) {
    int i;
    for (i = 0; i < ENG_LETTERS; ++i) {
        Contact *curr_contact = phonebook[i];
        while (curr_contact != NULL) {
            // if the wanted contact was found
            if (strcmp(curr_contact->phoneNum, phoneNum) == 0) {
                return 1;
            }
            curr_contact = curr_contact->next;
        }
    }
    return 0;
}

/******************************************************************************/

void printPhoneNum(Contact *phonebook[ENG_LETTERS], char *phoneNum) {
    int i;
    for (i = 0; i < ENG_LETTERS; ++i) {
        Contact *curr_contact = phonebook[i];
        while (curr_contact != NULL) {
            // if the wanted contact was found
            if (strcmp(curr_contact->phoneNum, phoneNum) == 0) {
                printf("The following contact was found: %s %s %s\n",
                       curr_contact->firstName, curr_contact->lastName,
                       curr_contact->phoneNum);
            }
            curr_contact = curr_contact->next;
        }
    }
}

/******************************************************************************/

int checkFullName(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, int letter_list) {
    Contact *curr_contact = phonebook[letter_list];
    while (curr_contact != NULL) {
        // if the wanted contact was found
        if (strcmp(curr_contact->firstName, firstName) == 0 &&
            strcmp(curr_contact->lastName, lastName) == 0) {
            return 1;
        }
        curr_contact = curr_contact->next;
    }
    return 0;
}

/******************************************************************************/

void printFullName(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, int letter_list) {
    Contact *curr_contact = phonebook[letter_list];
    while (curr_contact != NULL) {
        // if the wanted contact was found
        if (strcmp(curr_contact->firstName, firstName) == 0 &&
            strcmp(curr_contact->lastName, lastName) == 0) {
            printf("The following contact was found: %s %s %s\n",
                   curr_contact->firstName, curr_contact->lastName,
                   curr_contact->phoneNum);
        }
        curr_contact = curr_contact->next;
    }
}

/******************************************************************************/

void deleteContact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName) {
    int letter_list = lastName[0] - 'A';
    Contact *curr_contact = phonebook[letter_list];
    // initialize another pointer to keep track of the prev contact in the list
    Contact *previous = NULL;
    /*
     searching the whole list and when we find the contact to be deleted
     then deleting the contact using the two pointers we declared
     (currentPtr,previous) more explains below.
     */
    while (curr_contact != NULL) {
        // if the current contact has the same name as the wanted contact
        if (strcmp(curr_contact->firstName, firstName) == 0 &&
            strcmp(curr_contact->lastName, lastName) == 0) {
            // if the running contact is the first contact in the list
            if (previous == NULL) {
                //update the list's head to be the next contact in the list
                phonebook[letter_list] = curr_contact->next;
            } else {
                //update the next pointer of prev cont to skip the current cont
                previous->next = curr_contact->next;
            }
            // free the memory allocated for the curr_contact contact
            free(curr_contact->firstName);
            free(curr_contact->lastName);
            free(curr_contact->phoneNum);
            free(curr_contact);
            break;
        } else {
            /*
              update the previous contact to be the current contact and move
              to the next contact in th list
             */
            previous = curr_contact;
            curr_contact = curr_contact->next;
        }
    }
}

/******************************************************************************/

void update_contact(Contact *phonebook[ENG_LETTERS], char *firstName, char *lastName, char *newPhoneNum) {
    int spot = lastName[0] - 'A';
    Contact *curr_contact = phonebook[spot];
    while (curr_contact != NULL) {
        if (strcmp(curr_contact->firstName, firstName) == 0 &&
            strcmp(curr_contact->lastName, lastName) == 0) {
            // update the phone number
            strcpy(curr_contact->phoneNum, newPhoneNum);
            printf("The contact has been updated successfully!\n");
            return;
        }
        curr_contact = curr_contact->next;
    }

}

/******************************************************************************/

void arrayInitializing(Contact *phonebook[ENG_LETTERS]) {
    int i;
    for (i = 0; i < ENG_LETTERS; ++i) {
        phonebook[i] = NULL;
    }
}

/******************************************************************************/

void print_list_in_reverse(Contact *list) {
    // if the list is empty
    if (list == NULL)
        return;
    // Recursive case: print the rest of the list in reverse order
    print_list_in_reverse(list->next);
    printf("%-10s %-10s %-10s\n",
           list->firstName, list->lastName, list->phoneNum);
}

/******************************************************************************/

void print_phonebook(Contact *phonebook[ENG_LETTERS]) {
    int i;
    for (i = 0; i < ENG_LETTERS; i++) {
        if (phonebook[i] != NULL) {
            // print it in reverse order
            print_list_in_reverse(phonebook[i]);
        }
    }
}

/******************************************************************************/

void freeingListMemory(Contact *list) {
    //if the list is empty
    if (list == NULL) {
        return;
    }
    // freeing every thing in each contact
    Contact *curr_contact = list;
    while (curr_contact != NULL) {
        Contact *tempPtr = curr_contact;
        curr_contact = curr_contact->next;
        free(tempPtr->phoneNum);
        free(tempPtr->firstName);
        free(tempPtr->lastName);
        free(tempPtr);
    }
}
/******************************************************************************/
