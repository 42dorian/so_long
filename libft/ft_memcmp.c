/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:28:20 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/09 11:25:23 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char a1[] = "Hello", a2[] = "Hello";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(a1, a2, 5), memcmp(a1, a2, 5));

	char b1[] = "abc", b2[] = "abd";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(b1, b2, 3), memcmp(b1, b2, 3));

	char c1[] = "abcd", c2[] = "abce";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(c1, c2, 4), memcmp(c1, c2, 4));

	char d1[] = "12345", d2[] = "123";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(d1, d2, 3), memcmp(d1, d2, 3));

	char e1[] = "sameprefixX", e2[] = "sameprefixY";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(e1, e2, 11), memcmp(e1, e2, 11));

	char f1[] = "short", f2[] = "shorter";
	printf("ft_memcmp: %d | memcmp: %d\n", 
	ft_memcmp(f1, f2, 10), memcmp(f1, f2, 10));

	return (0);
}*/