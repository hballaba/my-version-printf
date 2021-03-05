NAME = libftprintf.a

OBJECT = ./object/check_format.o ./object/ft_c_s.o ./object/ft_d_u.o ./object/ft_printf.o\
	./object/printf_utils.o ./object/printf_utils_2.o ./object/proc.o ./object/ft_p.o\
	./object/ft_x_xx.o

HEADER = ./includes/
DIR_SRC = ./srcs/
DIR_OBJ = ./object/
DIR_LIBFT = ./srcs/libft/
OBJ_LIBFT = ./srcs/libft/*.o

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)
	@make -C $(DIR_LIBFT) --no-print-directory

$(NAME): $(OBJECT) 
	@ar rc $(NAME) $? $(OBJ_LIBFT) 
	@ranlib $(NAME)
	@echo libftprintf is ready

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	@gcc -Wextra -Werror -Wall -I $(HEADER) -c $< -o $@ 
	@echo Компиляция $@ из $<

main: re
	gcc main.c -g -L. libftprintf.a -I ./includes/
		
clean:
	@rm -f $(OBJECT)
	@make clean -C $(DIR_LIBFT) --no-print-directory
	@rm -rf object
	@echo objects deleted

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DIR_LIBFT) --no-print-directory
	@rm -f ./a.out
	@echo libftprintf deleted

re: fclean all

.PHONY: all clean fclean re main
