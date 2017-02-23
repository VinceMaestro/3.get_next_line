NAME = gnl

CFLAGS = -Wall -Werror -Wextra

SRC_GNL = main_get_next_line.c \
			get_next_line.c

SRC_LIB = ft_putnbr.c \
			ft_bzero.c \
			ft_memalloc.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_putstr.c \
			ft_putstr_fd.c

DIR_LIB = ./libft

SRC = $(foreach element,$(SRC_LIB), $(DIR_LIB)/$(element)) \
		$(SRC_GNL)

OBJ = $(SRC_GNL:.c=.o)\
		$(SRC_LIB:.c=.o)

INCL = ./libft/libft.h \
		./get_next_line.h

all: $(NAME)

$(NAME) : $(SRC)
			@gcc $(CFLAGS) -c $(SRC) -g -I $(INCL)
			@gcc $(CFLAGS) $(OBJ) -o /tmp/forgnl/$(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f /tmp/forgnl/$(NAME)

re: fclean all
