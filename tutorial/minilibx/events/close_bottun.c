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
#define ESC 0xff1b

enum Xevent {
  ON_KEYDOWN = 2,
  ON_KEYUP = 3,
  ON_MOUSEDOWN = 4,
  ON_MOUSEUP = 5,
  ON_EXPOSE = 12,
  ON_DESTROY = 17
};

enum Xmask {
  KEY_PRESS_MASK = 1L << 0,
  KEY_RELEASE_MASK = 1L << 1,
  BOTTUN_PRESS_MASK = 1L << 2,
  BOTTUN_RELEASE_MASK = 1L << 3,
  STRUCTURE_NOTIFY_MASK = 1L << 17,
};
typedef struct {
  void *mlx;
  void *win;
} t_vars;

int close(t_vars *vars) {
  mlx_destroy_window(vars->mlx, vars->win);
  return (0);
}

int main(void) {
  t_vars vars;

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  mlx_hook(vars.win, ON_DESTROY, STRUCTURE_NOTIFY_MASK, close, &vars);
  mlx_loop(vars.mlx);
  return (0);
}
