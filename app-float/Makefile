# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/02/21 22:02:49 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#	42-fdf makefile
#

SRCS =          srcs/fdf.c 

SRCS +=			srcs/1_read_map/0_read_map.c \
				srcs/1_read_map/1_parse_map.c \
				srcs/1_read_map/2_init_structs.c \
				srcs/1_read_map/3_get_width.c \
				srcs/1_read_map/4_get_height.c \
				srcs/1_read_map/5_malloc_matrix.c \
				srcs/1_read_map/6_fill_matrix.c \
				srcs/1_read_map/7_print_matrix.c 
											
SRCS +=			srcs/2_draw_map/0_draw_map.c \
				srcs/2_draw_map/1_bresenham.c \
				srcs/2_draw_map/2_link_draws_to_bresenham.c \
				srcs/2_draw_map/3_draw_zoom.c \
				srcs/2_draw_map/4_draw_move.c \
				srcs/2_draw_map/5_draw_rotation.c \
				srcs/2_draw_map/6_draw_projection.c \
				srcs/2_draw_map/7_draw_color.c \
				srcs/2_draw_map/8_draw_alignment.c

SRCS +=			srcs/3_add_projection/add_plane_projection.c \
				srcs/3_add_projection/add_isometric_projection.c 

SRCS +=			srcs/4_functionalities/0_detect_input.c \
				srcs/4_functionalities/1_add_zoom.c \
				srcs/4_functionalities/2_add_move.c \
				srcs/4_functionalities/3_add_rotation.c \
				srcs/4_functionalities/4_change_projection.c \
				srcs/4_functionalities/5_change_color.c \
				srcs/4_functionalities/6_change_map.c \
				srcs/4_functionalities/7_hint_box.c  \
				srcs/4_functionalities/prepare_for_change_map.c 

OBJS =          $(SRCS:.c=.o)

CC =            gcc 

CFLAGS =		-Wall -Wextra -Werror

MATHFLAGS = 	-lm

MLXFLAGS =		-lXext -lX11 
		
LIBFT.A =       libs/libft/libft.a
MLX.A =			libs/minilibx/libmlx.a

AR =             ar -rcs     

#
#	Compilation and Linking
#

fdf: 			libft.a $(OBJS) headers/fdf.h
				$(CC) $(CFLAGS) -o fdf $(OBJS) $(LIBFT.A) $(MLX.A) $(MLXFLAGS) $(MATHFLAGS)

libft.a:
				$(MAKE) -C libs/libft

%.o: 			%.c headers/fdf.h
				$(CC) $(CFLAGS) -c $<	-o $@

all:			fdf
				$(MAKE) -C libs/libft
				$(MAKE) -C libs/minilibx

bonus:			all

clean:
				rm $(OBJS)

fclean:			clean
				rm fdf

re:				fclean all
				$(MAKE) -C libs/libft

.PHONY:			clean fclean re


#
#	Tester
#

VAL = 			valgrind --leak-check=full --show-leak-kinds=all

run:
				$(MAKE)					
				./fdf maps/42.fdf

leak:
				$(MAKE)							
				$(VAL) ./fdf maps/42.fdf 2> leak.txt && cat leak.txt | more

leak_all:
				$(MAKE)							
				$(VAL) ./fdf maps/10-2.fdf   && \
				$(VAL) ./fdf maps/10-70.fdf	&& \
				$(VAL) ./fdf maps/20-60.fdf	&& \
				$(VAL) ./fdf maps/42.fdf	&& \
				$(VAL) ./fdf maps/50-4.fdf &&	\
				$(VAL) ./fdf maps/100-6.fdf &&	\
				$(VAL) ./fdf maps/basictest.fdf && \
				$(VAL) ./fdf maps/elem-col.fdf && \
				$(VAL) ./fdf maps/elem-fract.fdf && \
				$(VAL) ./fdf maps/elem.fdf && \
				$(VAL) ./fdf maps/elem2.fdf && \
				$(VAL) ./fdf maps/julia.fdf && \
				$(VAL) ./fdf maps/mars.fdf && \
				$(VAL) ./fdf maps/pentenegpos.fdf && \
				$(VAL) ./fdf maps/plat.fdf  && \
				$(VAL) ./fdf maps/pnp_flat.fdf && \
				$(VAL) ./fdf maps/pylone.fdf && \
				$(VAL) ./fdf maps/pyra.fdf && \
				$(VAL) ./fdf maps/pyramide.fdf && \
				$(VAL) ./fdf maps/t1.fdf && \
				$(VAL) ./fdf maps/t2.fdf > leak.txt && more leak.txt