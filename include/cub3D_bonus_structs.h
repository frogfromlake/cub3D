/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:03:08 by fquist            #+#    #+#             */
/*   Updated: 2022/07/09 15:19:13 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_STRUCTS_H
# define CUB3D_BONUS_STRUCTS_H

/* standard	 Aspect rat.   width   height
	HD+			16:9		1600	900
	FHD			16:9		1920	1080
*/

//window size
// HD+
# define WIDTH 1600
# define HEIGHT 900
// FHD
// # define WIDTH 1920
// # define HEIGHT 1080

/* ************************************************************************** */
/* 	DATA STRUCTURES															  */
/* ************************************************************************** */

typedef enum e_sprite_type
{
	FOE,
	RUDI,
	P1,
	P2,
	P3,
	P4,
	P5,
	P6,
	P7
}			t_stype;

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_offset
{
	float	left;
	float	right;
	float	up;
	float	down;
}	t_offset;

typedef struct s_intpair
{
	int	x;
	int	y;
}	t_intpair;

typedef struct s_texes
{
	mlx_texture_t	*tex_n;
	mlx_texture_t	*tex_s;
	mlx_texture_t	*tex_e;
	mlx_texture_t	*tex_w;
	mlx_texture_t	*tex_p;
	mlx_texture_t	**enemy;
	mlx_texture_t	**sprites;
	mlx_texture_t	*start;
	mlx_texture_t	*win;
	mlx_texture_t	*lose;
	mlx_texture_t	*gun;
	mlx_texture_t	*gun_fire;
	mlx_texture_t	*crosshair;
	mlx_texture_t	*counter;
}	t_texes;

typedef struct s_map
{
	char	**map;
	char	*paths[4];
	int		f_colour;
	int		c_colour;
	int		map_fd;
	int		x;
	int		y;
	bool	no;
	bool	ea;
	bool	so;
	bool	we;
	bool	f;
	bool	c;
	bool	created;
}	t_map;

typedef struct s_mouse
{
	float		x_pos;
	float		y_pos;
	int32_t		x_new;
	int32_t		y_new;
	float		pitch;
	float		rotation_speed;
	bool		init_mousepos;
}				t_mouse;

typedef struct s_player
{
	t_vec		dir;
	t_vec		init_pos;
	t_vec		kill_pos;
	float		p_x;
	float		p_y;
	float		old_x;
	float		old_y;
	float		old_dir;
	float		p_dir;
	float		p_dir_x;
	float		p_dir_y;
	float		move_speed;
	float		sprint_speed;
	float		p_old_dir_x;
	bool		firing;
	bool		f_aim;
}				t_player;

typedef struct s_portal
{
	int			portal_nbr;
	int			modifier;
	bool		reverse;
	t_intpair	pos;
	t_vec		f_pos;
}				t_portal;

typedef struct s_enemy
{
	t_intpair		start;
	t_intpair		end;
	t_intpair		screen;
	t_intpair		direction;
	t_intpair		i_pos;
	t_intpair		tex;
	t_vec			pos;
	t_vec			transf;
	t_vec			init_pos;
	mlx_texture_t	*texture;
	unsigned int	enemy_frame;
	float			distance;
	int				stripe;
	int				height;
	int				width;
	int				sign;
	bool			first;
	float			move_screen;
	bool			dead;
	int				hit;
	bool			ray_hit;
	t_stype			type;
}				t_enemy;

typedef struct s_minimap
{
	int				x_offset;
	int				init_draw_start_x;
	t_intpair		p_offset_start;
	t_intpair		p_offset_end;
	t_vec			tiledraw_start;
	t_vec			draw_start;
	t_vec			draw_end;
	int				map_size;
	int				map_zoom;
	mlx_texture_t	*m_player_n;
	mlx_texture_t	*m_player_s;
	mlx_texture_t	*m_player_e;
	mlx_texture_t	*m_player_w;
	mlx_texture_t	*m_player_nw;
	mlx_texture_t	*m_player_ne;
	mlx_texture_t	*m_player_sw;
	mlx_texture_t	*m_player_se;
	mlx_texture_t	*m_background;
	mlx_texture_t	*m_wall;
	mlx_texture_t	*m_portal;
	mlx_texture_t	*m_enemy;
	mlx_texture_t	*m_sprite;
	mlx_texture_t	*m_rudi;
}				t_minimap;

typedef struct s_camera
{
	t_vec	plane;
	t_vec	ray;
	float	aim_ray;
	float	camerapos;
}				t_camera;

typedef struct s_data
{
	void		*mlx;
	mlx_image_t	*main_img;
	mlx_image_t	*start_img;
	mlx_image_t	*win_img;
	mlx_image_t	*lose_img;
	mlx_image_t	*gun_img;
	mlx_image_t	*gun_fire;
	mlx_image_t	*crosshair;
	mlx_image_t	*counter;
	mlx_image_t	*mm_img;
	mlx_image_t	*fps;
	t_texes		imgs;
	t_map		map;
	t_player	player;
	t_vec		vec;
	t_minimap	minimap;
	t_mouse		mouse;
	t_portal	*portal;
	t_intpair	map_values;
	t_enemy		*enemy;
	t_camera	camera;
	int			sprite_count;
	float		perp_wall_dist_s[WIDTH];
	float		h;
	int			m_x;
	int			m_y;
	float		fov_factor_x;
	float		fov_factor_y;
	int			*wall_heights;
	char		*wall_types;
	float		*wall_shade;
	int			side;
	bool		float_keys;
	bool		lose;
	bool		win;
	bool		reset;
	clock_t		fps_val;
	time_t		runtime;
	int			time_count;
}				t_data;

#endif
