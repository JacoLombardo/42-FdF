/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:46:21 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/15 15:05:22 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_close_window(t_vars *vars)
{
	ft_close_libx(vars);
	exit(0);
	return (0);
}

int	ft_handle_hooks(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		ft_close_libx(vars);
		exit(0);
	}
	return (0);
}
