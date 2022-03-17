# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/03/17 16:57:40 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#	42-fdf makefile
#

NAME =			fdf

NAME_B =		fdf_b	

SRCS =          srcs/1_read_map/0_read_map.c \
				srcs/1_read_map/1_parse_map.c \
				srcs/1_read_map/2_init_structs.c \
				srcs/1_read_map/3_get_width.c \
				srcs/1_read_map/4_get_height.c \
				srcs/1_read_map/5_malloc_matrix.c \
				srcs/1_read_map/6_fill_matrix.c \
				srcs/2_draw_map/1_decide_pixel_color.c \
				srcs/2_draw_map/2_draw_pixel_in_image.c \
				srcs/2_draw_map/3_draw_line.c \
				srcs/2_draw_map/4_draw_wireframe.c \
				srcs/2_draw_map/5_align_center.c \
				srcs/2_draw_map/6_zoom.c \
				srcs/2_draw_map/7_render.c 	\
				srcs/3_projection/isometric.c  \
				srcs/4_hook/1_on_release_key.c \
				srcs/4_hook/2_on_destroy.c  \
				srcs/6_utils/free.c \
				srcs/fdf.c 

SRCS_B =        srcs_b/1_read_map/0_read_map.c \
				srcs_b/1_read_map/1_parse_map.c \
				srcs_b/1_read_map/3_get_width.c \
				srcs_b/1_read_map/4_get_height.c \
				srcs_b/1_read_map/5_malloc_matrix.c \
				srcs_b/1_read_map/6_fill_matrix.c \
				srcs_b/1_read_map/2_init_structs.c \
				srcs_b/2_draw_map/1_decide_pixel_color.c \
				srcs_b/2_draw_map/2_draw_pixel_in_image.c \
				srcs_b/2_draw_map/3_draw_line.c \
				srcs_b/2_draw_map/4_draw_wireframe.c \
				srcs_b/2_draw_map/5_render.c 	\
				srcs_b/2_draw_map/6_draw_rectangle.c \
				srcs_b/3_projection/isometric.c  \
				srcs_b/4_hook/1_on_release_key.c \
				srcs_b/4_hook/2_on_mouse_down.c \
				srcs_b/4_hook/3_on_destroy.c \
				srcs_b/5_bonus/0_enable_bonus.c \
				srcs_b/5_bonus/1_zoom.c \
				srcs_b/5_bonus/2_translate.c \
				srcs_b/5_bonus/3_rotate.c \
				srcs_b/5_bonus/4_change_color.c \
				srcs_b/5_bonus/5_change_map.c \
				srcs_b/5_bonus/6_hint_box.c  \
				srcs_b/5_bonus/7_align_center.c \
				srcs_b/6_utils/free.c \
				srcs_b/fdf.c

OBJS =          $(SRCS:.c=.o)

OBJS_B =		$(SRCS_B:.c=.o)

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

# mandatory #
all:			$(NAME)
				
$(NAME): 		$(OBJS) headers/fdf.h
				$(MAKE) -C libs/libft
				$(MAKE) -C libs/minilibx
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT.A) $(MLX.A) $(MLXFLAGS) $(MATHFLAGS) -I./headers/
				@echo "\033[1;32m\nMANDATORY COMPILED SUCCESFULY!\033[0m\n\n"

%.o: 			%.c headers/fdf.h
				$(CC) $(CFLAGS) -c $<	-o $@

# bonus #
bonus:			$(NAME_B)

$(NAME_B):		$(OBJS_B) headers/fdf_bonus.h
				$(MAKE) -C libs/libft
				$(MAKE) -C libs/minilibx
				$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) $(LIBFT.A) $(MLX.A) $(MLXFLAGS) $(MATHFLAGS) -I./headers
				@echo "\033[1;32m\nBONUS COMPILED SUCCESFULY!\033[0m\n\n"

%.o: 			%.c headers/fdf.h
				$(CC) $(CFLAGS) -c $<	-o $@

# utils #
clean:
				rm $(OBJS_B) $(OBJS)  leak.txt 

fclean:			
				@$(MAKE) clean 2>/dev/null || true
				@rm fdf clean 2>/dev/null || true
				@make fclean -C libs/libft 2>/dev/null || true
				@rm vgcore* *.txt 2>/dev/null || true
				@rm fdf_b clean 2>/dev/null || true
				@echo "\033[1;32m\nFCLEAN EXECUTED SUCCESFULY!\033[0m\n\n"
				
re:				fclean all

.PHONY:			clean fclean re


#
#	Tester 
#

norm:
				norminette headers/
				norminette libs/libft/
				norminette srcs/*
				norminette srcs_b/*

VAL = 			valgrind --leak-check=full --show-leak-kinds=all

run:
				$(MAKE)					
				./fdf maps/42.fdf
run_b:
				$(MAKE) bonus					
				./fdf_b maps/42.fdf

leak:
				$(MAKE)							
				$(VAL) ./fdf maps/42.fdf 2> leak.txt && cat leak.txt | more

leak_b:
				$(MAKE) bonus							
				$(VAL) ./fdf_b maps/42.fdf 2> leak.txt && cat leak.txt | more

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
leak_b_all:
				$(MAKE) bonus						
				$(VAL) ./fdf_b maps/10-2.fdf   && \
				$(VAL) ./fdf_b maps/10-70.fdf	&& \
				$(VAL) ./fdf_b maps/20-60.fdf	&& \
				$(VAL) ./fdf_b maps/42.fdf	&& \
				$(VAL) ./fdf_b maps/50-4.fdf &&	\
				$(VAL) ./fdf_b maps/100-6.fdf &&	\
				$(VAL) ./fdf_b maps/basictest.fdf && \
				$(VAL) ./fdf_b maps/elem-col.fdf && \
				$(VAL) ./fdf_b maps/elem-fract.fdf && \
				$(VAL) ./fdf_b maps/elem.fdf && \
				$(VAL) ./fdf_b maps/elem2.fdf && \
				$(VAL) ./fdf_b maps/julia.fdf && \
				$(VAL) ./fdf_b maps/mars.fdf && \
				$(VAL) ./fdf_b maps/pentenegpos.fdf && \
				$(VAL) ./fdf_b maps/plat.fdf  && \
				$(VAL) ./fdf_b maps/pnp_flat.fdf && \
				$(VAL) ./fdf_b maps/pylone.fdf && \
				$(VAL) ./fdf_b maps/pyra.fdf && \
				$(VAL) ./fdf_b maps/pyramide.fdf && \
				$(VAL) ./fdf_b maps/t1.fdf && \
				$(VAL) ./fdf_b maps/t2.fdf > leak.txt && more leak.txt