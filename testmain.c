#include "push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gerer les inputs en arguments séparés ou en liste OK

// remplir la liste chainée avec les arguments passés en paramètres OK

// coder les instructions de base



int main(int ac, char **av)
{    
    t_stack_node* head = NULL;
    head = create_list(ac, av);

 
    // rotate(&head);
  
   // rev_rotate(&head);

    printList(&head);

    find_maxi(&head);

    return 0;
}



