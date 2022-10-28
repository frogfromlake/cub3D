/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:08:23 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:35:46 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	set_portal_data(t_data *data, int x, int y)
{	
	if (data->map.map[y][x] == 'P')
	{
		data->portal[data->portal->portal_nbr].pos.x = x;
		data->portal[data->portal->portal_nbr].pos.y = y;
	}
}

void	set_sprite_type(t_data *game, char c)
{
	if (c == '2')
		game->enemy[game->sprite_count].type = RUDI;
	else if (c == '3')
		game->enemy[game->sprite_count].type = P1;
	else if (c == '4')
		game->enemy[game->sprite_count].type = P2;
	else if (c == '5')
		game->enemy[game->sprite_count].type = P3;
	else if (c == '6')
		game->enemy[game->sprite_count].type = P4;
	else if (c == '7')
		game->enemy[game->sprite_count].type = P5;
	else if (c == '8')
		game->enemy[game->sprite_count].type = P6;
	else if (c == '9')
		game->enemy[game->sprite_count].type = P7;
}

void	parse_sprites(char c, t_data *data, int x, int y)
{
	if (data->sprite_count > 150)
		error(data, "\033[0;31mError: More than 150 sprites.\e[0m\n");
	else if (c == 'F')
	{
		data->enemy[data->sprite_count].type = FOE;
		data->enemy[data->sprite_count].pos.x = x + 0.5;
		data->enemy[data->sprite_count].pos.y = y + 0.5;
		data->enemy[data->sprite_count].init_pos.x
			= data->enemy[data->sprite_count].pos.x;
		data->enemy[data->sprite_count].init_pos.y
			= data->enemy[data->sprite_count].pos.y;
	}
	else if (c == '2' || c == '3' || c == '4'
		|| c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
	{
		set_sprite_type(data, c);
		data->enemy[data->sprite_count].pos.x = x + 0.15;
		data->enemy[data->sprite_count].pos.y = y + 0.15;
	}
	data->enemy[data->sprite_count].direction.x = 0;
	data->enemy[data->sprite_count].direction.y = 0;
	data->sprite_count += 1;
}
