#include "push_swap.h"

static long my_atol(const char *s)
{
    long res;
    int sign;

    res = 0;
    sign = 1;

    while (*s && (*s == ' ' || *s == '\n' || *s == '\t' ||
                  *s == '\v' || *s == '\f' || *s == '\r'))
        s++;
    if (*s == '-')
        sign = -1;
    if (*s == '-' || *s == '+')
        s++;
    while (*s && *s >= '0' && *s <= '9')
    {
        res = res * 10 + (*s - 48);
        s++;
    }
    return (res * sign);
}

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
    newNode->prev = NULL;


    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    
    t_stack_node *lastNode = *headRef;
    while (lastNode->next != NULL)
    {   
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;
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
            int nbr = my_atol(result[i]);
            append(&head, nbr); 
            i++;
        }

        free(result); // Free memory allocated by my_split
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



t_stack_node* create_small_list(char *av) {
    
    t_stack_node* head = NULL;

    char **result = my_split(av, ' ');
    if (result == NULL)
        return NULL;
    
    int i = 0;
    while (result[i])
    {
        int nbr = my_atol(result[i]);
        append(&head, nbr); 
        i++;
    }
    free(result); // Free memory allocated by my_split

    return head;
}



t_stack_node* create_stack_a(t_stack_node **head)
{
    t_stack_node* a;
    a = *head; 
    return (a);
}

t_stack_node* create_stack_b(t_stack_node **head)
{
    t_stack_node* b;
    b = *head; 
    return (b);
}

