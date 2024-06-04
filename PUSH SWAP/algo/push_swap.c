#include "../push_swap.h"

void push_a_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    int stack_a_len;

    stack_a_len = list_size(a);
    while (stack_a_len > 3)
    {
        pab(a, b);
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
    //printf("push until len a 3\n");
    push_a_nodes_to_b(a, b);
    //printf("sort list 3\n");
    sort_three(a);
    //printf_for_shell_debbug(a, b);
    
    while (*b)
    {
        reinitialise_before_next_move(a, b);
        //printf("BEFORE move node in a and b to top\n");
        //printf_for_shell_debbug(a, b);
        move_cheapest_to_top(b);
        find_target_to_move(a, b);
        move_cheapest_to_top_a(a, b);
        //printf("AFTER move node in a and b to top\n");
        //printf_for_shell_debbug(a, b); 
        pba(a, b);     
        //printf_for_shell_debbug(a, b);
    }
   
    t_stack_node *min_node = find_min(a);
    if (min_node->above_median)
    {
        while (*a != min_node)
        {
            //printf("rotate a final sort\n");
            ra(a);
        }
           
    }
    else 
    {
        while (*a != min_node)
        {
            //printf("reverse rotate a final sort\n");
            rra(a);
        }
    }
    // printf_for_shell_debbug(a, b);
}


