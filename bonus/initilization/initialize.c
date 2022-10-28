/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:25:27 by gohar             #+#    #+#             */
/*   Updated: 2022/07/08 20:50:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	init_data(t_data *game)
{
	init_game_variables(game);
	init_enemy_variables(game);
	load_texture_pngs(game);
	create_images(game);
	load_images(game);
	set_mlx_images(game);
	load_minimap_pngs(game);
	load_enemy_sprite_pngs(game);
	put_images_to_window(game);
	return (0);
}
