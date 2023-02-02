/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_fire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:35 by fquist            #+#    #+#             */
/*   Updated: 2023/02/02 04:22:08 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	dying_condition(t_data *game)
{
	int	i;

	i = -1;
	while (++i < game->sprite_count)
	{
		if (game->enemy[i].start.x < WIDTH * 0.5
			&& game->enemy[i].end.x > WIDTH * 0.5
			&& game->enemy[i].start.y < HEIGHT * 0.5
			&& game->enemy[i].end.y > HEIGHT * 0.5)
		{
			game->enemy[i].hit++;
			if (game->enemy[i].hit == 5)
				game->enemy[i].dead = true;
			i++;
		}
	}
}

static void	ammo_count(t_data *game)
{
	if (game->player.ammo == 19)
	{
		game->a17->enabled = true;
		game->a18->enabled = false;
	}
	else if (game->player.ammo == 18)
	{
		game->a16->enabled = true;
		game->a17->enabled = false;
	}
	else if (game->player.ammo == 17)
	{
		game->a15->enabled = true;
		game->a16->enabled = false;
	}
	else if (game->player.ammo == 16)
	{
		game->a14->enabled = true;
		game->a15->enabled = false;
	}
	else if (game->player.ammo == 15)
	{
		game->a13->enabled = true;
		game->a14->enabled = false;
	}
	else if (game->player.ammo == 14)
	{
		game->a12->enabled = true;
		game->a13->enabled = false;
	}
	else if (game->player.ammo == 13)
	{
		game->a11->enabled = true;
		game->a12->enabled = false;
	}
	else if (game->player.ammo == 12)
	{
		game->a10->enabled = true;
		game->a11->enabled = false;
	}
	else if (game->player.ammo == 11)
	{
		game->a9->enabled = true;
		game->a10->enabled = false;
	}
	else if (game->player.ammo == 10)
	{
		game->a8->enabled = true;
		game->a9->enabled = false;
	}
	else if (game->player.ammo == 9)
	{
		game->a7->enabled = true;
		game->a8->enabled = false;
	}
	else if (game->player.ammo == 8)
	{
		game->a6->enabled = true;
		game->a7->enabled = false;
	}
	else if (game->player.ammo == 7)
	{
		game->a5->enabled = true;
		game->a6->enabled = false;
	}
	else if (game->player.ammo == 6)
	{
		game->a4->enabled = true;
		game->a5->enabled = false;
	}
	else if (game->player.ammo == 5)
	{
		game->a3->enabled = true;
		game->a4->enabled = false;
	}
	else if (game->player.ammo == 4)
	{
		game->a2->enabled = true;
		game->a3->enabled = false;
	}
	else if (game->player.ammo == 3)
	{
		game->a1->enabled = true;
		game->a2->enabled = false;
	}
	else if (game->player.ammo == 2)
	{
		game->a0->enabled = true;
		game->a1->enabled = false;
	}
	else if (game->player.ammo == 1)
	{
		game->a0->enabled = false;
	}
}

void	gun_fire(t_data *game, int button)
{
	static clock_t	frame;

	if (game->gun_fire->enabled == true
		&& clock() - frame > CLOCKS_PER_SEC / 10)
	{
		game->gun_img->enabled = true;
		game->gun_fire->enabled = false;
		mlx_stop_sound(game->player.pid[3]);
	}
	if (button == 0)
	{
		if (clock() - frame > CLOCKS_PER_SEC / 5 && game->player.ammo > 0)
		{
			frame = clock();
			dying_condition(game);
			game->gun_img->enabled = false;
			game->gun_fire->enabled = true;
			if (game->main_img->enabled == true)
			{
				mlx_start_sound(0, "afplay -v 0.6 ./bonus/audio/Gun.mp3 &");
				game->player.ammo--;
				ammo_count(game);
			}
		}
	}
}
