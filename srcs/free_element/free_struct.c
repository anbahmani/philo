/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:06:38 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/21 06:50:23 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_args *args, t_philo *philo)
{
	t_philo	*curr;
	
	if (args != NULL)
		free(args);
	curr = philo;
	while (curr != NULL)
	{
		curr = curr->next;
		free(philo);
		philo = curr;
	}
	philo = NULL;
}

void	join_threads(t_philo *philo, int index)
{
	t_philo	*curr;
	int		i;
	
	i = 1;
	curr = philo;
	while (i < index)
	{
		pthread_join(curr->th_philo, NULL);
		curr = curr->next;
		i++;
	}
}
 