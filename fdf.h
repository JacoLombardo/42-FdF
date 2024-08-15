/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:19 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/15 13:28:42 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "hooks.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

/* # define WIDTH 640
# define HEIGHT 480 */
# define WIDTH 960
# define HEIGHT 720
/* # define WIDTH 1920
# define HEIGHT 1080 */
# define STD_COLOR 0xFFFFFF
# define BLUE 0x0000FF
# define RED 0xFF0000
# define ZOOM 20
# define ANGLE 0.7854
# define COS 0.707105
# define SIN 0.707108

typedef struct s_matrix
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_2D		*iso;
}					t_matrix;

typedef struct s_2D
{
	int				x;
	int				y;
}					t_2D;

typedef struct s_limits
{
	int				max_x;
	int				min_x;
	int				max_y;
	int				min_y;
	int				zoom;
}					t_limits;

typedef struct s_size
{
	int				x;
	int				y;
}					t_size;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_image			*image;
}					t_vars;

typedef struct s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				color1;
	int				color2;
	int				step;
}					t_line;

/* calculate_map */
int					ft_get_rows(char *map);
int					ft_get_columns(char *map);

/* draw_line */
t_line				*ft_to_line(t_line *line, t_matrix *p1, t_matrix *p2);
void				ft_draw_line(t_line *line, t_image *image);
void				ft_print_line(t_matrix *p1, t_matrix *p2, t_image *image);

/* hooks */
int					ft_close_window(t_vars *vars);
void				ft_close(t_vars *vars);
int					ft_handle_hooks(int keycode, t_vars *vars);

/* isometric */
int					ft_zoom(t_limits *limits);
t_2D				*ft_zoom_n_center(t_matrix *point, t_limits *limits);
t_2D				*ft_to_isometric(t_matrix *point);

/* libx */
void				ft_mlx_pixel_put(t_image *data, int x, int y, int color);
void				ft_print_line(t_matrix *first, t_matrix *second,
						t_image *image);
void				ft_create_img(t_matrix ***matrix, t_size *size,
						t_image *image);

/* limits */
void				ft_calc_max_width(t_matrix ***matrix, t_size *size,
						t_limits *limits);
void				ft_calc_max_height(t_matrix ***matrix, t_size *size,
						t_limits *limits);
t_limits			*ft_calc_limits(t_matrix ***matrix, t_size *size);

/* malloc */
t_matrix			***ft_free_matrix(t_matrix ***matrix, t_size *size);
t_matrix			***ft_free_that_matrix(t_matrix ***matrix, int i, int j,
						t_size *size);
t_matrix			***ft_malloc(t_size *size);

/* parse_map */
void				ft_free_tab(char **tab);
unsigned int		ft_hex_to_int(char *hex);
void				ft_parse_line(char **tab, t_matrix ***matrix, int x);
void				ft_parse(char *map, t_matrix ***matrix);

/* fdf */
void				ft_init(t_matrix ***matrix, t_size *size);
void				fdf(char *map);

#endif