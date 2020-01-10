#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
	int pid[2];
	int finish;
	pid[0] = fork();
	pid[1] = fork();

	if (pid[1] > 0) 
	{
		printf("I(%d) am the parent process, I have two child processes: %d and %d.\n", getpid(), pid[0], pid[1]);
   		finish = wait(0);
   		printf("The child process %d is done and the value of pid[0] is: %d, the value of pid[1] is: %d.\n", finish, pid[0], pid[1]);
	} 

	else if (pid[1] == 0) 
	{
   		printf("I(%d) am the child process and the value of pid[0] is: (%d) , the value of pid[1] is: (%d).\n", getpid(),pid[0],pid[1]);
   		printf("The child process %d returns.\n", getpid());
	} 

	else printf ("fork error\n");
}


