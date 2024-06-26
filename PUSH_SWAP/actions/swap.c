#include "../push_swap.h"

void     swap(t_stack_node **head)
{
    int tmp_index;
    int tmp_nbr;

    t_stack_node *first_node; // premier noeud
    t_stack_node *next; // deuxieme noeud

    first_node = *head;
    next = first_node->next;
    
    if (list_size(head) < 2)
    {
        printf("error : list too small");
        return ;
    }
    if (!head || !next) // if no first or second node 
	{
        printf("error node doesn't exist");
        return ;
    }
    tmp_index = first_node->index;
    tmp_nbr = first_node->nbr;
    first_node->index = next->index;
    first_node->nbr = next->nbr;
    next->index = tmp_index;
    next->nbr = tmp_nbr;
}

void    sa(t_stack_node **a)
{
    swap(a);
    printf("sa\n");
}

void    sb(t_stack_node **b)
{
    swap(b);
    printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b) 
{
	swap(a);
	swap(b);
    printf("ss\n");
}