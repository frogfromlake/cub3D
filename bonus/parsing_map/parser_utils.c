/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:19:22 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 18:56:09 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

char	*strjoin(char *s1, const char *s2)
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (NULL);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}

int	line_is_whitespace(char *str)
{
	if (!ft_strcmp(str, " ") || !ft_strcmp(str, "\t") || !ft_strcmp(str, "\n")
		|| !ft_strcmp(str, "\v") || !ft_strcmp(str, "\f")
		|| !ft_strcmp(str, "\r") || !ft_strcmp(str, "	"))
		return (true);
	return (false);
}

static int	atoi_helper(long int *n, const char *str, int is_negative)
{
	*n = (*n * 10) + (*str - '0');
	if (*n > INT_MAX)
		return (0);
	if (*n < 0 && is_negative == -1)
		return (0);
	else if (*n < 0 && is_negative == 1)
		return (0);
	else
		return (1);
}

int	ft_atoi_cub(const char *str, int *res)
{
	long int		n;
	int				is_negative;
	int				ret;

	n = 0;
	is_negative = 1;
	ret = 0;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (ft_is_digit(*str))
	{
		ret = atoi_helper(&n, str, is_negative);
		if (ret == 0)
			return (0);
		str++;
	}
	*res = (n * is_negative);
	return (1);
}

int	skip_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	return (i);
}
