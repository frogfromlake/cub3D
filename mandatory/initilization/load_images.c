/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:25:27 by gohar             #+#    #+#             */
/*   Updated: 2022/07/08 23:00:16 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	load_images(t_data *game)
{
	load_textures(game);
	game->mlx = mlx_init
		(game->screen_width, game->screen_height, "cub3D", true);
	if (game->mlx == NULL)
		error (game, "\033[0;31mError: MLX Init returned Null.\e[0m\n");
	game->main_img = mlx_new_image
		(game->mlx, game->screen_width, game->screen_height);
	if (game->main_img == NULL)
		error (game, "\033[0;31mError: Allocation for main_image"
			"returned Null.\e[0m\n");
	mlx_image_to_window(game->mlx, game->main_img, 0, 0);
}

void	load_textures(t_data *game)
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
}
