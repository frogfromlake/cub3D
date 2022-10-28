/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_forward_backward.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:32:13 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 20:42:36 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

bool	get_portal(t_data *game, int i)
{
	if (((int)(game->player.p_x + 1) == (int)(game->portal[i].pos.x)
		&& (int)(game->player.p_y) == (int)(game->portal[i].pos.y))
		|| ((int)(game->player.p_x - 1) == (int)(game->portal[i].pos.x)
		&& (int)(game->player.p_y) == (int)(game->portal[i].pos.y))
		|| ((int)(game->player.p_x) == (int)(game->portal[i].pos.x)
		&& (int)(game->player.p_y + 1) == (int)(game->portal[i].pos.y))
		|| ((int)(game->player.p_x) == (int)(game->portal[i].pos.x)
		&& (int)(game->player.p_y) - 1 == (int)(game->portal[i].pos.y)))
		return (true);
	else
		return (false);
}

static void	check_portal_exit_move_2(t_data *game, int i, int modifier)
{
	if (game->map.map[(int)(game->portal[i + modifier].pos.y + 1.5)]
		[(int)(game->portal[i + modifier].pos.x + 0.5)] != '1'
		&& game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x - 0.5)] != ' ')
	{
		game->player.p_x = game->portal[i + modifier].pos.x + (0.5);
		game->player.p_y = game->portal[i + modifier].pos.y + (1.5);
		game->player.dir = (t_vec){0.0, -1.0};
		game->player.p_dir = SOUTH;
	}
	else if ((game->map.map[(int)(game->portal[i + modifier].pos.y - 0.5)]
		[(int)(game->portal[i + modifier].pos.x + 0.5)] != '1')
		&& game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x - 0.5)] != ' ')
	{
		game->player.p_x = game->portal[i + modifier].pos.x + 0.5;
		game->player.p_y = game->portal[i + modifier].pos.y - 0.5;
		game->player.dir = (t_vec){0.0, 1.0};
		game->player.p_dir = NORTH;
	}
}

void	check_portal_exit_move(t_data *game, int i, int modifier)
{
	if (game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x - 0.5)] != '1'
		&& game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x - 0.5)] != ' ')
	{
		game->player.p_x = game->portal[i + modifier].pos.x - (0.5);
		game->player.p_y = game->portal[i + modifier].pos.y + (0.5);
		game->player.dir = (t_vec){-1.0, 0.0};
		game->player.p_dir = EAST;
	}
	else if (game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x + 1.5)] != '1'
		&& game->map.map[(int)(game->portal[i + modifier].pos.y + 0.5)]
		[(int)(game->portal[i + modifier].pos.x - 0.5)] != ' ')
	{
		game->player.p_x = game->portal[i + modifier].pos.x + (1.5);
		game->player.p_y = game->portal[i + modifier].pos.y + (0.5);
		game->player.dir = (t_vec){-1.0, 0.0};
		game->player.p_dir = WEST;
	}
	check_portal_exit_move_2(game, i, modifier);
}

static void	calculating_player_pos(t_data *game, int p, float move_speed)
{
	game->player.old_x = game->vec.x;
	game->player.old_y = game->vec.y;
	game->player.move_speed = (move_speed + game->player.sprint_speed) * p;
	game->vec.x = game->player.p_x + game->player.dir.x
		* game->player.move_speed;
	game->vec.y = game->player.p_y + game->player.dir.y
		* -game->player.move_speed;
}

// forward backward
void	moveplayer_par(t_data *game, int p, float move_speed)
{
	calculating_player_pos(game, p, move_speed);
	if (game->map.map[(int)(game->vec.y - 0.1)][(int)game->vec.x] == 'P'
		|| game->map.map[(int)game->vec.y][(int)(game->vec.x + 0.1)] == 'P'
		|| game->map.map[(int)game->vec.y][(int)(game->vec.x - 0.1)] == 'P'
		|| game->map.map[(int)(game->vec.y + 0.1)][(int)(game->vec.x)] == 'P')
		portal_move(game);
	if (game->map.map[(int)game->vec.y][(int)game->vec.x] != '1'
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
