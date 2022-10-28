/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:31:34 by fquist            #+#    #+#             */
/*   Updated: 2022/07/02 18:49:54 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
	Save a copy of a string.
	The ft_strdup() function allocates sufficient memory for a copy of
	the string s1 and does the copy using ft_strlcpy().
	The pointer may subsequently be used as an argument to the function free(3).
	If insufficient memory is available, NULL is returned and errno is set to
	ENOMEM.
RETURN VALUES
	ft_strdup() returns a pointer to the copied s1 or NULL if the allocation failed.
*/
char	*ft_strdup(const char *s1)
{
	char	*result;
	char	*string;

	string = (char *)s1;
	result = malloc(ft_strlen(string) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, string, ft_strlen(string) + 1);
	return (result);
}
