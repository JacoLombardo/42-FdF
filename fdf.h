/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:19 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/08 16:45:00 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <fcntl.h>
# include <unistd.h>

# define WIDTH 640
# define HEIGHT 480

typedef struct s_matrix
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_matrix;

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

/* calculate_map */
int					ft_get_rows(char *map);
int					ft_get_columns(char *map);

/* libx */
void				ft_mlx_pixel_put(t_image *data, int x, int y, int color);

/* malloc */
t_matrix			***ft_free_matrix(t_matrix ***matrix, t_size *size);
t_matrix			***ft_free_that_matrix(t_matrix ***matrix, int i, int j,
						t_size *size);
t_matrix			***ft_malloc(t_size *size);

/* parse_map */
void				ft_free_tab(char **tab);
unsigned int		ft_hex_to_int(char *hex);
void				ft_parse_line(char **tab, t_matrix **matrix, int x);
void				ft_parse(char *map, t_matrix ***matrix);

/* fdf */

#endif