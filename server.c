/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:18:46 by wting             #+#    #+#             */
/*   Updated: 2022/08/11 22:08:06 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiver(int sig, siginfo_t *info, void *context)
{
	static int	msg;
	static int	count;

	(void)context;
	if (sig == SIGUSR1)
		msg += 1;
	if (++count == 8)
	{
		if (msg == 0)
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &msg, 1);
		msg = 0;
		count = 0;
	}
	else
		msg <<= 1;
	usleep(50);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_sigaction = receiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("pid: %i \n", (int)pid);
	while (1)
		pause();
	return (0);
}
