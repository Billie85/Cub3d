NAME		= cub3d
#PRINTF		= ./ft_printf/libftprintf.a

SRCS		=	srcs/main.c \
				srcs/set_map/array_2d.c srcs/set_map/check_around_map.c srcs/set_map/check_map_error.c srcs/set_map/make_square.c srcs/set_map/check_map_inside.c srcs/set_map/set_map.c\
				srcs/global/cf.c srcs/global/dis.c srcs/global/img.c srcs/global/key.c srcs/global/map.c srcs/global/mlx.c srcs/global/now.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT		= libft/libft.a

LIBMLX		= libmlx.dylib

CC			= gcc 

CFLAGS		:= -Wshadow -Imlx

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(LIBMLX) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBMLX):
	make -C minilibx_mms_20200219
	cp minilibx_mms_20200219/libmlx.dylib ./

$(LIBFT):
	make bonus -C libft
	
clean:
	make clean -C libft
	make clean -C minilibx_mms_20200219
	$(RM) $(OBJS)

fclean: clean
	rm -f $(LIBMLX)
	$(RM) $(NAME) $(LIBFT) $(PRINTF)

re: fclean all

PHONY: fclean clean all re