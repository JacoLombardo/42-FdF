/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:46:21 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 17:35:28 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image->img);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_matrix(vars->matrix, vars->size);
	exit(0);
	return (0);
}

void	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_handle_hooks(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(vars->mlx, vars->image->img);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_matrix(vars->matrix, vars->size);
		exit(0);
	}
	return (0);
}
