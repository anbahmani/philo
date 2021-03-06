/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:04:23 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 16:04:00 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(&philo->args->m_end);
	dead = philo->args->end;
	pthread_mutex_unlock(&philo->args->m_end);
	return (dead);
}

void	*activities_loop(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	if (philo->index % 2 == 0)
		usleep(get_time_to_eat(philo->args) / 2);
	while (!is_dead(philo) && !check_nb_eat(philo, get_nb_eat(philo->args)))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo);
}

void	start_activities(t_struct *s)
{
	int		i;
	t_philo	*curr;

	i = 1;
	curr = s->first_philo;
	while (i <= s->args->nb_philo)
	{
		if (pthread_create(&curr->th_philo, NULL, activities_loop, curr) != 0)
		{
			print_error("Issue during the threads creation.");
			free_struct(s->args, s->first_philo);
			return ;
		}
		curr = curr->next;
		i++;
	}
	if (get_nb_eat(s->args) != -1)
		check_nb_eat_and_death(s);
	else
		check_death(s);
	join_threads(s->first_philo, s->args->nb_philo);
}

int	main(int ac, char **av)
{
	t_args		*args;
	t_struct	s;

	if (!check_args(ac, av))
		return (1);
	args = init_args(ac, av);
	s.args = args;
	init_all_philo(&s);
	init_args_mutex(&s);
	if (!s.first_philo)
	{
		print_error("Issue during the philo allocation.");
		return (1);
	}
	start_activities(&s);
	free_struct(s.args, s.first_philo);
}
