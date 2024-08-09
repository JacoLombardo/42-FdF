/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:19 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/09 16:32:44 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "hooks.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <fcntl.h>
# include <unistd.h>

/* # define WIDTH 640
# define HEIGHT 480 */
# define WIDTH 1920
# define HEIGHT 1080
# define STD_COLOR 0xFFFFFF

typedef struct s_matrix
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_2D		*iso;
	struct s_size	*size;
}					t_matrix;

typedef struct s_2D
{
	int				x;
	int				y;
}					t_2D;

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
}					t_vars;

typedef struct s_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				color1;
	int				color2;
	int				step;
}					t_line;

/* calculate_map */
int					ft_get_rows(char *map);
int					ft_get_columns(char *map);

/* hooks */
int					close_window(void *param);
void				ft_close(t_vars *vars);
int					ft_handle_hooks(int keycode, t_vars *vars);

/* isometric */
t_2D				*ft_to_isometric(t_matrix *point, t_size *size);

/* libx */
void				ft_mlx_pixel_put(t_image *data, int x, int y, int color);
void				ft_create_img(t_matrix ***matrix, t_size *size,
						t_image *image);

/* malloc */
t_matrix			***ft_free_matrix(t_matrix ***matrix, t_size *size);
t_matrix			***ft_free_that_matrix(t_matrix ***matrix, int i, int j,
						t_size *size);
t_matrix			***ft_malloc(t_size *size);

/* parse_map */
void				ft_free_tab(char **tab);
unsigned int		ft_hex_to_int(char *hex);
void				ft_parse_line(char **tab, t_matrix **matrix, int x,
						t_size *size);
void				ft_parse(char *map, t_matrix ***matrix, t_size *size);

/* fdf */

#endif