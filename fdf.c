/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/08 16:20:47 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_play(void)
{
	void	*mlx;
	void	*window;
	t_image	image;
	int		width;
	int		height;
	int	x;
	int	y;

	width = 640;
	height = 480;
	mlx = mlx_init();
	window = mlx_new_window(mlx, width, height, "FdF Window");
	image.img = mlx_new_image(mlx, width, height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	y = 240;
	x = 0;
	while (x++ < 640)
		ft_mlx_pixel_put(&image, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, window, image.img, 0, 0);
	mlx_loop(mlx);
}

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_size		*size;

	size = (t_size *)malloc(1 * sizeof(t_size));
	size->x = ft_get_rows(map);
	size->y = ft_get_columns(map);
	matrix = ft_malloc(size);
	ft_parse(map, matrix);
	ft_play();
	ft_free_matrix(matrix, size);
	free(size);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_printf("Try ./fdf [MAP NAME.fdf]\n");
	return (0);
}
