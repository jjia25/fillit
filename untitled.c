
#include "./headers/fillit.h"

void ft_error()
{
        (ft_putstr("error\n"));
        exit (EXIT_FAILURE);
}
 
t_pos ft_remove(char c, char ***board, int size)
{
	t_pos pos;
	t_pos curr;
	int i;
	int count;

	i = 0;
	count = 0;
	pos.row = 0;
	pos.col = 0;
	curr.row = pos.row;
	curr.col = pos.col;
	while (pos.row < size)
	{
		pos.col = 0;
		while (pos.col < size)
		{
			if (board[0][pos.row][pos.col] == c)
            {
             	if (!i)
             	{
             		curr.row = pos.row;
             		curr.col = pos.col;

             		i++;
             	}
             	board[0][pos.row][pos.col] = '.';
             	count++;
            }
            if (count == 4)
            {
            	return (curr);
            }
        	pos.col++;
		}
		pos.row++;
	}
	return (curr);
}

void push_letter(char *stack, int *index)
{
    if (*index == 26)
    {
        return ;
    }
   else
    {
		if (*index == 0)
		{
            stack[*index] = 'A';
		}
    	(*index)++;
    }
}


char pop_letter(char *stack, int *index)
{
    char c;

    if (*index == -1)
    {
        return 0;
    }
    (*index)--;
	c = stack[*index];
    return (c);
}
static void create_stack(char **list)
{
	char c;
	int index;

	c = 'A';
	*list = (char *)malloc(sizeof(char) * 26);
	index = 0;
	while (index < 26)
	{
		list[0][index] = c++;
		index++;
	}
}

int solve(char ***tetrimino, int num_tets, char **board, int size)
{
	int tet;
	t_pos *pos;
	char *stack;

	tet = 0;
	pos.col = 0;
	pos.row = 0;
	create_stack(&stac, tet);
	while (tet < num_tets)
	{
		if (can_place(tetrimino[tet], &board, size, pos))
		{
			place_tet(tetrimino[tet], &board, size, pos);
			pos.row = 0;
			pos.col = 0;
			if (tet == (num_tets - 1))
			{
				return (1);
			}
			push_letter(stack, &tet, pos);
			print_map(&board, size); ft_putchar('\n');
		}
		else
		{
			if (pos.col == size)
			{
				if (pos.row == (size - 1))
				{
					if (tet == 0)
					{
						return (0);
					}
					pos = ft_remove(pop_pos(stack, &tet), &board, size);
					// pos = pop_pos(stack, &tet);
					// ft_remove(('A' + index), &board, size);
					ft_putstr("pop pos.col returned: "); ft_putnbr(pos.col); ft_putchar('\n');
					ft_putstr("pop pos.row returned: "); ft_putnbr(pos.row); ft_putchar('\n');
					print_map(&board, size); ft_putchar('\n');

				}
				else
				{
					pos.row++;
					pos.col = 0;
					continue ;
				}
			}
			pos.col++;
		}

	}
	return (0);
}
