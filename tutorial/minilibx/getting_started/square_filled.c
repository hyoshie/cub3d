#include "../minilibx-linux/mlx.h"
#include <stdio.h>

// Color
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[39m"

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

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

void draw_filled(t_info *info, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      my_mlx_pixel_put(&(info->img), j, i, 0x0000FF00);
      printf("[i]%d[j]%d\n", i, j);
    }
  }
}

void draw_square(t_info *info, int length) {
  const int base_x = 30;
  const int base_y = 30;

  draw_filled(info, length);
  mlx_put_image_to_window(info->mlx, info->mlx_win, (info->img).img, base_x,
                          base_y);
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
  draw_square(&info, 100);
  mlx_loop(info.mlx);
  return (0);
}
