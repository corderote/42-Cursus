NAME = libftprintf.a
COMPILER_COMMAND = cc
COMPILER_FLAGS = -c -Wall -Werror -Wextra

C_FILES = 						\
ft_printf/ft_printf.c			\
ft_printf/ft_printf_utils.c		\
ft_printf/ft_printf_cases_1.c	\
ft_printf/ft_printf_cases_2.c	\

OBJ_FILES = $(C_FILES:.c=.o)

${NAME}: $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)
	
# Rule that compiles every .c file into a .o file
%.o: %.c
	$(COMPILER_COMMAND) $(COMPILER_FLAGS) $< -o $@

all: ${NAME}
	
clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
