#ifndef _LIST_H
# define _LIST_H

# include <unistd.h>
# include <stdlib.h>



t_list				*ft_create_elem(char *data);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_push_back(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_putlist(t_list *list);
#endif
