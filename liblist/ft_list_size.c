#include "../headers/list.h"

int ft_list_size(t_list *begin_list)
{
    int count;
    t_list *temp;

    temp = begin_list;
    count = 0;
    while (temp)
    {
		count++;
        temp = temp->next;
    }
    return (count);
}