/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:21:16 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 10:57:29 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_get_columns(char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	ft_free_tab(tab);
	return (i);
}

t_size	*ft_calc_map(char *map)
{
	int		i;
	int		fd;
	char	*line;
	t_size	*size;

	i = 0;
	size = (t_size *)malloc(1 * sizeof(t_size));
	if (!size)
		return (NULL);
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			size->x = ft_get_columns(line);
		i++;
		free(line);
	}
	size->y = i;
	ft_printf("X: %i, Y: %i\n", size->x, size->y);
	close(fd);
	return (size);
}
