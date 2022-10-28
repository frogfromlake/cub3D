/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_left_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:32:13 by fquist            #+#    #+#             */
/*   Updated: 2022/07/04 17:56:01 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	portal_order(t_data *game, int i)
{
	if (i + 1 <= game->portal->portal_nbr
		&& game->portal->reverse == false)
	{
		game->portal->modifier = 1;
		check_portal_exit_move(game, i, game->portal->modifier);
	}
	else
	{
		game->portal->reverse = true;
		game->portal->modifier = -1;
		if (i - 1 < 1)
		{
			game->portal->modifier = 1;
			game->portal->reverse = false;
		}
		check_portal_exit_move(game, i, game->portal->modifier);
	}
}

void	portal_move(t_data *game)
{
	int	i;

	i = 0;
	while (++i <= game->portal->portal_nbr)
	{
		if (get_portal(game, i) == true)
		{
			portal_order(game, i);
			break ;
		}
	}
}

// left right
void	moveplayer_per(t_data *game, int p, float move_speed)
{
	game->player.old_x = game->vec.x;
	game->player.old_y = game->vec.y;
	game->player.move_speed = (move_speed + game->player.sprint_speed) * p;
	game->vec.y = game->player.p_y + game->player.dir.x
		* -game->player.move_speed;
	game->vec.x = game->player.p_x - game->player.dir.y
		* game->player.move_speed;
	if (game->map.map[(int)(game->vec.y - 0.1)][(int)game->vec.x] == 'P'
		|| game->map.map[(int)game->vec.y][(int)(game->vec.x + 0.1)] == 'P'
		|| game->map.map[(int)game->vec.y][(int)(game->vec.x - 0.1)] == 'P')
		portal_move(game);
	else if (game->map.map[(int)game->vec.y][(int)game->vec.x] != '1'
		&& game->map.map[(int)game->vec.y][(int)game->vec.x] != 'P'
		&& game->map.map[(int)(game->vec.y + 0.1)][(int)(game->vec.x + 0.1)]
			!= '1'
		&& game->map.map[(int)(game->vec.y - 0.1)][(int)(game->vec.x - 0.1)]
			!= '1'
		&& game->map.map[(int)(game->vec.y + 0.1)][(int)(game->vec.x + 0.1)]
			!= 'P'
		&& game->map.map[(int)(game->vec.y - 0.1)][(int)(game->vec.x - 0.1)]
			!= 'P')
	{
		game->player.p_x = game->vec.x;
		game->player.p_y = game->vec.y;
	}
}
