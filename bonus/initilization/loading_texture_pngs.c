/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_menus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:24:39 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 18:31:04 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	load_menu_pngs(t_data *game)
{
	if (WIDTH == 1920 && HEIGHT == 1080)
	{
		game->imgs.gun = mlx_load_png("./textures/gun.png");
		game->imgs.start = mlx_load_png("./textures/fhd/start_fhd.png");
		game->imgs.win = mlx_load_png("./textures/fhd/win_fhd.png");
		game->imgs.lose = mlx_load_png("./textures/fhd/lose_fhd.png");
	}
	else if (WIDTH == 1600 && HEIGHT == 900)
	{
		game->imgs.gun = mlx_load_png("./textures/gun.png");
		game->imgs.start = mlx_load_png("./textures/hd+/start_hd+.png");
		game->imgs.win = mlx_load_png("./textures/hd+/win_hd+.png");
		game->imgs.lose = mlx_load_png("./textures/hd+/lose_hd+.png");
	}
}

void	load_texture_pngs(t_data *game)
{
	game->imgs.tex_n = mlx_load_png(game->map.paths[0]);
	if (game->imgs.tex_n == NULL)
		error (game, "\033[0;31mError: Texture NO: Path not found.\e[0m\n");
	game->imgs.tex_s = mlx_load_png(game->map.paths[1]);
	if (game->imgs.tex_s == NULL)
		error (game, "\033[0;31mError: Texture SO: Path not found.\e[0m\n");
	game->imgs.tex_e = mlx_load_png(game->map.paths[2]);
	if (game->imgs.tex_e == NULL)
		error (game, "\033[0;31mError: Texture EA: Path not found.\e[0m\n");
	game->imgs.tex_w = mlx_load_png(game->map.paths[3]);
	if (game->imgs.tex_w == NULL)
		error (game, "\033[0;31mError: Texture WE: Path not found.\e[0m\n");
	game->imgs.tex_p = mlx_load_png("./textures/portal.png");
	if (game->imgs.tex_p == NULL)
		error (game, "\033[0;31mError: Texture Portal: Path not found.\e[0m\n");
	game->imgs.gun_fire = mlx_load_png("./textures/gun_fire.png");
	if (game->imgs.tex_p == NULL)
		error (game, "\033[0;31mError: Texture Gun_fire: Path not found.\e[0m\n");
	game->imgs.crosshair = mlx_load_png("./textures/crosshair.png");
	if (game->imgs.tex_p == NULL)
		error (game, "\033[0;31mError: Texture Crosshair: Path not found.\e[0m\n");
	load_menu_pngs(game);
}
