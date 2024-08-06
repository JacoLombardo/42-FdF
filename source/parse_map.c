/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:20:02 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/06 11:24:03 by jalombar         ###   ########.fr       */
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
	const char		*ptr = hex;

	result = 0;
	// Skip the "0x" prefix if present
	if (ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
		ptr += 2;
	// Iterate over each character in the string
	while (*ptr)
	{
		result *= 16;
		// Shift the current result left by 4 bits (multiply by 16)
		if (*ptr >= '0' && *ptr <= '9')
		{
			result += *ptr - '0';
		}
		else if (*ptr >= 'a' && *ptr <= 'f')
		{
			result += *ptr - 'a' + 10;
		}
		else if (*ptr >= 'A' && *ptr <= 'F')
		{
			result += *ptr - 'A' + 10;
		}
		else
		{
			// Handle invalid character
			break ;
		}
		ptr++;
	}
	return (result);
}

void	ft_parse_line(char **tab, t_matrix **matrix, int x)
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
			matrix[i]->color = 0;
		}
		i++;
	}
	ft_free_tab(tab);
}

void	ft_parse(char *map, t_matrix ***matrix)
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
		ft_parse_line(ft_split(line, ' '), matrix[i], i);
		i++;
		free(line);
	}
}
