NAME	=	liblist
HEADER	=	list.h
CFLAGS	+=	-c -Wall -Wextra -Werror
CFILES	=	ft_create_elem.c \
			ft_list_push_front.c \
			ft_list_push_back.c \
			ft_list_size.c	\
			ft_putlist.c
OFILES	=	$(CFILES:.c=.o)
LIBDIR	=	/nfs/2016/s/srodrigu/libft
CC		=	gcc

all: $(NAME)

$(NAME): $(OFILES)
	ar -rc $(NAME) $(OFILES) 

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) 

library_a: $(OFILES)
	ar -rc ./liblist.a $(OFILES)

# link_main:
# 	$(CC) main.c -o fillmeup -L./libft/ -llist

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean re library fclean
