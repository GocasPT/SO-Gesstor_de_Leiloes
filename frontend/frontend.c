#include "frontend.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **getCommad(char *str, int *index){
  char **argv = malloc(sizeof(char *));
  char s[2] = " ";
  char *tmp;
  int i = 0;

  tmp = strtok(str, s);
  tmp[strcspn(tmp, "\n")] = 0;

  while( tmp != NULL ) {
    argv = realloc(argv, (i + 1) * sizeof(char *));
    argv[i] = tmp; 
    tmp = strtok(NULL, s);
    i++;
  }

  *index = i - 1;
  return argv;
}

int main(int argc, char *argv[]){
   //  Verifaicar de backend está aberto
  if(0){
    printf("O Backend nao esta aberto\n");
    exit(1);
  }

  //  Validação se foi introduzido credênciais
	if(argc < 2) {
    printf("Precisa de loggin\n");
    exit(1);
  } else if (argc != 3) {
    printf("Nao foi incerido password\n");
    exit(1);
	}

  printf("\033[2J\033[1;1H");
  printf("  ______ _____   ____  _   _ _______ ______ _   _ _____  \n");  
  printf(" |  ____|  __ \\ / __ \\| \\ | |__   __|  ____| \\ | |  __ \\ \n");
  printf(" | |__  | |__) | |  | |  \\| |  | |  | |__  |  \\| | |  | |\n");
  printf(" |  __| |  _  /| |  | | . ` |  | |  |  __| | . ` | |  | |\n");
  printf(" | |    | | \\ \\| |__| | |\\  |  | |  | |____| |\\  | |__| |\n");
  printf(" |_|    |_|  \\_\\\\____/|_| \\_|  |_|  |______|_| \\_|_____/ \n"); 
  printf("\nBem vindo, %s\n", argv[1]);
  fflush(stdout);                                            
                                                         

  //  Mandar credenciais para backend


  //  Leitura de comandos
  char input[MAX];
  char **cmd;
  int index;

  while(1){
    printf("<User> ");
    fgets(input, MAX, stdin);
    cmd = getCommad(input, &index);

    if(!strcmp(cmd[0], "sell")){
      if(index != 5)
        printf("$ Parametos incompletos\n");
      else
        printf("sell...\n");

    }else if(!strcmp(cmd[0], "list")){
      printf("list...\n");

    }else if(!strcmp(cmd[0], "licat")){
      if(index != 1)
        printf("$ Parametos incompletos\n");
      else
        printf("licat\n");

    }else if(!strcmp(cmd[0], "lisel")){
      if(index != 1)
        printf("$ Parametos incompletos\n");
      else
        printf("lisel\n");

    }else if(!strcmp(cmd[0], "lival")){
      if(index != 1)
        printf("$ Parametos incompletos\n");
      else
        printf("licat\n");

    }else if(!strcmp(cmd[0], "time")){
      printf("time\n");

    }else if(!strcmp(cmd[0], "buy")){
      if(index  != 2)
        printf("$ Parametos incompletos\n");
      else
        printf("licat\n");

    }else if(!strcmp(cmd[0], "cash")){
      printf("cash\n");

    }else if(!strcmp(cmd[0], "add")){
      if(index != 1)
        printf("$ Parametos incompletos\n");
      else
        printf("add\n");

    }else if(!strcmp(cmd[0], "exit")){
      exit(1);

    }else
      printf("$ Comando inextente\n");
  }

	return 0;
}
