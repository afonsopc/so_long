NAME = so_long
SRC = main.c

BONUS=1

SRC += utils/player/player.c utils/player/entity.c utils/player/moviment_count.c 
SRC += utils/player/global.c utils/player/intercept.c utils/player/wall_collision.c
SRC += utils/player/sprites.c utils/player/get_sprite.c
SRC += utils/canvas/canvas.c utils/canvas/global.c
SRC += utils/map/map.c utils/map/checks.c utils/map/process.c
SRC += utils/map/generate.c utils/map/has_exit.c utils/map/still_has_food.c
SRC += utils/error.c utils/mlx.c utils/image.c utils/sprite.c utils/entity.c
SRC += utils/object_list.c utils/loop.c utils/wall.c utils/food.c utils/exit_place.c utils/exit.c
SRC += libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_abs.c libft/ft_gnl.c libft/ft_bzero.c
SRC += libft/ft_count_occurrences.c libft/ft_putnbr_fd.c libft/ft_itoa.c libft/ft_calloc.c
SRC += libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c

OBJDIR = objs/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
CC = emcc
CFLAGS = -Wall -Wextra -Werror -I$(EMSCRIPTEN)/system/include/SDL2 -I$(EMSCRIPTEN)/system/include -I/opt/homebrew/Cellar/sdl2/2.30.10/include/SDL2 -I/opt/homebrew/Cellar/sdl2/2.30.10/include -I/opt/homebrew/Cellar/sdl2_image/2.8.4/include
LDFLAGS = --shell-file minimal.html -s NO_EXIT_RUNTIME=1 -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 -s SAFE_HEAP=1 -s ASSERTIONS=1 -s ENVIRONMENT="web" -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file maps --preload-file assets
VPATH = utils:libft
MAPS = 4.ber 1.ber 2.ber 3.ber

ifeq ($(BONUS),1)
	SRC += bonus/time.c
else
	SRC += utils/time.c
endif

all: $(NAME).html

$(NAME).html: $(OBJDIR) $(OBJS)
	@echo "\nCompiling $(NAME).html...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME).html

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
	@rm -rf $(NAME).html $(NAME).js $(NAME).wasm $(NAME).data

re: fclean all

%.ber:
	-@./$(NAME) maps/$@

run: re $(MAPS)
	@echo "\033[1;32mRunning $(NAME)...\033[0m"
	make fclean

norm:
	@mv includes/mlx.h includes/mlx.h.bak
	-@norminette
	@mv includes/mlx.h.bak includes/mlx.h

.PHONY: all clean fclean re