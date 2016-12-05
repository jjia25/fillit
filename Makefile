 ########################################
 #				Makefile			    #
 ########################################

		#		Basics		#

NAME		=	fillit
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -I headers/
OFLAGS		=	-c $(CFLAGS)


		#  libs & link cmd	#
LIB_DIR		=	./lib/
LIB_LINKS	=	-lft
LINK_LIBS	=	-L $(LIB_DIR) $(LIB_LINKS)


		#	  files/folders		#
MAIN		=	main.c
CFILES		=	read_create.c maps.c solve.c stack.c

###OFILES		=	$(addprefix $(OBJ_DIR),$(SRC:.c=.o))
OFILES		= $(CFILES:.c=.o)


all: $(NAME)


$(NAME): $(OFILES)
	$(MAKE) -C ./libft
	mv ./libft/libft.a ./lib/
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OFILES) $(LINK_LIBS)

clean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean

fclean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean
	/bin/rm -rf ./lib/libft.a
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean



#link main.c to libft.a
#gcc main.c -o fillmeup -L./libft/ -lft
#gcc main.c -o fillmeup -L./lib/ -lft -llist

#/*==== creating new libft.a file and replacing old one =======*/
#/* (same thing goes for changing list functions in liblist */
#cd libft
#make re 
#rm ../lib/libft.a
#cp libft.a ../lib/
