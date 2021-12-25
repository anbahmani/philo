/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:32:12 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/24 00:57:26 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static bool	check_args_number(int ac)
{
	if (ac == 5 || ac == 6)
		return (true);
	print_error("Le nombre d'arguments est incorrectes.");
	return (false);
}

static bool	check_is_args_number(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			print_error("Les arguments sont incorrectes.");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_args(int ac, char **av)
{
	if (!check_args_number(ac) || !check_is_args_number(ac, av))
		return (false);
	return (true);
}