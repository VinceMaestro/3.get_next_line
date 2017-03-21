NAME = gnl

CFLAGS = -Wall -Werror -Wextra

SRC = main_get_next_line.c \
			get_next_line.c

LIBDIR = ./libft

OBJ = $(SRC:.c=.o)

INCL = $(LIBDIR) \
		./

all: $(NAME)

$(LIBDIR)/libft.a:
	@make -C $(LIBDIR)

%.o:%.c
	@gcc $(CFLAGS) -c $< -o $@ -g $(addprefix -I, $(INCL))

$(NAME) : $(OBJ) | $(LIBDIR)/libft.a
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBDIR) -l ft

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
