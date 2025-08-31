# Reset
OFF='\033[0m'

# Regular Colors
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
LGREEN='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

SRC_DIR	= src/
BN_DIR = bonus/
SRCF = main.c data.c camera.c default.c helpers.c memory_arena.c \
	memory_arena_helpers.c movement.c \
	game_load.c game.c rayCast.c textures.c image.c \
	minimap.c
SRBF = main.c data_bonus.c camera.c default.c helpers_bonus.c memory_arena.c \
	memory_arena_helpers.c movement_bonus.c \
	load_bonus.c game_bonus.c cast_bonus.c textures.c image_bonus.c \
	minimap_bonus.c \
	ray_bonus.c floor_bonus.c 
SRCB = $(addprefix $(BN_DIR), $(SRBF))
OBJB = $(SRCB:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRCF))
OBJS = $(SRCS:.c=.o)
HEADERS = ./inc/cube.h
INC = ./inc
NAME = cub3d
BNAME = cub3d_bonus
CC = @cc
CFLAGS = -Wall -Wextra -pthread -Iinc -Ilibft -I./MLX42/include/MLX42/ -g3 -fsanitize=address -fsanitize=undefined
# -g3 -fsanitize=address -fsanitize=undefined
EFLAGS = -Llibft -lft -L./MLX42/build -ldl -lglfw -pthread -lm
MAKE = @make -s
all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo -e $(LGREEN)Compiling OBJ files$(OFF)

$(NAME): $(OBJS) libft/libft.a MLX42/build/libmlx42.a
		$(CC) $(CFLAGS) -I $(INC) $^ $(EFLAGS) -o $(NAME)
		@echo -e $(GREEN)Compiled $(NAME)$(OFF)

MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cmake -B MLX42/build -S MLX42
	$(MAKE) -C MLX42/build
	@echo "Compiled MLX"

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJB)
	$(MAKE) -C libft clean

fclean:
	@rm -f $(OBJS)
	@rm -f $(OBJB)
	@rm -f $(NAME)
	$(MAKE) -C libft fclean

.BONUS: $(OBJB) libft/libft.a MLX42/build/libmlx42.a
		$(CC) $(CFLAGS) -I $(INC) $^ $(EFLAGS) -o $(BNAME)
		@echo -e $(GREEN)Compiled $(BNAME)$(OFF)

bonus: .BONUS

re: fclean all

libft/libft.a:
	$(MAKE) -C libft

.PHONY: clean flcean re all debug bonus