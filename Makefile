NAME		:= 	ft_printf
FLAGS		:=	-Wall -Wextra -Werror
F_N			:=	main ft_printf proc_fmt
SRC			:=	$(addsuffix .c, $(F_N))	
OBJ			:=	$(addprefix objects/, $(addsuffix .o, $(F_N)))
INCL		:=	libprintf.h

LIB			:=	libft
LIB_LINK	:=	-L $(LIB) -l ft

.PHONY:	all clean fclean re

all	: $(NAME)

objects/%.o : %.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@

$(NAME)	: $(OBJ)
	@make -C $(LIB)
	@gcc $(LIB_LINK) $(OBJ) -o $(NAME)
	
clean:
	@/bin/rm -rf objects
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
