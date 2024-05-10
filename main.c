#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gerer les inputs en arguments séparés ou en liste OK

// remplir la liste chainée avec les arguments passés en paramètres OK

// coder les instructions de base

int main(int ac, char **av)
{    
    // init pointers to NULL to avoid segfault
    t_stack_node* head = NULL;
    t_stack_node* b = NULL;
    t_stack_node* a = NULL;
    head = create_list(ac, av);

    char *string = "1 2 3 4";
    b = create_small_list(string);
    a = create_stack_a(&head);

    // printf("stack a : ");
    // printList(&a);
    // printf("\n");
    // printf("stack b : ");
    // printList(&b);

    // printf("\n");
    // printf("\n");

    // push_a_nodes_to_b(&a, &b);

    // printf("stack a : ");
    // printList(&a);
    // printf("\n");
    // printf("stack b : ");
    // printList(&b);

    // sort_three(&a);
    // printf("stack a after sort three : ");
    // printList(&a);


    // t_stack_node *min_node = find_min(&a);
    // printf("The smallest number is: %d\n", min_node->nbr);

    assign_target_node(&a, &b);
    // printf("size %d", ft_list_size(&a));

    define_nodes_position(&a);

    is_above_median(&a);
     
    define_push_cost(&a);

    // define_cheapest(&a);

    return 0;
}