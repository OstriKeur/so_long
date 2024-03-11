NAME		=	so_long


CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	libft

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_FLAGS	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux

MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

C_FILE		=	main.c \
				parsing_map.c \
				parsing_utils.c \
				utils.c \
				free.c \
				games.c \
				ft_close.c \


OBJS		=	$(C_FILE:.c=.o)


.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m\n"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

ball:	$(NAME) $(BNAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@make -sC $(MLX_PATH)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm 
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

bre: fclean ball


$(BNAME): lib mlx $(BOBJS)
	@$(CC) $(LIBFT_LIB) $(MLX_EX) -o $(BNAME) -lm 
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

.PHONY: all clean fclean re
