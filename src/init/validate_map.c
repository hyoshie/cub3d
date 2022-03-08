#include "constants.h"
#include "cub3d.h"

//for test
/* void	print_array(char **array)
{
	int y;
	y = 0;
	while (array[y])
	{
		printf("%s\n", array[y]);
		y++;
	}
} */

static size_t	count_array_rows(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**array_dup(char **array)
{
	char	**copy;
	size_t	i;
	size_t	num_rows;

	i = 0;
	num_rows = count_array_rows(array);
	copy = (char **)xmalloc((sizeof(char *)) * num_rows + 1);
	while (array[i])
	{
		copy[i] = ft_strdup(array[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static bool	is_map_closed(char **map, int x, int y)
{
	if (!map[y] || map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == '@')
		return (true);
	map[y][x] = '@';
	//print_array(map);
	return (is_map_closed(map, x + 1, y) && is_map_closed(map, x - 1, y)
		&& is_map_closed(map, x, y + 1) && is_map_closed(map, x, y - 1));
}

void	validate_map(char **map, int player_pos_x, int player_pos_y)
{
	char	**copy;

	//all_free_exit的なやつにする
	copy = array_dup(map);
	if (!is_map_closed(copy, player_pos_x / TILE_SIZE, player_pos_y / TILE_SIZE))
		exit(1);
}
