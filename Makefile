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

SRC_DIR = src/
BN_DIR  = bonus/
OBJ_DIR = obj/

SRCF = main.c data.c camera.c helpers.c memory_arena.c \
	memory_arena_helpers.c movement.c \
	game_load.c game_load_helpers.c game.c rayCast.c image.c \
	parsing.c parsing_helpers.c minimap.c parsing_utility.c

SRBF = main_bonus.c data_bonus.c camera_bonus.c helpers_bonus.c memory_arena.c \
	memory_arena_helpers.c movement_bonus.c \
	load_bonus.c game_bonus.c cast_bonus.c image_bonus.c \
	minimap_bonus.c \
	ray_bonus.c floor_bonus.c key_hook.c parsing_helpers_bonus.c \
	parsing_bonus.c parsing_utility_bonus.c game_load_bonus.c game_load_helpers_bonus.c \

SRCS = $(addprefix $(SRC_DIR), $(SRCF))
SRCB = $(addprefix $(BN_DIR), $(SRBF))

OBJS = $(addprefix $(OBJ_DIR), $(SRCF:.c=.o))
OBJB = $(addprefix $(OBJ_DIR), $(SRBF:.c=.o))

HEADERS = ./inc/cube.h
INC = ./inc
NAME = cub3d
BNAME = cub3d_bonus
CC = @cc
CFLAGS = -Wall -Wextra -Werror -pthread -Iinc -Ilibft -I./MLX42/include/MLX42/
EFLAGS = -Llibft -lft -L./MLX42/build -ldl -lglfw -pthread -lm
MAKE = @make -s
MLX42 = MLX42/build/libmlx42.a

all: $(NAME)

# Ensure obj/ exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule for normal objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) | $(OBJ_DIR) $(MLX42)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo -e $(LGREEN)Compiling $< -> $@$(OFF)

# Rule for bonus objects
$(OBJ_DIR)%.o: $(BN_DIR)%.c $(HEADERS) | $(OBJ_DIR) $(MLX42)
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@echo -e $(LGREEN)Compiling $< -> $@$(OFF)

$(NAME): $(OBJS) libft/libft.a $(MLX42)
	$(CC) $(CFLAGS) -I $(INC) $^ $(EFLAGS) -o $(NAME)
	@echo -e $(GREEN)Compiled $(NAME)$(OFF)

$(MLX42):
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cmake -B MLX42/build -S MLX42
	$(MAKE) -C MLX42/build
	@echo "Compiled MLX"

libft/libft.a:
	@$(MAKE) -s -C libft

clean:
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean
	@echo -e $(RED)Cleaned OBJ files $(OFF)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNAME)
	$(MAKE) -C libft fclean
	@echo -e $(RED)Cleaned everything $(OFF)

$(BNAME): $(OBJB) libft/libft.a $(MLX42)
	$(CC) $(CFLAGS) -I $(INC) $^ $(EFLAGS) -o $(BNAME)
	@echo -e $(GREEN)Compiled $(BNAME)$(OFF)

bonus: $(BNAME)

re: fclean all

.PHONY: clean fclean re all debug bonus
