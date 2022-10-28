/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_minimap_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:17:55 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 18:39:52 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	load_minimap_pngs_2(t_data *game)
{
	game->minimap.m_player_se = mlx_load_png("./textures/arrow_se.png");
	if (game->minimap.m_player_se == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_background = mlx_load_png("./textures/m_background.png");
	if (game->minimap.m_background == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_wall = mlx_load_png("./textures/m_wall.png");
	if (game->minimap.m_wall == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_portal = mlx_load_png("./textures/m_portal.png");
	if (game->minimap.m_portal == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_enemy = mlx_load_png("./textures/m_enemy.png");
	if (game->minimap.m_enemy == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_sprite = mlx_load_png("./textures/m_sprite.png");
	if (game->minimap.m_sprite == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_rudi = mlx_load_png("./textures/m_rudi.png");
	if (game->minimap.m_rudi == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	mlx_set_mouse_pos
		(game->mlx, WIDTH * 0.5, HEIGHT * 0.5);
	moveplayer_per(game, 0, PLAYER_SPEED);
}

// stores textures into minimap_struct.
void	load_minimap_pngs(t_data *game)
{
	game->minimap.m_player_n = mlx_load_png("./textures/arrow_n.png");
	if (game->minimap.m_player_n == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_s = mlx_load_png("./textures/arrow_s.png");
	if (game->minimap.m_player_s == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_e = mlx_load_png("./textures/arrow_e.png");
	if (game->minimap.m_player_e == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_w = mlx_load_png("./textures/arrow_w.png");
	if (game->minimap.m_player_w == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_nw = mlx_load_png("./textures/arrow_nw.png");
	if (game->minimap.m_player_nw == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_ne = mlx_load_png("./textures/arrow_ne.png");
	if (game->minimap.m_player_ne == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	game->minimap.m_player_sw = mlx_load_png("./textures/arrow_sw.png");
	if (game->minimap.m_player_sw == NULL)
		error(game, "\033[0;31mError: Couldn't load minimap textures.\033[m\n");
	load_minimap_pngs_2(game);
}
