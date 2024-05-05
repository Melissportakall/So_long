/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:12:16 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:12:18 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(str);
	dst = (char *)malloc(len + 1);
	if ((dst) == NULL)
		return (NULL);
	ft_memcpy(dst, str, len + 1);
	return (dst);
}
