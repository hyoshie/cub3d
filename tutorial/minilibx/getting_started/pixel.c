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

void print_img_info(t_data *data) {
  printf("[data->img]%p\n", data->img);
  printf("[data->addr]%p\n", data->addr);
  printf("[data->bits_per_pixel]%d\n", data->bits_per_pixel);
  printf("[data->line_length]%d\n", data->line_length);
  printf("[data->endian]%d\n", data->endian);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

int main(void) {
  void *mlx;
  void *mlx_win;
  t_data img;

  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
  img.img = mlx_new_image(mlx, 1920, 1080);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                               &img.endian);
  my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
  // print_img_info(&img);
  return (0);
}
