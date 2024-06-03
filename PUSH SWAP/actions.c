#include "push_swap.h"

// - on definit un pointeur vers le dernier node OK
// - on trouve le dernier node avec find last node OK

// - dans la variable qui pointe vers le noeud suivant du last node
// on met le premier noeud OK 
// - on definit le deuxieme noeud de la liste comme etant le premier noeud OK

// - le premier noeud ne pointe sur aucun noeud donc on met prev a null OK
// - on met a jour le noeud precedent avant le dernier noeud de la pile



// static void     rev_rotate(t_stack_node **head)
// {
//     t_stack_node	*last; //To store the pointer to the last node

// 	if (!*head || !(*head)->next) 
// 		return ;
// 	last = find_last_node(head);
// 	last->prev->next = NULL;
// 	last->next = *head;
//     // printf("%d printf", (*head)->nbr);
//     last->prev = NULL; 
//     *head = last; 
//     last->next->prev = last;
// }    

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