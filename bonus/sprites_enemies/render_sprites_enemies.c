/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_enemies.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:41:57 by fquist            #+#    #+#             */
/*   Updated: 2022/07/05 17:20:14 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

unsigned int	mlx_pixel_read(mlx_texture_t *data, int x, int y)
{
	unsigned char	*dst;

	dst = data->pixels + (y * (data->width * 4) + x * data->bytes_per_pixel);
	if (dst > data->pixels + data->height * data->width * 4)
		return (0);
	return (*(unsigned int *)dst);
}

static void	draw_stripe(t_data *game, int i)
{
	int				d;
	int				y;
	unsigned int	color;

	get_tex_x(game, i);
	if (game->enemy[i].transf.y > 0 && game->enemy->stripe > 0
		&& game->enemy->stripe < WIDTH && game->enemy[i].transf.y
		< game->perp_wall_dist_s[game->enemy->stripe])
	{
		y = game->enemy[i].start.y;
		while (y < game->enemy[i].end.y)
		{
			d
				= (y - game->enemy[i].move_screen - game->mouse.pitch)
				* 256 - HEIGHT * 128 + game->enemy[i].height * 128;
			game->enemy->tex.y
				= (((d * game->enemy[i].texture->height)
						/ game->enemy[i].height) / 256);
			color = mlx_pixel_read(game->enemy[i].texture,
					game->enemy->tex.x, game->enemy->tex.y);
			get_sprite_pixels(game, i, color, y);
			y++;
		}
	}
}

void	get_enemy_texture(t_data *game, int i)
{
	if (game->enemy[i].type == FOE)
	{
		game->enemy[i].texture
			= game->imgs.enemy[game->enemy[i].enemy_frame / 10];
		if (game->enemy[i].dead == true)
			game->enemy[i].texture = game->imgs.sprites[8];
		if (game->enemy->ray_hit == true)
		{
			game->enemy[i].enemy_frame += 10;
			if (game->enemy[i].enemy_frame == 210)
				game->enemy[i].enemy_frame = 0;
		}
	}
	set_sprite_textures(game, i);
}

void	render_enemy(t_data *game, int i)
{
	game->enemy->stripe = game->enemy[i].start.x;
	while (game->enemy->stripe < game->enemy[i].end.x)
	{	
		draw_stripe(game, i);
		game->enemy->stripe++;
	}
}
