/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:22:15 by gohar             #+#    #+#             */
/*   Updated: 2022/07/04 17:54:21 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_fround(int mul, float num)
{
	float	f;

	f = (float)mul;
	f = f * num;
	if (f - (int)f > 0.5 && (int)(f + 1) < num)
		return ((int)(f + 1));
	return ((int)f);
}

static mlx_texture_t	*get_correct_tex(t_data *game, char wtype)
{
	if (wtype == 'N')
		return (game->imgs.tex_n);
	if (wtype == 'S')
		return (game->imgs.tex_s);
	if (wtype == 'E')
		return (game->imgs.tex_e);
	if (wtype == 'W')
		return (game->imgs.tex_w);
	return (0);
}

static uint32_t	get_texpixel(t_data *game, char wtype, float xrat, float yrat)
{
	mlx_texture_t	*tex;
	t_intpair		pixel_pos;
	uint32_t		color;
	uint8_t			*pixel_reader;

	tex = get_correct_tex(game, wtype);
	pixel_pos.x = ft_fround(tex->width, xrat);
	pixel_pos.y = ft_fround(tex->height, yrat);
	pixel_reader = tex->pixels;
	pixel_reader += (pixel_pos.y * tex->width) * tex->bytes_per_pixel;
	pixel_reader += pixel_pos.x * tex->bytes_per_pixel;
	color = create_trgb
		(*(pixel_reader + 0), *(pixel_reader + 1), *(pixel_reader + 2));
	return (color);
}

uint32_t	get_pixel(t_data *game, int x, int y)
{
	int		h;
	int		fac;
	float	x_rat;
	float	y_rat;

	h = game->wall_heights[x] + game->wall_heights[x];
	fac = (0.5 * (game->screen_height - h));
	if (y > fac && y < fac + h)
	{
		y_rat = (float)(y - fac) / h;
		x_rat = game->wall_shade[x];
		return (get_texpixel(game, game->wall_types[x], x_rat, y_rat));
	}
	else if (y > game->screen_height * 0.5)
		return (game->map.f_colour);
	else if (y < game->screen_height * 0.5)
		return (game->map.c_colour);
	return (0);
}

int	rendering_world(t_data *game)
{
	int			x;
	int			y;
	uint32_t	color;

	x = -1;
	while (++x < game->screen_width)
	{
		y = -1;
		while (++y < game->screen_height)
		{
			color = get_pixel(game, x, y);
			color = color << 8;
			mlx_put_pixel(game->main_img, x, y, 0xFF + color);
		}
	}
	return (1);
}
