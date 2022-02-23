# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/02/01 05:18:18 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#  😈 Printf with Bonus - Makefile 👿
#

# Name of the project
OUTPUT_NAME =   libs.a

# .c files
SRCS =	42-libft/ft_isalnum.c \
	42-libft/ft_atoi.c \
	42-libft/ft_isascii.c \
	42-libft/ft_putstr_fd.c \
	42-libft/ft_isdigit.c \
	42-libft/ft_isalpha.c \
	42-libft/ft_bzero.c \
	42-libft/ft_isprint.c \
	42-libft/ft_itoa.c \
	42-libft/ft_memchr.c \
	42-libft/ft_memcmp.c \
	42-libft/ft_memcpy.c \
	42-libft/ft_memmove.c \
	42-libft/ft_memset.c \
	42-libft/ft_putchar_fd.c \
	42-libft/ft_putendl_fd.c \
	42-libft/ft_putnbr_fd.c \
	42-libft/ft_split.c \
	42-libft/ft_strchr.c \
	42-libft/ft_strdup.c \
	42-libft/ft_striteri.c \
	42-libft/ft_strjoin.c \
	42-libft/ft_strlcat.c \
	42-libft/ft_strlcpy.c \
	42-libft/ft_strlen.c \
	42-libft/ft_strmapi.c \
	42-libft/ft_strncmp.c \
	42-libft/ft_strnstr.c \
	42-libft/ft_strrchr.c \
	42-libft/ft_strtrim.c \
	42-libft/ft_substr.c \
	42-libft/ft_tolower.c \
	42-libft/ft_toupper.c\
	42-libft/ft_calloc.c \
	42-libft/ft_lstadd_front.c \
	42-libft/ft_lstadd_back.c \
	42-libft/ft_lstdelone.c \
	42-libft/ft_lstclear.c \
	42-libft/ft_lstsize.c \
	42-libft/ft_lstlast.c \
	42-libft/ft_lstiter.c \
	42-libft/ft_lstmap.c \
	42-libft/ft_lstnew.c \
	42-libft/ft_chr_to_str.c \
	42-libft/ft_str_merge.c \
	42-libft/ft_str_replace.c \
	42-libft/ft_free_ptr.c\
	42-libft/ft_uitoa_base.c\
	42-libft/ft_putstr_fd.c\
	42-get-next-line/get_next_line.c \
	42-libft/ft_strjoin_free.c\
	42-printf/ft_printf.c \
	42-printf/vendor/base/initialize_struct.c         \
	42-printf/vendor/base/destroy_struct.c         \
	42-printf/vendor/base/has_visible_signal.c         \
	42-printf/vendor/base/remove_minus.c         \
	42-printf/vendor/base/prepare_to_translation.c         \
	42-printf/vendor/base/understanding_format.c         \
	42-printf/vendor/base/what_flags.c         \
	42-printf/vendor/base/what_format_type.c         \
	42-printf/vendor/base/what_precision.c         \
	42-printf/vendor/base/what_width.c         \
	42-printf/vendor/translators/translate_percent.c \
	42-printf/vendor/translators/translate_to_char.c  \
	42-printf/vendor/translators/translate_to_decimal.c  \
	42-printf/vendor/translators/translate_to_integer.c  \
	42-printf/vendor/translators/translate_to_string.c  \
	42-printf/vendor/translators/translate_to_unsigned_int.c  \
	42-printf/vendor/translators/translate_to_pointer.c  \
	42-printf/vendor/translators/translate_to_hexadecimal.c \
	42-libft/ft_free_matrix.c \
	42-libft/ft_free_gnl.c

# .h file
HEADER =        42-libft/libft.h

# .o files
OBJS =          $(SRCS:.c=.o)

# Compiler
CC =            gcc

# Flags
CFLAGS =		-Wall   \
				-Wextra \
				-Werror 
#				-I/usr/include \
				-Imlx_linux  \
				-O3 

# Libs Settings
#LIBFT.A =        $(LIBFT_PATH)/libft.a
#LIBFT_PATH =     vendor/libft_plusplus

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

$(OUTPUT_NAME): $(OBJS) $(HEADER)
#								@cp $(LIBFT.A) $(OUTPUT_NAME)
								@$(AR) $(ARFLAGS) $(OUTPUT_NAME) $(OBJS) $(HEADER)
#								@$(CC) $(CFLAGS) -o $(OUTPUT_NAME) $(OBJS)

# Compile or recompile Libft.a library
#$(LIBFT.A):
#								$(MAKE) -C $(LIBFT_PATH)

# $(OBJS) directive is called and %.o automatically assume this paper of execute one directive for each object inside $(OBJS);  % get the name until dot(.); So, the same name can be used both as .c files or .o files; the command line then compiles each object; $< represents %.c, so all c files in SRCS, and  $@ = represents all $(OBJS);
%.o: 							%.c $(HEADER)
								$(CC) $(CFLAGS) -c $<	-o $@

# Cleaning .o files
clean:
								$(RM) $(OBJS) 

# Cleaning everything
fclean:					clean
								$(RM) $(OUTPUT_NAME) 

# Re-making everything
re:							fclean all

# Indicates that:                                                   \
	1) The following targets don't create files with its own names;   \
	2) If some of them create a file with it's own name, they executes regardless it's prerequisite have updates or not; \
Then in few words, .PHONY make these targets avoit problems with file name.
.PHONY:					clean fclean re
