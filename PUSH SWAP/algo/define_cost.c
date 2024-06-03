#include "../push_swap.h"

void    define_push_cost(t_stack_node **head)
{
    int len;
    t_stack_node *current = *head; 

    len = list_size(head);
    while (current != NULL) {   
        if (current->above_median == true)
        {
            current->push_cost = current->position;
        }
        else if (current->above_median == false) 
        {
            current->push_cost = len - current->position;
        }
        current = current->next;
    }
}

void    define_combined_cost(t_stack_node **head)
{
   // int len;
    int total_cost;
    t_stack_node *current = *head; 

    total_cost = 0;
   // len = list_size(head);
    while (current != NULL) { 
        total_cost = current->push_cost + current->target_node->push_cost;
        current->total_cost = total_cost;
        current = current->next;
    }
}

void    define_push_cost_a_b(t_stack_node **a, t_stack_node **b)
{
    define_push_cost(a);
    define_push_cost(b);
}

t_stack_node* define_cheapest(t_stack_node **head)
{
    t_stack_node *current = *head; 
    t_stack_node *cheapest_node;
    long cheapest;

    cheapest_node = NULL;
    cheapest = LONG_MAX;
    while (current != NULL) {   
        if (current->total_cost < cheapest)
        {
            cheapest = current->total_cost;
            cheapest_node = current;
            current->cheapest = true;
        }
        current = current->next;
    }
    return (cheapest_node);
}
