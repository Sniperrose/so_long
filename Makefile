SRCS_DIR = ./srcs/
SRCS =	ft_getmap.c\
		ft_mapchek.c\
		ft_validpath.c\
		ft_split2.c\
		solong.c\
		ft_getimages.c\
		ft_moves.c\
		ft_move_hor.c\
		ft_move_ver.c\

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = minilibx-linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -Wall -Werror -Wextra -g # -MMD
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS) 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME}

re: 	fclean all

.PHONY: all clean fclean re



# NAME = so_long

# SRCS = srcs/ft_test.c

# CC = clang

# LIBFT		= libft/libft.a
# CFLAGS		= -Wall -Wextra -Werror
# MLXFLAGS	= -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
# RM			= rm -f
# OBJS		= $(SRCS:%.c=%.o)

# ifeq ($(shell uname), Linux)
# MLXFLAGS	= -L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
# endif

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 			make -C libft
# 			make clean -C libft
# 			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

# %o:			%.c 
# 			$(CC) $(CFLAGS) -Imlx -c $< -o $@

# clean:
# 			$(RM) $(OBJS)

# fclean:	clean
# 			$(RM) $(NAME)
# 			$(RM) *.out
# 			make fclean -C libft/


# re:			fclean all

# .PHONY:		all clean fclean re