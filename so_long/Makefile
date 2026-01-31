NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src/
GNL_DIR     = src/get_next_line/
INC_DIR     = include/
MLX_DIR     = minilibx-linux/


MLX_LIB     = $(MLX_DIR)libmlx.a

MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES    = -I$(INC_DIR) -I$(MLX_DIR)


SRC_FILES   = map_init.c utils.c game_init.c
GNL_FILES   = get_next_line.c get_next_line_utils.c
MAIN_FILE   = main.c


SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
              $(addprefix $(GNL_DIR), $(GNL_FILES)) \
              $(MAIN_FILE)


OBJS        = $(SRCS:.c=.o)


all: $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)


$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re