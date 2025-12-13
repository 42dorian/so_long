/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:15:22 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/09 11:24:25 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (src > dest)
	{
		while (n--)
			*d++ = *s++;
	}
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{

	char s1[] = "Hello, World!", d1[20], d1_memmove[20];
	ft_memmove(d1, s1, ft_strlen(s1) + 1);
	memmove(d1_memmove, s1, ft_strlen(s1) + 1);
	printf("Test 1: %s | %s\n", d1, d1_memmove);

	char s2[] = "ABCDEEEEEEEEE", d2[20] = "1234567890",
	d2_std[20] = "1234567890";
	ft_memmove(d2, s2, 5);
	memmove(d2_std, s2, 5);
	printf("Test 2: %s | %s\n", d2, d2_std);

	int s3[] = {1, 2, 3, 4, 5}, d3[5] = {0}, d3_std[5] = {0};
	ft_memmove(d3, s3, sizeof(s3));
	memmove(d3_std, s3, sizeof(s3));
	printf("Test 3: ");
	for (int i = 0; i < 5; i++) printf("%d ", d3[i]);
	printf("| ");
	for (int i = 0; i < 5; i++) printf("%d ", d3_std[i]);
	printf("\n");

	char s4[] = "OverlapTest", s4_std[] = "OverlapTest";
	ft_memmove(s4 + 2, s4, 5);
	memmove(s4_std + 2, s4_std, 5);
	printf("Test 4: %s | %s\n", s4, s4_std);

	char s5[] = "OverlapTest", s5_std[] = "OverlapTest";
	ft_memmove(s5, s5 + 2, 5);
	memmove(s5_std, s5_std + 2, 5);
	printf("Test 5: %s | %s\n", s5, s5_std);

	char s6[] = "SameBuffer", s6_std[] = "SameBuffer";
	ft_memmove(s6, s6, ft_strlen(s6) + 1);
	memmove(s6_std, s6_std, ft_strlen(s6_std) + 1);
	printf("Test 6: %s | %s\n", s6, s6_std);

	char s7[] = "BoundaryCheck", d7[20] = {0}, d7_std[20] = {0};
	ft_memmove(d7, s7, 0);
	memmove(d7_std, s7, 0);
	printf("Test 7: %s | %s\n", d7, d7_std);

	return (0);
}*/