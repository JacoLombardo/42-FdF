/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 11:08:33 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_close_libx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	ft_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init_libx(t_matrix ***matrix, t_size *size)
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
	vars.image = &image;
	mlx_key_hook(vars.win, ft_handle_hooks, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
	mlx_loop(vars.mlx);
	ft_close_libx(&vars);
}
