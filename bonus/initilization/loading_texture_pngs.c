/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_texture_pngs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:24:39 by fquist            #+#    #+#             */
/*   Updated: 2023/02/03 21:02:46 by fquist           ###   ########.fr       */
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
		
	game->imgs.a0 = mlx_load_png("./textures/ammo/0.png");
	if (game->imgs.a0 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a1 = mlx_load_png("./textures/ammo/1.png");
	if (game->imgs.a1 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a2 = mlx_load_png("./textures/ammo/2.png");
	if (game->imgs.a2 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a3 = mlx_load_png("./textures/ammo/3.png");
	if (game->imgs.a3 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a4 = mlx_load_png("./textures/ammo/4.png");
	if (game->imgs.a4 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a5 = mlx_load_png("./textures/ammo/5.png");
	if (game->imgs.a5 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a6 = mlx_load_png("./textures/ammo/6.png");
	if (game->imgs.a6 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a7 = mlx_load_png("./textures/ammo/7.png");
	if (game->imgs.a7 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a8 = mlx_load_png("./textures/ammo/8.png");
	if (game->imgs.a8 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a9 = mlx_load_png("./textures/ammo/9.png");
	if (game->imgs.a9 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a10 = mlx_load_png("./textures/ammo/10.png");
	if (game->imgs.a10 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a11 = mlx_load_png("./textures/ammo/11.png");
	if (game->imgs.a11 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a12 = mlx_load_png("./textures/ammo/12.png");
	if (game->imgs.a12 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a13 = mlx_load_png("./textures/ammo/13.png");
	if (game->imgs.a13 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a14 = mlx_load_png("./textures/ammo/14.png");
	if (game->imgs.a14 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a15 = mlx_load_png("./textures/ammo/15.png");
	if (game->imgs.a15 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a16 = mlx_load_png("./textures/ammo/16.png");
	if (game->imgs.a16 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a17 = mlx_load_png("./textures/ammo/17.png");
	if (game->imgs.a17 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a18 = mlx_load_png("./textures/ammo/18.png");
	if (game->imgs.a18 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.a19 = mlx_load_png("./textures/ammo/19.png");
	if (game->imgs.a19 == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	game->imgs.reload = mlx_load_png("./textures/reload.png");
	if (game->imgs.reload == NULL)
		error (game, "\033[0;31mError: Texture: Path not found.\e[0m\n");
	
	load_menu_pngs(game);
}
