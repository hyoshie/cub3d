#include "../minilibx-linux/mlx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
#define KEY_ESC 0xff1b
#define KEY_A 0x61

enum Xevent {
  ON_KEYDOWN = 2,
  ON_KEYUP = 3,
  ON_MOUSEDOWN = 4,
  ON_MOUSEUP = 5,
  ON_MOUSEMOVE = 6,
  ON_ENTER_NOTIFY = 7,
  ON_LEAVE_NOTIFY = 8,
  ON_EXPOSE = 12,
  ON_DESTROY = 17,
  ON_RESIZE = 25
};

enum Xmask {
  NO_EVENT_MASK = 0,
  KEY_PRESS_MASK = 1L << 0,
  KEY_RELEASE_MASK = 1L << 1,
  BOTTUN_PRESS_MASK = 1L << 2,
  BOTTUN_RELEASE_MASK = 1L << 3,
  ENTER_WINDOW_MASK = 1L << 4,
  LEAVE_WINDOW_MASK = 1L << 5,
  POINTER_MOTION_MASK = 1L << 6,
  BOTTUN1_MOTION_MASK = 1L << 8,
  STRUCTURE_NOTIFY_MASK = 1L << 17,
  RESIZE_REQUEST_MASK = 1 << 25,
};
typedef struct {
  void *mlx;
  void *win;
} t_vars;

int key_press_hook(int keycode, t_vars *vars) {
  (void)vars;
  if (keycode == KEY_ESC) {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(1);
  } else {
    printf("[keycode]" GREEN "%d\n" RESET, keycode);
  }
  return (0);
}

void set_hooks(t_vars *vars) { mlx_key_hook(vars->win, key_press_hook, vars); }

int main(void) {
  t_vars vars;

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");

  set_hooks(&vars);
  mlx_loop(vars.mlx);
  return (0);
}
