/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/06 14:44:28 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_size		*size;
	void	*mlx;

	size = (t_size *)malloc(1 * sizeof (t_size));
	size->x = ft_get_rows(map);
	size->y = ft_get_columns(map);
	matrix = ft_malloc(size);
	ft_parse(map, matrix);

	mlx = mlx_init();
	mlx_new_window(mlx, 640, 480, "test window");
	/* int	x = 0;
	int	y = 240;
	while (x++ < 640)
		mlx_pixel_put(mlx, window, x, y, 0xFFFFFF); */
	mlx_loop(mlx);
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
