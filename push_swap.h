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
    int     nbr; // a change par long !
    int     index;
    int     push_cost;
    int     position;
    bool    above_median;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;

#include "./split.c"
#include "./debbug_ps.c"
#include "./utils_ps.c"
#include "./actions.c"
#include "./initList.c"
#include "./actions/rotate.c"
#include "./actions/rev_rotate.c"
#include "./actions/push.c"
#include "./actions/swap.c"
#include "./actions/sort_three.c"
#include "./algo/push_swap.c"




// FUNCTIONS
// UTILS
char    *my_strncpy(char *s1, char *s2, int n);
char    **my_split(char *str, char delimiter);
static long my_atol(const char *s);

// UTILS PUSHSWAP
// static t_stack_node *find_maxi(t_stack_node **head);
static t_stack_node *find_min(t_stack_node **head);
static t_stack_node* find_last_node(t_stack_node **headRef);
int	list_size(t_stack_node **head);

// DEBBUG
void printList(t_stack_node **head);
void display_prev_values(t_stack_node **head);
void debugPrintList(t_stack_node **head); 



// INIT
t_stack_node* create_small_list(char *av);
t_stack_node* create_list(int ac, char **av);
t_stack_node* create_stack_a(t_stack_node **head);
t_stack_node* create_stack_b(t_stack_node **head);

// ACTIONS
// rotate
static void	rotate(t_stack_node **head);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);

// rev_rotate
static void     rev_rotate(t_stack_node **head);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);

// push
static void	push(t_stack_node **src, t_stack_node **dst);
void    pab(t_stack_node **a, t_stack_node **b);
void    pba(t_stack_node **b, t_stack_node **a);
// swap
static void     swap(t_stack_node **head);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

// sort_three
// static void	sort_three(t_stack_node **a);

// push swap algo 
// void push_a_nodes_to_b(t_stack_node **a, t_stack_node **b);
// // void    define_push_cost(t_stack_node **head);
// // void    define_nodes_position(t_stack_node **head);
void    is_above_median(t_stack_node **head);
void assign_target_node(t_stack_node **a, t_stack_node **b);
// static t_stack_node define_cheapest(t_stack_node **head);
void push_swap(t_stack_node **a, t_stack_node **b);

#endif