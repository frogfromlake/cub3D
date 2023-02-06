/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:49:49 by fquist            #+#    #+#             */
/*   Updated: 2023/02/03 20:53:37 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/* ************************************************************************** */
/* STANDARD INCLUDES														  */
/* ************************************************************************** */
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include "../libs/libft/include/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../include/cub3D_bonus_structs.h"
# include "../include/cub3D_bonus_defines.h"

/* ************************************************************************** */
/* 	PARSER																	  */
/* ************************************************************************** */
void			allocating_map(t_data *data, char **argv);
void			parsing_data(t_data *data, int argc, char **argv);
void			loading_map(t_data *data);
int				parsing_identifiers(t_data *data);
char			*parsing_path(t_data *data, char *str, int i);
int				parsing_color(t_data *data, char *str, int i);
int				create_trgb(int r, int g, int b);
void			parsing_map(t_data *data);
int				is_empty_tile(char tile);
void			set_portal_data(t_data *data, int x, int y);
int				is_sprite(char c, int option);
void			set_sprite_type(t_data *game, char c);
void			parse_sprites(char c, t_data *data, int x, int y);
void			set_init_player_dir(t_data *game, int x, int y);
int				player_values(t_data *data, int x, int y);
int				skip_textures(t_data *data);
bool			no_whitespaces(char *str);
char			*cub_strdup(t_data *data, const char *s1);
void			check_valid_zero(t_data *data, int x, int y);
void			check_valid_player_pos(t_data *data, int x, int y);

/* ************************************************************************** */
/* 	ERRORS																	  */
/* ************************************************************************** */
void			malloc_error(t_data *game, char *error_obj);
void			error(t_data *game, char *error_message);
void			input_error(t_data *game, int argc);

/* ************************************************************************** */
/* 	UTILS																	  */
/* ************************************************************************** */
char			*strjoin(char *s1, const char *s2);
int				line_is_whitespace(char *str);
int				ft_atoi_cub(const char *str, int *res);
int				skip_whitespaces(char *str);
void			print_map(t_data *data);
time_t			timer(t_data *data);
int				only_sprites(char c);
int				is_player(char tile);
int				get_resolution(void);
void			run(t_data *game);
void			play_walk_sound(t_data *game, pid_t *pid, bool state);
void 			disable_ammo(t_data *game);
void			ammo_count(t_data *game);
/* ************************************************************************** */
/* 	MINIMAP																	  */
/* ************************************************************************** */
int32_t			create_window(t_data *data);

/* ************************************************************************** */
/* 	RAYCASTING																  */
/* ************************************************************************** */
int				calculating_walls(t_data *game);
t_vec			calc_ray(t_data *game, int i);
float			find_hit(t_data *game, int i);
int				dda(t_data *game, t_vec *side_dist,
					t_vec delta_dist, t_intpair step);

/* ************************************************************************** */
/* 	INITILIZATION															  */
/* ************************************************************************** */
t_vec			calc_dir(int d);
void			init_enemy_variables(t_data *game);
void			init_game_variables(t_data *game);
int				init_data(t_data *game);
void			load_texture_pngs(t_data *game);
void			create_images(t_data *game);
void			load_images(t_data *game);
void			set_mlx_images(t_data *game);
void			put_images_to_window(t_data *game);

/* ************************************************************************** */
/* 	MOVEMENT																  */
/* ************************************************************************** */
void			key_hook(void *data);
void			reset_handler(t_data *game);
void			win_handler(t_data *game);
void			lose_handler(t_data *game);
void			rotdir(t_data *game, int p);
void			call_key_events(t_data *game, int param, bool rotation,
					char dir);
void			moveplayer_per(t_data *game, int p, float move_speed);
void			moveplayer_par(t_data *game, int p, float move_speed);
bool			get_portal(t_data *game, int i);
int				is_occupied(char c);
t_vec			calc_dir(int d);
void			check_portal_exit_move(t_data *game, int i, int modifier);
void			portal_move(t_data *game);
void			portal_order(t_data *game, int i);
float			calc_disp(float x1, float x2, float y1, float y2);

/* ************************************************************************** */
/* 	MOUSE CONTROL															  */
/* ************************************************************************** */
void			mouse_hook(void *data);
int				event_mouse_move(t_data *data);
void			dying_condition(t_data *game);
void			gun_fire(t_data *game, int button);
void			mouse_controls(double x, double y, void *data);
void			mouse_controls(double x, double y, void *data);
int				event_mouse_press(t_data *game, int button, float x, float y);
void			arrow_key_camera(t_data *game);

/* ************************************************************************** */
/* 	RENDERER																  */
/* ************************************************************************** */
int				rendering_world(t_data *game);
uint32_t		get_pixel(t_data *game, int x, int y);

/* ************************************************************************** */
/* 	MINIMAP																	  */
/* ************************************************************************** */
void			load_minimap_pngs(t_data *data);
void			draw_minimap(t_data *data);
void			minimap_movement_textures(t_data *data, int x_tile, int y_tile);
void			my_keyhook(void *dat);
void			draw_player_movement(t_data	*data);
void			move_player(t_data *data, char pos, float dir);

/* ************************************************************************** */
/* 	ENEMIES																	  */
/* ************************************************************************** */
void			load_enemy_sprite_pngs(t_data *game);
void			rendering_enemies_and_sprites(t_data *game);
void			get_enemy_texture(t_data *game, int i);
void			render_enemy(t_data *game, int i);
void			enemy_textures(t_data *game);
void			move_enemy(t_data *game);
unsigned int	mlx_pixel_read(mlx_texture_t *data, int x, int y);
void			move_enemy(t_data *game);
void			end_condition(t_data *game);
void			win_condition(t_data *game, int i);
void			sort_enemies(t_data *game);
void			get_enemy_distance(t_data *game);
void			load_sprite_pngs(t_data *game);
void			set_sprite_textures(t_data *game, int i);
void			get_sprite_pixels(t_data *game, int i, unsigned int color,
					int y);
void			get_tex_x(t_data *game, int i);
void			exit_game(t_data *game);
#endif
