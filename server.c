/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wting <wting@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:18:46 by wting             #+#    #+#             */
/*   Updated: 2022/08/11 13:27:25 by wting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


//reveive

void	receiver(int sig, siginfo_t *info, void *context)
{
	// int msg = 2;

	(void)context;
	if (sig == SIGUSR1)
		write(1, "1\n", 2);
	else if (sig == SIGUSR2)
		write(1, "0\n", 2);
	// printf("msg: %i \n", msg);
}

int main(void)
{
	pid_t pid;
	struct sigaction sa;

	pid = getpid();
	sa.sa_sigaction = receiver;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%i \n", (int)pid);
	while (1)
		pause();
	return (0);
}