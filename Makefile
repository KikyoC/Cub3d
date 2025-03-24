NAME= cub3D

SRCS=
OBJS= $(SRCS:.c=.o)
CFLAGS= -Wall -Werror -Wextra -g

MLX_DIR=minilibx
MLX=$(MLX_DIR)/libmlx.a

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

all: $(NAME)

$(NAME): $(MLX) $(OBJS) 
	@cc $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

objs/%.o: %.c
	@cc $(CFLAGS) $^ -c -o $@

$(MLX): $(MLX_DIR)
	@echo "$(YELLOW)Compiling minilibx... $(WHITE)"
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@make --no-print-directory -C mlx_linux
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="
	@echo "$(GREEN)==================================================================="

$(MLX_DIR):
	@echo "$(YELLOW)Downloading minilibx"
	@mkdir -p mlx_linux
	@wget https://cdn.intra.42.fr/document/document/30137/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz -C mlx_linux --strip-components 1
	@rm -f minilibx-linux.tgz
	@echo "$(GREEN)Sucessfully downloaded minilibx"

.PHONY: all clean fclean re prune
