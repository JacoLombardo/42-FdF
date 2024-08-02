/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:19 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 19:25:45 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_matrix
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_matrix;

/* parse_map */
void				ft_free_tab(char **tab);
unsigned int		ft_hex_to_int(char *hex);
void				ft_parse_line(char **tab, t_matrix **matrix, int x);
void				ft_parse(char *map, t_matrix ***matrix);
t_matrix			***ft_malloc(char *map);

/* calculate_map */
int					ft_get_rows(char *map);
int					ft_get_columns(char *map);

/* fdf */
void				ft_free_matrix(t_matrix ***matrix);

#endif