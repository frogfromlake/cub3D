/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:32:26 by fquist            #+#    #+#             */
/*   Updated: 2022/07/04 16:57:26 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static char	*get_path(char *trimmed)
{
	char	*tmp;

	while (ft_is_space(trimmed[ft_strlen(trimmed) - 1]))
	{
		tmp = ft_strtrim(trimmed, &trimmed[ft_strlen(trimmed) - 1]);
		free(trimmed);
		trimmed = tmp;
	}
	return (trimmed);
}

// check identifiers paths
char	*parsing_path(t_data *data, char *str, int i)
{
	char	*path;
	char	*trimmed;

	i += 2;
	i += skip_whitespaces(&str[i]);
	trimmed = ft_strdup(&str[i]);
	trimmed = get_path(trimmed);
	if (trimmed != NULL)
	{
		path = ft_strdup(trimmed);
		free(trimmed);
	}
	else
		path = ft_strdup(&str[i]);
	if (!path)
	{
		free(str);
		error(data, "\033[0;31mError:"
			" Allocation for texture paths failed.\e[0m\n");
	}
	return (path);
}
