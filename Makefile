NAME = gnl

CFLAGS = -Wall -Werror -Wextra

SRC_GNL = main_get_next_line.c \
			get_next_line.c

SRC_LIB = ft_bzero.c \
			ft_strchr.c \
			ft_putstr.c \
			ft_min.c \
			ft_strncpy.c \
			ft_strnew.c \
			ft_putstr_fd.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_strdel.c

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
			@gcc $(CFLAGS) $(OBJ) -o $(NAME)
			@/bin/rm -f get_next_line.h.gch

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
