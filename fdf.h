/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgorun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:44:42 by cgorun            #+#    #+#             */
/*   Updated: 2018/02/11 16:14:40 by cgorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"
# include "get_next_line/libft/libft.h"

typedef struct	s_coords
{
	int			x;
	int			y;
	int			z;
	int			dotsnbr;
	int			lastonlinepoint;
}				t_coords;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	float		size;
	int			anglex;
	int			angley;
	int			anglez;
	int			r;
	int			mx;
	int			my;
	t_coords	*coords;
}				t_mlx;

typedef	struct	s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_line;

void			putline(t_line line, t_mlx *ptr, int color);
void			draw(t_coords *coords, t_mlx *ptr);
void			ft_to00(t_coords *coords, int *deltax, int *deltay);
void			ft_toorigin(t_coords *coords, int deltax, int deltay);
int				key_press(int keycode, t_mlx *mlx);
int				key_hook(int keycode, void *param);
void			ft_copycoords(t_coords *dest, t_coords *src);
int				ft_dotsnr(char *filename);
t_coords		*ft_read(char *filename);
t_line			linestructx(t_coords *coords);
t_line			linestructy(t_coords *coords, int points);
void			ft_setcoords(char *str, t_coords *coords, int y, int dotsnr);
void			ft_movecoords(t_coords *coords);
int				ft_onlinepoints(t_coords *coords);

#endif
