#include "push_swap.h"

static t_stack_node *find_min(t_stack_node **head)
{
    t_stack_node *current = *head; 
    t_stack_node *min_node = NULL;
    
    long int min = LONG_MAX; // a changer par INT_MIN

    while (current != NULL) {
        // printf("%d -> ", current->nbr); 
        if (current->nbr < min)
        {
            min = current->nbr;
            min_node = current;
        }
        current = current->next; 
    }
    return (min_node);
}


static t_stack_node *find_maxi(t_stack_node **head)
{
    t_stack_node *current = *head; 
    t_stack_node *max_node = NULL;
    
    long int max = LONG_MIN; // a changer par INT_MIN

    while (current != NULL) {
        if (current->nbr > max)
        {
            max = current->nbr;
            max_node = current;
        }
           
        current = current->next; 
    }
    return (max_node);
}

int list_size(t_stack_node **head)
{
    t_stack_node *current = *head; 
    int size;

    size = 0;
    while (current != NULL) {
        size++;
        current = current->next; 
    }
    printf("NULL\n");

    return (size);
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

