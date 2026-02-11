#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
