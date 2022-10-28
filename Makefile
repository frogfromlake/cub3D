# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fquist <fquist@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 17:02:53 by fquist            #+#    #+#              #
#    Updated: 2022/05/31 17:02:53 by fquist           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
BONUS_NAME	= cub3D_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g

SDIR		= mandatory/*
SRCS		= main.c \
			  init_variables.c \
			  allocating_map.c \
			  allocating_map_utils.c \
			  parsing_data.c \
			  loading_file_data.c \
			  parsing_textures.c \
			  parsing_colors.c \
			  parsing_map.c \
			  check_validity.c \
			  load_player.c \
			  parser_utils.c \
			  parser_utils_2.c \
			  load_images.c \
			  raycast.c \
			  find_hit.c \
			  find_hit_2.c \
			  dda.c \
			  rotation.c \
			  movement_forward_backward.c \
			  movement_left_right.c \
			  key_hook.c \
			  rendering_world.c \
			  mlx_deletes.c \
			  errors.c \
			  loading_filedata_utils.c

BONUS_SDIR	= bonus/*
BONUS_SRCS	= main.c \
			  errors.c \
			  allocating_map.c \
			  allocating_map_utils.c \
			  parsing_data.c \
			  loading_file_data.c \
			  parsing_colors.c \
			  parsing_textures.c \
			  parsing_map.c \
			  load_player.c \
			  load_sprites.c \
			  check_validity.c \
			  parser_utils.c \
			  parser_utils_2.c \
			  raycast.c \
			  find_hit.c \
			  find_hit_2.c \
			  dda.c \
			  rotation.c \
			  movement_forward_backward.c \
			  movement_left_right.c \
			  initialize.c \
			  key_hook_init.c \
			  key_hook.c \
			  mouse_hook.c \
			  rendering_world.c \
			  draw_minimap.c \
			  minimap_movement.c \
			  rendering_enemies_and_sprites.c \
			  render_sprites_enemies.c \
			  loading_minimap_textures.c \
			  loading_sprites_enemies.c \
			  loading_texture_pngs.c \
			  creating_images.c \
			  init_variables.c \
			  enemies_movement.c \
			  hook_conditions.c \
			  gun_fire.c \
			  sprite_enemies_utils.c \
			  utils_bonus.c \
			  end_conditions.c \
			  mlx_deletes.c \
			  loading_filedata_utils.c

INCLUDES	= -I./libs/libft/include/ -I./libs/mlx42/include/MLX42/
LIBS		= -L ./libs/mlx42/ -lmlx42 -L ./libs/libft -lft -ldl -lglfw -lm
ODIR		= obj
BONUS_ODIR	= obj_b
OBJS		= $(addprefix $(ODIR)/, $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(BONUS_ODIR)/, $(BONUS_SRCS:.c=.o))

# COLORS
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
UP = "\033[A"
CUT = "\033[K"

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: bonus
all: libft mlx $(NAME)

header:
	@printf "$(COM_COLOR)==================== $(OBJ_COLOR)$(NAME)$(COM_COLOR) ====================$(NO_COLOR)\n"

# Linking
$(NAME): $(ODIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBS) -o $(NAME)
	@printf $(UP)$(CUT)
	@printf "%-52b %b" "$(OK_COLOR)$(NAME) compiled successfully!" "$(G)[✓]$(X)$(NO_COLOR)\n"

# Compiling
$(ODIR)/%.o: $(SDIR)/%.c include/cub3D.h include/cub3D_structs.h include/cub3D_defines.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf $(UP)$(CUT)
	@printf "%-59b %b" "$(COM_COLOR)compiling: $(OBJ_COLOR)$@" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

# Linking
$(BONUS_NAME): $(BONUS_ODIR) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBS) -o $(BONUS_NAME)
	@printf $(UP)$(CUT)
	@printf "%-52b %b" "$(OK_COLOR)$(BONUS_NAME) compiled successfully!" "$(G)[✓]$(X)$(NO_COLOR)\n"

# Compiling
$(BONUS_ODIR)/%.o: $(BONUS_SDIR)/%.c include/cub3D_bonus.h include/cub3D_bonus_structs.h include/cub3D_bonus_defines.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf $(UP)$(CUT)
	@printf "%-59b %b" "$(COM_COLOR)compiling: $(OBJ_COLOR)$@" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

bonus: libft mlx $(BONUS_NAME)

libft:
	@make -C libs/libft

mlx:
	@make -C libs/mlx42

$(ODIR):
	@mkdir -p $(ODIR)

$(BONUS_ODIR):
	@mkdir -p $(BONUS_ODIR)

.PHONY: clean
clean: header
	@$(RM) -r $(ODIR)
	@$(RM) -r $(BONUS_ODIR)
	@make clean -C libs/libft
	@make clean -C libs/mlx42
	@printf "%-51b %b" "$(ERROR_COLOR)$(NAME) cleaned!" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "%-51b %b" "$(ERROR_COLOR)libft cleaned!" "$(OK_COLOR)[✓]$(NO_COLOR)\n"
	@printf "%-51b %b" "$(ERROR_COLOR)MLX42 cleaned!" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

.PHONY: fclean
fclean: header clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(RM) -r mandatory/$(NAME) mandatory/*.dSYM
	@$(RM) -r bonus/$(BONUS_NAME) bonus/*.dSYM
	@make fclean -C libs/libft
	@make clean -C libs/mlx42

.PHONY: re
re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader include/*.h | grep --color=always 'Error!\|Error:' || echo "$(OK_COLOR)Everything is OK!$(NO_COLOR)" >&1
	@norminette -R CheckForbiddenSourceHeader mandatory/*/*.c | grep --color=always 'Error!\|Error:' || echo "$(OK_COLOR)Everything is OK!$(NO_COLOR)" >&1
	@norminette -R CheckForbiddenSourceHeader bonus/*/*.c | grep --color=always 'Error!\|Error:' || echo "$(OK_COLOR)Everything is OK!$(NO_COLOR)" >&1