NAME = so_long
NAME_B = so_long_bonus
CFLAGS = -Wall -Werror -Wextra -g -Wno-gnu-include-next
SRCS = src/so_long.c \
		src/check_map_1.c \
		src/check_map_2.c \
		src/check_map.c \
		src/error.c \
		src/exit_free.c \
		src/movement.c \
		src/graphic.c \
		src/helper_2.c \
		src/helper_1.c
SRCSB = src_bonus/so_long_bonus.c \
		src_bonus/check_map_1_bonus.c \
		src_bonus/check_map_2_bonus.c \
		src_bonus/check_map_bonus.c \
		src_bonus/error_bonus.c \
		src_bonus/exit_free_bonus.c \
		src_bonus/movement_1_bonus.c \
		src_bonus/movement_2_bonus.c \
		src_bonus/graphic_bonus.c \
		src_bonus/win_die_bonus.c \
		src_bonus/helper_2_bonus.c \
		src_bonus/helper_1_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
LIBFT = lib/libft
PRINTF = lib/printf
GET_NEXT = lib/get_next_line
MLX = lib/libmlx
INLIBFT = -L $(LIBFT) -lft
INPRINF = -L $(PRINTF) -lftprintf
INGET_NEXT = -L $(GET_NEXT) -lget_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -lglfw -pthread -lm
$(NAME):		$(OBJS)
				make -C $(LIBFT)
				make -C $(PRINTF)
				make -C $(GET_NEXT)
				cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				cc $(OBJS) $(INLIBFT) $(INPRINF) $(INGET_NEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME) $(CFLAGS)
$(NAME_B):		$(OBJSB)
				make -C $(LIBFT)
				make -C $(PRINTF)
				make -C $(GET_NEXT)
				cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
				cc $(OBJSB) $(INLIBFT) $(INPRINF) $(INGET_NEXT) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME_B) $(CFLAGS)

all:		$(NAME)

bonus:		$(NAME_B)

%.o:%.c
				cc ${CFLAGS} -c $< -o $@\

clean:
				rm -f $(OBJS) $(OBJSB)
				@cd $(LIBFT) && $(MAKE) clean
				@cd $(PRINTF) && $(MAKE) clean
				@cd $(GET_NEXT) && $(MAKE) clean
				@rm -rf $(MLX)/build

fclean:		clean
				rm -f $(NAME) $(NAME_B)
				@cd $(LIBFT) && $(MAKE) fclean
				@cd $(PRINTF) && $(MAKE) fclean
				@cd $(GET_NEXT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re