#include "../push_swap.h"

void move_cheapest_to_top(t_stack_node **head)
{
    t_stack_node *cheapest_node = define_cheapest(head);

    if (cheapest_node == *head)
        return;

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

void move_both_cheapest_to_top(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_a = define_cheapest(a);
    t_stack_node *cheapest_b = define_cheapest(b);
    
    printf("\n");
    printf("  STACK A cheapest node %d  cheapest ? %d\n", cheapest_a->nbr, cheapest_a->cheapest);
    printf("  STACK B cheapest node %d  cheapest ? %d\n", cheapest_b->nbr, cheapest_b->cheapest);

    if (!cheapest_a->cheapest && !cheapest_b->cheapest)
    {
        move_cheapest_to_top(a);
        move_cheapest_to_top(b);
    }
    else if (!cheapest_a->cheapest && cheapest_b->cheapest)
    {
        move_cheapest_to_top(a);
    }
    else if (cheapest_a->cheapest && !cheapest_b->cheapest)
    {
        move_cheapest_to_top(b);
    }
}

void     sort_after_push(t_stack_node **head)
{
    // t_stack_node *max_node = find_maxi(head);
    t_stack_node *min_node = find_min(head);

    if (*head != min_node)
    {
        ra(head);
    }
}

void reinitialise_before_next_move(t_stack_node **a, t_stack_node **b)
{   
    // set positions
    // set target nodes
    // set price 
    /// set cheapest

    // position
    define_nodes_position_a_b(a, b);
    // assign target node
    assign_target_node(a, b);
    define_is_above_median_a_b(a, b);
    // set price
    define_push_cost_a_b(a, b);
    // define cheapest
    define_cheapest_a_b(a, b);
    // move_both_cheapest_to_top(a, b);
    // pba(a, b);
    // printf_for_shell_debbug(a, b);
}