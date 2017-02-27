#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//
// Estructura para los mensajes que se quieren enviar y/o recibir. Deben llevar
// obligatoriamente como primer campo un long para indicar un identificador
// del mensaje.
// Los siguentes campos son la información que se quiera transmitir en el
// mensaje. Cuando más adelante, en el código, hagamos un cast a
// (struct msgbuf *), todos los campos de datos los verá el sistema como
//un único(char *)
//
typed struct{
  long Id_Mensaje;
  int Dato_Numerico;
  char Mensaje[10];
}Mi_Tipo_Mensaje;

int int main() {
  key_t Clave1;
  int Id_Cola_Mensajes;
  Mi_Tipo_Mensaje Un_Mensaje;
  printf("Soy el proces %d\n",(int)getpid());
  //
  // Igual que en cualquier recurso compartido (memoria compartida, semáforos
  // o colas) se obtiene una clave a partir de un fichero existente cualquiera
  // y de un entero cualquiera. Todos los procesos que quieran compartir este
  // semaforo, deben usar el mismo fichero y el mismo entero.
  //
  Clave1 = ftok ("/bin/ls", 33);
  if(Clave1 == (key_t)-1){
    printf("Error al obtener clave para cola mensajes\n" );
    exit(-1);
  }

  //
  // Se crea la cola de mensajes y se obtiene un identificador para ella.
  // El IPC_CREAT indica que cree la cola de mensajes si no lo está ya.
  // El 0600 son permisos de lectura y escritura para el usuario que lance
  // los procesos. Es importante el 0 delante para que se interprete en
  // octal.
  //
  Id_Cola_Mensajes ) msgget (Clave1, 0600 | IPC_CREAT);
  if(Id_Cola_Mensajes == -1){
    printf("Error al obtener identificador para cola mensajes");
    exit(-1);
  }else{
    printf("Cola %d\n", Id_Cola_Mensajes);
  }

  // Se recibe un mensaje del otro proceso. Los párametros son:
  // -Id de la cola de mensajes.
  // -Dirección del sitio en el que queremos recibir el mensaje,
  // convirtiendolo en puntero a (struct msgbuf *).
  // -Tamaño máximo de nuestos campos de datos.
  // -Identificador del tipo de mensaje que queremos recibir. n este caso
  // se quiere un mensaje tipo 1, que es el que envia el proceso cola1.c
  // -flags. En sste caso se quiere que el programa quede bloqueado hasta
  // que llegue un mensaje tipo 1. Se pone IPC_NOWAIT, se devolvería
  // un error en caso de que no haya mensaje de tipo 1 y el programa
  // continuaría ejecutandose.
  //
  msgrcv(Id_Cola_Mensajes, (struct msgbuf *)& Un_Mensaje,
    siseof(Un_Mensaje.Dato_Numerico) + siseof(Un_Mensaje.Mensaje),
    5, 0);

    printf("Recibido mensaje tipo 5\n");
    printf("Dato_Numerico = %d\n",Un_Mensaje.Dato_Numerico);
    printf("Mensaje = %s\n",Un_Mensaje.Mensaje);

    //
    // Se rellenan los campos del mensaje que se quiere enviar.
    // El Id_Mensaje es un identificador del tipo de mensaje. Luego se podrá
    // recoger aquellos mensajes de tipo 1, tipo 2, etc.
    // Dato_Numerico es un daro que se quiera pasar al otro proceso. Se pone,
    // por ejemplo 13.
    // Mensaje es un texto que se quiera pasar al otro proceso.
    //
    Un_Mensaje.Id_Mensaje = 2;
    Un_Mensaje.Dato_Numerico = 13;
    strcpy(Un_Mensaje.Mensaje, "Adios");

    // Se envia el mensaje. Los parametros son:
    // -Id de cola de mensajes.
    // -Dirección al mensaje, convirtiendola en un puntero a (struct msgbuf *)

  return 0;
}
