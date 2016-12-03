#ifndef _FILLIT_H

# define _FILLIT_H
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "list.h"
#include <stdio.h>

typedef struct    s_stack
{
   char list[26];
   int last;
}                t_stack;


typedef struct	s_pos
{
	int row;
	int col;
}				t_pos;

// int g_inbetween[19][3] = {
// 	{0, 0, 0},
// 	{4, 4, 4},
// 	{0, 2, 0},
// 	{4, 0, 4},
// 	{0, 4, 0},
// 	{3, 0, 3},
// 	{0, 3, 0},
// 	{4, 3, 0},
// 	{4, 0, 0},
// 	{0, 0, 4},
// 	{0, 3, 4},
// 	{3, 0, 0},
// 	{4, 0, 3},
// 	{0, 0, 3},
// 	{3, 0, 4},
// 	{4, 4, 0},
// 	{0, 0, 2},
// 	{0, 4, 4},
// 	{2, 0, 0}
// };

void 	file_read_create(char *file_name, t_list **list);
char **convert_1d_to_2d(char *tetrimino1d);
void shift_origin(char **tetrimino);
int		valid_file(char *buffer, int chars_read);
int		*chars_between_hashes(t_list *list);
int	is_valid_tetrimino(char **tetrimino);
char **create_board(int size);
int		can_place(char **tetrimino, char ***board, int size, t_pos pos);
void place_tet(char **tetrimino, char ***board, int size, t_pos pos);
char			*ft_strndup(char *s, size_t n);
void print_map(char ***board, int size);
// void print_map(char **board);
int size_map(int size, int num_tets);
// int	solve(char **tetrimino, char **board, int size, t_pos pos, int num_tets);
int solve(char ***tetrimino, int num_tets, char **board, int size);
char ***hash_to_alph(char ***alltetriminos, int num_tets);
void push_letter(char *stack, int *index);
char pop_letter(char *stack, int *index);
t_pos ft_remove(char c, char ***board, int size);

#endif