/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemies_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:52:24 by fquist            #+#    #+#             */
/*   Updated: 2022/06/28 17:56:13 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	sort_enemies(t_data *game)
{
	int		x;
	int		y;
	t_enemy	tmp;

	x = 0;
	while (x < game->sprite_count - 1)
	{
		y = 0;
		while (y < game->sprite_count - x - 1)
		{
			if (game->enemy[y].distance
				< game->enemy[y + 1].distance)
			{
				tmp = game->enemy[y];
				game->enemy[y]
					= game->enemy[y + 1];
				game->enemy[y + 1] = tmp;
			}
			y++;
		}
		x++;
	}
}

void	get_enemy_distance(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		game->enemy[i].distance
			= ((int)game->player.p_x - game->enemy[i].pos.x)
			* (game->player.p_x - game->enemy[i].pos.x)
			+ (game->player.p_y - game->enemy[i].pos.y)
			* (game->player.p_y - game->enemy[i].pos.y);
		i++;
	}
}

void	set_sprite_textures(t_data *game, int i)
{
	if (game->enemy[i].type == RUDI)
		game->enemy[i].texture = game->imgs.sprites[0];
	else if (game->enemy[i].type == P1)
		game->enemy[i].texture = game->imgs.sprites[1];
	else if (game->enemy[i].type == P2)
		game->enemy[i].texture = game->imgs.sprites[2];
	else if (game->enemy[i].type == P3)
		game->enemy[i].texture = game->imgs.sprites[3];
	else if (game->enemy[i].type == P4)
		game->enemy[i].texture = game->imgs.sprites[4];
	else if (game->enemy[i].type == P5)
		game->enemy[i].texture = game->imgs.sprites[5];
	else if (game->enemy[i].type == P6)
		game->enemy[i].texture = game->imgs.sprites[6];
	else if (game->enemy[i].type == P7)
		game->enemy[i].texture = game->imgs.sprites[7];
}

void	get_sprite_pixels(t_data *game, int i, unsigned int color, int y)
{
	if (game->enemy[i].type == FOE && color != 0)
	{
		color = color << 8;
		mlx_put_pixel(game->main_img, game->enemy->stripe, y, 0xFF + color);
	}
	else if (game->enemy[i].type != FOE && game->enemy[i].type != RUDI
		&& color != 0)
	{
		color = color << 8;
		mlx_put_pixel(game->main_img, game->enemy->stripe, y, 0xFF + color);
	}
	else if (game->enemy[i].type == RUDI && color != 0)
		mlx_put_pixel(game->main_img, game->enemy->stripe, y, 0xFF + color);
}

void	get_tex_x(t_data *game, int i)
{
	game->enemy->tex.x
		= (int)((256 * (game->enemy->stripe - (-(game->enemy[i].width)
						/ 2 + game->enemy[i].screen.x))
				* game->enemy[i].texture->width
				/ game->enemy[i].width) / 256);
}
