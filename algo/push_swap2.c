#include "../push_swap.h"

void move_cheapest_to_top(t_stack_node **head)
{
    t_stack_node *cheapest_node = define_cheapest(head);

    while (cheapest_node->cheapest == false)
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

void determine_next_move(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_a = define_cheapest(a);
    t_stack_node *cheapest_b = define_cheapest(b);
    
    printf("STACK A cheapest node %d  cheapest ? %d\n", cheapest_a->nbr, cheapest_a->cheapest);
    printf("STACK B cheapest node %d  cheapest ? %d\n", cheapest_b->nbr, cheapest_b->cheapest);

    if (cheapest_a->cheapest == false && cheapest_b->cheapest == false)
    {
        move_cheapest_to_top(a);
        move_cheapest_to_top(b);
    }
    else if (cheapest_a->cheapest == true && cheapest_b->cheapest == true)
    {
        pba(b, a);
        printf("push top node of b on top of a");
    } 
    // si le cheapest n'est pas en haut de la pile
    else if (cheapest_a->cheapest == false && cheapest_b->cheapest == true)
    {
       move_cheapest_to_top(a);
       pba(b, a);
    }
    else if (cheapest_a->cheapest == true && cheapest_b->cheapest == false)
    {
       move_cheapest_to_top(b);
       pba(b, a);
    }
}

