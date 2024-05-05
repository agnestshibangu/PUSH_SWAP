#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gerer les inputs en arguments séparés ou en liste OK

// remplir la liste chainée avec les arguments passés en paramètres OK

// coder les instructions de base

int main(int ac, char **av)
{    
    t_stack_node* head = NULL;
    // t_stack_node* b = NULL;
    t_stack_node* b = NULL;
    t_stack_node* a = NULL;
    head = create_list(ac, av);

    char *string = "10 23 56 89 19";
    b = create_small_list(string);
    a = create_stack_a(&head);

    find_maxi(&b);

    printf("stack a : ");
    printList(&a);
    swap(&b);
    swap(&a);
    printf("\n");
    printf("stack a after swap : ");
    printList(&a);

    return 0;
}



