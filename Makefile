
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
		compare.c\
		sort.c\
		useful_things.c\
		free.c\
		recursion.c

OBJECT = $(SOURCE:.c=.o)
LIBFT = libft/libft.a
LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJECT)
	$(CC) $(FLAGS) -o $@ $(OBJECT) $(LIBFT) $(LIBFTPRINTF)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	@make -C libft

$(LIBFTPRINTF):
	@make -C ft_printf

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@echo "\033[34mremoving object files of $(NAME)\033[39m"
	@rm -f $(OBJECT)

fclean:
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "\033[34mremoving object files of $(NAME)\033[39m"
	@rm -f $(OBJECT)
	@echo "\033[34mremoving $(NAME)\033[39m"
	@rm -f $(NAME)

re: fclean all
