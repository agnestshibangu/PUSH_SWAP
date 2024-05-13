#include "../push_swap.h"

void push_a_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    int stack_a_len;

    stack_a_len = list_size(a);
    while (stack_a_len > 3)
    {
        push(a, b);
        stack_a_len--;
    }
}

// A DEBUGGER = target node pour le maximum est le min node !
void assign_target_node(t_stack_node **a, t_stack_node **b) {
    t_stack_node *current_in_a = *a;
    t_stack_node *current_in_b = *b;
    t_stack_node *target_node;
    long best_match;

    target_node = NULL;

    while (current_in_b) 
    {
        best_match = LONG_MAX; // Reset for each element in b
        while (current_in_a)
        {
            if (current_in_a->nbr > current_in_b->nbr && current_in_a->nbr < best_match) {
                best_match = current_in_a->nbr;
                target_node = current_in_a;
            }
            current_in_a = current_in_a->next;
        }
        current_in_a = *a; // Reset for next iteration over b
        if (best_match != LONG_MAX) {
            current_in_b->target_node = target_node;
            printf("le target node de %d est : %d\n", current_in_b->nbr, current_in_b->target_node->nbr);
        }
        else if (best_match == LONG_MAX)
        {
            current_in_b->target_node = find_min(a);
            printf("valeur maximale, le target node de %d est : %d\n", current_in_b->nbr, current_in_b->target_node->nbr);
        }
        printf("-----\n");
        current_in_b = current_in_b->next;
    }
}

void    define_nodes_position(t_stack_node **head)
{
    t_stack_node *current; 
    int i;
    i = 0;

    current = *head;
    while (current != NULL) {
        current->position = i;
        printf("NODE %d at postion %d \n", current->nbr, current->position);
        i++;
        current = current->next;
    }
}

void    define_nodes_position_a_b(t_stack_node **a, t_stack_node **b)
{
    define_nodes_position(a);
    define_nodes_position(b);

    printf("define position done\n");
}


void    is_above_median(t_stack_node **head)
{
    t_stack_node *current = *head; 
    int len;
    int median;

    len = list_size(head);
    if (len % 2 != 0)
        median = len / 2 + 1;
    else 
        median = len / 2;

    while (current != NULL) {
        if (current->position < median)
            current->above_median = true;
        else
            current->above_median = false;
        current = current->next;
    }

    current = *head;
    // printf part
    while (current != NULL) {
        printf("is the node %d above median ? %d\n", current->nbr, current->above_median);
        current = current->next;
    }
}

void    define_is_above_median_a_b(t_stack_node **a, t_stack_node **b)
{
    define_nodes_position(a);
    define_nodes_position(b);

    printf("define position done for a and b\n");
}

void    define_push_cost(t_stack_node **head)
{
    int len;
    t_stack_node *current = *head; 

    len = list_size(head);
    while (current != NULL) {   
        if (current->above_median == true)
        {
            current->push_cost = current->position;
            printf("the cost of the node %d is %d\n", current->nbr, current->push_cost);
        }
        else if (current->above_median == false) 
        {
            current->push_cost = len - current->position;
            printf("the cost of the node %d is %d\n", current->nbr, current->push_cost);
        }
        current = current->next;
    }
}


void    define_push_cost_a_b(t_stack_node **a, t_stack_node **b)
{
    define_push_cost(a);
    define_push_cost(b);
    printf("define push cost for a and b done\n");

}

static t_stack_node* define_cheapest(t_stack_node **head)
{
    t_stack_node *current = *head; 
    t_stack_node *cheapest_node;
    long cheapest;

    cheapest_node = NULL;
    cheapest = LONG_MAX;
    while (current != NULL) {   
        if (current->push_cost < cheapest)
        {
            cheapest = current->push_cost;
            cheapest_node = current;
            current->cheapest = true;
            // printf("current cheapest node : %d\n", cheapest_node->nbr);
        }
        // else if (current->push_cost == cheapes)
        // {
        //     // If there's another node with the same cheapest cost, add it to the list
        //     current->next_cheapest = cheapests;
        //     cheapest_nodes = current;
        // }
        current = current->next;
    }
    return (cheapest_node);
}

void    define_cheapest_a_b(t_stack_node **a, t_stack_node **b)
{
    define_cheapest(a);
    define_cheapest(b);
    printf("define cheapest in a and b done\n");
}


void check_two_cheapest_after_def(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_a = define_cheapest(a);
    t_stack_node *cheapest_b = define_cheapest(b);
    
    printf("STACK A cheapest node %d  cheapest ? %d\n", cheapest_a->nbr, cheapest_a->cheapest);
    printf("STACK B cheapest node %d  cheapest ? %d\n", cheapest_b->nbr, cheapest_b->cheapest);

}

void push_swap(t_stack_node **a, t_stack_node **b)
{
    // pushing node from a to b until there is only 3 nodes in a 
    push_a_nodes_to_b(a, b);
    // sort three for the a stack
    sort_three(a);
    // on definit un target node pour chaque node de b vers a
    assign_target_node(a, b);
    // t_stack_node *smallest;

    // on definit un push cost pour chaque node 

    
    // return;
}