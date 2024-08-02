/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:24:19 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 18:08:40 by jalombar         ###   ########.fr       */
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
	// struct s_list	*next;
}					t_matrix;

#endif