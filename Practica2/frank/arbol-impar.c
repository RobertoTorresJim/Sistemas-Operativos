#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
 
main(){
pid_t pid,pid_raiz;
 int x,y,N,status=0,k;
 pid_raiz=getpid();


printf("¿Introduce un numero >=0?\n");
scanf("%d",&N);
k=(N*2)+1;
wait(&status);
//for(x=(k-1);x>0;x--){
for(x=(N+1);x>1;x=x-2){
		if((pid=fork())==0){
			printf("Soy el proceso hijo: %d y mi padre es %d \n",getpid(),getppid());
                        //exit(WEXITSTATUS(status)+1);
		}else{

		if(pid==-1){
			printf("Error en la creacion del proceso \n");
		exit(1);

		}else{
		printf("Soy el proceso padre: %d \n",getpid());
		wait(&status);
                //exit(WEXITSTATUS(status)+1);
                break;

		}
		}
}
x=(x*2)-2;
//printf("El valor de x es:%d soy el proceso=%d \n",x,getpid());
for(y=0;y<x;y=y+2){

 if((pid=fork())==0){
			printf("Soy el proceso hijo: %d y mi padre es %d \n",getpid(),getppid());
                        //exit(WEXITSTATUS(status)+1);
		}else{

		if(pid==-1){
			printf("Error en la creacion del proceso \n");
		exit(1);

		}else{
		printf("Soy el proceso padre: %d \n",getpid());
		wait(&status);
                break;

		}

		}

}
if(pid_raiz==getpid()){
			printf("El numero de procesos que somos es: %d \n",WEXITSTATUS(status)+1);
		exit(0);

		}else
		exit(WEXITSTATUS(status)+1);




}//fin main 
