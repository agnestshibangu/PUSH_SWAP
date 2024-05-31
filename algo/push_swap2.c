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


