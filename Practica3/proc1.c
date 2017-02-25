#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typed struct{
  long Id_Mensaje;
  int Dato_Numerico;
  char Mensaje[10];
}Mi_Tipo_Mensaje;

int main(){
  key_t Clave1;
  int Id_Cola_Mensajes;
  Mi_Tipo_Mensaje Un_Mensaje[3];
  Mi_Tipo_Mensaje Resp;

  printf("Soy el proceso %d\n", (int)getpid());
  Clave1 = ftok ("/bin/ls", 33);
  if(Clave1 == (key_t)-1){
    printf("Error al obtener clave para cola de mensajes");
    exit(-1);
  }
  //
  //Se crea la cola de mensajes y se obtiene un identificados para ella.
  //El IPC_CREAT indica que cree la cola de mensajes si no lo está ya.
  //el 0600 son permisos de lectura y escritura para el ususario que lance
  //los procesos. Es importante el 0 delante para que se interprete en octal.
  //
  Id_Cola_Mensajes = msgget(Clave1, 0600 | IPC_CREAT);

  if(Id_Cola_Mensajes == -1){
    printf(""Error al obtener identificador para cola de mensajes");
    exit(-1);
  }else{
    printf(Cola %d\n",Id_Cola_Mensajes);
  }

  //
  //Se rellenan los campos del mensaje que se quiere enviar.
  //
  Un_Mensaje[0].Id_Mensaje = 1;
  Un_Mensaje[0].Dato_Numerico = 29;
  strcpy(Un_Mensaje[0].Mensaje, "Hola");

  Un_Mensaje[1].Id_Mensaje = 3;
  Un_Mensaje[1].Dato_Numerico = 25;
  strcpy(Un_Mensaje[1]-Mensaje, "Hola1");

  Un_Mensaje[2].Id_Mensaje = 5;
Un_Mensaje[2].Dato_Numerico = 24;
strcpy (Un_Mensaje[2].Mensaje, "Hola2");
  //
  // Se envia el mensaje. Los parámetros son:
  // - Id de la cola de mensajes.
  // - Dirección al mensaje, convirtiéndola en puntero a (struct msgbuf*)
  // - Tamaño total de los campos de datos de nuesto mensaje, es decir
  // de Dato_Numerico y de Mensaje
  // -Unos flags. IPC_NOWAIT indica que si el mensaje no se puede enviar
  // (habitualmente porque la cola de mensajes esta llena), que no espere
  // y de un error. Si no se pone este flag, el programa queda bloqueado
  // hasta que se pueda enviar el mensaje.
  //
  msgsend(Id_Cola_Mensajes, (struct msgbuf*)&(Un_Mensaje[0]),
  siseof(Un_Mensaje[0].Dato_Numerico)+sizeof(Un_Mensaje[0].Mensaje),
  IPC_NOWAIT);
  msgsend(Id_Cola_Mensajes, (struct msgbuf*)&(Un_Mensaje[1]),
  siseof(Un_Mensaje[1].Dato_Numerico)+sizeof(Un_Mensaje[1].Mensaje),
  IPC_NOWAIT);
  msgsend(Id_Cola_Mensajes, (struct msgbuf*)&(Un_Mensaje[2]),
  siseof(Un_Mensaje[2].Dato_Numerico)+sizeof(Un_Mensaje[2].Mensaje),
  IPC_NOWAIT);
  printf("ya entregue el mensaje\n");

  //
  // Se recibe un mensaje del otro proceso. Los parámetros son:
  // -Id de la cola de mensajes.
  // -Dirección del sitio en el que queremos recibir el mensaje,
  // convirtiéndolo en puntero a (struct msgbuf*).
  // -Tamaño máximo de nuestos campos de datos.
  //
}
