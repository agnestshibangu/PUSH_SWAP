#include "push_swap.h"

void append(t_stack_node **headRef, int nbr)
{
    t_stack_node *newNode = (t_stack_node *)malloc(sizeof(t_stack_node));

    if (newNode == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    newNode->nbr = nbr;
    newNode->next = NULL;
    // prev

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    t_stack_node *lastNode = *headRef;

    while (lastNode->next != NULL)
    {   
        lastNode->next = newNode;
    }

    lastNode->next = newNode;
}

t_stack_node* find_last_node(t_stack_node **headRef)
{
    if (headRef == NULL || *headRef == NULL)
        return NULL;

    t_stack_node *lastNode = *headRef;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    return (lastNode);
}



t_stack_node* create_list(int ac, char **av) {
    t_stack_node* head = NULL;

    if (ac < 2 || (ac == 2 && !av[1][0]))
        return NULL;
    // If we have a space-separated list
    else if (ac == 2)
    {
        char **result = my_split(av[1], ' ');
        if (result == NULL)
            return NULL;
        
        int i = 0;
        while (result[i])
        {
            int nbr = atoi(result[i]);
            append(&head, nbr); 
            i++;
        }
    }
    // If we have arguments already split
    else if (ac > 2)
    {
        int y = 1;
        while (y < ac)
        {
            int nbr = atoi(av[y]);
            append(&head, nbr); 
            y++;
        }
    }
    return head;
}
