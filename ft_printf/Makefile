CFILES = ft_printf.c \
         ft_putchar.c \
         ft_putstr.c \
         ft_putint.c 
OFILES = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
#colors
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
RESET   := \033[0m

all: $(NAME)

$(NAME): $(OFILES) 
	@printf "$(GREEN)[Archivage] Archivage libft ...$(RESET)\n"
	ar rcs $@ $^

clean:
	@printf "$(YELLOW)[Nettoyage] Nettoyage fichiés objets ...$(RESET)\n"
	$(RM) $(OFILES)

fclean:
	@printf "$(YELLOW)[Nettoyage] Nettoyage global printf ...$(RESET)\n"
	$(RM) $(NAME) $(OFILES)

re: fclean all
