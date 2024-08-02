/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:23:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 18:50:11 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_hex_to_int(char *hex_color)
{
	unsigned int	result;
	const char		*ptr = hex_color;

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
	ft_printf("X: %i\n", i);
	return (i);
}

int	ft_get_columns(char *map)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	line = get_next_line(open(map, O_RDONLY));
	tab = ft_split(line, ' ');
	free(line);
	while (tab[i])
		i++;
	ft_free_tab(tab);
	ft_printf("Y: %i\n", i);
	return (i);
}

t_matrix	***ft_malloc(char *map)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_matrix	***matrix;

	i = 0;
	x = ft_get_rows(map);
	y = ft_get_columns(map);
	matrix = (t_matrix ***)malloc(x * sizeof(t_matrix **));
	while (i < x)
	{
		j = 0;
		matrix[i] = (t_matrix **)malloc(y * sizeof(t_matrix *));
		while (j < y)
		{
			matrix[i][j] = (t_matrix *)malloc(1 * sizeof(t_matrix));
			j++;
		}
		i++;
	}
	return (matrix);
}

void	fdf(char *map)
{
	t_matrix	***matrix;

	matrix = ft_malloc(map);
	ft_parse(map, matrix);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fdf(argv[1]);
	else
		ft_printf("Try ./fdf [MAP NAME.fdf]\n");
	return (0);
}
