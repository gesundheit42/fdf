/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:55:10 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/11 16:19:02 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_dotsnr(char *filename)
{
	int		fd;
	int		i;
	char	symbol;
	int		lastspace;

	lastspace = 1;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &symbol, 1))
	{
		if (ft_isdigit(symbol) && lastspace == 1)
		{
			lastspace = 0;
			i++;
		}
		else
			lastspace = 1;
	}
	close(fd);
	return (i);
}

t_coords	*ft_read(char *filename)
{
	t_coords	*coords;
	int			fd;
	char		*str;
	int			i;
	int			dotsnr;

	i = 0;
	dotsnr = ft_dotsnr(filename);
	coords = malloc(sizeof(t_coords) * (dotsnr));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_setcoords(str, coords, i, dotsnr);
		i++;
	}
	ft_strdel(&str);
	close(fd);
	return (coords);
}

int			ft_onlinepoints(t_coords *coords)
{
	int	i;

	i = 0;
	while (coords[i].lastonlinepoint == 0)
		i++;
	return (i + 1);
}

void		ft_copycoords(t_coords *dest, t_coords *src)
{
	int	i;

	i = 0;
	while (i < src[0].dotsnbr)
	{
		dest[i] = src[i];
		i++;
	}
}
