/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:57:59 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:27:59 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

// draws the textures regarding player orientation.
// (!CHANGE: only north direction for wasd keys. Arrow keys handle rotation.)
void	minimap_movement_textures(t_data *data, int x_tile, int y_tile)
{
	if (data->player.p_dir == NORTH)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_n,
			x_tile, y_tile);
	if (data->player.p_dir == NE)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_ne,
			x_tile, y_tile);
	if (data->player.p_dir == EAST)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_e,
			x_tile, y_tile);
	if (data->player.p_dir == SE)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_se,
			x_tile, y_tile);
	if (data->player.p_dir == SOUTH)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_s,
			x_tile, y_tile);
	if (data->player.p_dir == SW)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_sw,
			x_tile, y_tile);
	if (data->player.p_dir == WEST)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_w,
			x_tile, y_tile);
	if (data->player.p_dir == NW)
		mlx_draw_texture(data->mm_img, data->minimap.m_player_nw,
			x_tile, y_tile);
}

void	draw_player_movement(t_data	*data)
{
	int	mini_x;
	int	mini_y;

	mini_x = (WIDTH - data->minimap.map_size * TILE_WIDTH)
		+ (data->minimap.map_size * 0.5 * TILE_WIDTH) - TILE_WIDTH / 2;
	mini_y = (data->minimap.map_size * 0.5 * TILE_HEIGHT);
	minimap_movement_textures(data, mini_x, mini_y);
}
