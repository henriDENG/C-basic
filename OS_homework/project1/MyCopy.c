#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

//效果：将前一个文件复制到后一个中，若后一个文件不存在，则新建一个文件并将内容复制进去

int main (int argc, char* argv[]) {
	// open files and detect error
	FILE *src, *dest;
	src = fopen(argv[1], "r");
	if (src == NULL) {
		printf("Error: Could not open file '%s'.\n", argv[1]);
		exit(-1);
	}
	dest = fopen(argv[2], "w+");
	if (dest == NULL) {
		printf("Error: Could not open file '%s'.\n", argv[2]);
		fclose(src);
		exit(-1);
	}

	// start copying
	size_t read_in; // length of the read in string
	char buffer[BUFFER_SIZE];
	while (read_in = fread(buffer, 1, BUFFER_SIZE, src))
		fwrite(buffer, 1, read_in, dest);

	// close files
	fclose(src);
	fclose(dest);

	exit(0);
}

/*
tips：

//argc代表需要拷贝的文档有多少参数
//argv字符指针数组

src可看成一个流

ex:
 /Mycopy a.c b.c
    argu[0],argu[1],argu[2] ->argc = 3;

fork函数作用：
生成一个新的进程


Execve函数作用：
用另外的文件替换当前process里存的text部分(memory)，
这样刚才创建的进程可以执行这个文件

code：
    pid = fork();
    char *envp = {0, NULL};
    if( pid == 0){
        execve("cp”，argv, envp) //cp为我们想让它跑的可执行文件， argv把参数的argv赋给它，envp）
    }
    else if( pid >0){
        继续做主进程该做的事
    }


*/

