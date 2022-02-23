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

int main(void) {
  void *mlx;
  void *mlx_win;

  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, 1920, 1080, "HEllo world!");
  (void)mlx;
  (void)mlx_win;
  mlx_loop(mlx);
  return (0);
}
