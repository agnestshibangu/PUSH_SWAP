#include "../push_swap.h"

static void	sort_three(t_stack_node **a)
{
    t_stack_node* max;

    max = find_maxi(a);
    // printf("nbr of first node : %d\n", (*a)->nbr);
    // printf("nbr of max : %d\n", max->nbr);
    if (*a == max)
    {
        printf("rra\n");
        ra(a);
    }
       
    else if ((*a)->next == max)
    {
        printf("rra\n");
        rra(a);
    }   
    if ((*a)->nbr > (*a)->next->nbr)
    {
        printf("sa\n");
        sa(a);
    }   
}