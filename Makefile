CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = ft_ls
SOURCE = main.c\
		ls.c\
		ls_files.c\
		calc_table.c\
		ls_dirs.c\
		get_info.c\
		get_info2.c\
		get_info3.c\
		read_flags.c\
		read_params.c\
		sorting.c\
		useful_things.c\
		free.c\
		recursion.c
OBJECT = $(SOURCE:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECT)
	make -C ./libft
	$(CC) $(FLAGS) -o $@ $(OBJECT) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	make -C libft
clean:
	make clean -C ./libft
	rm -f $(OBJECT)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
