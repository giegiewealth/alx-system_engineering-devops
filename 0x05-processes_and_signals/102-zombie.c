#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Function that runs an infinite loop to keep the program running
 *
 * Return: Always returns 0
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
 * main - Entry point of the program
 *
 * Return: Always returns 0
 */
int main(void)
{
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork(); // Create a child process
        if (child_pid == -1)
        {
            perror("Fork failed");
            return (1);
        }
        if (child_pid == 0) // This code will be executed by the child
        {
            printf("Zombie process created, PID: %d\n", getpid());
            exit(0);
        }
    }

    infinite_while(); // Parent process keeps running in an infinite loop

    return (0);
}
