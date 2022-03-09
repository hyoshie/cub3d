#include "constants.h"
#include "cub3d.h"

void	free_all_exit(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->design.north.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->design.south.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->design.west.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->design.east.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->win_img.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	mlx_loop_end(game->mlx_ptr);
	free(game->mlx_ptr);
	free_vector(game->map.map_ptr);
	exit (EXIT_SUCCESS);
}
