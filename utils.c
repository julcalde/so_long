/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:48 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/13 17:20:25 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf("%S", str);
	exit(EXIT_FAILURE);
}
