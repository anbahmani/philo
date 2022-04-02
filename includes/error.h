/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:32:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/26 13:37:27 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philo.h"

# define ERROR_ARG_SYNTAX 

bool	check_args(int ac, char **av);
void	print_error(char *msg);
void	printf_syntax_error(void);

#endif