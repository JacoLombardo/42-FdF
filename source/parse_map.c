/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:20:02 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 12:02:38 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (1);
}

unsigned int	ft_hex_to_int(char *hex)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		result *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			result += hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			result += hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result += hex[i] - 'A' + 10;
		else
			break ;
		i++;
	}
	return (result);
}

int	ft_parse_line(char **tab, t_matrix ***matrix, int y)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		matrix[x][y]->x = x;
		matrix[x][y]->y = y;
		matrix[x][y]->z = ft_atoi(tab[x]);
		if (ft_strrchr(tab[x], ','))
			matrix[x][y]->color = ft_hex_to_int(ft_strrchr(tab[x], ',') + 1);
		else
		{
			if (matrix[x][y]->z > 10)
				matrix[x][y]->color = BLUE;
			else if (matrix[x][y]->z < 0)
				matrix[x][y]->color = RED;
			else
				matrix[x][y]->color = STD_COLOR;
		}
		matrix[x][y]->iso = ft_to_isometric(matrix[x][y]);
		if (!matrix[x][y]->iso)
			return (0);
		x++;
	}
	return (ft_free_tab(tab));
}

int	ft_parse(char *map, t_matrix ***matrix)
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
			break ;
		if (!ft_parse_line(ft_split(line, ' '), matrix, i))
			return (0);
		i++;
		free(line);
	}
	return (1);
}
