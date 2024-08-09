#include "cub3d.h"

void check_texture(t_data *game, char *line, t_dir dir)
{
    char *path;
    int i;
    int fd;

    if (is_texture_duplicate(game, dir))
        game->error = 3;
    if (!line[2] || !is_space(line[2]))
        game->error = 4;
    i = 2;
    while (line[i] && is_space(line[i]))
        i++;
    path = ft_strdup(line + i);
    if (!path)
        game->error = 5;
    fd = open(path, O_RDONLY);
    if (fd < 0)
        game->error = 4;
    close(fd);ma
    check_file_extension(game, path);
    set_player_direction(game, path, dir);
}

// texture
void get_textures_and_colors(char *line, t_data *game)
{

    // north
    if (line && line[0] == 'N' && line[1] == 'O')
        ft_path_texture(line, &game->no, game, 2);
    // south
    else if (line && line[0] == 'S' && line[1] == 'O')
        ft_path_texture(line, &game->so, game, 2);
    // west
    else if (line && line[0] == 'E' && line[1] == 'A')
        ft_path_texture(line, &game->ea, game, 2);
    // east
    else if (line && line[0] == 'W' && line[1] == 'E')
        ft_path_texture(line, &game->we, game, 2);
    // floor
    else if (line && line[0] == 'F')
        ft_path_texture(line, &game->floor, game, 1);
    // floor
    else if (line && line[0] == 'C')
        ft_path_texture(line, &game->ceiling, game, 1);
    else if (line && line[0] != 'N' && line[0] != 'S' && line[0] != 'E' && line[0] != 'W' && line[0] != 'F' && line[0] != 'C')
        game->error = 2;
    // is checking if color already set necess
}

static void route_lines(t_game *game, char *line)
{
    game->line = NULL;
    if (ft_strchr(line, '.') || ft_strchr(line, ','))
        game->line = ft_strtrim(line, " \t\r");
    game->line_tmp = line;
    parse_textures_and_colors(game, game->line);
    game->line_tmp = NULL;
    if (game->line)
        free(game->line);
    else if ((line[0] == '1' || line[0] == ' ') &&
             (all_textures_and_colors_set(game)))
        get_map_size(game, line);
    else if (!is_empty_line(line))
    {
        free(line);
        close(game->fd);
        error_msg(game, "Invalid line in input file.\n");
    }
    free(line);
}


void parse_file(t_game *game, char *file)
{
    char *line;
    char *tmp_line;

    game->fd = open(file, O_RDONLY);
    if (game->fd < 0)
        return (error_msg("Error: Could not open map file.\n", 1));
    line = get_next_line(game->fd);
    while (line != NULL)
    {
        tmp_line = ft_strtrim(line, "\r\n");
        free(line);
        route_lines(game, tmp_line);
        if (game->error)
            return(handle_parse_error(tmp_line, game->fd, game->error));
        free(tmp_line);
        line = get_next_line(game->fd);
    }
    close(game->fd);
    if (!all_textures_and_colors_set(game))
        return (error_msg("Error: Missing textures or colors in map file.\n", 1));
    parse_map(game, file);
}




