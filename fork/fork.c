#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main ()
{ 
	int p1;

	p1=fork();
	
	switch(p1)
	{
		case -1: 
			printf("Error is forking\n");
			break;
			
 		case 0: 
 			printf("Child created and its id is %d\n",getpid());
 			break;

		default: 
			printf("parent id : %d \n",getpid());
	}
	return 0;
}