/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:45:09 by fquist            #+#    #+#             */
/*   Updated: 2023/02/06 22:53:49 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

static void	hd_menu(t_data *game, float x, float y)
{
	if (game->main_img->enabled == false
		&& x > 880 && x < 1040 && y > 680 && y < 740)
	{
		game->player.p_dir = game->player.old_dir;
		game->player.p_x = game->player.init_pos.x;
		game->player.p_y = game->player.init_pos.y;
		game->start_img->enabled = false;
		game->lose = false;
		game->reset = true;
	}
	else if (game->main_img->enabled == false
		&& x > 900 && x < 1010 && y > 750 && y < 800)
		exit_game(game);
}

int	event_mouse_press(t_data *game, int button, float x, float y)
{
	gun_fire(game, button);
	if (button == 0)
	{
		if (get_resolution() == 2)
		{
			if (game->main_img->enabled == false
				&& x > 700 && x < 900 && y > 580 && y < 620)
			{
				game->player.p_dir = game->player.old_dir;
				game->player.p_x = game->player.init_pos.x;
				game->player.p_y = game->player.init_pos.y;
				game->start_img->enabled = false;
				game->lose = false;
				game->reset = true;
				game->player.ammo = 20;
				ammo_count(game);
			}
			else if (game->main_img->enabled == false
				&& x > 700 && x < 900 && y > 620 && y < 760)
				exit_game(game);
		}
		else if (get_resolution() == 1)
			hd_menu(game, x, y);
	}
	return (0);
}

static void	handle_mousepos(t_data *game, double x, double y)
{
		if (!mlx_is_key_down(game->mlx, MLX_KEY_TAB))
	{
		if (game->mouse.init_mousepos == false)
		{
			game->mouse.x_pos = WIDTH * 0.5;
			game->mouse.y_pos = HEIGHT * 0.5;
			game->mouse.x_new = game->mouse.x_pos;
			game->mouse.y_new = game->mouse.y_pos;
			game->mouse.init_mousepos = true;
		}
		if ((x < 0 || y < 0 || y > HEIGHT
				|| x > WIDTH))
			mlx_set_mouse_pos(game->mlx, WIDTH * 0.5, HEIGHT * 0.5);
	}
}

static void	rotation_camera(t_data *game)
{
	if (game->mouse.x_new < game->mouse.x_pos - 1)
		call_key_events(game, 1, true, 'a');
	if (game->mouse.x_new > game->mouse.x_pos + 1)
		call_key_events(game, -1, true, 'd');
	if (game->mouse.y_new < game->mouse.y_pos)
		game->mouse.pitch += 450 * game->mouse.rotation_speed;
	if (game->mouse.y_new > game->mouse.y_pos)
		game->mouse.pitch -= 450 * game->mouse.rotation_speed;
}

void	mouse_controls(double x, double y, void *data)
{
	t_data	*game;

	game = (t_data *)data;
	game->mouse.x_new = x;
	game->mouse.y_new = y;
	handle_mousepos(game, x, y);
	if (game->main_img->enabled == true)
		rotation_camera(game);
	game->mouse.x_pos = game->mouse.x_new;
	game->mouse.y_pos = game->mouse.y_new;
}
