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

#define WIN_WIDTH 960
#define WIN_HEIGHT 540
#define ON_KEYDOWN 2
#define ESC 0xff1b

typedef struct {
  void *mlx;
  void *win;
} t_vars;

int close(int keycode, t_vars *vars) {
  (void)keycode;
  mlx_destroy_window(vars->mlx, vars->win);
  return (0);
}

int main(void) {
  t_vars vars;

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  mlx_hook(vars.win, ON_KEYDOWN, 1L << 0, close, &vars);
  mlx_loop(vars.mlx);
  return (0);
}
