/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:01:48 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:20:45 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static mlx_texture_t	*draw_minimap_textures(t_data *data,
	float rx, float ry)
{
	if (rx >= 0.0 && rx < data->m_x && ry >= 0.0 && ry < data->m_y)
	{
		if (data->map.map[(int)ry]
			[(int)rx] == '1')
			return (data->minimap.m_wall);
		else if (data->map.map[(int)ry]
			[(int)rx] == '0')
			return (data->minimap.m_background);
		else if (data->map.map[(int)ry]
			[(int)rx] == 'F')
			return (data->minimap.m_enemy);
		else if (data->map.map[(int)ry]
			[(int)rx] == 'P')
			return (data->minimap.m_portal);
		else if (data->map.map[(int)ry]
			[(int)rx] == '2')
			return (data->minimap.m_rudi);
		else if (is_sprite(data->map.map[(int)ry]
				[(int)rx], 2))
			return (data->minimap.m_sprite);
		else
			return (data->minimap.m_background);
	}
	else
		return (data->minimap.m_background);
}

static unsigned int	mypread(mlx_texture_t *data, int x, int y)
{
	unsigned char	*dst;

	if (data == NULL)
		return (0);
	dst = data->pixels + (y * data->width
			* data->bytes_per_pixel) + (x * data->bytes_per_pixel);
	if (dst > data->pixels + data->height * data->width * 4)
		return (0);
	return (create_trgb(*(dst + 0), *(dst + 1), *(dst + 2)));
}

static void	draw_mm_pixel(t_data *data, int x, int y)
{
	float			rx;
	float			ry;
	mlx_texture_t	*tile;
	unsigned int	color;

	rx = data->player.p_x - data->minimap.map_zoom
		+ ((2 * data->minimap.map_zoom)
			* ((float)x / (TILE_WIDTH * data->minimap.map_size)));
	ry = data->player.p_y - data->minimap.map_zoom
		+ ((2 * data->minimap.map_zoom)
			* ((float)y / (TILE_HEIGHT * data->minimap.map_size)));
	tile = draw_minimap_textures(data, rx, ry);
	if (rx < 0)
		rx = 1.0 + (rx - (int)rx);
	if (ry < 0)
		ry = 1.0 + (ry - (int)ry);
	color = mypread(tile, (rx - (int)rx) * TILE_WIDTH,
			(ry - (int)ry) * TILE_HEIGHT);
	color = color << 8;
	mlx_put_pixel(data->mm_img,
		(WIDTH - data->minimap.map_size * TILE_WIDTH) + x, y, 0xFF + color);
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_WIDTH * data->minimap.map_size)
	{
		j = 0;
		while (j < TILE_HEIGHT * data->minimap.map_size)
		{
			draw_mm_pixel(data, i, j);
			j++;
		}
		i++;
	}
}
