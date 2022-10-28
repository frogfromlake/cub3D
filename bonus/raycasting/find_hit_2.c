/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:29:44 by gohar             #+#    #+#             */
/*   Updated: 2022/07/08 00:12:02 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

/*
	plane.y: Camera plane.
	camerapos: pixel position on the camera plane.
	ray.x: Direction of the ray for current pixel.
*/
t_vec	calc_ray(t_data *game, int i)
{
	game->camera.plane.x = game->player.dir.y * game->fov_factor_x;
	game->camera.plane.y = -game->player.dir.x * game->fov_factor_x;
	game->camera.camerapos = (2 * i / (float)(WIDTH - 1)) - 1;
	game->camera.ray.x = game->player.dir.x
		+ game->camera.plane.x * game->camera.camerapos;
	game->camera.ray.y = game->player.dir.y
		+ game->camera.plane.y * game->camera.camerapos;
	game->camera.aim_ray
		= (2 * (WIDTH / 2) / (float)(WIDTH - 1)) - 1;
	return (game->camera.ray);
}
