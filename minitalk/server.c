#include <signal.h>
#include <unistd.h>

static void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	print_pid(void)
{
	write(1, "Server PID: ", 12);
	putnbr(getpid());
	write(1, "\n", 1);
}

static void	handle_signal(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	if (sig == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
}

int	main(void)
{
	setup_signals();
	print_pid();
	while (1)
		pause();
	return (0);
}
