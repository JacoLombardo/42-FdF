/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/06 12:11:38 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(char *map)
{
	t_matrix	***matrix;
	t_size		*size;

	size = (t_size *)malloc(1 * sizeof (t_size));
	size->x = ft_get_rows(map);
	size->y = ft_get_columns(map);
	matrix = ft_malloc(size);
	//free(size);
	//ft_parse(map, matrix);
	//ft_free_matrix(matrix, size);
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
