#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

// STRUCTURES

typedef struct s_stack_node
{
    int     nbr;
    int     index;
    struct s_stack_node *next;
    struct s_stack_node *prev;

}   t_stack_node;

#include "./split.c"
#include "./actions.c"
#include "./initList.c"
#include "./rotate.c"
#include "./rev_rotate.c"
#include "./push.c"


// FUNCTIONS
// UTILS
char    *my_strncpy(char *s1, char *s2, int n);
char    **my_split(char *str, char delimiter);
static long my_atol(const char *s);

// UTILS PUSHSWAP
void printList(t_stack_node **head);
void display_prev_values(t_stack_node **head);

// INIT
t_stack_node* create_small_list(char *av);
t_stack_node* create_list(int ac, char **av);
t_stack_node* create_stack_a(t_stack_node **head);
t_stack_node* create_stack_b(t_stack_node **head);


t_stack_node* find_last_node(t_stack_node **headRef);



// ACTIONS
// rotate
static void	rotate(t_stack_node **head);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
// push
static void	push(t_stack_node **src, t_stack_node **dst);
void debugPrintList(t_stack_node **head); 

// static void     rev_rotate(t_stack_node **head);
// t_stack_node* create_list(int ac, char **av, t_stack_node** head);
// static t_stack_node *find_maxi(t_stack_node **head);
#endif