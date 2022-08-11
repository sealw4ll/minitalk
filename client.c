/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:18:47 by wting             #+#    #+#             */
/*   Updated: 2022/08/11 22:04:38 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirmation(int sig)
{
	(void)sig;
	write(1, "message received\n", 17);
	exit(0);
}

void	bit_calc(char msg, int pid)
{
	int count;
	int shifter;

	count = 0;
	shifter = 7;
	while (count <= 7)
	{
		if ((msg >> shifter) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		++count;
		--shifter;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		count;

	if (argc != 3)
	{
		ft_printf("Kematian program");
		return (0);
	}
	signal(SIGUSR2, confirmation);
	pid = (pid_t)ft_atoi(argv[1]);
	message = argv[2]; 
	while (*message)
	{
		bit_calc(*message, pid);
		++message;
	}
	bit_calc(0, pid);
	return (0);
}