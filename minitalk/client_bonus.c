#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static volatile sig_atomic_t	g_ack = 0;

static void	handle_ack(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_char(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		return (1);
	signal(SIGUSR1, handle_ack);
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	while (!g_ack)
		pause();
	write(1, "ACK received\n", 13);
	return (0);
}
