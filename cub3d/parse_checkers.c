
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

