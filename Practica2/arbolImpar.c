#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(){
 int v1,v2,a=0;
 int n = 7;
 int i = 0;
	//Ciclo para crear procesos 
	while(n >= 1){
		for(i = 0; i < n-1; i++){
			if(fork())
				break;
		}
		if(i==n)
			exit(1);
		else
			wait(&v1);
			wait(&v2);
		n=n-2;
		if(i == 0){
			fork();
			
		}
	}
	if(i == 0)
		printf("Procesos %d \n", WEXITSTATUS(v1)+1);
	else
		exit(WEXITSTATUS(v1)+1);
}
		
/*
		wait(&v1);
		wait(&v2);
			if(i!=0){
		a = WEXITSTATUS(v1) + WEXITSTATUS(v2) + 1;
			exit(a);
			}
		printf("Numero de procesos %d\n",WEXITSTATUS(v1)+WEXITSTATUS(v2)+1);
				}
		}
*/	

