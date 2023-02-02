/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:01:05 by fquist            #+#    #+#             */
/*   Updated: 2023/02/02 01:53:05 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	play_walk_sound(t_player *player, pid_t *pid, bool run)
{
	if (run && player->running)
	{
		mlx_stop_sound(pid[1]);
		mlx_start_sound(pid[2], "afplay ./bonus/audio/sprinting.mp3 &");
		pid[2] = mlx_get_pid("./bonus/audio/sprinting.mp3");
	}
	else
	{
		mlx_start_sound(pid[1], "afplay ./bonus/audio/running.mp3 &");
		pid[1] = mlx_get_pid("./bonus/audio/running.mp3");
	}
}

void	run(t_data *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		game->player.sprinting = true;
	else
	{
		game->player.sprinting = false;
		mlx_stop_sound(game->player.pid[2]);
	}
}