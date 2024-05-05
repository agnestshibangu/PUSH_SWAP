#include "push_swap.h"

static t_stack_node *find_maxi(t_stack_node **head)
{
    t_stack_node *current = *head; 
    t_stack_node *max_node = NULL;
    
    int max = 0; // a changer par INT_MIN

    while (current != NULL) {
        // printf("%d -> ", current->nbr); 
        if (current->nbr > max)
        {
            max = current->nbr;
            max_node = current;
        }
           
        current = current->next; 
    }
    printf("max : %d", max_node->nbr);
    return (max_node);
}

int	ft_list_size(t_stack_node *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}


static t_stack_node* find_last_node(t_stack_node **headRef)
{
    if (headRef == NULL || *headRef == NULL)
        return NULL;

    t_stack_node *lastNode = *headRef;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    return lastNode;
}

