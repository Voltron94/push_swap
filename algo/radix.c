#include "push_swap.h"

int get_max_bits(t_list *stack)
{
    int bit_size;
    int max_val;

    bit_size = 0;
    max_val = ft_lstsize(stack) - 1;
    while (max_val > 1)
    {
        bit_size++;
        max_val /= 2;
    }
    return (bit_size);
}

void radix(t_list **stack_a, t_list **stack_b)
{
    int i;
    int tmp;
    int size;
    int max_bit;

    i = 0;
    size = ft_lstsize(*stack_a);
    max_bit = get_max_bits(*stack_a); // nb bits du plus grand nombre
    if (size == 2)
        two_case(stack_a, stack_b);
    if (size == 3)
        three_case(stack_a, stack_b);
    while (i <= max_bit && size != 2)
    {
        tmp = size; // nombre d'element a traiter . Chaque fois que on relance, stack_a doit conserver le meme nb d'element !
        while (tmp-- > 0)
        {
            if ((((*stack_a)->index >> i) & 1) == 0)
                push(stack_a, stack_b, 'b');
            else
                rotate(stack_a, stack_b, 'a');
        }
        while (*stack_b)
            push(stack_a, stack_b, 'a');
        i++;
    }
}

/*
    # si le chiffre a pour bit de poids faible 0 on push dans la stack B
        # sinon on rotate et on passe a la suite
    # on renvoie dans la stack A se qui se trouve dans la stack B
*/
