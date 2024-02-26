#include "BinTree.h"

/******************************************************************************/
void print_menu() {
    printf("please choose action:\n");
    printf("(1) A child was born\n");
    printf("(2) Throw into the Nile\n");
    printf("(3) Find Moshe\n");
    printf("(4) Print All\n");
    printf("(5) Size of jews\n");
    printf("(6) Exit\n");
}

/******************************************************************************/
int is_time_for_freedom(void *node) {
    BinTree *root = (BinTree *) node;
    int exit = 0;
    increase_age(root);
    int time_for_freedom = moshe_reached_eighty(root);
    if (time_for_freedom) {
        printf("Moshe say: let my people go!");
        // Delete the whole tree before leaving
        free_people_of_moshe(root);
        exit = 1;
    }
    return exit;
}

/******************************************************************************/
void free_people_of_moshe(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    free_people_of_moshe(BinTreeRoot->left);
    free_people_of_moshe(BinTreeRoot->right);
    free(BinTreeRoot->name);
    free(BinTreeRoot);
}

/******************************************************************************/
void child_task(void *val) {
    char *childName = (char *) val;
    printf("%s cry waaaa\n", childName);
}

/******************************************************************************/
void moshe_task(void *val) {
    char *Moshe = (char *) val;
    printf("%s quiet\n", Moshe);
}

/******************************************************************************/
void add_child(BinTree **root, BinTree *newKid) {
    if ((*root) == NULL) {
        (*root) = newKid;
        return;
    }
    if (newKid->id > (*root)->id) {
        // Add child to right
        add_child(&(*root)->right, newKid);
    } else {
        // Add child to left
        add_child(&(*root)->left, newKid);
    }
}

/******************************************************************************/
BinTree *new_child_was_born(BinTree **root) {
    int id;
    char name[Max_Len];
    char enter, gender;
    printf("please enter child id:\n");
    scanf("%d", &id);
    printf("please insert child name:\n");
    scanf("%s", name);
    printf("please insert child gender:\n");
    scanf("%c%c", &enter, &gender);
    printf("\n");

    BinTree *newKid = (BinTree *) malloc(sizeof(BinTree));
    if (!newKid) {
        free_people_of_moshe(root);
        exit(1);
    }

    newKid->name = (char *) malloc(sizeof(char) * Max_Len);
    if (!newKid->name) {
        free(newKid);
        free_people_of_moshe(root);
        exit(1);
    }

    // Set the child fields
    strcpy(newKid->name, name);
    newKid->id = id;
    newKid->gender = gender;
    newKid->age = 0;
    newKid->action = newKid->name;
    if (newKid->gender == 'M' && strcmp(newKid->name, "Moshe") == 0) {
        newKid->task = moshe_task;
    } else {
        newKid->task = child_task;
    }
    newKid->left = NULL;
    newKid->right = NULL;
    return newKid;
}

/******************************************************************************/
void create_and_add_child(BinTree **root) {
    // Create a new child
    BinTree *newKid = new_child_was_born(root);
    // Add the new child to the tree
    add_child(root, newKid);
}

/******************************************************************************/
BinTree *find_male_child(BinTree *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->gender == 'M' && strcmp(root->name, "Moshe") != 0) {
        return root;
    }
    // Search right and left
    BinTree *search_left = find_male_child(root->left);
    BinTree *search_right = find_male_child(root->right);
    if (search_left != NULL) {
        return search_left;
    } else {
        return search_right;
    }
}

/******************************************************************************/
// called find_replacement func in delete_child func
BinTree *find_replacement(BinTree *root) {
    if (root == NULL) {
        return NULL;
    }
    // Searching for the smallest that is larger than the node to be deleted
    if (root->left != NULL) {
        return find_replacement(root->left);
    }
    return root;
}

