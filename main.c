/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:32:04 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:20:08 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

int main(int ac, char **av)
{
	t_list *list;
	t_list *curr;
	int	num_tets;
	int size;
	char ***alltetriminos;
	char **board;
	t_pos pos;
	// t_pos test;
	int tmp_tets;

	// test.col = 1;
	// test.row = 0;
	tmp_tets = 0;
	pos.row = 0;
	pos.col = 0;
	list = 0;
	if (ac != 2)
	{
		(ft_putstr("error\n"));
		exit (EXIT_FAILURE);
	}
	else
	{
		file_read_create(av[1], &list);
		num_tets = 0;
		curr = list;
		while (curr)
		{
			num_tets++;
			curr = curr->next;
		}
		if (!(alltetriminos = (char ***)malloc(sizeof(char **) * num_tets)))
			return (0);
		curr = list;
		tmp_tets = num_tets;
		num_tets = 0;
		while (curr)
		{
			alltetriminos[num_tets] = convert_1d_to_2d(curr->data);
			shift_origin(alltetriminos[num_tets]);
			// int i = 0;
			// while (i < 4)
			// {
			// 	printf("Shifted: %s\n", alltetriminos[num_tets][i++]);
			// }
			if(!is_valid_tetrimino(alltetriminos[num_tets]))
			{
				ft_putstr("error\n");
				exit (EXIT_FAILURE);
			}
			num_tets++;
			curr = curr->next;
		}
		free(list);
		alltetriminos = hash_to_alph(alltetriminos, num_tets);
		size = 2;
		board = create_board(size_map(size, num_tets));
		// ft_putstr("Can Place?\n");
		// if (can_place(alltetriminos[0], &board, size, test))
		// {
		// 	ft_putstr("tet placed\n");
		// 	place_tet(alltetriminos[0], &board, size, test);
		// }
		//board = create_board(size);
		//print_map(&board, size);
		// ft_putstr("SOLVING FILLIT");
		//solve(alltetriminos, num_tets, board, size);
		 while (!(solve(alltetriminos, num_tets, board, size)))
		 {
		 	//tmp_tets++;
		 	//ft_putstr("OLD BOARD\n");
		 	//print_map(&board, size);
		 	board = create_board(size_map(++size, tmp_tets));
		 	//ft_putstr("NEW BOARD\n");
		 	//print_map(&board, size);
		 }
		//ft_putstr("final board main\n");
		print_map(&board, size);
		free(alltetriminos);
		//printf("size: %i\n", size);
	}
	return (0);
}
