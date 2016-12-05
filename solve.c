
#include "./headers/fillit.h"

// int find_first_hash(char *first_tetrimino, t_pos *pos)
// {
// 	int index;

// 	index = 0;
// 	while (index < 4)
// 	{
// 		if (ft_isalpha(first_tetrimino[index]))
// 		{
// 			pos->row = 0;
// 			pos->col = index;
// 			return (1);
// 		}
// 		index++;
// 	}
// 	return (0);
// }

void ft_error()
{
        (ft_putstr("error\n"));
        exit (EXIT_FAILURE);
}
// static void	create_stack(t_pos ***new_stack, t_pos **stack)
// {
// 	int index;

// 	index = 0;
//     stack = (t_pos **)malloc(sizeof(t_pos *) * 26);
//     while (index < 26)
//     	stack[index++] = (t_pos *)malloc(sizeof(t_pos));
//     index = 0;
//     while (index < 26)
//     {
//     	(stack[index])->col = 0;
//     	(stack[index++])->row = 0;
//     }
// 	*new_stack = stack; 
//     // ft_memset(stack,'0', 26);
// }
static t_pos	*create_stack()
{
	int index = 0;
	t_pos *stack;

	stack = (t_pos*)malloc(sizeof(t_pos) * 26);
    while (index < 26)
    {
    	(stack[index]).col = 0;
    	(stack[index++]).row = 0;
    }
	// t_pos **new_stack;
	return stack;
}
 
void ft_remove(char c, char ***board, int size)
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
	//ft_putstr("1) Removing tet...\n");
	//ft_putchar(c);
	//ft_putchar('\n');
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
             		//printf("curr.row: %d\ncurr.col: %d\n", curr.row, curr.col);
             		i++;
             	}
             	board[0][pos.row][pos.col] = '.';
             	count++;
            }
            //printf("Count: %d\n", count);
            if (count == 4)
            {
            	//ft_putstr("BOARD WITHIN REMOVE FUNCTION\n");
            	//print_map(board, size);
            	return ;
            }
        	pos.col++;
		}
		pos.row++;
	}
}

int solve(char ***tetrimino, int num_tets, char **board, int size)
{
	//printf("3) num_tets is %d\n", num_tets);
	// ft_putstr("ENTERING IN SOLVE size"); ft_putnbr(size); ft_putchar('\n');
	int tet;
	t_pos pos;
	t_pos *stack;

	tet = 0;
	pos.col = 0;
	pos.row = 0;
	
	stack = create_stack();
	while (tet < num_tets)
	{
		// ft_putstr("Placing tet: "); ft_putchar(('A' + tet)); ft_putchar('\n');
		if (can_place(tetrimino[tet], &board, size, pos))
		{
			//ft_putstr("call place function..\n");
			place_tet(tetrimino[tet], &board, size, pos);
			push_pos(&pos, &stack, &tet);
			// print_map(&board, size); ft_putchar('\n');
			pos.row = 0;
			pos.col = 0;
			if (tet == (num_tets))
			{
			//	ft_putstr("Solved\n");
				//print_map(&board, size);
				return (1);
			}

		}
		else
		{

			if (pos.col == size)
			{
				if (pos.row == (size - 1))
				{
					if (tet == 0)
					{
					//	ft_putstr("DOESNT WORK\n");
						return (0);
					}
					// ft_putstr("Removing tet\n");
					pos = pop_pos(&stack, &tet);
					if (tet == 0)
					{
						// ft_putstr("Tet:"); ft_putnbr(0); ft_putchar('\n');
						ft_remove('A', &board, size);
					}
					else
					{
					// ft_putstr("Tet:"); ft_putnbr(tet); ft_putchar('\n');
						ft_remove(('A' + tet), &board, size);
					} 
					// ft_remove(('A' + index), &board, size);
					// ft_putstr("pop pos.col returned: "); ft_putnbr(pos.col); ft_putchar('\n');
					// ft_putstr("pop pos.row returned: "); ft_putnbr(pos.row); ft_putchar('\n');
					//print_map(&board, size); ft_putchar('\n');
					//pos.col = 0;
					// pos.row = 0;
					// pos.col++;
					// pos.row++;
					// tet--;
					//ft_putstr("continue :(\n");
					// continue ;
				}
				else
				{
					//ft_putstr("increase row col \n");
					//ft_putstr("pos.row: ");ft_putnbr(pos.row); ft_putchar('\n'); ft_putstr("pos.col: ");ft_putnbr(pos.col); ft_putchar('\n');
					pos.row++;
					pos.col = 0;
					// ft_putstr("continue\n");
					continue ;
				}
			}
			// ft_putstr("pop pos.col before: "); ft_putnbr(pos.col); ft_putchar('\n');
			// ft_putstr("pop pos.row before: "); ft_putnbr(pos.row); ft_putchar('\n');
			// ft_putstr("pos.col: ");ft_putnbr(pos.col); ft_putchar('\n');
			pos.col++;
			// ft_putstr("pop pos.col after: "); ft_putnbr(pos.col); ft_putchar('\n');
			// ft_putstr("pop pos.row after: "); ft_putnbr(pos.row); ft_putchar('\n');
		}

	}
	return (0);
}
