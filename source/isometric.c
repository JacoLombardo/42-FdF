/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/09 17:06:18 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_2D	*ft_to_isometric(t_matrix *point, t_size *size)
{
	t_2D	*iso;

	(void)size;
	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	/* iso->x = (point->x - point->y) * ((HEIGHT / 2) / size->y);
	iso->y = ((point->x + point->y) / 2 - point->z) * ((HEIGHT / 2)
			/ size->y); */
	iso->x = (point->x - point->y) * 10;
	iso->y = ((point->x + point->y) / 2 - point->z) * 10;
	return (iso);
}
