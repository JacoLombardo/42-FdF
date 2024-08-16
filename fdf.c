/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 11:03:21 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_size		*size;

	size = ft_calc_map(map);
	if (!size)
		return ;
	matrix = ft_malloc(size);
	if (!matrix)
		return ;
	ft_parse(map, matrix);
	ft_init_libx(matrix, size);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_printf("Try ./fdf [MAP NAME.fdf]\n");
	return (0);
}
