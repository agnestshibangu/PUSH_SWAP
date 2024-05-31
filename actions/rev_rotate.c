#include "../push_swap.h"

void     rev_rotate(t_stack_node **head)
{
    t_stack_node	*last; //To store the pointer to the last node

	if (!*head || !(*head)->next) 
		return ;
	last = find_last_node(head);
	last->prev->next = NULL;
	last->next = *head;
    // printf("%d printf", (*head)->nbr);
    last->prev = NULL; 
    *head = last; 
    last->next->prev = last;
}    

void    rra(t_stack_node **a)
{
    rev_rotate(a);
    printf("rra\n");
}

void    rrb(t_stack_node **b)
{
    rev_rotate(b);
    printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
    rev_rotate(a);
    rev_rotate(b);
    printf("rrr\n");
}
