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
    int     total_cost;
    int     position;
    bool    above_median;
    bool    cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;

// FUNCTIONS
// UTILS
char    *my_strncpy(char *s1, char *s2, int n);
char    **my_split(char *str, char delimiter);
long my_atol(const char *s);

// UTILS PUSHSWAP
t_stack_node *find_maxi(t_stack_node **head);
t_stack_node *find_min(t_stack_node **head);
t_stack_node* find_last_node(t_stack_node **headRef);
int	list_size(t_stack_node **head);
void     sort_after_push(t_stack_node **head);

// DEBBUG
void printList(t_stack_node **head);
void display_prev_values(t_stack_node **head);
void debugPrintList(t_stack_node **head); 
int if_list_is_sorted(t_stack_node **head);
void printf_for_shell_debbug(t_stack_node **a, t_stack_node **b);

// INIT
t_stack_node* create_small_list(char *av);
t_stack_node* create_list(int ac, char **av);
t_stack_node* create_stack_a(t_stack_node **head);
t_stack_node* create_stack_b(t_stack_node **head);

// ACTIONS
// rotate
void	rotate(t_stack_node **head);
void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);

// rev_rotate
void     rev_rotate(t_stack_node **head);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);

// push
void	push(t_stack_node **src, t_stack_node **dst);
void    pab(t_stack_node **a, t_stack_node **b);
void    pba(t_stack_node **a, t_stack_node **b);
// swap
void     swap(t_stack_node **head);
void    sa(t_stack_node **a);
void    sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

// sort_three
void	sort_three(t_stack_node **a);

// [[[algo]]] ---> (push_swap.c) 
void    push_a_nodes_to_b(t_stack_node **a, t_stack_node **b);
// define the push cost for a and b
void    define_push_cost(t_stack_node **head);
void    define_push_cost_a_b(t_stack_node **a, t_stack_node **b);
// define the position for a and b
void    define_nodes_position(t_stack_node **head);
void    define_nodes_position_a_b(t_stack_node **a, t_stack_node **b);
// for both stacks, define which nodes are above the median in a and b
void    is_above_median(t_stack_node **head);
void    define_is_above_median_a_b(t_stack_node **a, t_stack_node **b);
// assigne a target for b nodes
void assign_target_node(t_stack_node **a, t_stack_node **b);
// define cheapest
t_stack_node* define_cheapest(t_stack_node **head);
//void define_cheapest_in_both_stack(t_stack_node **a, t_stack_node **b);
void    define_cheapest_a_b(t_stack_node **a, t_stack_node **b);
// check the two cheapest nodes in a and b
// void check_two_cheapest_after_def(t_stack_node **a, t_stack_node **b);
void push_swap(t_stack_node **a, t_stack_node **b);
void    define_combined_cost(t_stack_node **head);

// // [[[algo]]] ---> (push_swap2.c)
void reinitialise_before_next_move(t_stack_node **a, t_stack_node **b);
void move_cheapest_to_top(t_stack_node **head);
t_stack_node *find_target_to_move(t_stack_node **a, t_stack_node **b);
void once_on_top_push_b_to_a(t_stack_node **a, t_stack_node **b);
void move_cheapest_to_top_a(t_stack_node **a, t_stack_node **b);

#endif