/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:49 by fquist            #+#    #+#             */
/*   Updated: 2023/02/02 01:56:05 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	minimap_zoom_hook(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_M))
	{
		game->minimap.map_size = WIDTH / (2 * TILE_WIDTH);
		game->minimap.map_zoom = 12;
	}
	else
	{
		game->minimap.map_size = 15;
		game->minimap.map_zoom = 6;
		while (++i < WIDTH)
		{
			j = -1;
			while (++j < HEIGHT)
				mlx_put_pixel(game->mm_img, i, j, 0);
		}
	}
}

void	init_hook_data(t_data *game)
{
	game->player.move_speed = PLAYER_SPEED;
	game->player.sprinting = false;
	game->player.sprint_speed = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		game->player.sprinting = true;
		game->player.sprint_speed = PLAYER_SPRINT_SPEED;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_TAB))
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
		return ;
	}
	else if (game->main_img->enabled == true)
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_SPACE))
	{
		event_mouse_press(game, MLX_MOUSE_BUTTON_LEFT,
			game->mouse.x_new, game->mouse.y_new);
		game->player.firing = true;
	}
	else
		game->player.firing = false;
	minimap_zoom_hook(game);
}
