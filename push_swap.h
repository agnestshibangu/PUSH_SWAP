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
    struct s_stack_node *next_node;
    struct s_stack_node *prev_node;

}   t_stack_node;

// FUNCTIONS


#endif