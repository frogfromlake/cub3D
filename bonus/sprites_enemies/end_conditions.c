/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:20:06 by fquist            #+#    #+#             */
/*   Updated: 2022/07/07 16:07:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

float	calc_disp(float x1, float x2, float y1, float y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

void	end_condition(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		if (calc_disp(game->enemy[i].pos.x, game->player.p_x,
				game->enemy[i].pos.y, game->player.p_y) < 0.1)
		{
			if (game->enemy[i].type == FOE && game->enemy[i].dead == false)
				game->lose = true;
			else if (game->enemy[i].type == RUDI)
				game->win = true;
		}
		i++;
	}
}
