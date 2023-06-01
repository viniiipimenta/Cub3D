/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:33:51 by mpimenta          #+#    #+#             */
/*   Updated: 2022/05/27 14:13:17 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					i;
	int					signal;
	unsigned long int	result;

	result = 0;
	signal = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result >= 9223372036854775807 && signal == 1)
			return (-1);
		if (result > 9223372036854775807 && signal == -1)
			return (0);
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * signal);
}
