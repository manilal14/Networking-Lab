#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h> 
int main(){ 
   int pid,a,n,p[2],i,vv;
   char buffr1[100][100],buffr2[100][100];

   printf("Enter no. of strings : ");
   scanf("%d",&n);

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
       		read(p[0],buffr2,sizeof(buffr2));
         	printf("In child process (ID: %d)\n", getpid());
         	for(i=0;i<n;i++)
            	printf("String %d : %s\n",i+1,buffr2[i]);
         	exit(1);
         	break;
       default:
            printf("In parent process (ID: %d)\n", getpid());
         	for(i=0;i<n;i++){
            	printf("Enter the string %d : ",i+1);
            	scanf("%s",buffr1[i]);
         	}
         	write(p[1],buffr1,sizeof(buffr1));
         	waitpid(pid,NULL,0);
         	break;
    } 
    close(p[0]);
    close(p[1]);
    return 0; 
}