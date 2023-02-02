/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:29:11 by gohar             #+#    #+#             */
/*   Updated: 2023/02/02 02:19:34 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	minimap_handler(t_data *game);
void	init_hook_data(t_data *game);

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
		{
		call_key_events(game, 1, false, 'r');
			play_walk_sound(&game->player, game->player.pid, true);
		}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_A)))
		{
		call_key_events(game, 1, false, 'l');
			play_walk_sound(&game->player, game->player.pid, true);
		}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		call_key_events(game, 1, false, 'f');
		play_walk_sound(&game->player, game->player.pid, true);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		call_key_events(game, 1, false, 'b');
		play_walk_sound(&game->player, game->player.pid, true);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		call_key_events(game, 1, false, 'a');
		play_walk_sound(&game->player, game->player.pid, true);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		call_key_events(game, 1, false, 'd');
		play_walk_sound(&game->player, game->player.pid, true);
	}
	else if (!mlx_is_key_down(game->mlx, MLX_KEY_W) && !mlx_is_key_down(game->mlx, MLX_KEY_A)
			&& !mlx_is_key_down(game->mlx, MLX_KEY_S) && !mlx_is_key_down(game->mlx, MLX_KEY_D))
		mlx_stop_sound(game->player.pid[1]);
}

void	arrow_key_camera(t_data *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		call_key_events(game, 1, true, 'f');
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		call_key_events(game, -1, true, 'f');
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->mouse.pitch += 500 * game->mouse.rotation_speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->mouse.pitch -= 500 * game->mouse.rotation_speed;
}

static void	hook_routine(t_data *game)
{
	win_handler(game);
	wasd(game);
	reset_handler(game);
	arrow_key_camera(game);
	move_enemy(game);
	calculating_walls(game);
	rendering_world(game);
	rendering_enemies_and_sprites(game);
	end_condition(game);
	minimap_handler(game);
}

void	key_hook(void *data)
{
	t_data	*game;
	clock_t	begin_frame;
	clock_t	end_frame;

	game = (t_data *)data;
	init_hook_data(game);
	if (game->lose == false)
	{
		begin_frame = clock();
		hook_routine(game);
		end_frame = clock();
		game->fps_val = CLOCKS_PER_SEC / ((end_frame - begin_frame));
		if (game->time_count - timer(game) == 0)
			game->lose = true;
	}
	else
		lose_handler(game);
}
