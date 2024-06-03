#include "../push_swap.h"

void move_cheapest_to_top(t_stack_node **head)
{
    t_stack_node *cheapest_node = define_cheapest(head);
    printf(" cheapest_node %d \n", cheapest_node->nbr);

    if (cheapest_node == *head)
    {
        printf("  !!! cheapest node already at the top ! \n");
        return;
    }
    else
    {
        while ((*head) != cheapest_node)
        {
            if (cheapest_node->above_median == true)
            {
                ra(head);
            }
            else if (cheapest_node->above_median == false)
            {
                rra(head);
            }
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
        {
            cheapest_s_match = current;
        }
        current = current->next;
    }
    // printf("  cheapest s match : %d\n", cheapest_s_match->nbr);
    return (cheapest_s_match);
}

void move_cheapest_to_top_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *node_to_move = find_target_to_move(a, b);
    printf(" in move cheapest to top cheapest_node %d\n", node_to_move->nbr);
    printf("  top of the stack %d\n", (*a)->nbr);

    if (node_to_move == *a)
    {
        printf("  !!! target node already at the top ! \n");
    }
    else
    {
        printf(" !!! the target is not at the top \n");
        while ((*a) != node_to_move)
        {
            if (node_to_move->above_median == true)
            {
                ra(a); // Rotate up
            }
            else if (node_to_move->above_median == false)
            {
                rra(a); // Rotate down
            }
        }
    }
}

