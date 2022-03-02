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
  write(STDOUT_FILENO, YELLOW "Pressed!!" RESET, 14);
  if (keycode == KEY_ESC) {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(1);
  }
  return (0);
}

int mouse_hook(t_vars *vars) {
  (void)vars;
  write(STDOUT_FILENO, YELLOW "HAHA!!I'm Mouse!!\n'" RESET, 23);
  ;
  return 0;
}

int mouse_motin_hook(int x, int y, t_vars *vars) {
  (void)x;
  (void)y;
  (void)vars;
  if (x < 100)
    write(STDOUT_FILENO, GREEN "BOTTUN!!" RESET, 14);
  return (0);
}

int enter_window_hook(t_vars *vars) {
  (void)vars;
  write(STDOUT_FILENO, GREEN "ENTER!!\n" RESET, 14);
  return (0);
}

int leave_window_hook(t_vars *vars) {
  (void)vars;
  write(STDOUT_FILENO, CYAN "LEAVE21!!\n" RESET, 15);
  return (0);
}

void set_hooks(t_vars *vars) {
  // mlx_mouse_show(vars.mlx, vars.win);
  mlx_mouse_hide(vars->mlx, vars->win);
  mlx_mouse_hook(vars->win, mouse_hook, vars);
  mlx_hook(vars->win, ON_ENTER_NOTIFY, ENTER_WINDOW_MASK, enter_window_hook,
           vars);
  mlx_hook(vars->win, ON_LEAVE_NOTIFY, LEAVE_WINDOW_MASK, leave_window_hook,
           vars);
  mlx_hook(vars->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press_hook, vars);
  mlx_hook(vars->win, ON_MOUSEMOVE, POINTER_MOTION_MASK, mouse_motin_hook,
           vars);
}

int main(void) {
  t_vars vars;

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");

  set_hooks(&vars);
  mlx_loop(vars.mlx);
  return (0);
}
