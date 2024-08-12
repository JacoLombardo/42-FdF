/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/12 17:34:14 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_matrix ***matrix, t_size *size)
{
	t_vars	vars;
	t_image	image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "FdF Window");
	image.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	ft_create_img(matrix, size, &image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, ft_handle_hooks, &vars);
	mlx_hook(vars.win, 17, 0, close_window, NULL);
	mlx_loop(vars.mlx);
}

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_size		*size;

	size = (t_size *)malloc(1 * sizeof(t_size));
	size->x = ft_get_rows(map);
	size->y = ft_get_columns(map);
	matrix = ft_malloc(size);
	ft_parse(map, matrix, size);
	ft_init(matrix, size);
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
