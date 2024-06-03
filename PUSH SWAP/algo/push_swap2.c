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

void reinitialise_before_next_move(t_stack_node **a, t_stack_node **b)
{
    // // position
    // // assign target node
    // // set price
    // // define cheapest

    // on definit un target node pour chaque node de b vers a
    printf(" == assign a target for each node b to a\n\n");
    assign_target_node(a, b);
    // t_stack_node *smallest;

    // on definit la position des nodes pour pouvoir definir leur push cost
    printf(" == define positions in a and b\n\n");
    define_nodes_position_a_b(a, b);

    // on definit position des nodes par rapport a la mediane 
    printf(" == define positions in a and b according to median\n\n");
    define_is_above_median_a_b(a, b);

    // on definit un push cost pour chaque node
    printf(" == define a push cost for each node\n");
    define_push_cost_a_b(a, b);
    printf_for_shell_debbug(a, b);
    // printf_for_shell_debbug(a, b);

    // define cost 
    printf(" == define combine push cost\n\n");
    define_combined_cost(b);
    
    // // on definit le cheapest pour chaque stack a et b
    printf(" == define the cheapest for b\n");
    define_cheapest(b);

    printf("\n\n");
    // une fois les noeuds les plus cheap definit, on les fait remonter en haut des deux piles
    printf(" == move cheapest of a and b to top\n");
    move_cheapest_to_top(b); // move cheapest of b to top
    //find_target_to_move(a, b); // find b's match
    move_cheapest_to_top_a(a, b); // move b's match in a to top

    // // une fois les noeuds les moins chers en haut, on les push fron stack B to stack A
    pba(a, b);
    printf_for_shell_debbug(a, b);     
}