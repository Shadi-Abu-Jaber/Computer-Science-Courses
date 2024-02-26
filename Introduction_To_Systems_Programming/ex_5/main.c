#include "Phonebook.h"
#define TRUE 1
#define FALSE 0
int main() {
    int option;
    int exit = FALSE;
    char firstName[Max_Len], lastName[Max_Len], phoneNum[Max_Len];
    Contact *phonebook[ENG_LETTERS];

    //initializing phonebook with NULL
    arrayInitializing(phonebook);

    while (exit == FALSE) {
        print_menu();
        scanf("%d", &option);
        option = is_valid_option(option);

        if (option == 1) {
            printf("Enter a contact details"
                   " (<first name> <last name> <phone number>): ");
            scanf("%s", firstName);
            scanf("%s", lastName);
            scanf("%s", phoneNum);
            option_1(phonebook, firstName, lastName, phoneNum);
            continue;
        }

        if (option == 2) {
            printf("Enter a contact name (<first name> <last name>): ");
            scanf("%s", firstName);
            scanf("%s", lastName);
            option_2(phonebook, firstName, lastName);
            continue;
        }

        if (option == 3) {
            printf("Enter a phone number: ");
            scanf("%s", phoneNum);
            option_3(phonebook, phoneNum);
            continue;
        }

        if (option == 4) {
            printf("Enter a contact name (<first name> <last name>): ");
            scanf("%s", firstName);
            scanf("%s", lastName);
            option_4(phonebook, firstName, lastName);
            continue;
        }

        if (option == 5) {
            printf("Enter a contact name (<first name> <last name>): ");
            scanf("%s", firstName);
            scanf("%s", lastName);
            option_5(phonebook, firstName, lastName);
            continue;
        }

        if (option == 6) {
            print_phonebook(phonebook);
            continue;
        }

        if (option == 7) {
            option_7(phonebook);
            printf("Bye!");
            exit = TRUE;
        }
    }
    return 0;
}
