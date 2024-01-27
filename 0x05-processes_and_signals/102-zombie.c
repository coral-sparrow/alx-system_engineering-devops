#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * infinite_while - Entry point
 *
 * Return: Always 0 (Success)
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}

	return (0);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid != 0)
			printf("Zombie process created, PID: %d\n", pid);
		else if (pid == 0)
			exit(EXIT_SUCCESS);
	}

	infinite_while();
	return (0);
}
