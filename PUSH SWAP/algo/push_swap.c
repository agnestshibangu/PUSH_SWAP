#include "../push_swap.h"

void push_a_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    int stack_a_len;

    stack_a_len = list_size(a);
    while (stack_a_len > 3)
    {
        push(a, b);
        stack_a_len--;
    }
}

void reinitialise_before_next_move(t_stack_node **a, t_stack_node **b)
{
    // // position
    // // assign target node
    // // set price
    // // define cheapest

    assign_target_node(a, b);
    define_nodes_position_a_b(a, b);
    define_is_above_median_a_b(a, b);
    define_push_cost_a_b(a, b);
    define_combined_cost(b);
    define_cheapest(b);
}


void push_swap(t_stack_node **a, t_stack_node **b)
{
    push_a_nodes_to_b(a, b);
    
    sort_three(a);

    while (*b)
    {
        reinitialise_before_next_move(a, b);
        move_cheapest_to_top(b);
        find_target_to_move(a, b);
        move_cheapest_to_top_a(a, b); 
        pba(a, b);     
    }
   
    t_stack_node *min_node = find_min(a);
    if (min_node->above_median)
    {
        while (*a != min_node)
            ra(a);
    }
    else 
    {
        while (*a != min_node)
            rra(a);
    }
    printf_for_shell_debbug(a, b);
}


