/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprites_enemies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:46:52 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 18:59:36 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	get_enemy_dimension(t_data *game, int i)
{
	game->enemy[i].move_screen = (int)(V_MOVE / game->enemy[i].transf.y);
	game->enemy[i].height
		= fabs((int)(HEIGHT / game->enemy[i].transf.y) / V_DIV);
	game->enemy[i].start.y = (-game->enemy[i].height / 2 + HEIGHT / 2
			+ game->enemy[i].move_screen + game->mouse.pitch);
	if (game->enemy[i].start.y < 0)
		game->enemy[i].start.y = 0;
	game->enemy[i].end.y = (game->enemy[i].height / 2 + HEIGHT / 2
			+ game->enemy[i].move_screen + game->mouse.pitch);
	if (game->enemy[i].end.y >= HEIGHT)
		game->enemy[i].end.y = HEIGHT - 1;
	game->enemy[i].width
		= fabs((int)(HEIGHT / game->enemy[i].transf.y) / U_DIV);
	game->enemy[i].start.x
		= (-game->enemy[i].width / 2 + game->enemy[i].screen.x);
	if (game->enemy[i].start.x < 0)
		game->enemy[i].start.x = 0;
	game->enemy[i].end.x = (game->enemy[i].width / 2 + game->enemy[i].screen.x);
	if (game->enemy[i].end.x >= WIDTH)
		game->enemy[i].end.x = WIDTH - 1;
}

static void	get_enemy_pos(t_data *game, int i)
{
	t_vec	enemy_pos;
	float	inv_det;

	enemy_pos.x = game->enemy[i].pos.x
		- game->player.p_x;
	enemy_pos.y = game->enemy[i].pos.y
		- game->player.p_y;
	inv_det = 1.0 / (game->camera.plane.x * game->player.dir.y
			- game->player.dir.x * game->camera.plane.y);
	game->enemy[i].transf.x = (inv_det * (game->player.dir.y * enemy_pos.x
				- game->player.dir.x * (enemy_pos.y * -1)));
	game->enemy[i].transf.y = (inv_det * (-game->camera.plane.y * enemy_pos.x
				+ game->camera.plane.x * (enemy_pos.y * -1)));
	game->enemy[i].screen.x = (int)((WIDTH / 2)
			* (1 + game->enemy[i].transf.x / game->enemy[i].transf.y));
}

void	rendering_enemies_and_sprites(t_data *game)
{
	int		i;

	get_enemy_distance(game);
	sort_enemies(game);
	i = 0;
	while (i < game->sprite_count)
	{
		get_enemy_pos(game, i);
		get_enemy_dimension(game, i);
		get_enemy_texture(game, i);
		render_enemy(game, i);
		i++;
	}
}
