#include "./list.h"

void	ft_print(char *str)
{
	unsigned int i;
	
	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i++], 1);
	}
}


void ft_putlist(t_list *list)
{
	t_list *tmp;
	
	tmp = list;
	while (tmp)
	{
		ft_print(tmp->data);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}