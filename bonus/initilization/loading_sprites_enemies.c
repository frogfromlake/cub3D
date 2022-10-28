/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:47:56 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 18:40:42 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	load_enemy_pngs_3(t_data *game)
{
	game->imgs.enemy[14] = mlx_load_png("./textures/15.png");
	if (game->imgs.enemy[14] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[15] = mlx_load_png("./textures/16.png");
	if (game->imgs.enemy[15] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[16] = mlx_load_png("./textures/17.png");
	if (game->imgs.enemy[16] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[17] = mlx_load_png("./textures/18.png");
	if (game->imgs.enemy[17] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[18] = mlx_load_png("./textures/19.png");
	if (game->imgs.enemy[18] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[19] = mlx_load_png("./textures/20.png");
	if (game->imgs.enemy[19] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[20] = mlx_load_png("./textures/21.png");
	if (game->imgs.enemy[20] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
}

static void	load_enemy_pngs_2(t_data *game)
{
	game->imgs.enemy[7] = mlx_load_png("./textures/8.png");
	if (game->imgs.enemy[7] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[8] = mlx_load_png("./textures/9.png");
	if (game->imgs.enemy[8] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[9] = mlx_load_png("./textures/10.png");
	if (game->imgs.enemy[9] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[10] = mlx_load_png("./textures/11.png");
	if (game->imgs.enemy[10] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[11] = mlx_load_png("./textures/12.png");
	if (game->imgs.enemy[11] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[12] = mlx_load_png("./textures/13.png");
	if (game->imgs.enemy[12] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[13] = mlx_load_png("./textures/14.png");
	if (game->imgs.enemy[13] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	load_enemy_pngs_3(game);
}

static void	load_sprite_pngs_2(t_data *game)
{
	game->imgs.sprites[6] = mlx_load_png("./textures/p6.png");
	if (game->imgs.sprites[6] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[7] = mlx_load_png("./textures/p7.png");
	if (game->imgs.sprites[7] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[8] = mlx_load_png("./textures/ash.png");
	if (game->imgs.sprites[8] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
}

void	load_sprite_pngs(t_data *game)
{
	game->imgs.sprites[0] = mlx_load_png("./textures/rudi.png");
	if (game->imgs.sprites[0] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[1] = mlx_load_png("./textures/p1.png");
	if (game->imgs.sprites[1] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[2] = mlx_load_png("./textures/p2.png");
	if (game->imgs.sprites[2] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[3] = mlx_load_png("./textures/p3.png");
	if (game->imgs.sprites[3] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[4] = mlx_load_png("./textures/p4.png");
	if (game->imgs.sprites[4] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	game->imgs.sprites[5] = mlx_load_png("./textures/p5.png");
	if (game->imgs.sprites[5] == NULL)
		error(game, "\033[0;31mError: Couldn't load sprite textures.\033[m\n");
	load_sprite_pngs_2(game);
}

void	load_enemy_sprite_pngs(t_data *game)
{
	game->imgs.enemy[0] = mlx_load_png("./textures/1.png");
	if (game->imgs.enemy[0] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[1] = mlx_load_png("./textures/2.png");
	if (game->imgs.enemy[1] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[2] = mlx_load_png("./textures/3.png");
	if (game->imgs.enemy[2] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[3] = mlx_load_png("./textures/4.png");
	if (game->imgs.enemy[3] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[4] = mlx_load_png("./textures/5.png");
	if (game->imgs.enemy[4] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[5] = mlx_load_png("./textures/6.png");
	if (game->imgs.enemy[5] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	game->imgs.enemy[6] = mlx_load_png("./textures/7.png");
	if (game->imgs.enemy[6] == NULL)
		error(game, "\033[0;31mError: Couldn't load enemy textures.\033[m\n");
	load_enemy_pngs_2(game);
	load_sprite_pngs(game);
}
