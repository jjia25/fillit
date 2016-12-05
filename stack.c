#include "./headers/fillit.h"

void push_pos(t_pos *pos, t_pos **stack, int *tet)
{
    // t_pos tmp;

    // tmp = *pos;
    //ft_putstr("=======push=======\n");
    //ft_putstr("Current Tet"); ft_putnbr(*tet); ft_putchar('\n');
   // ft_putstr("push pos.col being stored: "); ft_putnbr(pos->col); ft_putchar('\n');
	//ft_putstr("push pos.row being stored: "); ft_putnbr(pos->row); ft_putchar('\n');
    if (*tet >= 26)
    {
        ft_putstr("stack is going over");
        return ;
    }
   else
    {
		// if (*tet == 0)
		// {
  //           stack[*tet] = 'A';
		// }
      //  ft_putstr("before seg\n");
        (stack[0][*tet]) = *pos;
       // ft_putstr("after seg\n");
    	*tet += 1;
    }
    // ft_putstr(" col: "); ft_putnbr(pos->col); ft_putchar('\n');
    // pos->col++;
    //  ft_putstr("before col: "); ft_putnbr(pos->col); ft_putchar('\n');
}


t_pos pop_pos(t_pos **stack, int *tet)
{
    t_pos res;
    //ft_putstr("=======pop=======\n");
    if (*tet == -1)
    {
        ft_putstr("error\n");
        exit (1);
    }
    *tet -= 1;
    res = stack[0][*tet];
    stack[0][*tet].col = 0;
    stack[0][*tet].row = 0;
    //ft_putstr("pop pos.col returned: "); ft_putnbr(res.col); ft_putchar('\n');
	//ft_putstr("pop pos.row returned: ");ft_putnbr(res.row); ft_putchar('\n');
    return (res);
	// stack[*tet] = pos;
 //    return (pos);
}