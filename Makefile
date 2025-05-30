NAME= cub3D

SRCS = parsing/color.c parsing/parsing.c parsing/texture.c parsing/map_creation.c parsing/map_checker.c parsing/player.c utils/destroyer.c utils/row.c utils/access.c utils/map.c parsing/point_checker.c utils/parsing.c utils/get_color.c

SRC_EXEC = exec/raycast.c exec/raycast_utils.c exec/render.c exec/init_game.c exec/mlx_utils.c exec/keybinds.c cub3d.c
SRC_BONUS = $(addsuffix _bonus.c, $(SRC_EXEC:.c=)) utils/player_bonus.c exec/minimap_bonus.c utils/draw.c exec/mouse_bonus.c

OBJS_PATH= objs/ objs/parsing objs/utils objs/exec
OBJ_PATH= objs/
OBJS= $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
M_OBJS = $(addprefix $(OBJ_PATH), $(SRC_EXEC:.c=.o))
B_OBJS = $(addprefix $(OBJ_PATH), $(SRC_BONUS:.c=.o))


CFLAGS= -Wall -Werror -Wextra -g -I/usr/include -Imlx_linux

MLX_DIR=mlx_linux
MLX=mlx_linux/libmlx.a
LIBFT=libft.a


GREEN= \e[0;32m
WHITE= \e[0;37m
AQUA= \e[0;36m
YELLOW= \e[0;33m
RESET= \e[0m

all: $(OBJS_PATH) $(MLX_DIR) $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS) $(M_OBJS)
	@cc $(CFLAGS) $(OBJS) $(M_OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -L/usr/lib -o $(NAME)
	@tput cuu1 && tput el
	@echo "$(GREEN)Compilation finished !!!!!!"

objs/%.o: %.c
	@tput cuu1 && tput el	
	@echo "Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

objs/%.o: mandatory/%.c
	@tput cuu1 && tput el
	@echo "Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

objs/%.o: bonus/%.c
	@tput cuu1 && tput el
	@echo "Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

$(OBJS_PATH):
	@mkdir -p $@

$(MLX):
	@echo "$(YELLOW)Compiling minilibx... $(RESET)"
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)===================================================================$(RESET)"
	@make --no-print-directory -C mlx_linux
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)===================================================================$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compiling libft... $(RESET)" 
	@make --no-print-directory -C libft
	@mv libft/libft.a ./
	@echo "$(RESET)"

$(MLX_DIR):
	@echo "$(YELLOW)Downloading minilibx$(RESET)"
	@mkdir -p mlx_linux
	@wget https://cdn.intra.42.fr/document/document/30137/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz -C mlx_linux --strip-components 1
	@rm -f minilibx-linux.tgz
	@echo "$(GREEN)Sucessfully downloaded minilibx$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -fr $(OBJS_PATH)
	@make -C libft --no-print-directory clean
	@echo "$(GREEN)Cleaned !$(RESET)"

fclean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -fr $(OBJS_PATH)
	@rm -fr $(NAME)
	@rm -fr $(LIBFT)
	@make -C libft --no-print-directory fclean
	@echo "$(GREEN)Cleaned !$(RESET)"

re: fclean all

prune:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -fr $(OBJS_PATH)
	@rm -fr $(LIBFT)
	@rm -fr $(NAME)
	@rm -fr $(MLX)
	@rm -fr $(MLX_DIR)
	@make -C libft --no-print-directory fclean
	@echo "$(GREEN)Cleaned !$(RESET)"

mlx: $(MLX_DIR) $(MLX)

bonus: $(OBJS_PATH) $(MLX_DIR) $(MLX) $(LIBFT) $(OBJS) $(B_OBJS)
	@cc $(CFLAGS) $(OBJS) $(B_OBJS) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -L/usr/lib -o $(NAME)
	@tput cuu1 && tput el
	@echo "$(GREEN)Bonus compilation finished !!!!!!"


.PHONY: all clean fclean re prune mlx bonus