/******************************************************************************/
void delete_child(BinTree **BinTreeRoot, int id) {
    if (*BinTreeRoot == NULL) {
        return;
    }
    BinTree *temp = *BinTreeRoot;
    if (temp->id == id) {
        // If the root has no children
        if (temp->left == NULL && temp->right == NULL) {
            // Delete the root
            free(temp->name);
            free(temp);
            temp = NULL;
            *BinTreeRoot = NULL;
        }
            // If the root has only right child
        else if (temp->left == NULL && temp->right != NULL) {
            BinTree *copy = temp->right;
            // Replace the values then delete right child
            (*BinTreeRoot)->id = copy->id;
            strcpy((*BinTreeRoot)->name, copy->name);
            (*BinTreeRoot)->gender = copy->gender;
            (*BinTreeRoot)->age = copy->age;
            (*BinTreeRoot)->task = copy->task;
            (*BinTreeRoot)->right = copy->right;
            (*BinTreeRoot)->left = copy->left;
            free(copy->name);
            free(copy);
            copy = NULL;
        }
            // If the root has only left child
        else if (temp->left != NULL && temp->right == NULL) {
            BinTree *copy = temp->left;
            // Replace the values then delete left child
            (*BinTreeRoot)->id = copy->id;
            strcpy((*BinTreeRoot)->name, copy->name);
            (*BinTreeRoot)->gender = copy->gender;
            (*BinTreeRoot)->age = copy->age;
            (*BinTreeRoot)->task = copy->task;
            (*BinTreeRoot)->right = copy->right;
            (*BinTreeRoot)->left = copy->left;
            free(copy->name);
            free(copy);
            copy = NULL;
        }
            // If the root has two children
        else {
            // Find the successor to replace it with the child te be deleted
            BinTree *replacement = find_replacement(temp->right);
            // Copy the fields values
            temp->id = replacement->id;
            strcpy(temp->name, replacement->name);
            temp->age = replacement->age;
            temp->gender = replacement->gender;
            temp->task = replacement->task;
            delete_child(&temp->right, replacement->id);
        }
        return;
    }
    if (temp->id < id) {
        delete_child(&temp->right, id);
    } else {
        delete_child(&temp->left, id);
    }
}

/******************************************************************************/
int throw_into_the_nile(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    // Find the males
    BinTree *male_child = find_male_child(BinTreeRoot);
    // Delete all males
    while (male_child != NULL) {
        delete_child(&BinTreeRoot, male_child->id);
        // Warning! : send message that the Tree root was deleted
        if (BinTreeRoot == NULL) {
            return 1;
        }
        male_child = find_male_child(BinTreeRoot);
    }
    return 0;
}

/******************************************************************************/
BinTree *find_older_one(BinTree *root) {
    if (root == NULL) {
        return NULL;
    }
    // If child reached max age (120)
    if (root->age >= Max_Age) {
        return root;
    }
    // search right and left
    BinTree *search_left = find_older_one(root->left);
    BinTree *search_right = find_older_one(root->right);
    if (search_left != NULL) {
        return search_left;
    } else {
        return search_right;
    }
}

/******************************************************************************/
int delete_older_one(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    // Find child who reached 120 years old
    BinTree *older_one = find_older_one(BinTreeRoot);
    // delete him
    if (older_one != NULL) {
        delete_child(&BinTreeRoot, older_one->id);
        // Warning! : send message that the Tree root was deleted
        if (BinTreeRoot == NULL) {
            return 1;
        }
    }
    return 0;
}

/******************************************************************************/
void print_action_preorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    // Print the action of the child
    BinTreeRoot->task((void *) BinTreeRoot->action);
    print_action_preorder(BinTreeRoot->left);
    print_action_preorder(BinTreeRoot->right);
}

/******************************************************************************/
void print_action_inorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    print_action_inorder(BinTreeRoot->left);
    // Print the action of the child
    BinTreeRoot->task((void *) BinTreeRoot->action);
    print_action_inorder(BinTreeRoot->right);
}

/******************************************************************************/
void print_action_postorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    print_action_postorder(BinTreeRoot->left);
    print_action_postorder(BinTreeRoot->right);
    // Print the action of the child
    BinTreeRoot->task((void *) BinTreeRoot->action);
}

/******************************************************************************/
int is_moshe_exist(BinTree *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->gender == 'M' && strcmp(root->name, "Moshe") == 0) {
        return 1;
    }
    // moshe can be found in one side
    return is_moshe_exist(root->left) + is_moshe_exist(root->right);
}

/******************************************************************************/
int moshe_check(BinTree *root) {
    // Search for Moshe
    int mosheFound = is_moshe_exist(root);
    // If Moshe was found
    if (mosheFound) {
        // Delete all males
        int is_root_deleted = throw_into_the_nile(root);
        // If the root was deleted Reinitialize
        if (is_root_deleted) {
            return 1;
        }
    } else {
        printf("Moshe Not Found!\n");
    }
    return 0;
}

/******************************************************************************/
int find_moshe(void *node) {
    int order, is_root_deleted;
    BinTree *BinTreeRoot = (BinTree *) node;
    printf("please choose order:\n");
    printf("(1) preorder\n(2) inorder\n(3) postorder\n");
    scanf("%d", &order);
    if (order == 1) {
        // Print children actions (preorder)
        print_action_preorder(BinTreeRoot);
        is_root_deleted = moshe_check(BinTreeRoot);
        if (is_root_deleted) {
            return 1;
        }
    } else if (order == 2) {
        // Print children actions (inorder)
        print_action_inorder(BinTreeRoot);
        is_root_deleted = moshe_check(BinTreeRoot);
        if (is_root_deleted) {
            return 1;
        }
    } else if (order == 3) {
        // Print children actions (postorder)
        print_action_postorder(BinTreeRoot);
        is_root_deleted = moshe_check(BinTreeRoot);
        if (is_root_deleted) {
            return 1;
        }
    } else {
        printf("wrong order!\n");
    }
    return 0;
}

