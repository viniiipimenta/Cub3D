/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:17:24 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/15 16:02:59 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**dup_matrix(char **matrix)
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * (matrix_len(matrix) + 1));
	if (!result)
		return (NULL);
	while (matrix && matrix[i])
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			matrix_free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix)
		free(matrix);
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

char	**matrix_push(char **matrix, char *new)
{
	char	**result;
	int		i;
	int		len;

	i = 0;
	if (!new)
		return (matrix);
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len + 2));
	result[len + 1] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			matrix_free(matrix);
			matrix_free(result);
		}
		i++;
	}
	result[i] = ft_strdup(new);
	matrix_free(matrix);
	return (result);
}