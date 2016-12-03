#include "./libft/libft.h"
#include "./headers/list.h"
#include <unistd.h>
#include <fcntl.h>

//link main.c to libft.a
// gcc main.c -o fillmeup -L./libft/ -lft

int is_valid(char *termino)
{
	return (0);
}

void store_terminos(char *buffer)
{
	int count;
	char *termino;
	t_list master_list;
	
	while(*buffer != 0)
	{
		termino = (char *)malloc(sizeof(char) * 21);
		count = 21;

		if ((*buffer == '.' || *buffer == '#') && (*(buffer + 20) == '\n' || *(buffer + 20) == '\0'))
			while (count > 0 && *buffer)
				*(termino + (21 - count--)) = *buffer++;
		else
			break ;
//		ft_list_push_front(t_list **begin_list, void *data);
		ft_create_elem(termino);
		ft_list_push_front(&master_list, termino);
//		while (*termino)
//			ft_putchar(*termino++);
		ft_putstr(termino);
	}

}

void file_read_store(int fd)
{
	char buffer[546];
	t_list list;
	
	if (fd == -1)
		return ft_putstr("problem opening file");
	if (read(fd, buffer, 546) != 0)
		store_terminos(buffer);
//	return list = (read(fd, buffer, 546) != 0) ? store_terminos(buffer) : NULL;
}

int main(int ac, char **av)
{
	int index;
//	int fd;

	index = 0;
	if(!3)
		ft_putstr("Incorrect number of parameters");
	else
		file_read_store(open(*(av + ++index), O_RDONLY));
	return (0);
}
