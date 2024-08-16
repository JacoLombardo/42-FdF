/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 12:00:08 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_2D		*size;

	size = (t_2D *)malloc(1 * sizeof(t_2D));
	if (!size)
		return ;
	size = ft_calc_map(map, size);
	if (!size)
		return ;
	matrix = ft_malloc(size);
	if (!matrix)
		return ;
	if (!ft_parse(map, matrix))
	{
		ft_free_matrix(matrix, size);
		return ;
	}
	ft_init_libx(matrix, size);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else if (argc == 1)
		ft_printf("ERROR: Too few parameters, try ./fdf [MAP NAME.fdf]\n");
	else
		ft_printf("ERROR: Too many parameters, try ./fdf [MAP NAME.fdf]\n");
	return (0);
}