/******************************************************************************/
void print_tree_inorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;

    if (BinTreeRoot == NULL) {
        return;
    }
    print_tree_inorder((BinTreeRoot)->left);
    printf("id: %d, name: %s, gender: %c, age: %d\n", BinTreeRoot->id, BinTreeRoot->name, BinTreeRoot->gender,
           BinTreeRoot->age);
    print_tree_inorder((BinTreeRoot)->right);
}

/******************************************************************************/
void print_tree_preorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    printf("id: %d, name: %s, gender: %c, age: %d\n", BinTreeRoot->id, BinTreeRoot->name, BinTreeRoot->gender,
           BinTreeRoot->age);
    print_tree_preorder((BinTreeRoot)->left);
    print_tree_preorder((BinTreeRoot)->right);
}

/******************************************************************************/
void print_tree_postorder(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    print_tree_postorder((BinTreeRoot)->left);
    print_tree_postorder((BinTreeRoot)->right);
    printf("id: %d, name: %s, gender: %c, age: %d\n", BinTreeRoot->id, BinTreeRoot->name, BinTreeRoot->gender,
           BinTreeRoot->age);
}

/******************************************************************************/
void print_tree(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    int order;
    printf("please choose order:\n");
    printf("(1) preorder\n(2) inorder\n(3) postorder\n");
    scanf("%d", &order);
    if (order == 1) {
        print_tree_preorder(BinTreeRoot);
    } else if (order == 2) {
        print_tree_inorder(BinTreeRoot);
    } else if (order == 3) {
        print_tree_postorder(BinTreeRoot);
    } else {
        printf("wrong order!\n");
    }
}

/******************************************************************************/
int count_all_jews(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return 0;
    }
    // Count right and left sides of the tree and add 1 (the root)
    return count_all_jews(BinTreeRoot->left) + count_all_jews(BinTreeRoot->right)
           + ROOT;
}

/******************************************************************************/
int count_males_jews(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return 0;
    }
    int maleCount = 0;
    // If the child is male
    if (BinTreeRoot->gender == 'M') {
        // Increment the counter
        maleCount++;
    }
    // Count males on  left side of the tree
    maleCount += count_males_jews(BinTreeRoot->left);
    // Count males on  right side of the tree
    maleCount += count_males_jews(BinTreeRoot->right);
    return maleCount;
}

/******************************************************************************/
int count_females_jews(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return 0;
    }
    int femaleCount = 0;
    // If the child is female
    if (BinTreeRoot->gender == 'F') {
        // Increment the counter
        femaleCount++;
    }
    // Count females on left side of the tree
    femaleCount += count_females_jews(BinTreeRoot->left);
    // Count females on right side of the tree
    femaleCount += count_females_jews(BinTreeRoot->right);
    return femaleCount;
}

/******************************************************************************/
void count_tree(void *node) {
    int countKind;
    BinTree *BinTreeRoot = (BinTree *) node;
    printf("please choose what you want to calculate:\n");
    printf("(1) All jews\n(2) Male\n(3) Female\n");
    scanf("%d", &countKind);
    if (countKind == 1) {
        int allJews = count_all_jews(BinTreeRoot);
        printf("size of all jews is: %d\n\n", allJews);
    } else if (countKind == 2) {
        int AllMaleJews = count_males_jews(BinTreeRoot);
        printf("size of all male jews is: %d\n\n", AllMaleJews);
    } else if (countKind == 3) {
        int AllFemaleJews = count_females_jews(BinTreeRoot);
        printf("size of all female jews is: %d\n\n", AllFemaleJews);
    }
}

/******************************************************************************/
void increase_age(void *node) {
    BinTree *BinTreeRoot = (BinTree *) node;
    if (BinTreeRoot == NULL) {
        return;
    }
    // Increase the age of the child by 20 years
    BinTreeRoot->age += 20;
    increase_age(BinTreeRoot->left);
    increase_age(BinTreeRoot->right);
}

/******************************************************************************/
int moshe_reached_eighty(void *node) {
    BinTree *root = (BinTree *) node;
    if (root == NULL) {
        return 0;
    }
    // If Moshe reached the age 80
    if (root->gender == 'M' && strcmp(root->name, "Moshe") == 0 &&
        root->age >= Moshe_Max_Age) {
        return 1;
    }
    int reached_eighty_left = moshe_reached_eighty(root->left);
    if (reached_eighty_left) {
        return 1;
    }
    int reached_eighty_right = moshe_reached_eighty(root->right);
    if (reached_eighty_right) {
        return 1;
    }
    return 0;
}

/******************************************************************************/
void generic_function(BinTree *root, void(*task)(void *)) {
    task(root);
}

/******************************************************************************/
int generic_int_function(BinTree *root, int(*task)(void *)) {
    return task(root);
}
/******************************************************************************/




