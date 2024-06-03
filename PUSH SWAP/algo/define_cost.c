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
            printf("  the cost of the node %d is %d\n", current->nbr, current->push_cost);
        }
        else if (current->above_median == false) 
        {
            current->push_cost = len - current->position;
            printf("  the cost of the node %d is %d\n", current->nbr, current->push_cost);
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
        printf(" the cost of the current node %d is %d\n", current->nbr, current->push_cost);
        printf(" the cost of the target node %d is %d\n", current->target_node->nbr, current->target_node->push_cost);
        total_cost = current->push_cost + current->target_node->push_cost;
        printf(" the total cost for the duo is %d\n", total_cost);
        current->total_cost = total_cost;
        printf(" SAVED total cost for the duo is %d in nbr %d\n", current->nbr, current->total_cost);
        printf("\n\n");
        current = current->next;
    }
}

void    define_push_cost_a_b(t_stack_node **a, t_stack_node **b)
{
    printf("\n\n define push cost for a \n\n");
    define_push_cost(a);
    printf("\n\n define push cost for a \n\n");
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
            //printf("cheapest nbr %d with cost %d and target\n\n", current->nbr, current->total_cost);
        }
        current = current->next;
    }
    return (cheapest_node);
}
