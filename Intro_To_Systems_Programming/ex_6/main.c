#include "BinTree.h"

#define TRUE 1
#define FALSE 0

int main() {
    int option;
    // Tree root initialization
    BinTree *root = NULL;
    int exit = FALSE;
    int is_root_deleted;

    while (exit == FALSE) {

        // Delete the one who reached 120 years old
        is_root_deleted = generic_int_function(root, delete_older_one);
        // If the root was deleted Reinitialize to NULL
        if (is_root_deleted) {
            root = NULL;
        }

        // Printing the menu
        print_menu();

        scanf("%d", &option);
        switch (option) {
            case 1:
                exit = generic_int_function(root, is_time_for_freedom);
                create_and_add_child(&root);
                break;
            case 2:
                // Delete all males
                is_root_deleted = generic_int_function(root, throw_into_the_nile);
                if (is_root_deleted) {
                    root = NULL;
                }
                exit = generic_int_function(root, is_time_for_freedom);
                printf("\n");
                break;
            case 3:
                // Search for Moshe
                is_root_deleted = generic_int_function(root, find_moshe);
                // If the root was deleted Reinitialize
                if (is_root_deleted) {
                    root = NULL;
                }
                exit = generic_int_function(root, is_time_for_freedom);
                printf("\n");
                break;
            case 4:
                // Print the tree
                generic_function(root, print_tree);
                exit = generic_int_function(root, is_time_for_freedom);
                printf("\n");
                break;
            case 5:
                // Count the tree
                generic_function(root, count_tree);
                exit = generic_int_function(root, is_time_for_freedom);
                break;
            case 6:
                // Free allocated memory
                generic_function(root, free_people_of_moshe);
                exit = TRUE;
                break;
            default:
                printf("wrong choose please choose again\n\n");
                exit = generic_int_function(root, is_time_for_freedom);
                break;
        }
    }
    return 0;
}
