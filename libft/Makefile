CFILES = ft_arg_len.c \
         ft_atoi.c \
         ft_lstadd_back.c \
         ft_lstclear.c \
         ft_lstnew.c \
         ft_lstsize.c \
         ft_split.c \
         ft_strdup.c \
         ft_strjoin.c \
         ft_strlen.c \
         ft_copy_cat.c \
         ft_sort_int_tab.c
OFILES = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

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
