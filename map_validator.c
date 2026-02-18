/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulla <dabdulla@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:10:41 by dabdulla          #+#    #+#             */
/*   Updated: 2026/02/18 10:33:25 by dabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_list *head)
{
	if (!valid_chars(head))
	{
		ft_printf("Error\nInvalid Character\n");
		return (0);
	}
	else if (!valid_required_chars(head, 0, 0, 0))
	{
		ft_printf("Error\nThe map must have:\n");
		ft_printf("1 exit, 1 start position and at least 1 collectible\n");
		return (0);
	}
	else if (!valid_rectangle(head))
	{
		ft_printf("Error\nNot Rectangular\n");
		return (0);
	}
	else if (!valid_walls(head))
	{
		ft_printf("Error\nNot surrounded by walls\n");
		return (0);
	}
	return (1);
}

int	valid_chars(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		while (head->content[i])
		{
			if (!(ft_strchr("01CEP", head->content[i])) && (head->content))
				return (0);
			i++;
		}
		i = 0;
		head = head->next;
	}
	return (1);
}

int	valid_required_chars(t_list *head, int e, int p, int c)
{
	int	i;

	i = 0;
	while (head)
	{
		while (head->content[i])
		{
			if (head->content[i] == 'E')
				e++;
			else if (head->content[i] == 'P')
				p++;
			else if (head->content[i] == 'C')
				c++;
			i++;
		}
		i = 0;
		head = head->next;
	}
	if ((e == 1) && (p == 1) && (c >= 1))
		return (1);
	return (0);
}

int	valid_rectangle(t_list *head)
{
	size_t	width;
	t_list	*curr;

	if (!head)
		return (0);
	width = ft_strlen(head->content);
	curr = head;
	while (curr != NULL)
	{
		if (ft_strlen(curr->content) != width)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	valid_walls(t_list *head)
{
	int	i;
	int	node;
	int	len;

	len = ft_strlen(head->content) - 1;
	i = 0;
	node = 0;
	while (head)
	{
		while ((head->content[i]))
		{
			if (head->content[i] != '1' && (node == 0 || head->next == NULL))
				return (0);
			else if ((head->content[0] != '1') || (head->content[len] != '1'))
				return (0);
			i++;
		}
		i = 0;
		node++;
		head = head->next;
	}
	return (1);
}
