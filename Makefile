NAME = so_long
SRC = main.c

SRC += utils/player/player.c utils/player/entity.c utils/player/global.c
SRC += utils/canvas/canvas.c utils/canvas/global.c
SRC += utils/map/map.c utils/map/checks.c utils/map/process.c utils/map/generate.c
SRC += utils/error.c utils/mlx.c utils/image.c utils/sprite.c utils/entity.c
SRC += utils/object_list.c utils/loop.c utils/wall.c utils/food.c utils/exit_place.c  utils/exit.c
SRC += libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_abs.c libft/ft_gnl.c libft/ft_count_occurrences.c

OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = utils:libft
_MAP = 1.ber

ifeq ($(shell uname -s),Darwin)
	MLX_COMPILE = echo "\033[1;32mNot compiling mlx...\033[0m"
    MLX_FLAGS = -Lmlx -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
else
	MLX_COMPILE = echo "\033[1;33mCompiling mlx...\033[0m"; make -C minilibx-linux; cp minilibx-linux/libmlx.a mlx/
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
endif

all: $(NAME)

$(NAME): mlx $(OBJDIR) $(OBJS)
	@echo "\nCompiling $(NAME)...\033[0m"
	@cc $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

mlx:
	@$(MLX_COMPILE)

$(OBJDIR)%.o: %.c
	@printf "\033[1;33m.\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@printf "\033[1;33mCompiling\033[0m"
	@mkdir -p $(OBJDIR)

clean:
	@echo "\033[1;31mCleaning objects...\033[0m"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[1;31mCleaning binaries...\033[0m"
	@rm -f $(NAME) mlx/libmlx.a

re: fclean all

run: re
	@echo "\033[1;32mRunning $(NAME)...\033[0m"
	@./$(NAME) maps/$(_MAP)

norm:
	@mv includes/mlx.h includes/mlx.h.bak
	-@norminette
	@mv includes/mlx.h.bak includes/mlx.h

.PHONY: all clean fclean re mlx