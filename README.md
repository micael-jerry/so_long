# So Long

So Long is a small 2D game developed as part of the 42 school curriculum. The objective is to navigate a player through a map, collect all the collectibles, and then reach the exit.

## Prerequisites

This project is designed for a Linux environment and requires the following to be installed on your system:

* `gcc` (C compiler)
* `make`
* `X11` development libraries (libXext, libX11)
* `zlib` development library (libz)

On Debian-based distributions (like Ubuntu), you can install the necessary libraries with the following command:

```bash
sudo apt install build-essential libx11-dev libxext-dev zlib1g-dev
```

## Getting Started

1. **Clone the repository:**

    ```bash
    git clone <repository-url>
    cd so_long
    ```

2. **Build the project:**

    Use the `make` command to compile the game.

    ```bash
    make
    ```

    This will create an executable file named `so_long`.

3. **Run the game:**

    Provide a map file from the `maps/` directory as an argument to the executable.

    ```bash
    ./so_long maps/basic.ber
    ```

## Makefile Rules

The included `Makefile` provides the following rules:

* `make all`: (Default) Compiles the project.
* `make clean`: Removes the generated object files.
* `make fclean`: Removes all generated files, including the `so_long` executable.
* `make re`: Cleans and rebuilds the project.

## Resources

- [so_long guide](https://42-cursus.gitbook.io/guide/rank-02/so_long)
- [Minilibx docs (no official)](https://harm-smits.github.io/42docs/libs/minilibx)
- [Resizi img](https://onlinepngtools.com/resize-png)
- [Convert img to xpm](https://convertio.co/fr/png-xpm/)
