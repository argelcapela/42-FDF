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
				vendor/base/reading_map/malloc_read_map_and_fill_matrix.c \
				vendor/utils/print_matrix.c 


# .h file
HEADER =        fdf.h

# .o files
OBJS =          $(SRCS:.c=.o)

# Compiler
CC =            gcc

# Flags
CFLAGS =
#		-Wall   \
				-Wextra \
				-Werror \
				-I/usr/include \
				-Imlx_linux  \
				-O3 

# Libs Settings
LIBS.A =        $(LIBS_PATH)/libs.a
LIBS_PATH =     vendor/libs

# Create Library
AR =             ar
ARFLAGS =        -rcs

# Remove files
RM =             rm



#
# 🔨Compilation and Linking 🔌
#

# When make is called
all:					$(OUTPUT_NAME)
#						$(MAKE) clean

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
#								@cp $(LIBS.A) $(OUTPUT_NAME)
#								@$(AR) $(ARFLAGS) $(OUTPUT_NAME) $(OBJS) $(HEADER)
								@$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(OBJS) $(LIBS.A)

# Compile or recompile Libft.a library
$(LIBS.A):
								@$(MAKE) -C $(LIBS_PATH)

# $(OBJS) directive is called and %.o automatically assume this paper of execute one directive for each object inside $(OBJS);  % get the name until dot(.); So, the same name can be used both as .c files or .o files; the command line then compiles each object; $< represents %.c, so all c files in SRCS, and  $@ = represents all $(OBJS);
%.o: 						%.c $(HEADER)
								@$(CC) $(CFLAGS) -c $<	-o $@

#
# 🔨Tests
#

run:
								$(MAKE) re
								clear
								@./fdf vendor/resources/test_maps/42.fdf

run_leak:
								$(MAKE) re
								clear
								@valgrind --leak-check=full --show-leak-kinds=all ./fdf vendor/resources/test_maps/42.fdf



# Cleaning .o files
clean:
								@$(RM) $(OBJS)
#								$(MAKE) clean -C vendor/libs
								

# Cleaning everything
fclean:							clean						
								@$(RM) vendor/libs/libs.a 
								@$(RM) $(OUTPUT_NAME) 

# Re-making everything
re:							fclean all

# Indicates that:                                                   \
	1) The following targets don't create files with its own names;   \
	2) If some of them create a file with it's own name, they executes regardless it's prerequisite have updates or not; \
Then in few words, .PHONY make these targets avoit problems with file name.
.PHONY:					clean fclean re
