/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:10:15 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:10:17 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t len)
{
	void	*dst;

	dst = malloc(n * len);
	if (!dst)
		return (NULL);
	else
		ft_bzero(dst, n * len);
	return (dst);
}
