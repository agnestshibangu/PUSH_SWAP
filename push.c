#include "push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst) 
{
    t_stack_node *top_src; // node

    if (!*src)
        return;

    top_src = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    top_src->prev = NULL;
    if (!*dst)
    {
        *dst = top_src;
        top_src->next = NULL;
    }
    else
    {
        top_src->next = *dst; //  // le top n de la source devient top n de dest
        top_src->next->prev = top_src; // on attache le deuxieme noeud de dest au nouveau premier noeud
        *dst = top_src;
    }
}

// push a vers b 
void    pab(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
}

// push b vers a
void    pba(t_stack_node **b, t_stack_node **a)
{
    push(b, a);
}









// void debugPrintList(t_stack_node **head) {

//     t_stack_node *current = *head;
//     while (current != NULL) {
//         printf("Node value: %d, Prev: %d, Next: %d\n", current->nbr, (current->prev != NULL) ? current->prev->nbr : -1, (current->next != NULL) ? current->next->nbr : -1);
//         current = current->next;
//     }
// }

