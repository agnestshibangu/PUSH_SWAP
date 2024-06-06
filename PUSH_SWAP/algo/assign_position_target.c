#include "../push_swap.h"

void assign_target_node(t_stack_node **a, t_stack_node **b) {

    t_stack_node *current_in_a = *a;
    t_stack_node *current_in_b = *b;
    t_stack_node *target_node;
    long best_match;

    target_node = NULL;

    while (current_in_b) 
    {
        best_match = LONG_MAX; // Reset for each element in b
        current_in_a = *a; // Reset for next iteration over b
        while (current_in_a)
        {
            if (current_in_a->nbr > current_in_b->nbr && current_in_a->nbr < best_match)
            {
                best_match = current_in_a->nbr;
                target_node = current_in_a;
            }
            current_in_a = current_in_a->next;
        }
        if (LONG_MAX == best_match)
        {
            current_in_b->target_node = find_min(a);
        }
        else 
        {
            current_in_b->target_node = target_node;
        }
        current_in_b = current_in_b->next;
    }
}

void    define_nodes_position(t_stack_node **head)
{
    t_stack_node *current; 
    int i;
    i = 0;

    current = *head;
    while (current != NULL) {
        current->position = i;
        i++;
        current = current->next;
    }
}

void    define_nodes_position_a_b(t_stack_node **a, t_stack_node **b)
{
    define_nodes_position(a);
    define_nodes_position(b);
}

void    is_above_median(t_stack_node **head)
{
    t_stack_node *current = *head; 
    int len;
    int median;

    len = list_size(head);
    if (len % 2 != 0)
        median = len / 2 + 1;
    else 
        median = len / 2;

    while (current != NULL) {
        if (current->position < median)
            current->above_median = true;
        else
            current->above_median = false;
        current = current->next;
    }
    current = *head;
}

void    define_is_above_median_a_b(t_stack_node **a, t_stack_node **b)
{
    is_above_median(a);
    is_above_median(b);
}
