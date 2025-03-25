NAME= cub3D

SRCS= cub3d.c close_game.c keybind.c init_game.c ceiling.c
OBJS_PATH= objs/
OBJS= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
CFLAGS= -Wall -Werror -Wextra -g

MLX_DIR=mlx_linux
MLX=mlx_linux/libmlx.a
LIBFT=libft.a


GREEN= \e[0;32m
WHITE= \e[0;37m
AQUA= \e[0;36m
YELLOW= \e[0;33m
RESET= \e[0m

all: $(OBJS_PATH) $(MLX_DIR) $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@cc $(CFLAGS) $(OBJS) $(MLX) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME)

objs/%.o: %.c
	@tput cuu1 && tput el
	@echo "Compilation de $<..."
	@cc $(CFLAGS) -c $< -o $@

$(OBJS_PATH):
	mkdir -p $@

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
	@echo "$(GREEN)Libft compiled ! $(RESET)"
	@echo ""

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
	@echo "$(GREEN)Cleaned !$(RESET)"

fclean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -fr $(OBJS_PATH)
	@rm -fr $(NAME)
	@echo "$(GREEN)Cleaned !$(RESET)"

re: fclean all

prune:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -fr $(OBJS_PATH)
	@rm -fr $(LIBFT)
	@rm -fr $(NAME)
	@rm -fr $(MLX)
	@rm -fr $(MLX_DIR)
	@echo "$(GREEN)Cleaned !$(RESET)"

.PHONY: all clean fclean re prune
