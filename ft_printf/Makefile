CFILES = ft_printf.c \
         ft_putchar.c \
         ft_putstr.c \
         ft_putint.c 
OFILES = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES) 
	@echo [ Archivage... ]
	ar rcs $@ $^

clean:
	@echo [ Nettoyage fichiés objets... ]
	$(RM) $(OFILES)

fclean:
	@echo [ Nettoyage archive... ]
	$(RM) $(NAME) $(OFILES)

re: fclean all
