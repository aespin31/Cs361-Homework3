#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	char *argsarray[] = {"/bin/ls", (char *)0};	

	char command[10];
	int end = 1;
	int pid_number;
	int exitstatus;
	do{
		printf("CS361 > ");
		scanf("%s",command);
		if(strcmp(command, "exit")==0){
			return 0;
		}
		if(strcmp(command,"ls")==0){
			int pid = fork();

			if(pid ==0){
				pid_number = getpid();
				execv(argsarray[0], argsarray);
			}
			else{
				int status;
				wait(&status);
				exitstatus=WEXITSTATUS(status);
			}
			
	}
		printf("pid:%d status:%d\n", pid_number, exitstatus);
		end =0;
	
		
		
	}while(end == 1);

	return 0;
}
