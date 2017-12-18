NAME = fractol

SRCS = main.c utility.c draw_fractal.c hook.c hook2.c init.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = -I./

FLAG_MLX = -L/usr/local/lib -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

MLX = ./minilibx_macos/libmlx.a

all : $(NAME)

$(NAME) : $(OBJ)
	@make re -C ./libft/
	@make re -C ./minilibx_macos/
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m libft"
	@gcc $(FLAGS) -o $(NAME) $(SRCS) $(HEADER) $(FLAG_MLX) $(LIBFT) $(MLX)
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m $(NAME)"

clean :
	@rm -f $(OBJ)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m OBJS"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m $(NAME)"

re : fclean all

.phony: all clean
