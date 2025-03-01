#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include "../external/libft/libft.h"
#include "../external/ft_printf/ft_printf.h"

typedef struct s_data
{
    int *a;
    int *b;
    int size;
    int size_a;
    int size_b;
    char **buffer;
} t_data;

int     init(t_data *data);
int     program_exit(t_data *data);
int     program_exit_with_error(t_data *data);
int     param_controls(t_data *data, int ac, char **av);
int     param_count(char **av);
int     stack_controls(t_data *data);
void	free_params(t_data *data);
void    memory_free(t_data *data);

#endif