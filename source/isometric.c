/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 11:20:25 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_zoom(t_limits *limits)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (float)WIDTH / (limits->max_x - limits->min_x);
	zoom_y = (float)HEIGHT / (limits->max_y - limits->min_y);
	if (zoom_x < zoom_y)
		return (round(zoom_x * 0.5));
	else
		return (round(zoom_y * 0.5));
}

t_2D	*ft_zoom_n_center(t_matrix *point, t_limits *limits)
{
	t_2D	*iso;
	int		offset_x;
	int		offset_y;

	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	if (!iso)
		return (NULL);
	offset_x = (WIDTH - (limits->max_x - limits->min_x)) / 2 - limits->min_x;
	offset_y = (HEIGHT - (limits->max_y - limits->min_y)) / 2 - limits->min_y;
	iso->x = ((round(point->x * COS) - round(point->y * COS)) * limits->zoom)
		+ offset_x;
	iso->y = (((round(point->x * SIN) + round(point->y * SIN)) / 2 - point->z)
			* limits->zoom) + offset_y;
	return (iso);
}

t_2D	*ft_to_isometric(t_matrix *point)
{
	t_2D	*iso;

	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	if (!iso)
		return (NULL);
	iso->x = round(point->x * COS) - round(point->y * COS);
	iso->y = (round(point->x * SIN) + round(point->y * SIN)) / 2 - point->z;
	return (iso);
}
