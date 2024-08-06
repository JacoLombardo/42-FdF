/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/06 15:10:35 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_play(void)
{
	void		*mlx;
	void		*window;
	/* void		*image; */
	int			x;
	int			y;
	/* int		bits_pixel;
	int		size_line;
	int		endian;
	char	*img_buffer; */

	mlx = mlx_init();
	window = mlx_new_window(mlx, 640, 480, "test window");
	x = 0;
	y = 240;
	while (x++ < 640)
		mlx_pixel_put(mlx, window, x, y, 0xFFFFFF);
	mlx_loop(mlx);
	/* // 1
	image = mlx_new_image(mlx, width, height);
	// 2
	// 3
	img_buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	// 4
	(decide the color of each pixel)
		// 5
		mlx_put_image_to_window(mlx, window, image, 0, 0); */
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
