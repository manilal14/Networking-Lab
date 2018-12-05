#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h>
int main(){

    int pid,a,n,p[2],i,buffr1[100],buffr2[100];

    a = pipe(p);

    if(a == -1) { 
       printf("Pipe Failed.\n"); 
       return 0;
    }

    pid = fork();

    switch(pid){ 
       case -1:
       		printf("Error is forking\n");
			return 0;
       case 0:
	   		n = read(p[0],buffr2,sizeof(buffr2));
			printf("In child process (ID: %d)\n", getpid());
         	
         	n=n/sizeof(int);
         	printf("numbers are : ");
         	for(i=0;i<n;i++)
            	printf("%d ",buffr2[i]);
            printf("\n");
         	break;
       default: 
       		printf("In parent process (ID: %d)\n", getpid());
         	printf("Enter no. of elements : ");
         	scanf("%d",&n);
         	printf("Enter elements : ");

         	for(i=0;i<n;i++)
         		scanf("%d",&buffr1[i]);
         	
         	write(p[1],buffr1,n*sizeof(int));
         	waitpid(pid,NULL,0);
         	break;
   }

   close(p[0]);
   close(p[1]);

   return 0; 
}