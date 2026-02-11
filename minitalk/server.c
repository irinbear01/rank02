#include <signal.h>
#include <unistd.h>

static void	handle_signal(int sig)
{
	static int	bit_count = 0;
	static char	c = 0;

	if (sig == SIGUSR2)
		c |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	write(1, "Server PID: ", 12);
	{
		int		pid;
		char	buf[12];
		int		len;

		pid = getpid();
		len = 0;
		while (pid > 0)
		{
			buf[len++] = (pid % 10) + '0';
			pid /= 10;
		}
		while (--len >= 0)
			write(1, &buf[len], 1);
		write(1, "\n", 1);
	}
	while (1)
		pause();
	return (0);
}
