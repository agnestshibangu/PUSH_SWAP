#include "../push_swap.h"

void push_a_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    int stack_a_len;

    stack_a_len = ft_list_size(a);
    while (stack_a_len > 3)
    {
        push(a, b);
        stack_a_len--;
    }
}

// A DEBUGGER ! 
void assign_target_node(t_stack_node **a, t_stack_node **b) {
    t_stack_node *current_in_a = *a;
    long best_match;

    while (*b) 
    {
        best_match = LONG_MAX; // Reset for each element in b
        while (current_in_a)
        {
            if (current_in_a->nbr > (*b)->nbr && current_in_a->nbr < best_match) {
                best_match = current_in_a->nbr;
            }
            current_in_a = current_in_a->next;
        }
        current_in_a = *a; // Reset for next iteration over b
        if (best_match != LONG_MAX) {
            printf("best match : %ld\n", best_match);
        }
        else {
            printf("No match found for %d\n", (*b)->nbr);
        }
        printf("-----\n");
        (*b) = (*b)->next;
    }
}

void push_swap(t_stack_node **a, t_stack_node **b)
{
   // pushing node from a to b until there is only 3 nodes in a 
   push_a_nodes_to_b(a, b);
   // sort three for the a stack
   sort_three(a);
   // on definit un target node pour chaque node de b vers a

    // t_stack_node *smallest;
    
    // return;
}