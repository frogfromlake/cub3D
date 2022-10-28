/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:01:13 by fquist            #+#    #+#             */
/*   Updated: 2022/07/08 00:21:43 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	set_images(t_data *game)
{
	game->counter->enabled = true;
	game->fps->enabled = true;
	game->crosshair->enabled = true;
	game->runtime = 0;
	game->main_img->enabled = true;
	game->gun_img->enabled = true;
	game->lose_img->enabled = false;
	game->gun_fire->enabled = false;
	game->start_img->enabled = false;
	game->win = false;
	game->win_img->enabled = false;
}

void	reset_handler(t_data *game)
{
	int		i;

	i = -1;
	if (game->reset == true)
	{
		set_images(game);
		moveplayer_per(game, 0, game->player.move_speed);
		while (++i < game->sprite_count)
		{
			if (game->enemy[i].type == FOE)
			{
				game->enemy[i].dead = false;
				game->enemy[i].hit = 0;
				game->enemy[i].pos.x = game->enemy[i].init_pos.x;
				game->enemy[i].pos.y = game->enemy[i].init_pos.y;
			}
		}
		game->reset = false;
	}
}

void	win_handler(t_data *game)
{
	if (game->player.firing == false)
	{
		game->gun_img->enabled = true;
		game->gun_fire->enabled = false;
	}
	if (game->win == true)
	{
		game->win_img->enabled = true;
		game->counter->enabled = false;
		game->fps->enabled = false;
		game->crosshair->enabled = false;
		game->main_img->enabled = false;
		game->gun_img->enabled = false;
		game->gun_fire->enabled = false;
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	}
}

void	lose_handler(t_data *game)
{
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	game->counter->enabled = false;
	game->fps->enabled = false;
	game->lose_img->enabled = true;
	game->main_img->enabled = false;
	game->crosshair->enabled = false;
	game->gun_img->enabled = false;
	game->gun_fire->enabled = false;
}

void	minimap_handler(t_data *game)
{
	draw_minimap(game);
	draw_player_movement(game);
}
