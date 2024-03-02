/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:08:52 by oussama           #+#    #+#             */
/*   Updated: 2024/02/29 16:11:23 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
	   return (NULL);
	while (src[i] && i < n)
	{
	   dup[i] = src[i];
	   i++;
	}
	while (i <= n)
	{
	   dup[i] = '\0';
	   i++;
	}
	return (dup);
}
