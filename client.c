#include "includes/client.h"

int send_char(pid_t pid, int character)
{
	int shift;
	int mask;

	mask = 128;
	shift = 0;
	while (shift < 8)
	{
		if (character & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		character = character << 1;
		shift++;
		usleep(100);
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
	return EXIT_SUCCESS;
}