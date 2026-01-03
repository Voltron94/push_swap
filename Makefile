#classic file

CFILE =	push_swap.c \
		global_utils.c \
		instruction/ft_pa_pb.c \
		instruction/ft_ra_rb.c \
		instruction/ft_rra.c \
		instruction/ft_sa_sb.c \
		instruction/global_inst.c \
		instruction/linked_utils.c \
		algo/ft_memory.c \
		algo/index.c \
		algo/radix.c \
		algo/spe_case.c
OBJS = $(CFILE:.c=.o)

#Flag et nom

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

#Librairie

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
INCLUDES = -I libft -I ft_printf

#Couleur
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
RESET   := \033[0m

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	@printf "$(GREEN)[Compilation] Compilation principal ...$(RESET)\n"
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@printf "$(GREEN)[Compilation] Compilation libft ...$(RESET)\n"
	$(MAKE) -C libft

$(PRINTF):
	@printf "$(GREEN)[Compilation] Compilation printf ...$(RESET)\n"
	$(MAKE) -C ft_printf

clean:
	@printf "$(YELLOW)[Nettoyage] Nettoyage fichiés objets ...$(RESET)\n"
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclean: clean
	@printf "$(YELLOW)[Nettoyage] Nettoyage global ...$(RESET)\n"
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

