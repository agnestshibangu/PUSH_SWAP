#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gerer les inputs en arguments séparés ou en liste OK

// remplir la liste chainée avec les arguments passés en paramètres OK

// coder les instructions de base


void debugPrintList(t_stack_node **head) {

    t_stack_node *current = *head;
    while (current != NULL) {
        printf("Node value: %d, Prev: %d, Next: %d\n", current->nbr, (current->prev != NULL) ? current->prev->nbr : -1, (current->next != NULL) ? current->next->nbr : -1);
        current = current->next;
    }
}

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

    printf("stack a : ");
    printList(&a);
    swap(&b);
    swap(&a);
    printf("\n");
    printf("stack a after swap : ");
    printList(&a);

    // push(&a, &b);
    // printf("stack a after push : ");
    // printList(&a);
    // // printf("\n");
    // // rb(&b);
    // printf("stack b after push : ");
    // printList(&b);
    // printf("\n");
    // debugPrintList(&b);

   // rev_rotate(&head);

    //printList(&head);

    // display_prev_values(&head);

    
    // find_maxi(&head);

    return 0;
}



