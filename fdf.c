/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/08 16:49:51 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_matrix ***matrix)
{
	void	*mlx;
	void	*window;
	t_image	image;
	int		x;
	int		y;

	(void)matrix;
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF Window");
	image.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	y = HEIGHT / 2;
	x = 0;
	while (x++ < WIDTH)
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
	ft_init(matrix);
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
