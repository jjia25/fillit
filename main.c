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

char		g_tetriminos[19][20] = {
	{"####\n....\n....\n....\n"},
	{"#...\n#...\n#...\n#...\n"},
	{".##.\n##..\n....\n....\n"},
	{"#...\n##..\n.#..\n....\n"},
	{"##..\n.##.\n....\n....\n"},
	{".#..\n##..\n#...\n....\n"},
	{"##..\n##..\n....\n....\n"},
	{".#..\n.#..\n##..\n....\n"},
	{"#...\n###.\n....\n....\n"},
	{"###.\n..#.\n....\n....\n"},
	{"##..\n#...\n#...\n....\n"},
	{".#..\n###.\n....\n....\n"},
	{"#...\n##..\n#...\n....\n"},
	{"###.\n.#..\n....\n....\n"},
	{".#..\n##..\n.#..\n....\n"},
	{"#...\n#...\n##..\n....\n"},
	{"###.\n#...\n....\n....\n"},
	{"##..\n.#..\n.#..\n....\n"},
	{"..#.\n###.\n....\n....\n"}
};

int			size_map(int size, int num_tets)
{
	while (size * size < 4 * (num_tets))
		size++;
	return (size);
}

int			count_num_tets(t_list **curr)
{
	int		num_tets;
	t_list	*tmp;

	num_tets = 0;
	tmp = *curr;
	while (tmp)
	{
		num_tets++;
		tmp = tmp->next;
	}
	return (num_tets);
}

static void	ft_initialize(t_list **list, int *size)
{
	*list = 0;
	*size = 2;
}

static void	list_to_array(char ****alltetriminos, int *num_tets, t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		(*alltetriminos)[*num_tets] = convert_1d_to_2d(tmp->data);
		shift_origin((*alltetriminos)[*num_tets]);
		if (!is_valid_tetrimino((*alltetriminos)[*num_tets]))
			ft_error();
		(*num_tets)++;
		tmp = tmp->next;
	}
	free(*list);
}

int			main(int ac, char **av)
{
	t_list	*list;
	int		num_tets;
	int		size;
	char	***alltetriminos;
	char	**board;

	ft_initialize(&list, &size);
	if (ac != 2)
		ft_error();
	else
	{
		num_tets = file_read_create(av[1], &list);
		if (!(alltetriminos = (char ***)malloc(sizeof(char **) * num_tets)))
			return (0);
		num_tets = 0;
		list_to_array(&alltetriminos, &num_tets, &list);
		alltetriminos = hash_to_alph(alltetriminos, num_tets);
		board = create_board(size_map(size, num_tets));
		while (!(solve(alltetriminos, num_tets, board, size)))
			board = create_board(size_map(++size, num_tets));
		print_map(&board, size);
		free(alltetriminos);
	}
	return (0);
}
