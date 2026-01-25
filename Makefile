NAME = so_long

SOURCE = so_long.c \
			get_next_line.c \
			get_next_line_utils.c \
			map_parser.c \
			map_validator.c \
			map_helpers.c \
			general_helpers.c \
			game_init.c \
			game_input.c

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror -g

MINIFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(SOURCE:.c=.o)

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf

LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF = ${FT_PRINTF_DIR}/libftprintf.a

CC = CC
RM = rm -f

all: ${NAME}

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(FT_PRINTF):
		@make -C $(FT_PRINTF_DIR)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${FT_PRINTF} ${OBJECTS}
	${CC} ${CFLAGS} ${MINIFLAGS} ${OBJECTS} ${LIBFT} ${FT_PRINTF} -o ${NAME}

clean:
	make -C ${LIBFT_DIR} clean
	make -C ${FT_PRINTF_DIR} clean
	${RM} ${OBJECTS}

fclean: clean
	make -C ${LIBFT_DIR} fclean
	make -C ${FT_PRINTF_DIR} fclean
	${RM} ${NAME}

re: fclean all

make: make all

.PHONY: clean fclean re all