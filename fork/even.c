#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	int a1,a2,p1[2],p2[2],pid,n;
	int	buff1[100],buff2[100], tempBuff[100],result[100];

	a1 = pipe(p1);
	a2 = pipe(p2);

	if(a1 == -1 || a2 == -1){
		printf("Can't create pipe\n");
		return 0;
	}

	pid = fork();

	switch(pid)
	{

		case -1 :
			printf("Fork can't create a child process\n");
			break;

		case 0:
			
			n = read(p1[0], buff2, sizeof(buff2));
			printf("In child process (ID : %d)\n", getpid());
			n = n/sizeof(int);

			printf("Given elements are : \n");

			for(int i=0;i<n;i++){
				printf("%d ", buff2[i]);
				if(buff2[i] % 2 == 0)
					tempBuff[i] = 0;
				else
					tempBuff[i] = 1;
			}

			printf("\n");

			write(p2[1], tempBuff, n*sizeof(int));
			break;

				


		default : 

			printf("In Parent process (ID : %d)\n", getpid());

			printf("Enter number of elements : ");
			scanf("%d",&n);
			printf("Enter elements : ");
			for(int i=0;i<n;i++)
				scanf("%d",&buff1[i]);

			write(p1[1], buff1, n*sizeof(int));
			waitpid(pid,NULL,0);


			n = read(p2[0],result, sizeof(result));
			printf("In Parent process (ID : %d)\n", getpid());
			n = n / sizeof(int);

			for(int i=0;i<n; i++){
				if(result[i] == 0)
					printf("%d is even \n",buff1[i]);
				else
					printf("%d is odd \n",buff1[i]);
			}

			break;
		}

	close (p1[0]);
	close (p1[1]);
	close (p1[0]);
	close (p2[1]);
	
	return 0;


	




}