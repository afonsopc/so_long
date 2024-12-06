NAME = so_long
SRC = main.c
SRC += utils/player/player.c utils/player/entity.c utils/player/global.c
SRC += utils/map/map.c utils/map/global.c
SRC += utils/canvas/canvas.c utils/canvas/global.c
SRC += utils/error.c utils/mlx.c utils/image.c utils/sprite.c utils/entity.c utils/object_list.c
SRC += libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_abs.c
OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = utils:libft

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\nCompiling $(NAME)...\033[0m"
	@cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR)%.o: %.c
	@printf "."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@printf "\033[1;33mCompiling"
	@mkdir -p $(OBJDIR)

clean:
	@echo "\033[1;31mCleaning objects...\033[0m"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[1;31mCleaning binaries...\033[0m"
	@rm -f $(NAME)

re: fclean all

run: re
	@echo "\033[1;32mRunning $(NAME)...\033[0m"
	@./$(NAME) 2D_map.ber

norm:
	@mv includes/mlx.h includes/mlx.h.bak
	@norminette
	@mv includes/mlx.h.bak includes/mlx.h

.PHONY: all clean fclean re