#include "constants.h"
#include "cub3d.h"

//for test
void	print_array(char **array)
{
	int y;
	y = 0;
	while (array[y])
	{
		printf("%s\n", array[y]);
		y++;
	}
}

static bool	is_map_closed(char **map, int x, int y)
{
	if (!map[y] || map[y][x] == ' ' || map[y][x] == '\0')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'P')
		return (true);
	map[y][x] = 'P';
	//print_array(map);
	return (is_map_closed(map, x + 1, y) && is_map_closed(map, x - 1, y)
		&& is_map_closed(map, x, y + 1) && is_map_closed(map, x, y - 1));
}

void	validate_map(char **map, int player_pos_x, int player_pos_y)
{
	//all_free_exit的なやつにする
	if (!is_map_closed(map, player_pos_x / TILE_SIZE, player_pos_y / TILE_SIZE))
		exit(1);
}
