/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:29:11 by gohar             #+#    #+#             */
/*   Updated: 2022/06/24 23:15:42 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	call_key_events(t_data *game, int param, bool rotation, char dir)
{
	if (rotation == false)
	{
		if (game->player.sprint_speed > 0)
			game->player.move_speed = PLAYER_SPEED + PLAYER_SPRINT_SPEED;
		if (dir == 'a')
			moveplayer_per(game, param, game->player.move_speed);
		if (dir == 'd')
			moveplayer_per(game, -param, game->player.move_speed);
		if (dir == 'f')
			moveplayer_par(game, param, game->player.move_speed);
		if (dir == 'b')
			moveplayer_par(game, -param, game->player.move_speed);
		if (dir == 'l')
		{
			moveplayer_par(game, param, -game->player.move_speed);
			moveplayer_par(game, param, game->player.move_speed);
		}
		if (dir == 'r')
		{
			moveplayer_par(game, param, -game->player.move_speed);
			moveplayer_par(game, param, game->player.move_speed);
		}
	}
	else if (rotation == true)
		rotdir(game, param);
}

static void	wasd(t_data *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_D)))
		call_key_events(game, 1, false, 'r');
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_A)))
		call_key_events(game, 1, false, 'l');
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		call_key_events(game, 1, false, 'f');
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		call_key_events(game, 1, false, 'b');
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		call_key_events(game, 1, false, 'a');
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		call_key_events(game, 1, false, 'd');
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		call_key_events(game, 1, true, 'f');
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		call_key_events(game, -1, true, 'f');
}

static void	init_hook_data(t_data *game)
{
	game->player.move_speed = PLAYER_SPEED;
	game->player.sprint_speed = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
			game->player.sprint_speed = PLAYER_SPRINT_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit_game(game);
}

void	hook(void *data)
{
	t_data	*game;

	game = (t_data *)data;
	init_hook_data(game);
	wasd(game);
	calculating_walls(game);
	rendering_world(game);
}
