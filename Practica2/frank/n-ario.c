#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{//inicio main 
 pid_t pid,pid_raiz;
 int x,y,n,status=0;
 pid_raiz=getpid();


 printf("Profundidad del arbol:\n");
 scanf("%d",&n);


for(x=1;x<=n;x++)
{//inicio for 1
	pid=fork(); 
	if(pid)
	{//inicio if 1
   		printf("Soy el proceso %d\n",getpid());
   		wait(&status);
		
  	}//fin if 1

	else
	{// inicio else 1
   		printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
  	
 		for(y=1;y<=n;y++)
		        {//inicio for 2
			pid=fork();
     				if(pid)
   			        {//inicio if 2
     					 printf("Soy el proceso %d\n",getpid());
   					 wait(&status);
					
    				 }//fin if 2
     				 else
     				{//inicio else 2
      				printf("soy el hijo %d, mi padre es %d\n",getpid(),getppid());
     				exit(WEXITSTATUS(status)+1);
			
      			
          			}//fin else 2
                        }//fin for 2
         exit(WEXITSTATUS(status)+1);
	}//fin else 1
  
 }//fin for 1
if(pid_raiz==getpid()){
			printf("El numero de procesos que somos es: %d \n",WEXITSTATUS(status)+1);
		exit(0);

		}
 return 0;
}//fin main 
