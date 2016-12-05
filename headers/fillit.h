#ifndef _FILLIT_H

# define _FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

// char	g_tetriminos[19][20] = {
// 	{ "####\n....\n....\n....\n" },
// 	{"#...\n#...\n#...\n#...\n"},
// 	{".##.\n##..\n....\n....\n"},
// 	{"#...\n##..\n.#..\n....\n"},
// 	{ "##..\n.##.\n....\n....\n" },
// 	{ ".#..\n##..\n#...\n....\n" },
// 	{ "##..\n##..\n....\n....\n" },
// 	{ ".#..\n.#..\n##..\n....\n" },
// 	{ "#...\n###.\n....\n....\n" },
// 	{  "###.\n..#.\n....\n....\n" },
// 	{  "##..\n#...\n#...\n....\n" },
// 	{  ".#..\n###.\n....\n....\n" },
// 	{  "#...\n##..\n#...\n....\n" },
// 	{  "###.\n.#..\n....\n....\n" },
// 	{  ".#..\n##..\n.#..\n....\n" },
// 	{  "#...\n#...\n##..\n....\n" },
// 	{  "###.\n#...\n....\n....\n" },
// 	{  "##..\n.#..\n.#..\n....\n" },
// 	{  "..#.\n###.\n....\n....\n" }
// };

typedef struct	s_pos
{
	int row;
	int col;
}				t_pos;

void 	file_read_create(char *file_name, t_list **list);
char **convert_1d_to_2d(char *tetrimino1d);
void shift_origin(char **tetrimino);
//int		valid_file(char *buffer, int chars_read);
int		*chars_between_hashes(t_list *list);
int	is_valid_tetrimino(char **tetrimino);
char **create_board(int size);
int		can_place(char **tetrimino, char ***board, int size, t_pos pos);
void place_tet(char **tetrimino, char ***board, int size, t_pos pos);
char			*ft_strndup(char *s, size_t n);
void print_map(char ***board, int size);
int size_map(int size, int num_tets);
int solve(char ***tetrimino, int num_tets, char **board, int size);
char ***hash_to_alph(char ***alltetriminos, int num_tets);
void push_pos(t_pos *pos, t_pos **stack, int *index);
t_pos pop_pos(t_pos **stack, int *index);
void ft_remove(char c, char ***board, int size);
//int valid_hashes(t_list **list);

#endif