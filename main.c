#include "push_swap.h"

void print_stack_for_visualizer(t_stack_node *stack) {
    t_stack_node *current = stack;
    while (current) {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}

int main(int ac, char **av)
{    
    // init pointers to NULL to avoid segfault
    t_stack_node* head = NULL;
    t_stack_node* b = NULL;
    t_stack_node* a = NULL;
    head = create_list(ac, av);

    char *string = "";
    b = create_small_list(string);
    a = create_stack_a(&head);

    // if_list_is_sorted(&a);
    // printf("display prev values of STACK A : \n"); 
    // display_prev_values(&a);

    // printf("\n");
    // printf("\n");

    // VISUALIZER ----------------------------------------------------------------------------------------------------
    // push_swap(&a, &b);
    // int i = 1;
    // while (av[i])
    // {
    //     printf("%s ", av[i]);
    //     i++;
    // }
    // printf("\n");
    push_swap(&a, &b);
    //sort_three(&a);


    // print_stack_for_visualizer(&a);

    // sort_three(&a);
    // printf("stack a after sort three : ");
    // printList(&a);


    // t_stack_node *min_node = find_min(&a);
    // printf("The smallest number is: %d\n", min_node->nbr);

    // assign_target_node(&a, &b);

    // define_nodes_position_a_b(&a, &b);

    // define_push_cost_a_b(&a, &b);

   

    // // define_cheapest(&a);
    // define_cheapest_a_b(&a, &b);
    
    // printf("stack a : ");
    // printList(&a);
    // printf("\n");
    // printf("stack b : ");
    // printList(&b);

    // check_two_cheapest_after_def(&a, &b);

    // determine_next_move(&a, &b);

    // printf("AFTER FIRST PUSH\n");
    // printf("stack a : ");
    // printList(&a);
    // printf("\n");
    // printf("stack b : ");
    // printList(&b);


    return 0;
}