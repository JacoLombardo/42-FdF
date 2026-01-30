# FdF

FdF (Fil de Fer, "wireframe" in French) is a 42 School graphics project that visualizes 3D terrain maps as isometric wireframes. A grid of elevation values from a text file is converted into a 3D wireframe model displayed in a window.

## Overview

The program reads height coordinates from a `.fdf` map file and renders the landscape as connected wireframe lines using isometric projection. It uses the MiniLibX graphics library for display and window management.

## Composition

- **fdf.c** — entry point and main loop
- **source/** — parsing, drawing, and projection logic
  - `parse_map.c` — reads and parses `.fdf` map files
  - `calculate_map.c`, `limits.c` — coordinate and bounds calculations
  - `isometric.c` — isometric projection
  - `draw.c` — line drawing (Bresenham)
  - `hooks.c` — keyboard and window events
  - `libx.c` — MiniLibX setup and rendering
- **libft/** — custom C library (libft, get_next_line, ft_printf)
- **maps/** — sample terrain maps (42.fdf, mars.fdf, etc.)

## Features

- **Isometric projection** — 3D wireframe view
- **Map parsing** — reads grid files with optional color data
- **Window management** — resize, zoom, pan (depending on implementation)
- **ESC and close button** — clean exit
- **Multiple maps** — bundled example maps in `maps/`

## Technology

- C (C99)
- MiniLibX (42 graphics library)
- libft (custom)
- Linux: X11, Xext

## Setup

Build (requires MiniLibX in `minilibx/` subfolder):

```bash
make
```

Run with a map file:

```bash
./fdf maps/42.fdf
./fdf maps/mars.fdf
```

## Makefile targets

| Target   | Description           |
|----------|-----------------------|
| `all`    | Build `fdf`           |
| `clean`  | Remove object files   |
| `fclean` | Remove objects and binary |
| `re`     | Fclean then rebuild   |

## Notes

- MiniLibX must be present in the `minilibx` directory
- Map format: space-separated integers per line; optional hex colors after values
- Rank 2 project in the 42 graphics track
