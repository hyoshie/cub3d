#include "../minilibx-linux/mlx.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// Color
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF

typedef struct s_data {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;

typedef struct s_info {
  void *mlx;
  void *mlx_win;
  t_data img;
} t_info;

typedef struct s_point {
  int x;
  int y;
} t_point;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

bool is_in_circle(t_point p, t_point center, int radius) {
  if (pow(p.x - center.x, 2) + pow(p.y - center.y, 2) < pow(radius, 2))
    return true;
  else
    return false;
}

void draw_circle(t_info *info, int radius) {
  const t_point center = {250, 250};

  for (int i = -radius; i < radius; i++) {
    for (int j = -radius; j < radius; j++) {
      t_point current = {center.x + j, center.y + i};
      if (is_in_circle(current, center, radius))
        my_mlx_pixel_put(&(info->img), current.x, current.y, BLUE);
    }
  }

  const t_point base = {30, 30};
  mlx_put_image_to_window(info->mlx, info->mlx_win, (info->img).img, base.x,
                          base.y);
}

#define WIN_WIDTH 500
#define WIN_HEIGHT 500

int main(void) {
  t_info info;

  info.mlx = mlx_init();
  info.mlx_win =
      mlx_new_window(info.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  info.img.img = mlx_new_image(info.mlx, WIN_WIDTH, WIN_HEIGHT);
  info.img.addr =
      mlx_get_data_addr(info.img.img, &(info.img).bits_per_pixel,
                        &(info.img).line_length, &(info.img).endian);
  draw_circle(&info, 50);
  mlx_loop(info.mlx);
  return (0);
}
