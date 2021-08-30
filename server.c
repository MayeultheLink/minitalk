/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:47:14 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/30 20:06:44 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c |= (0 << i++);
	if (sig == SIGUSR2)
		c |= (1 << i++);
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int		p;
	char	*pid;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	p = getpid();
	pid = ft_itoa(p);
	write(1, pid, ft_strlen(pid));
	free(pid);
	pid = NULL;
	while (1)
	{
	}
	return (0);
}
