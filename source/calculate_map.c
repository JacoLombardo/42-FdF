/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:21:16 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 12:00:56 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_2D	*ft_handle_invalid(int fd, t_2D *size)
{
	close(fd);
	free(size);
	ft_printf("ERROR: Invalid Map\n");
	return (NULL);
}

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

t_2D	*ft_calc_map(char *map, t_2D *size)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_handle_invalid(fd, size));
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
	close(fd);
	return (size);
}
