#include "includes/client.h"

int g_signal;

void signal_handler(int sig) {
	g_signal = sig;
}

int validate(int sig)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pause();
	if (sig == g_signal)
		return (0);
	return (1);
}

int send_char(pid_t pid, int character)
{
	int shift;
	int mask;
	int signal;

	mask = 128;
	shift = 0;
	while (shift < 8)
	{
		if (character & mask)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		kill(pid, signal);
		if (validate(signal))
		{
			ft_printf("An error occurred. Signal is lost.");
			exit(1);
		}
		character = character << 1;
		shift++;
		usleep(50);
	}
	return 1;
}
int send_message(pid_t pid, char *message)
{
	int character;

	while (*message)
	{
		character = (int) *message;
		send_char(pid, character);
		message++;
	}
	send_char(pid, '\0');
	return 0;
}

int main(int argc, char **argv) {
	pid_t pid;
	char *message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			exit(1);
		message = argv[2];
		send_message(pid, message);
	}
	else
	{
		ft_printf("Usage: ./client (SERVER PID) (MESSAGE)");
	}
	return EXIT_SUCCESS;
}