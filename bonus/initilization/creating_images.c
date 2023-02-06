/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:34:56 by fquist            #+#    #+#             */
/*   Updated: 2023/02/06 21:34:20 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	create_images_2(t_data *game)
{
	game->gun_img = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->gun_img == NULL)
		error (game, "\033[0;31mError: Allocation for gun_img"
			" returned Null.\e[0m\n");
	game->gun_fire = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->gun_fire == NULL)
		error (game, "\033[0;31mError: Allocation for gun_fire"
			" returned Null.\e[0m\n");
	game->crosshair = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->crosshair == NULL)
		error (game, "\033[0;31mError: Allocation for crosshair"
			" returned Null.\e[0m\n");
	game->counter = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->counter == NULL)
		error (game, "\033[0;31mError: Allocation for counter"
			" returned Null.\e[0m\n");
	game->fps = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->fps == NULL)
		error (game, "\033[0;31mError: Allocation for fps"
			" returned Null.\e[0m\n");
	
	game->a0 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a0 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a1 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a1 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a2 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a2 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a3 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a3 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a4 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a4 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a5 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a5 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a6 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a6 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a7 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a7 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a8 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a8 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a9 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a9 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a10 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a10 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a11 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a11 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a12 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a12 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a13 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a13 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a14 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a14 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a15 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a15 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a16 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a16 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a17 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a17 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a18 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a18 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->a19 = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->a19 == NULL)
		error (game, "\033[0;31mError: Allocation for ammo_img returned Null.\e[0m\n");
	game->reload = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->reload == NULL)
		error (game, "\033[0;31mError: Allocation for reload_img returned Null.\e[0m\n");
}

void	create_images(t_data *game)
{
	game->mlx = mlx_init
		(WIDTH, HEIGHT, "cub3D", true);
	if (game->mlx == NULL)
		error (game, "\033[0;31mError: MLX Init returned Null.\e[0m\n");
	game->main_img = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->main_img == NULL)
		error (game, "\033[0;31mError: Allocation for main_image"
			" returned Null.\e[0m\n");
	game->win_img = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->win_img == NULL)
		error (game, "\033[0;31mError: Allocation for win_img"
			" returned Null.\e[0m\n");
	game->start_img = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->start_img == NULL)
		error (game, "\033[0;31mError: Allocation for start_img"
			" returned Null.\e[0m\n");
	game->lose_img = mlx_new_image
		(game->mlx, WIDTH, HEIGHT);
	if (game->lose_img == NULL)
		error (game, "\033[0;31mError: Allocation for lose_img"
			" returned Null.\e[0m\n");
	create_images_2(game);
}

void	load_images(t_data *game)
{
	game->win_img = mlx_texture_to_image(game->mlx, game->imgs.win);
	if (game->win_img == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for win_img returned Null.\e[0m\n");
	game->lose_img = mlx_texture_to_image(game->mlx, game->imgs.lose);
	if (game->lose_img == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for lose_img returned Null.\e[0m\n");
	game->start_img = mlx_texture_to_image(game->mlx, game->imgs.start);
	if (game->start_img == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for start_img returned Null.\e[0m\n");
	game->gun_img = mlx_texture_to_image(game->mlx, game->imgs.gun);
	if (game->gun_img == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for gun_img returned Null.\e[0m\n");
	game->gun_fire = mlx_texture_to_image(game->mlx, game->imgs.gun_fire);
	if (game->gun_fire == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for gun_fire returned Null.\e[0m\n");
	game->crosshair = mlx_texture_to_image(game->mlx, game->imgs.crosshair);
	if (game->crosshair == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for crosshair returned Null.\e[0m\n");
	
	game->a0 = mlx_texture_to_image(game->mlx, game->imgs.a0);
	if (game->a0 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a0 returned Null.\e[0m\n");
	game->a1 = mlx_texture_to_image(game->mlx, game->imgs.a1);
	if (game->a1 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a1 returned Null.\e[0m\n");
	game->a2 = mlx_texture_to_image(game->mlx, game->imgs.a2);
	if (game->a2 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a2 returned Null.\e[0m\n");
	game->a3 = mlx_texture_to_image(game->mlx, game->imgs.a3);
	if (game->a3 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a3 returned Null.\e[0m\n");
	game->a4 = mlx_texture_to_image(game->mlx, game->imgs.a4);
	if (game->a4 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a4 returned Null.\e[0m\n");
	game->a5 = mlx_texture_to_image(game->mlx, game->imgs.a5);
	if (game->a5 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a5 returned Null.\e[0m\n");
	game->a6 = mlx_texture_to_image(game->mlx, game->imgs.a6);
	if (game->a6 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a6 returned Null.\e[0m\n");
	game->a7 = mlx_texture_to_image(game->mlx, game->imgs.a7);
	if (game->a7 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a7 returned Null.\e[0m\n");
	game->a8 = mlx_texture_to_image(game->mlx, game->imgs.a8);
	if (game->a8 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a8 returned Null.\e[0m\n");
	game->a9 = mlx_texture_to_image(game->mlx, game->imgs.a9);
	if (game->a9 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a9 returned Null.\e[0m\n");
	game->a10 = mlx_texture_to_image(game->mlx, game->imgs.a10);
	if (game->a10 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a10 returned Null.\e[0m\n");
	game->a11 = mlx_texture_to_image(game->mlx, game->imgs.a11);
	if (game->a11 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a11 returned Null.\e[0m\n");
	game->a12 = mlx_texture_to_image(game->mlx, game->imgs.a12);
	if (game->a12 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a12 returned Null.\e[0m\n");
	game->a13 = mlx_texture_to_image(game->mlx, game->imgs.a13);
	if (game->a13 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a13 returned Null.\e[0m\n");
	game->a14 = mlx_texture_to_image(game->mlx, game->imgs.a14);
	if (game->a14 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a14 returned Null.\e[0m\n");
	game->a15 = mlx_texture_to_image(game->mlx, game->imgs.a15);
	if (game->a15 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a15 returned Null.\e[0m\n");
	game->a16 = mlx_texture_to_image(game->mlx, game->imgs.a16);
	if (game->a16 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a16 returned Null.\e[0m\n");
	game->a17 = mlx_texture_to_image(game->mlx, game->imgs.a17);
	if (game->a17 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a17 returned Null.\e[0m\n");
	game->a18 = mlx_texture_to_image(game->mlx, game->imgs.a18);
	if (game->a18 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a18 returned Null.\e[0m\n");
	game->a19 = mlx_texture_to_image(game->mlx, game->imgs.a19);
	if (game->a19 == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for a18 returned Null.\e[0m\n");
	game->reload = mlx_texture_to_image(game->mlx, game->imgs.reload);
	if (game->reload == NULL)
		error (game, "\033[0;31mError: Texture to img conversion"
			" for reload returned Null.\e[0m\n");

	game->mm_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
}

void	set_mlx_images(t_data *game)
{
	game->lose = false;
	game->win = false;
	game->reset = false;
	game->win_img->enabled = false;
	game->main_img->enabled = false;
	game->lose_img->enabled = false;
	game->gun_fire->enabled = false;
	game->gun_img->enabled = false;
	game->start_img->enabled = true;
	game->crosshair->enabled = false;
	game->reload->enabled = false;
}

void	put_images_to_window(t_data *game)
{
	mlx_image_to_window(game->mlx, game->lose_img, 0, 0);
	mlx_image_to_window(game->mlx, game->win_img, 0, 0);
	mlx_image_to_window(game->mlx, game->main_img, 0, 0);
	mlx_image_to_window(game->mlx, game->main_img, 0, 0);
	mlx_image_to_window(game->mlx, game->gun_fire,
		WIDTH * 0.5, HEIGHT * 0.5 + 30);
	mlx_image_to_window(game->mlx, game->gun_img,
		WIDTH * 0.5, HEIGHT * 0.5 + 30);
	mlx_image_to_window(game->mlx, game->mm_img, 0, 0);
	mlx_image_to_window(game->mlx, game->start_img, 0, 0);
	mlx_image_to_window(game->mlx,
		game->crosshair, WIDTH * 0.5 - 32, HEIGHT * 0.5 - 32);

	mlx_image_to_window(game->mlx, game->a0, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a1, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a2, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a3, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a4, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a5, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a6, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a7, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a8, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a9, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a10, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a11, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a12, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a13, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a14, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a15, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a16, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a17, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a18, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->a19, 0, HEIGHT - 200);
	mlx_image_to_window(game->mlx, game->reload, WIDTH * 0.5, HEIGHT * 0.5 + 30);
	mlx_image_to_window(game->mlx, game->fps, 0, 0);
	mlx_image_to_window(game->mlx, game->counter, 0, 0);

	disable_ammo(game);
}

void disable_ammo(t_data *game)
{
	game->a0->enabled = false;
	game->a1->enabled = false;
	game->a2->enabled = false;
	game->a3->enabled = false;
	game->a4->enabled = false;
	game->a5->enabled = false;
	game->a6->enabled = false;
	game->a7->enabled = false;
	game->a8->enabled = false;
	game->a9->enabled = false;
	game->a10->enabled = false;
	game->a11->enabled = false;
	game->a12->enabled = false;
	game->a13->enabled = false;
	game->a14->enabled = false;
	game->a15->enabled = false;
	game->a16->enabled = false;
	game->a17->enabled = false;
	game->a18->enabled = false;
	game->a19->enabled = false;
}
