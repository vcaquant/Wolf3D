#include "../includes/wolf.h"

int     ft_error(void)
{
    ft_putstr("Invalid File. Please chose a valid file in map directory\n");
    return (-1);
}

int     ft_error2(void)
{
    ft_putstr("error syntax : ./wolf3d <valid file>\n");
    return (-1);
}
