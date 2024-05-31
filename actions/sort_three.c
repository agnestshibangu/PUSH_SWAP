#include "../push_swap.h"

void	sort_three(t_stack_node **a)
{
    t_stack_node* max;

    max = find_maxi(a);
    // printf("nbr of first node : %d\n", (*a)->nbr);
    // printf("nbr of max : %d\n", max->nbr);
    if (*a == max)
    {
        ra(a);
    }
       
    else if ((*a)->next == max)
    {
        rra(a);
    }   
    if ((*a)->nbr > (*a)->next->nbr)
    {
        sa(a);
    }   
}