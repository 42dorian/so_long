*This project has been created as part of the 42 curriculum by dabdulla*

## Project Description
`so_long` is a 2D game, the project focuses on fundamental graphics programming, window management, and event handling using the MiniLibX library in C.

# Instructions

### Compilation

To compile the project, run the following command in the root directory:

```bash
make

```
### How to Play
To launch the game, execute the binary followed by the path to a map file:
```bash
./so_long maps/<map_name>.ber

```
You can find all valid map files (ending in `.ber`) located within the `maps/` directory of this project.

### Controls & Objectives

* **Movement:** Use `W`, `A`, `S`, and `D` to navigate.
* **Goal:** Collect all the coins on the map to unlock the exit and win!

# Resources

Here is where I learned how to free and destroy images and properly close the game without memory leaks:

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)  
  I learned how to create a window, initialize the game using MLX, and understand the loops that MLX provides.

- [MiniLibX Linux API Reference](https://deepwiki.com/42paris/minilibx-linux/4-api-reference)  
  From this resource, I learned how to properly end the game and handle cleanup.

These resources explain how to correctly use functions such as `mlx_destroy_image` and `mlx_destroy_window`, and how to properly exit the program to avoid memory leaks. They also describe the correct cleanup order (destroy images first, then the window, then free the display and MLX pointer when needed).
