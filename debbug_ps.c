#include "push_swap.h"

void printList(t_stack_node **head) {
    
    t_stack_node *current = *head; 
    
    while (current != NULL) {
        printf("%d -> ", current->nbr); 
        current = current->next; 
    }
    printf("NULL\n");
}

void display_prev_values(t_stack_node **head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    t_stack_node *currentNode = *head;

    while (currentNode != NULL)
    {
        printf("Value stored in 'prev' for node %d: ", currentNode->nbr);
        if (currentNode->prev != NULL)
            printf("%d\n", currentNode->prev->nbr);
        else
            printf("NULL\n");
        currentNode = currentNode->next;
    }
}

void debugPrintList(t_stack_node **head) {
    t_stack_node *current = *head;
    while (current != NULL) {
        printf("Node value: %d, Prev: %d, Next: %d\n", current->nbr, (current->prev != NULL) ? current->prev->nbr : -1, (current->next != NULL) ? current->next->nbr : -1);
        current = current->next;
    }
}

int if_list_is_sorted(t_stack_node **head)
{
    t_stack_node *currentNode = *head;

      while (currentNode != NULL)
    {
        printf("Value stored in 'prev' for node %d: ", currentNode->nbr);
        if (currentNode->prev != NULL)
        {
            printf("current %d\n", currentNode->nbr); 
            printf("prev %d\n", currentNode->prev->nbr);   
            printf("next %d\n", currentNode->next->nbr); 
        }
        else 
            printf("NULL\n");
        currentNode = currentNode->next;
    }
    printf("the list is sorted\\n");
    return (1);
}