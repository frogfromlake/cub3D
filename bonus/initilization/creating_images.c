/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:34:56 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:20:07 by gsiddiqu         ###   ########.fr       */
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
	mlx_image_to_window(game->mlx, game->counter, 0, 0);
	mlx_image_to_window(game->mlx, game->fps, 0, 0);
}
