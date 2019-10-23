#include <stdio.h>
#include <string.h>
#define MAX 20
int main(){

	char command[MAX];
	char command2[10];
	char command3[10];

	printf("Input ");
	fgets(command,MAX,stdin);	
	char str[MAX];
	printf("\nyou entered: %s\n", command);
	int i;
	for(i = 0; i <4; i++){
		printf("Values: %c \n", command[i]);
		str[i] = command[i];
	}	
	str[i++] = 0;
	printf("The str: %s\n", str);
	if(strcmp(str, "echo")==0){
		printf("This is echo\n");
	}
	



	return 0;
}
