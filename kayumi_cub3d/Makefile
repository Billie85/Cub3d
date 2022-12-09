NAME		= cub3d
#PRINTF		= ./ft_printf/libftprintf.a

SRCS		=	main.c map.c map_helper.c check_map.c\
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT		= ./libft/libft.a

LIBMLX		= libmlx.a

CC			= gcc

CFLAGS		:= 

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C ./libft
#make clean -C ./mlx_linux
#make clean -C ./ft_printf
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF)

re: fclean all

PHONY: fclean clean all re