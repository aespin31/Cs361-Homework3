#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 60
int main(){
	char *argsarray[] = {"/bin/ls", (char *)0};	
	char command[MAX];
	char words[MAX];
	
	int pid_number;
	int exitstatus;
	do{
		printf("CS361 > ");
		fgets(command,MAX,stdin);
		char str[MAX];
		
		int i;
		if(command[0]== 'l'){
			for(i=0; i<2;i++){
				str[i] = command[i];
			}
			str[2]=0;
		}
		if(command[1]=='x'){
			for(i=0;i<4;i++){
				
				str[i] = command[i];
			}
			str[4]=0;
		}
		int j=0;
		if(command[1]=='c'){
			for(i=0;i<4;i++){
				str[i]=command[i];
			}
			i=4;
			str[i]=0;
			i = 5;
			while(command[i]!= 0){
				words[j] = command[i];
				i++;
				j++;
			}
			j--;
		       	words[j--]=0;	

		}

		if(strcmp(str, "exit")==0){;
			return 0;
		}
		if(strcmp(str,"ls")==0){
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
		if(strcmp(str, "echo")==0){
			int pid = fork();
			if(pid==0){
				char *argsecho[] = {"echo",words, (char *)0};
				pid_number = getpid();
				execv("/bin/echo", argsecho);
			}
			else{
				int status;
				wait(&status);
				exitstatus=WEXITSTATUS(status);
			}
		}
		printf("pid:%d status:%d\n", pid_number, exitstatus);
		
	
		
		
	}while(1);

	return 0;
}
