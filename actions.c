#include "push_swap.h"

// - on definit un pointeur vers le dernier node OK
// - on trouve le dernier node avec find last node OK

// - dans la variable qui pointe vers le noeud suivant du last node
// on met le premier noeud OK 
// - on definit le deuxieme noeud de la liste comme etant le premier noeud OK

// - le premier noeud ne pointe sur aucun noeud donc on met prev a null OK
// - on met a jour le noeud precedent avant le dernier noeud de la pile

t_stack_node* find_last_node(t_stack_node **headRef)
{
    if (headRef == NULL || *headRef == NULL)
        return NULL;

    t_stack_node *lastNode = *headRef;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    return lastNode;
}



void printList(t_stack_node **head) {
    
    t_stack_node *current = *head; 
    
    while (current != NULL) {
        printf("%d -> ", current->nbr); 
        current = current->next; 
    }
    printf("NULL\n");
}


// static void	rotate(t_stack_node **head)
// {
//     t_stack_node    *last_node;

//     if (!*head || !(*head)->next)
//         return;
//     last_node = find_last_node(head);
//     last_node->next = *head; 
//     *head = (*head)->next;
//     (*head)->prev = NULL;
//     last_node->next->prev = last_node;
//     printf("%d", last_node->next->prev->nbr);
//     last_node->next->next = NULL;
// } 

// void display_prev_values(t_stack_node **head)
// {
//     if (head == NULL)
//     {
//         printf("The list is empty.\n");
//         return;
//     }

//     t_stack_node *currentNode = *head;

//     while (currentNode != NULL)
//     {
//         printf("Value stored in 'prev' for node %d: ", currentNode->nbr);
//         if (currentNode->prev != NULL)
//             printf("%d\n", currentNode->prev->nbr);
//         else
//             printf("NULL\n");
//         currentNode = currentNode->next;
//     }
// }


static void     rev_rotate(t_stack_node **head)
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

// static void     rev_rotate(t_stack_node **head)
// {
//     t_stack_node	*last; //To store the pointer to the last node

//     last = find_last_node(head);
//     printf("prev : %d\n", last->prev->nbr);
//     last->next = (*head);
//     last->prev = NULL;
//     (*head) = last;
//     printf("head nb : %d\n", (*head)->nbr);
// }    

/* head become last 
current = last node
lastnode next = head
head previous = last node
head next = null

*/

// static t_stack_node *find_maxi(t_stack_node **head)
// {
//     t_stack_node *current = *head; 
//     t_stack_node *max_node = NULL;
    
//     int max = 0; // a changer par INT_MIN

//     while (current != NULL) {
//         // printf("%d -> ", current->nbr); 
//         if (current->nbr > max)
//         {
//             max = current->nbr;
//             max_node = current;
//         }
           
//         current = current->next; 
//     }
//     printf("max : %d", max_node->nbr);
//     return (max_node);
// }