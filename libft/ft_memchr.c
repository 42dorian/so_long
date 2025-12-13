/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:09:00 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/09 11:19:29 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	const char str[] = "Hello, World!";

	void *res1 = ft_memchr(str, 'H', ft_strlen(str));
	void *std1 = memchr(str, 'H', ft_strlen(str));
	printf("ft_memchr: %s | memchr:  %s\n", (char*)res1, (char*)std1);

	void *res2 = ft_memchr(str, 'o', ft_strlen(str));
	void *std2 = memchr(str, 'o', ft_strlen(str));
	printf("ft_memchr: %s | memchr:  %s\n", (char*)res2, (char*)std2);

	void *res3 = ft_memchr(str, ',', ft_strlen(str));
	void *std3 = memchr(str, ',', ft_strlen(str));
	printf("ft_memchr: %s | memchr:  %s\n", (char*)res3, (char*)std3);

	void *res4 = ft_memchr(str, 'z', ft_strlen(str));
	void *std4 = memchr(str, 'z', ft_strlen(str));
	printf("ft_memchr: %s | memchr:  %s\n", res4 ? (char*)res4 : "(null)",
		std4 ? (char*)std4 : "(null)");

	void *res5 = ft_memchr(str, '\0', ft_strlen(str) + 1);
	void *std5 = memchr(str, '\0', ft_strlen(str) + 1);
	printf("ft_memchr: %s | memchr:  %s\n", res5 ? (char*)res5 : "(null)",
		std5 ? (char*)std5 : "(null)");

	return (0);
}*/