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

	pos.row = 0;
	pos.col = 0;
	list = 0;
	if (ac != 2)
	{
		(ft_putstr("1) error"));
		return (1);
	}
	else
	{
		file_read_create(av[1], &list); //stores everything we read in a list, each node is 20 to 21 chars
		num_tets = 0;
		curr = list;
		while (curr) //counts number of tets
		{
			num_tets++;
			curr = curr->next;
		}
		if (!(alltetriminos = (char ***)malloc(sizeof(char **) * num_tets)))
			return (0);
		curr = list;
		num_tets = 0; //being used as an index
		while (curr)
		{
			//printf("1) num_tets is %d\n", num_tets);
			alltetriminos[num_tets] = convert_1d_to_2d(curr->data); //store each node in num_tets, part of 3d array
			shift_origin(alltetriminos[num_tets]); //validate tetriminos
			int i = 0;
			while (i < 4)
			{
				printf("Shifted: %s\n", alltetriminos[num_tets][i++]);
			}
			if(is_valid_tetrimino(alltetriminos[num_tets]) == 0)
			{
				ft_putstr("2) error");
				return (1);
			}
			num_tets++;
			curr = curr->next;
		} //work out of alltetriminos from this point forward
		free(list);
		alltetriminos = hash_to_alph(alltetriminos, num_tets);
		//printf("2) num_tets is %d\n", num_tets);
		size = 4;
	 //create initial board based on num_tets
		board = create_board(size_map(size, num_tets));
		printf("size: %i\n", size);
		print_map(&board, size);
		ft_putstr("TESTING PRINT: \n");
		solve(alltetriminos, num_tets, board, size);
		free(alltetriminos);
		// while (!(solve(alltetriminos, num_tets, board, size)))
		// {
		// 	ft_putstr("Trying to solve...\n");
		// 	board = create_board(size_map(++size, num_tets));
		// }
		// printf("\nSolved? %d\n", solve(alltetriminos, num_tets, board, size));
		// printf("size: %i\n", size);

	}
	return (0);
}
