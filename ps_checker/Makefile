CF_M = checker.c \
    	get_next_line.c \
		get_next_line_utils.c \
		check_move.c \
		../global_utils.c
CF_I =	../instruction/ft_pa_pb.c \
		../instruction/ft_ra_rb.c \
		../instruction/ft_rra.c \
		../instruction/ft_sa_sb.c \
		../instruction/global_inst.c \
		../instruction/linked_utils.c
CF_A =	../algo/ft_memory.c \
		../algo/index.c \
		../algo/radix.c \
		../algo/spe_case.c
CFLAGS = -Wall -Wextra -Werror
NAME = checker
LIBFT =  ../libft/libft.a
FT_PRINTF = ../ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(CF_M)
	@echo [ Compilation.. ]
	cc ${CF_M} -o ${NAME} ${CF_I} ${CF_A} ${LIBFT} ${FT_PRINTF} -I ../libft -I ../ft_printf

clean:
	@echo [ Nettoyage fichiés objets... ]
	$(RM) $(NAME)

re: clean all

#cc *.c -o checker ../instruction/*.c ../algo/*.c  
#../libft/libft.a ../ft_printf/libftprintf.a -I ../libft -I ../ft_printf