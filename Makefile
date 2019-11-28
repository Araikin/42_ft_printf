NAME		:= 	libftprintf.a
FLAGS		:=	-Wall -Wextra -Werror
F_N			:=	ft_printf parse_format verify_params set_params handle_specifiers \
				helper_func
SRC			:=	$(addprefix sources/, $(addsuffix .c, $(F_N)))
OBJ			:=	$(addprefix objects/, $(addsuffix .o, $(F_N)))
INCL		:=	includes

LIB			:=	libft
LIB_LINK	:=	-L $(LIB) -l ft

.PHONY:	all clean fclean re

all	: $(NAME)

objects/%.o : sources/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -I $(INCL) -c $< -o $@

$(NAME)	: $(OBJ)
	@make -C $(LIB)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)
	
compile:
	@gcc -o xx main.c -L . -lftprintf -I $(INCL)

clean:
	@/bin/rm -rf objects
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
