
// on definit un smallest
// on definit la longeur de la stack A
// si A la stack A len est egale a 5 -> handle_five
// ensuite, tant que la len de a est superieure a 3, on push les nodes de A vers B
// ensuite, on fait un tiny sort de stack A
// ensuite, tant qu'on a des nodes dans B
// init nodes ---> on actualise la position des nodes et leur valeur avant chaque moves
// move nodes ---> on fait les actions qu'on a a faire 
// set current positon of STACK A (???)
// on trouve le plus petit et on le fait remonter avec une boucle while jusqu'a ce qu'il soit en haut de la pile 



// void	push_swap(t_stack_node **a, t_stack_node **b)
// {
// 	t_stack_node	*smallest;
// 	int				len_a;

// 	len_a = stack_len(*a);
// 	if (len_a == 5)
// 		handle_five(a, b);
// 	else
// 	{
// 		while (len_a-- > 3)
// 			pb(b, a, false);
// 	}
// 	tiny_sort(a);
// 	while (*b)
// 	{
// 		init_nodes(*a, *b);
// 		move_nodes(a, b);
// 	}
// 	set_current_position(*a);
// 	smallest = find_smallest(*a);
// 	if (smallest->above_median)
// 		while (*a != smallest)
// 			ra(a, false);
// 	else
// 		while (*a != smallest)
// 			rra(a, false);
// }