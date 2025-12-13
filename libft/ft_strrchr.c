/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:13:04 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/09 12:54:28 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;

	r = 0;
	if (*s == (unsigned char)c)
		r = (char *)s;
	while (*s++)
		if (*s == (unsigned char)c)
			r = (char *)s;
	return (r);
}

/*#include <stdio.h>
int main(void)
{
	char *s1 = "test---";
	printf("Last Occurrence: %s\n", ft_strrchr(s1, 't'));
}*/