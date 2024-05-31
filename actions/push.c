#include "../push_swap.h"

void	    push(t_stack_node **src, t_stack_node **dst) 
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
    printf("pa");
}

// push b vers a
void    pba(t_stack_node **b, t_stack_node **a)
{
    push(b, a);
    printf("pb");
}


