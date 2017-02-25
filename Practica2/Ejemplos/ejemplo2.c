#include <unistd.h>
#include <stdio.h>

/*
Entrada: ----
Salida: La opcion seleccionada por el usuario
Descripcion: Menu para la seleccion a ejecutar_execv
*/
int menu(){
  int option;
  printf("1 ---- ejecute execl\n");
  printf("2 ---- ejecute execv\n");
  scanf("%d",&option);
  return option;
}
/*
Entrada: ----
Salida: ----
Descripcion: Ejecuta la llamada al sistema execl invocando al programa
  xterm con un conjunto de parametros
*/
void ejecutar_execl(){
  if(execl("/usr/bin/xterm","xterm","-fg","green","-bg","black","-cr","yellow",NULL)==-1)
    printf("Error al ejecutar execl\n");
}
pensa
/*
Entrada: ----
Salida: ----
Descripcion: Ejecuta la llamada al sistema execv invocando al programa
  xterm con un conjunto de parametros
*/
void ejecutar_execv(){
  char *para[6];

para[0] = "xterm";
para[1] = "-fg";
para[2] = "green";
para[3] = "-fn";
para[4] = "9x15";
para[5] = NULL;
  if(execv("/usr/bin/xterm", para) == -1)
    printf("Error al ejecutar execv\n");
}
/*
Entrada: ----
Salida: ----
Descripcion: Ejecuta la funcion ejecutar_execl() o ejecutar_execv() dependiendo
  la opcion del usuario
*/
int main(){
  switch (menu()) {
    case 1:
      ejecutar_execl();
      break;
    case 2:
      ejecutar_execv();
      break;
  }
}
