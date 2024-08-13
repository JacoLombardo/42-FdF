/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:21:16 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 10:27:39 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_get_rows(char *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		i++;
		free(line);
	}
	ft_printf("Y: %i\n", i);
	close(fd);
	return (i);
}

int	ft_read_all(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (fd);
}

int	ft_get_columns(char *map)
{
	int		i;
	char	*line;
	char	**tab;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	free(line);
	while (tab[i])
		i++;
	ft_free_tab(tab);
	close(ft_read_all(fd));
	ft_printf("X: %i\n", i);
	return (i);
}
