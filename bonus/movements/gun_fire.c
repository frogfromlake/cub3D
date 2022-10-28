/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_fire.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:35 by fquist            #+#    #+#             */
/*   Updated: 2022/07/05 17:27:30 by fquist           ###   ########.fr       */
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

void	gun_fire(t_data *game, int button)
{
	static clock_t	frame;

	if (game->gun_fire->enabled == true
		&& clock() - frame > CLOCKS_PER_SEC / 10)
	{
		game->gun_img->enabled = true;
		game->gun_fire->enabled = false;
	}
	if (button == 0)
	{
		if (clock() - frame > CLOCKS_PER_SEC / 5)
		{
			frame = clock();
			dying_condition(game);
			game->gun_img->enabled = false;
			game->gun_fire->enabled = true;
		}
	}
}
