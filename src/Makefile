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
#  😈 FDF - Makefile 👿
#

# Name of the project
OUTPUT_NAME =   fdf

# .c files
SRCS =          fdf.c \
				vendor/base/reading_map/reading_map.c \
				vendor/base/reading_map/getting_height.c \
				vendor/base/reading_map/getting_width.c \
				vendor/base/reading_map/malloc_matrix.c \
				vendor/base/reading_map/fill_matrix.c \
				vendor/utils/error.c  \
				vendor/utils/print_matrix.c  \
				vendor/utils/bresenham.c



# .h file
HEADER =        fdf.h

# .o files
OBJS =          $(SRCS:.c=.o)

# Compiler
CC =            gcc -ggdb3

# Flags
CFLAGS =		-Wall   \
				-Wextra \
				-Werror
#				-I/usr/include -Imlx_linux -O3

# Libs Settings
LIBS.A =        $(LIBS_PATH)/libs.a
LIBS_PATH =     vendor/libs
LIBX_PATH =		vendor/libs/minilibx/

# Create Library
AR =             ar
ARFLAGS =        -rcs

# Remove files
RM =             rm



#
# 🔨Compilation and Linking 🔌
#

# When make is called
all:	$(OUTPUT_NAME)


# When make bonus is called
bonus:					all

# Main libftprintf.a constructor:   \
	1) \
	2) \
	3) \
	4) \
	5) \
	6) \
	7)

$(OUTPUT_NAME): $(LIBS.A) $(OBJS) $(HEADER)
								@$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(OBJS) $(LIBS.A)
								@$(RM) $(OBJS)


# Compile or recompile Libft.a library
$(LIBS.A):
								@$(MAKE) re -C $(LIBS_PATH)

# $(OBJS) directive is called and %.o automatically assume this paper of execute one directive for each object inside $(OBJS);  % get the name until dot(.); So, the same name can be used both as .c files or .o files; the command line then compiles each object; $< represents %.c, so all c files in SRCS, and  $@ = represents all $(OBJS);
%.o: 						%.c $(HEADER)
								@$(CC) $(CFLAGS) -c $<	-o $@

#
# 🔨Tests
#

VAL = valgrind --leak-check=full --show-leak-kinds=all

run:
								$(MAKE)
								$(MAKE) re
								clear
								@./fdf vendor/resources/test_maps/42.fdf

run_leak:
								$(MAKE)
								$(MAKE) re
								clear
								@$(VAL) ./fdf vendor/resources/test_maps/42.fdf 2> leak.txt && cat leak.txt | more

run_all_maps_leak:
								$(MAKE)
								$(MAKE) re
								clear
								@$(VAL) ./fdf vendor/resources/test_maps/10-2.fdf   && \
								$(VAL) ./fdf vendor/resources/test_maps/10-70.fdf	&& \
								$(VAL) ./fdf vendor/resources/test_maps/20-60.fdf	&& \
								$(VAL) ./fdf vendor/resources/test_maps/42.fdf	&& \
								$(VAL) ./fdf vendor/resources/test_maps/50-4.fdf &&	\
								$(VAL) ./fdf vendor/resources/test_maps/100-6.fdf &&	\
								$(VAL) ./fdf vendor/resources/test_maps/basictest.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/elem-col.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/elem-fract.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/elem.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/elem2.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/julia.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/mars.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/pentenegpos.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/plat.fdf  && \
								$(VAL) ./fdf vendor/resources/test_maps/pnp_flat.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/pylone.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/pyra.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/pyramide.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/t1.fdf && \
								$(VAL) ./fdf vendor/resources/test_maps/t2.fdf > leak.txt && more leak.txt


# Cleaning .o files
clean:
								@$(RM) $(OBJS)

clean_all:
								@$(MAKE) fclean -C vendor/libs 2> /dev/null

# Cleaning everything
fclean:
								@$(RM) $(OUTPUT_NAME)


# Re-making everything
re:							fclean all

# Indicates that:                                                   \
	1) The following targets don't create files with its own names;   \
	2) If some of them create a file with it's own name, they executes regardless it's prerequisite have updates or not; \
Then in few words, .PHONY make these targets avoit problems with file name.
.PHONY:					clean fclean re
