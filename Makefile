NAME = so_long
SRC = main.c
SRC += utils/error.c
SRC += libft/ft_strlen.c libft/ft_putstr_fd.c
OBJDIR = objs/
OBJ = $(notdir $(SRC:.c=.o))
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = cc
CFLAGS = -Wall -Wextra -Werror
VPATH = utils:libft

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re