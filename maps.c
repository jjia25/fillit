/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pre_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:50:39 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:27:07 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"


	// while (curr)
	// 	{
	// 		ft_putstr("Original map:\n");
	// 		print_map(board, size);
			
	// 		if (can_place(alltetriminos[0], board, size, pos) == 0)
	// 			size_map(size++, num_tets++);
	// 		// if (can_place(tetriminos[num_tets], board, size, pos) == 1)
	// 		// {
	// 		// 	place_tet(tetriminos[num_tets], board, size);
	// 		// }
	// 		curr = curr->next;
	// 	}

char ***hash_to_alph(char ***alltetriminos, int num_tets)
{
	char letter;
	int x;
	int y;
	int index= 0;

	letter = 'A';
	printf("Hash to alpha...\n");
	while (index < num_tets && letter <= 'Z')
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (alltetriminos[index][y][x] == '#')
					alltetriminos[index][y][x] = letter;
				x++;
			}
			printf("%s\n", alltetriminos[index][y]);
			y++;
		}
		letter++;
		index++;
	}
	return (alltetriminos);
}

int	size_map(int size, int num_tets)
{
	while (size * size < 4 * (num_tets))
	 	size++;
	printf("2) size: %d\n", size);
	return (size);
}

int		can_place(char **tetrimino, char ***board, int size, t_pos pos)
{
	int emptyspace;
	int x;
	int y;
	emptyspace = 0;

	y = 0;
	while (y < 4 && (y + pos.row) < size)
	{
		x = 0;
		while (x < 4 && (x + pos.col) <= size)
		{
			if (ft_isalpha(tetrimino[y][x]) && board[0][pos.row + y][pos.col + x] == '.')
			{
				emptyspace++;
				// printf("emptyspace: %i\n", emptyspace);
				// printf("y: %i\n", y);
				// printf("x: %i\n", x);
			}
			x++;
		}
		y++;
	}
	if ( emptyspace == 4)
		return (1);
	return (0);
}

void place_tet(char **tetrimino, char ***board, int size, t_pos pos)
{
    int x;
    int y;
    int orig_col;

    orig_col = pos.col;
    y = 0;
    ft_putstr("placing tetrimino...\n");
    while (y < 4 && pos.row < size)
    {
        x = 0;
        pos.col = orig_col;
        while (x < 4 && pos.col < size)
        {
            if (ft_isalpha(tetrimino[y][x]))
                board[0][pos.row][pos.col] = tetrimino[y][x];
            pos.col++;
            x++;
        }
        pos.row++;
        y++;
    }
    ft_putstr("placed.\n");
}

char **create_board(int size)
{
	char **board;
	int x;
	int y;

	y = 0;
	printf("Create board:\n");
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (0);
	ft_bzero(board, (sizeof(char *) * size));
	while (y < size)
	{	
		//printf("CREATING ANOTHER ROW\n");
		if (!(board[y] = (char *)malloc(sizeof(char) * size)))
			return (0);
		x = 0;
		ft_bzero(board[y], (sizeof(char) * size));
		while (x < size)
		{
			board[y][x] = '.';
			ft_putchar(board[y][x]);
			x++;
		}
		y++;
		ft_putchar('\n');
	}
	return (board);
}


void print_map(char ***board, int size)
{
	int x;
	int y;

	y = 0;
	printf("Printing now:\n");
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(board[0][y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}
