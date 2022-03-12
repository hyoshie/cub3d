import sys
import random

CUB_TEMPLATE = """NO ./texture/rat.xpm
SO ./texture/horse.xpm
WE ./texture/dog.xpm
EA ./texture/rabbit.xpm
F 100,100,40
C 211,237,251
"""
WALL = "1"
FLOOR = "0"
SPRITE = "2"
PLAYER = "N"

def gen_map(max_x: int, max_y: int, sprite_density: int):
    if max_x < 3 or max_y < 3:
        show_usage_and_exit()

    print(CUB_TEMPLATE)
    print(WALL * max_x)
    line = WALL + FLOOR * (max_x - 2) + WALL
    for y in range(max_y - 2):
        print_line(max_x, max_y, sprite_density, y)
    print(WALL * max_x, end="")


def print_line(max_x: int, max_y: int, sprite_density: int, now_y: int):
    print(WALL, end="")
    for x in range(max_x - 2):
        if now_y == (max_y - 2) // 2 and x == max_x // 2 - 1:
            print(PLAYER, end="")
        else:
            cell = (FLOOR if sprite_density <= random.randint(0, 99) else SPRITE)
            print(cell, end="")
    print(WALL)

def show_usage_and_exit():
    print(f"""Usage: {sys.argv[0]} x y [sprite_density=0]
         x >= 3, y >= 3, 0 <= sprite_density <= 100""")
    sys.exit()


if __name__ == "__main__":
    if not 3 <= len(sys.argv) <= 4:
        show_usage_and_exit()
    x, y = int(sys.argv[1]), int(sys.argv[2])
    sprite_density = (int(sys.argv[3]) if len(sys.argv) == 4 else 0)
    gen_map(x, y, sprite_density)
