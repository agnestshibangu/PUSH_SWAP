#include "../push_swap.h"

void	rotate(t_stack_node **head)
{
    t_stack_node    *last_node;

    if (!*head || !(*head)->next)
        return;
    last_node = find_last_node(head);
    last_node->next = *head; 
    *head = (*head)->next;
    (*head)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
} 

void    ra(t_stack_node **a)
{
    rotate(a);
    printf("ra\n");
}

void    rb(t_stack_node **b)
{
    rotate(b);
    printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}
