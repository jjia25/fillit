

#include "./headers/fillit.h"

int find_first_hash(char *first_tetrimino, t_pos *pos)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (ft_isalpha(first_tetrimino[index]))
		{
			pos->row = 0;
			pos->col = index;
			return (1);
		}
		index++;
	}
	return (0);
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
	ft_putstr("1) Removing tet...\n");
	ft_putchar(c);
	ft_putchar('\n');
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
             		printf("curr.row: %d\ncurr.col: %d\n", curr.row, curr.col);
             		i++;
             	}
             	board[0][pos.row][pos.col] = '.';
             	count++;
            }
            //printf("Count: %d\n", count);
            if (count == 4)
            {
            	ft_putstr("BOARD WITHIN REMOVE FUNCTION\n");
            	print_map(board, size);
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
    ft_putstr("Pushing letter...\n");
    // if (stack->last == 26)
    if (*index == 26)
    {
    	ft_putstr("stack is already maxed out");
        return ;
    }
   else
    {
		if (*index == 0)
		{
			ft_putstr("pushing first letter...\n");
            stack[*index] = 'A';
		}
        // else
        // {
        // 	ft_putstr("pushing a letter...\n");
        //     stack->list[stack->last + 1] = stack->list[stack->last] + 1;
        // }
    	(*index)++;
    }
   ft_putstr("Letter pushed.\n");
}


char pop_letter(char *stack, int *index)
{
    ft_putstr("Popping letter stack\n");
    char c;
    ft_putchar(stack[*index]);
    ft_putstr("\n");
    if (*index == -1)
    {
        ft_putstr("Last letter has already been Popped\n");
        return 0;
    }
    (*index)--;
	c = stack[*index];
	ft_putchar(c);
	ft_putstr("\n");
	// stack->last--;
	ft_putstr("Letter popped\n");
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
	printf("3) num_tets is %d\n", num_tets);
	
	int tet;
	t_pos pos; //where tet is on board
	char *stack;
	// t_pos ept;
	create_stack(&stack);
	// pos.row = 0;
	// pos.col = 0;
	// stack.list[0] = 'A';
	// stack.list[1] = 'B';
	// stack.list[2] = 'C';
	// stack.list[3] = 'D';
	// stack.last = 0;

	// ept.row = 0;
	// ept.col = 0;
	tet = 0;

	while (tet < num_tets)
	{
		//ft_putnbr(tet);
		if (can_place(tetrimino[tet], &board, size, pos))
		{
			ft_putstr("Placing first tet\n");
			place_tet(tetrimino[tet], &board, size, pos);
			pos.row = 0;
			pos.col = 0;
			if (tet == (num_tets - 1))
			{
				print_map(&board, size);
				return (1);
			}
			push_letter(stack, &tet);
			print_map(&board, size);
			ft_putnbr(tet);
			// tet++;
		}
		else
		{
			if (pos.col == (size - 1))
			{
				if (pos.row == (size - 1))
				{
					if (tet == 0)
					{
						ft_putstr("DOESNT WORK\n");
						return (0);
					}
					ft_putstr("Removing tet\n");
					pos = ft_remove(pop_letter(stack, &tet), &board, size);
					print_map(&board, size);
					// pos.col++;
					pos.row++;
					// tet--;
					continue ;
				}
				else
				{
					pos.row++;
					pos.col = 0;
				}
			}
			pos.col++;
		}
	}
	return (0);
}
//    run through again.
// }
// return (1);
// }
	// while (tetrimino_list) //goes through tetris LIST
	// 	if (cant place first tetrimino) //check first_pos corner against column size and row size
	// 		change tetrimino start
	// 		break;
	// 	while (ept.row < size) //goes through board rows
	// 		while (ept.col < size && tet < num_tets && board[size - 1][size - 1] != 'A') //goes through individual tetris piece rows
	// if (find_first_hash(tetrimino[0][0], &first_pos))
	// {
	// 	ft_putstr("WORKED\n");
	// 	printf("RESULTS %d, %d\n", first_pos.row, first_pos.col);
	// 	return 1;
	// }
	// else return 0;

	// while (ept.row < size && tet < num_tets  && tetrimino[0]) //goes through tetris LIST and board rows
	// {
	// 	ft_putstr("pos.row: ");
	// 	ft_putnbr(pos.row);
	// 	ft_putstr("\n");
	// 	ept.col = 0;
	// 	while (ept.col < size && tet < num_tets && board[size - 1][size - 1] != 'A') //goes through individual tetris piece rows
	// 	{
	// 		ft_putchar(board[pos.row][pos.col]);
	// 		if (board[pos.row][pos.col] == '.'  || ft_isalpha(board[pos.row][pos.col]))
	// 		{
	// 			pos = ept;
	// 			if (!(can_place(tetrimino[tet], board, size, pos)))
	// 			{
	// 				place_tet(tetrimino[tet], &board, size, pos);
	// 				tet++;
	// 			}
	// 			else
	// 			{
	// 				//recurse
	// 				//solve()
	// 				pos.row++;
	// 				pos.col++;
	// 				if (can_place(tetrimino[tet], board, size, pos))
	// 				{
	// 					place_tet(tetrimino[tet], &board, size, pos);
	// 					tet++;
	// 				}
	// 			}
	// 		}
	// 		ept.col++;
	// 	}
	// 	ept.row++;
	// }
	// printf("Placed map:\n");
	// print_map(board, size);
	// if ((ept.row == size) && (ept.col == size) && (tet < num_tets))
	// {
	// 	ft_putstr("DIDN'T SOLVE!\n");
 //        return 0;
	// }
	// ft_putstr("SOLVED!\n");
	// return (1);

