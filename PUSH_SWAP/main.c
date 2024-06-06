#include "push_swap.h"

int main(int ac, char **av)
{    
    // init pointers to NULL to avoid segfault
    t_stack_node* head = NULL;
    t_stack_node* b = NULL;
    t_stack_node* a = NULL;
    head = create_list(ac, av);

    // char *string = "";
    // b = create_small_list(string);
    b = create_stack_b(&b);
    a = create_stack_a(&head);

    push_swap(&a, &b);
    
    return 0;
}