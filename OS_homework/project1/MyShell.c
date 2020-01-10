#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int parseCommand (char* cmd, char* cmd_array[]) {
	int count = 0;
	char *p;
	p = strtok( cmd, " " );

	while(p != 0)
	{
		cmd_array[count++] = p;
		p = strtok( NULL, " " );
	}

	cmd_array[count++] = '\0';
    return count;
}

int main()
{
	while(1)
	{
		printf("myshell> ");

		char *cmd; // store the cmd
		cmd = malloc(sizeof(char)*100);

		fgets(cmd, 100, stdin);
		size_t len = strlen(cmd);
		if (len > 0 && cmd[len-1] == '\n')
            cmd[len-1] = '\0';

        if (strcmp( cmd, "exit" ) == 0)
			exit(0);

       	char *cmd_array[10]; // to store each argument in the command string
        parseCommand(cmd, cmd_array);
		
		int record = fork();
		int status;
		if( record != 0){
			waitpid(-1, &status, 0);
		}
		else{
			execvp(cmd_array[0], cmd_array);//cmd_array[0]存储命令，后面位置存储命令对应的参数
		}
		// to complete
        // 1. fork a child process
		// 2. use function "execvp" to execute the command

		free(cmd);
	}
	exit(0);
}

/*
tips:

生成一个提示符，读取一个command（包含所有参数），然后传给execve

让子程序去跑

*/
