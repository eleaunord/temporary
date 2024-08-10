
#include "cub3d.h"

bool check_args(int argc, char **argv)
{
    int i;
    char *extension;

    if (argc != 2 || !argv || !(argv[1]))
        return (FALSE);
    extension = argv[1];
    i = ft_strlen(extension);
    if (i < 5)
        return (FALSE);
    if (!(extension[i - 1] == 'b' &&
          extension[i - 2] == 'u' &&
          extension[i - 3] == 'c' &&
          extension[i - 4] == '.'))
        return (FALSE);
    return (TRUE);
}

bool is_already_loaded(t_data *game, t_identifier elem)
{
    if (elem == N && game->no)
        return (true);
    else if (elem == S && game->so)
        return (true);
    else if (elem == W && game->we)
        return (true);
    else if (elem == E && game->ea)
        return (true);
    else if (elem == F && game->floor_color)
        return (true);
    else if (elem == C && game->ceiling_color)
        return (true);
    return (false);
}
int is_xpm(char *path, t_data *game)
{
    int len;
    char *filename;

    filename = ft_strrchr(path, '/');
    if (filename)
        filename++;
    else
        filename = path;
    len = ft_strlen(filename);
    if (len <= 4 || ft_strcmp(filename + len - 4, ".xpm") != 0)
        return (1);
    return (0);
}