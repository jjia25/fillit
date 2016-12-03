


	while (ept.row < size) //goes through tetris LIST and board rows
	{
		ft_putstr("pos.row: ");
		ft_putnbr(pos.row);
		ft_putstr("\n");
		ept.col = 0;
		while(ept.col < size)
		{
	
			ept.col++;
		}
		ept.row++;
	}
// }

	t_pos value;

new_function{
	if (can_place(tetrimino[0], board, size, first_pos))
	{
		place_tet(tetrimino[0], &board, size, first_pos);
		tet++;
	}
	while (ept.row < size && tet < num_tets  && tetrimino[0]) //goes through tetris LIST and board rows
	{
		ft_putstr("pos.row: ");
		ft_putnbr(pos.row);
		ft_putstr("\n");
		ept.col = 0;
		while (ept.col < size && tet < num_tets && board[size - 1][size - 1] != 'A') //goes through individual tetris piece rows
		{
			ft_putchar(board[pos.row][pos.col]);
			if (board[pos.row][pos.col] == '.'  || ft_isalpha(board[pos.row][pos.col]))
			{
				pos = ept;
				if (!(can_place(tetrimino[tet], board, size, pos)))
				{
					place_tet(tetrimino[tet], &board, size, pos);
					tet++;
				}
				else
				{
					//recurse
					//solve()
					pos.row++;
					pos.col++;
					if (can_place(tetrimino[tet], board, size, pos))
					{
						place_tet(tetrimino[tet], &board, size, pos);
						tet++;
					}
				}
			}
			ept.col++;
		}
		ept.row++;
	}
	}