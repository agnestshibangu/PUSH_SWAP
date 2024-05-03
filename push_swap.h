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
#include "./initList.c"
#include "./actions.c"

// FUNCTIONS
// UTILS
char    *my_strncpy(char *s1, char *s2, int n);
char    **my_split(char *str, char delimiter);

t_stack_node* create_list(int ac, char **av);
void printList(t_stack_node **head);
t_stack_node* find_last_node(t_stack_node **headRef);
// static void	rotate(t_stack_node **head);
// static void     rev_rotate(t_stack_node **head);
// t_stack_node* create_list(int ac, char **av, t_stack_node** head);
// static t_stack_node *find_maxi(t_stack_node **head);
#endif