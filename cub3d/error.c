
#include "cub3d.h"

void error_msg(char *mess, int num)
{
    ft_putstr_fd("cub3D: Error", 2);
    if (mess)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(mess, 2);
    }
    ft_putstr_fd("\n", 2);
    return (num);
}

int handle_parse_error(char *tmp_line, int fd, int error_num)
{
    free(tmp_line);
    close(fd);
    if (error_num == 1)
        return (error_msg("blabla\n", 1));
    if (error_num == 2)
        return (error_msg("Map error : invalid identifier.\n", 1));
    if (error_num == 3)
        return (error_msg("Map error : duplicate texture.\n", 1));
    if (error_num == 4)
        return (error_msg("Map error : invalid texture line.\n", 1));
    if (error_num == 5)
        return (error_msg("Map error : memory fail for path.\n", 1));
}