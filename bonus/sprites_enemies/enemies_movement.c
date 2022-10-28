/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:29:00 by fquist            #+#    #+#             */
/*   Updated: 2022/07/05 23:16:12 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static int	check_valid_move(t_data *game, float new_x, float new_y)
{
	if (is_occupied(game->map.map[(int)(new_y + 0.1)][(int)(new_x + 0.1)]) == 1)
		return (1);
	if (is_occupied(game->map.map[(int)(new_y - 0.1)][(int)(new_x - 0.1)]) == 1)
		return (1);
	if (is_occupied(game->map.map[(int)(new_y - 0.1)][(int)(new_x + 0.1)]) == 1)
		return (1);
	if (is_occupied(game->map.map[(int)(new_y + 0.1)][(int)(new_x - 0.1)]) == 1)
		return (1);
	return (0);
}

static void	calc_new_pos(t_data *game, int i)
{
	if ((game->player.p_x - game->enemy[i].pos.x) < ENEMY_SPEED
		&& (game->player.p_x - game->enemy[i].pos.x) > -ENEMY_SPEED)
		game->enemy[i].direction.x = 0;
	else if ((game->player.p_x - game->enemy[i].pos.x) < 0)
		game->enemy[i].direction.x = -1;
	else if ((game->player.p_x - game->enemy[i].pos.x) > 0)
		game->enemy[i].direction.x = 1;
	if ((game->player.p_y - game->enemy[i].pos.y) < ENEMY_SPEED
		&& (game->player.p_y - game->enemy[i].pos.y) > -ENEMY_SPEED)
		game->enemy[i].direction.y = 0;
	else if ((game->player.p_y - game->enemy[i].pos.y) > 0)
		game->enemy[i].direction.y = 1;
	else if ((game->player.p_y - game->enemy[i].pos.y) < 0)
		game->enemy[i].direction.y = -1;
	if (game->enemy[i].direction.x != 0)
		game->enemy[i].pos.x = game->enemy[i].pos.x
			+ ((ENEMY_SPEED) * game->enemy[i].direction.x);
	if (game->enemy[i].direction.y != 0)
		game->enemy[i].pos.y = game->enemy[i].pos.y
			+ ((ENEMY_SPEED) * game->enemy[i].direction.y);
}

static void	get_new_pos_enemy(t_data *game, int i)
{
	while (1)
	{
		if (check_valid_move(game, game->enemy[i].pos.x,
				game->enemy[i].pos.y) != 1 && game->enemy->ray_hit == true)
			calc_new_pos(game, i);
		else if (game->enemy->ray_hit == true)
		{
			if (game->enemy[i].direction.x != 0)
				game->enemy[i].pos.x = game->enemy[i].pos.x
					+ ((ENEMY_SPEED) * (game->enemy[i].direction.x * -1));
			if (game->enemy[i].direction.y != 0)
				game->enemy[i].pos.y = game->enemy[i].pos.y
					+ ((ENEMY_SPEED) * (game->enemy[i].direction.y * -1));
		}
		return ;
	}
}

static int	check_moveability(t_data *game, int i)
{
	t_intpair	pos;

	pos.x = (int)game->enemy[i].pos.x;
	pos.y = (int)game->enemy[i].pos.y;
	if (!is_occupied(game->map.map[pos.y - 1][(pos.x)]))
		return (1);
	if (!is_occupied(game->map.map[pos.y - 1][pos.x - 1]))
		return (1);
	if (!is_occupied(game->map.map[pos.y + 1][pos.x + 1]))
		return (1);
	if (!is_occupied(game->map.map[pos.y + 1][pos.x - 1]))
		return (1);
	if (!is_occupied(game->map.map[pos.y - 1][pos.x + 1]))
		return (1);
	if (!is_occupied(game->map.map[pos.y + 1][(pos.x)]))
		return (1);
	if (!is_occupied(game->map.map[pos.y][(pos.x + 1)]))
		return (1);
	return (0);
}

void	move_enemy(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		if (game->enemy[i].type == FOE && game->enemy[i].dead == false)
		{
			if (check_moveability(game, i))
			{
				get_new_pos_enemy(game, i);
			}
		}
		i++;
	}
}
