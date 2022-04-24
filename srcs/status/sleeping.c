/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:33 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 02:29:43 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	if (!is_dead(philo))
	{
		write_philo_status(philo, "is sleeping");
		ft_usleep((long) philo->args->time_to_sleep);
	}
}