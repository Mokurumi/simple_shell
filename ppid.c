#include "main.h"

/**
 * _ppid - PID
 *
 * Return: Always 0.
 */
int _ppid(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
