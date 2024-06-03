#include "../push_swap.h"

void move_cheapest_to_top(t_stack_node **head)
{
    t_stack_node *cheapest_node = define_cheapest(head);

    if (cheapest_node == *head)
        return;
    else
    {
        while ((*head) != cheapest_node)
        {
            if (cheapest_node->above_median == true)
                ra(head);
            else if (cheapest_node->above_median == false)
                rra(head);
        }
    }
}

t_stack_node *find_target_to_move(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node = define_cheapest(b);
    t_stack_node *current = *a; 
    t_stack_node *cheapest_s_match;
    while (current != NULL)
    {
        if (current->nbr == cheapest_node->target_node->nbr)
            cheapest_s_match = current;
        current = current->next;
    }
    return (cheapest_s_match);
}

void move_cheapest_to_top_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *node_to_move = find_target_to_move(a, b);

    if (node_to_move == *a)
        return;
    else
    {
        while ((*a) != node_to_move)
        {
            if (node_to_move->above_median == true)
                ra(a); // Rotate up
            else if (node_to_move->above_median == false)
                rra(a); // Rotate down
        }
    }
}

