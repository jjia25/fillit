#include "../headers/list.h"

t_list *ft_create_elem(char *data)
{
    t_list *tmp;

    if(!(tmp = (t_list*)malloc(sizeof(t_list))))
        return (0);
    tmp->data = data;
    tmp->next = NULL;
    return (tmp);
}