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

void move_both_cheapest_to_top(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node_in_b = define_cheapest(b);
    t_stack_node *cheapest_node_in_a = find_target_to_move(a, b);

    if (cheapest_node_in_b == *b || cheapest_node_in_a == *a)
        return;
    while ((*b) != cheapest_node_in_b && (*a) != cheapest_node_in_a
            && cheapest_node_in_a->above_median && cheapest_node_in_b->above_median)
    {
        rr(a, b);
        //printf("rr both stacks !");
        
    }
    while ((*b) != cheapest_node_in_b && (*a) != cheapest_node_in_a
            && !cheapest_node_in_a->above_median && !cheapest_node_in_b->above_median)
    {
        rrr(a, b);
        //printf("------third case-----\n");
        //printf("rrr both stacks !");
    }
}

void finish_moving_to_top_b(t_stack_node **b)
{
    // printf("finish moving cheapest to top b\n");
    t_stack_node *cheapest_node_in_b = define_cheapest(b);
    if (cheapest_node_in_b == *b)
        return;
    if ((*b) != cheapest_node_in_b)
    {
        while ((*b) != cheapest_node_in_b)
        {
            if (cheapest_node_in_b->above_median)
                ra(b); // Rotate up
            else if (!cheapest_node_in_b->above_median)
                rra(b); // Rotate down
        }
    }
}

void finish_moving_to_top_a(t_stack_node **a, t_stack_node **b)
{
    //printf("finish moving cheapest to top a\n");
    t_stack_node *cheapest_node_in_a = find_target_to_move(a, b);
    if (cheapest_node_in_a == *a)
        return;
    if ((*a) != cheapest_node_in_a)
    {
        while ((*a) != cheapest_node_in_a)
        {
            if (cheapest_node_in_a->above_median)
                ra(a); // Rotate up
            else if (!cheapest_node_in_a->above_median)
                rra(a); // Rotate down
        }
    }
}


