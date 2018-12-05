#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int pid,a1,a2,n,p1[2],p2[2];
	int palindrome[100],result[100];
	char buffr1[100][20],buffr2[100][20];

	printf("Enter number of Strings : ");
			scanf("%d",&n);
			
	
	a1 = pipe(p1);
	a2 = pipe(p2);
	if (a1 ==-1 || a2 == -1)
	{
		printf("Error is forking\n");
		return 0;
	}
	pid = fork();
	switch(pid)
	{
		case -1:printf("Fork Failed\n");
				 return 0;
		case 0: 
			read(p1[0],buffr2,sizeof(buffr2));
			printf("In child process (ID: %d)\n",getpid());
			for(int i=0;i<n;i++)
			{
				int flag = 0;
				printf("String %d : %s\n",i+1,buffr2[i]);
				int l = 0; 
    			int h = strlen(buffr2[i]) - 1; 
    			while (h > l) 
    			{
        			if (buffr2[i][l] != buffr2[i][h]) 
        			{ 	
            			palindrome[i] = 0;
						flag=1;
						break; 
        			}

        			l++;
        			h--;
    			}

				if(!flag)
				palindrome[i] = 1;

			}
			write(p2[1],palindrome,n*sizeof(int));
			break;

		default: 
			printf("In parent process (ID:%d)\n",getpid());
			
			for(int i=0;i<n;i++)
			{
				printf("Enter string %d : ",i);
			 	scanf("%s",buffr1[i]);
			}
			write(p1[1],buffr1,sizeof(buffr1));
			waitpid(pid,NULL,0);

			read(p2[0],result,sizeof(result));
			printf("In parent process (ID: %d)\n",pid);
			for(int i=0;i<n;i++)
			{
				if(result[i]==0)
					printf("%s is not a palindrome.\n",buffr1[i]);
				else
			printf("%s is a palindrome.\n",buffr1[i]);
			}
			break;
	}
	close(p2[0]);
	close(p2[1]);
	close(p1[0]);
	close(p1[1]);
	return 0;
}
