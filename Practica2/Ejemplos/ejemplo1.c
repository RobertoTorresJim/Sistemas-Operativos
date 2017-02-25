#include <unistd.h>
#include <stdio.h>

/*Entrada: ----
Salida: ----
Descripción: Ejecuta la llama al sistema execv invocando al
programa genome-terminal con un conjunto de parametros
*/
void ejecutar_execv(){
	char *para[6];

	para[0]="gnome-terminal";
	para[1]="-x";
	para[2]="zsh";
	para[3]="-c";
	para[4]="ls; read -p 'Presiona la tecla [Enter] para continuar ...'";
	para[5]=NULL;
		if(execv("/usr/bin/gnome-terminal", para)==-1)
			printf("Error al ejecutar execv\n");
}
/*
Entrada: ----
Salida: ----
Descripción: Ejecuta la funcion ejecutar_execl() o ejecutar_execv()
dependiendo de la opcion del usuario.
*/
int main(){
	ejecutar_execv();
	printf("Se ha terminado la ejecución....\n");

}
