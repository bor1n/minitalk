#include "includes/server.h"


void print_char(int bit)
{
	static int shift = 0;
	static int character = 0;

	if (shift < 8)
	{
		character = character << 1;
		character = character | bit;
		shift++;
	}
	if (shift == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", (char) character);
		shift = 0;
		character = 0;
	}
}

void signal_handler(int sig) {
	if (sig == SIGUSR1)
	{

		print_char(1);
	}
	if (sig == SIGUSR2)
		print_char(0);
}

int main() {
	pid_t pid;
	pid = getpid();
	ft_printf("Server's PID:%d\n", pid);
	while(1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
}
