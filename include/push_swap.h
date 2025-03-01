#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../external/libft/libft.h"
#include "../external/ft_printf/ft_printf.h"

typedef struct  s_stack
{
    int size;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

typedef struct s_data
{
    char **buffer;
    t_stack *a;
    t_stack *b;
} t_data;

int     init(t_data *data);
int     program_exit_with_error(t_data *data);
int     param_controls(t_data *data, int ac, char **av);
void    memory_free(t_data *data);

#endif