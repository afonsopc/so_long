NAME = so_long
SRC = main.c
SRC += utils/ft_error.c utils/ft_mlx.c utils/ft_canvas.c utils/ft_player.c utils/ft_image.c utils/ft_sprite.c
SRC += libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_abs.c
OBJDIR = objs/
OBJ = $(notdir $(SRC:.c=.o))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = utils:libft

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit -o $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) 2D_map.ber

.PHONY: all clean fclean re