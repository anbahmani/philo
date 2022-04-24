/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:06:38 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 10:43:54 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_args *args, t_philo *philo)
{
	t_philo *tmp;
	int		i;
	
	i = 1;
	
	tmp = philo;
	while (i <= args->nb_philo)
	{	
		
		tmp = philo->next;
		free(philo);
		philo = tmp;
		i++;
	}
	if (args != NULL)
		free(args);
}

void	join_threads(t_philo *philo, int index)
{
	t_philo	*curr;
	int		i;
	
	i = 1;
	curr = philo;
	while (i <= index)
	{
		pthread_join(curr->th_philo, NULL);
		curr = curr->next;
		i++;
	}
}
 