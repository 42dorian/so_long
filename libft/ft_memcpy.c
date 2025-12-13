/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:20:58 by dabdulla          #+#    #+#             */
/*   Updated: 2025/10/13 12:21:39 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    char src1[] = "Hello, World!";
    char dest1[20];
    ft_memcpy(dest1, src1, ft_strlen(src1) + 1);
    printf("Test 1 (string copy): %s\n", dest1);

    char src2[] = "ABCDE";
    char dest2[10] = "XXXXXXXXX";
    ft_memcpy(dest2, src2, 5);
    printf("Test 2 (overwrite 5 chars): %s\n", dest2);

    int src3[] = {1, 2, 3, 4, 5};
    int dest3[5] = {0};
    ft_memcpy(dest3, src3, sizeof(src3));
    printf("Test 3 (int array): ");
    for (int i = 0; i < 5; i++)
        printf("%d ", dest3[i]);
    printf("\n");

    char src4[] = "OverlapTest";
    char dest4[20] = "XXXXXXXXXXXX";
    ft_memcpy(dest4, src4, 5);
    printf("Test 4 (partial copy): %s\n", dest4);

    char src5[] = "SameBuffer";
    ft_memcpy(src5, src5, ft_strlen(src5) + 1);
    printf("Test 5 (same source and destination): %s\n", src5);

    char src6[] = "BoundaryCheck";
    char dest6[20] = {0};
    ft_memcpy(dest6, src6, 0);
    printf("Test 6 (n = 0): %s\n", dest6);

    return 0;
}