/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:04:23 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/09 18:47:46 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*activities_loop()
{
	
}

int	main(int ac, char **av)
{
	t_args	args;

	if (!check_args(ac, av))
		return (1);
	init_args(ac, av, &args);
	if ((args.optional_arg && args.nb_eat == 0) || args.nb_philo == 0)
		return (0);
	
}
