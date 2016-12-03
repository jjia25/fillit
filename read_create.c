/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:49:34 by srodrigu          #+#    #+#             */
/*   Updated: 2016/11/18 23:06:43 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fillit.h"

char	g_tetriminos[19][20] = {
	{ "####\n....\n....\n....\n" },
	{"#...\n#...\n#...\n#...\n"},
	{".##.\n##..\n....\n....\n"},
	{"#...\n##..\n.#..\n....\n"},
	{ "##..\n.##.\n....\n....\n" },
	{ ".#..\n##..\n#...\n....\n" },
	{ "##..\n##..\n....\n....\n" },
	{ ".#..\n.#..\n##..\n....\n" },
	{ "#...\n###.\n....\n....\n" },
	{  "###.\n..#.\n....\n....\n" },
	{  "##..\n#...\n#...\n....\n" },
	{  ".#..\n###.\n....\n....\n" },
	{  "#...\n##..\n#...\n....\n" },
	{  "###.\n.#..\n....\n....\n" },
	{  ".#..\n##..\n.#..\n....\n" },
	{  "#...\n#...\n##..\n....\n" },
	{  "###.\n#...\n....\n....\n" },
	{  "##..\n.#..\n.#..\n....\n" },
	{  "..#.\n###.\n....\n....\n" }
};

// int		*chars_between_hashes(t_list *list) //helper function to count the number of chars between hashes
// {
// 	int	flag;
// 	int inbetween;
// 	t_list *curr;
// 	int *chars_between_hashes;

// 	curr = list;
// 	if (!(chars_between_hashes = (int *)malloc(sizeof(int) * 3))) //3 numbers determine tetrimino shape
// 		return (NULL);
// 	//i = 0;
// 	flag = 0;
// 	inbetween = 0;
// 	while (list)
// 	{
// 		if (*(curr++) != '#' && flag == 0)
// 			curr++;
// 		if (*(curr++) == '#')
// 			flag = 1;
// 		else (*(curr++) != '#')
// 			inbetween++;
// 		chars_between_hashes++ = inbetween;
// 	}
// 	return (chars_between_hashes);
// }
char **convert_1d_to_2d(char *tetrimino1d)
{
	printf("converting\n");
	char **new;
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	new = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		j = 0;
		new[i] = (char *)malloc(sizeof(char) * 4);
		while (j < 4)
		{
			new[i][j] = tetrimino1d[k];
			k++;
			j++;
		}
		k++;
		i++;
	}
	printf("conversion done\n");
	return (new);
}
void shift_origin(char **tetrimino)
{
	printf("shifting\n");
	t_pos pos;
	t_pos min;

	pos.col = -1;
	pos.row = -1;
	min.col = 4;
	min.row = 4;
	printf("pos col: %d, pos row: %d\n", pos.col, pos.row);
	while (++(pos.row) < 4 && (pos.col = -1))
	{
		while (++(pos.col) < 4)
		{
			if (tetrimino[pos.row][pos.col] == '#' && pos.col < min.col)
				min.col = pos.col;
			if (tetrimino[pos.row][pos.col] == '#' && pos.row < min.row)
				min.row = pos.row;	
		}
	}
	printf("2) pos col: %d, pos row: %d\n", pos.col, pos.row);
	printf("min col: %d, min row: %d\n", min.col, min.row);
	pos.row = -1;
	while (++(pos.row) < 4 && (pos.col = -1) && ((min.col != 0) || (min.row != 0)))
		while (++(pos.col) < 4)
		{
			if (tetrimino[pos.row][pos.col] == '#')
			{
				tetrimino[pos.row - min.row][pos.col - min.col] = '#';
				tetrimino[pos.row][pos.col] = '.';
			}
		}
	printf("shifting done\n");
}

int	is_valid_tetrimino(char **tetrimino)
{
	t_pos pos;
	int i;
	int j;
	int hashes_found;

	i = 0;
	while (i < 19)
	{
		printf("**** checking tet #%d\n", i);
		j = 0;
		pos.row = -1;
		hashes_found = 0;
		while (++(pos.row) < 4)
		{
			pos.col = -1;
			while (++(pos.col) < 4)
				if (g_tetriminos[i][j++] == '#' && tetrimino[pos.row][pos.col] == '#')
					hashes_found++;
			j++;
		}
		i++;
		if (hashes_found == 4)
		{
			printf("valid check success\n");
			return (1);
		}
	}
	return (0);
}

int		valid_file(char *buffer, int chars_read)
{
	while (chars_read > 0)
	{
		if (buffer[chars_read - 1] != '#' 
			&& buffer[chars_read - 1] != '.'
			&& buffer[chars_read - 1] != '\n' 
			&& buffer[chars_read - 1] != '\0')
			return (0);
		chars_read--;
	}
	return (1);
}

void file_read_create(char *file_name, t_list **list) //can't do % 21 because the
// last tetrimino ends with \0
{
	char buffer[546];
	ft_memset(buffer, '\0', 546);
	int fd;
	int chars_read;
	
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ft_putstr("Open file:  ERROR");
	while ((chars_read = read(fd, buffer, 21))) //read 1 tetrimino at a time
	{
		if ((chars_read == 21 || chars_read == 20) && valid_file(buffer, chars_read))
		{

			ft_list_push_back(list, ft_strndup(buffer, chars_read));
			printf("pushed \n%s", ft_strndup(buffer, chars_read));
		}
		// create_tetris_list(buffer, list, chars_read);
		else
		{
			//printf("chars read: %d\n", chars_read);
			ft_putstr("Read file:  ERROR\n");
			exit(1);
		}
	}
	
	close(fd);

	//printf("EVERYTHING IS VALID!\n");
}
