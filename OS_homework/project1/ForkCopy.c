#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char* argv[]) {
	// fork a child process
	int record = fork();
	char * const *envp = NULL;
	switch (record) {
		case -1: 
			printf("Error: Failed to fork.\n"); 
			break;
		case 0: 
			// to complete 
			execve("/bin/cp", argv, envp);
			break;

		default: 
			wait(0);
	}

	exit(0);
}
