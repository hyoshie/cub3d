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
  ON_EXPOSE = 12,
  ON_DESTROY = 17,
  ON_RESIZE = 25
};

enum Xmask {
  KEY_PRESS_MASK = 1L << 0,
  KEY_RELEASE_MASK = 1L << 1,
  BOTTUN_PRESS_MASK = 1L << 2,
  BOTTUN_RELEASE_MASK = 1L << 3,
  STRUCTURE_NOTIFY_MASK = 1L << 17,
  RESIZE_REQUEST_MASK = 1 << 25,
};
typedef struct {
  void *mlx;
  void *win;
  bool key_pressed;
  time_t press_start;
  int base_time;
} t_vars;

int key_press_hook(int keycode, t_vars *vars) {
  write(STDOUT_FILENO, YELLOW "Pressed!!" RESET, 14);
  if (keycode == KEY_ESC) {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(1);
  }

  time_t now;
  time(&now);

  vars->press_start = now;
  while (true) {
    time(&now);
    if (difftime(now, vars->press_start) > vars->base_time) {
      printf(CYAN "[%d]seconds passed!!" RESET, vars->base_time);
      fflush(stdout);
      return (0);
    }
  }
  return (0);
}

int key_release_hook(int keycode, t_vars *vars) {
  (void)keycode;
  (void)vars;
  printf(YELLOW "Release!!" RESET);
  fflush(stdout);
  return (0);
}
int main(void) {
  t_vars vars;

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
  vars.key_pressed = false;
  vars.press_start = -1;
  vars.base_time = 5;
  mlx_hook(vars.win, ON_KEYDOWN, KEY_PRESS_MASK, key_press_hook, &vars);
  mlx_hook(vars.win, ON_KEYUP, KEY_RELEASE_MASK, key_release_hook, &vars);
  mlx_loop(vars.mlx);
  return (0);
}
