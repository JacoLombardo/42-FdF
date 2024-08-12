/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/12 18:00:08 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_2D	*ft_to_isometric(t_matrix *point, t_size *size)
{
	t_2D	*iso;
	double	zoomx;
	double	zoomy;

	(void)size;
	zoomx = WIDTH / (2 * size->x);
	zoomy = HEIGHT / (2 * size->y);
	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	/* iso->x = ((point->x * cos(ANGLE)) - (point->y * cos(ANGLE))) * ZOOM;
	iso->y = (((point->x * sin(ANGLE)) + (point->y * sin(ANGLE))) / 2 - point->z) * ZOOM; */
	iso->x = point->x * 10;
	iso->y = point->y * 10;
	return (iso);
}
