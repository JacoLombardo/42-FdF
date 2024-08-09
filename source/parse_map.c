/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:20:02 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/09 17:02:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_tab(char **tab)
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

void	ft_parse_line(char **tab, t_matrix **matrix, int x, t_size *size)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		matrix[i]->x = x;
		matrix[i]->y = i;
		if (ft_strrchr(tab[i], ','))
		{
			matrix[i]->z = ft_atoi(tab[i]);
			matrix[i]->color = ft_hex_to_int(ft_strrchr(tab[i], ',') + 1);
		}
		else
		{
			matrix[i]->z = ft_atoi(tab[i]);
			matrix[i]->color = STD_COLOR;
		}
		matrix[i]->iso = ft_to_isometric(matrix[i], size);
		matrix[i]->size = size;
		i++;
	}
	ft_free_tab(tab);
}

void	ft_parse(char *map, t_matrix ***matrix, t_size *size)
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
		ft_parse_line(ft_split(line, ' '), matrix[i], i, size);
		i++;
		free(line);
	}
}
