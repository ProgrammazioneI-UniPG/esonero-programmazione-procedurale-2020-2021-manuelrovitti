#include <stdio.h>
#include <stdlib.h>
#include <time.h>         //includo le librerie
#include <string.h>

int main(){
  
  char M[128],K[128],C[128];    //M=message, K=key, C=cript-message
  int scelta;                   //scelta del modo in cui inserire la key
  int i;
  time_t t;

  //chiedo M(max 128 caratteri) e  chiedo in che modo vuole proseguire
  printf("\n----------Benvenuto!----------\n");
  printf ("\n|Ti chiedo di inserire una stringa M di massimo 127 caratteri.\n" );
  printf("|Se inserirai più di 127 caratteri i successivi saranno eliminati.\nM: ");
  fgets(M, 128, stdin);
  printf("\nLa stringa M è lunga: %lu.\n", strlen(M));
  printf("\nOra hai due possibilità:\n");
  printf(">>Digita 1 per inserire la chiave K.\n>>Digita 2 per generare un chiave K.\nScelta:");
  scanf("%d", &scelta);
  getchar();

  switch (scelta) {
    //prima scelta: la K viene inserita manualmente
    case 1: {
      printf("\n|Hai scelto di inserire la chiave K.");
      printf("\n|Inserisci la chiave K di massimo 127 caratteri per la cifratura.");
      printf("\n|La chiave K non deve essere inferiore alla stringa M.\nK: ");
      do {
        fgets(K, 128, stdin);
        if (strlen(M) > strlen(K)){
          printf("La chiave K è meno lunga della stringa M.\nPer favore reinserisci la K:  \n");
        }
      } while (strlen(M) > strlen(K)); //loop per avere k >= a M

      printf("\n|Perfetto!\n|Ora possiamo criptare la stringa M.\n");
      printf("\nLa tua stringa criptata è: ");
      for (i=0; i<strlen(M); i++){
        C[i]=M[i]^K[i];                   //xor per ricavare C
        printf("%c",C[i]+32);             //+32 per evitare i carattrei "speciali"
      }
      printf("\nIl tua stringa è: " );
      for (i=0;i<strlen(M); i++){
        M[i]=C[i]^K[i];                 //xor per riavere la stringa M
        printf("%c",M[i]);
      }
      break;
    }
  //seconda scelta, la K viene generata automaticamente
  case 2:{
    srand((unsigned) time(&t));
    printf("\nHai scelto di generare una chiave randomica.");
    printf("\nLa tua chiave K è: ");
    for (i=0;i<strlen(M);i++){          //genero la chiave K
      K[i]=random()%128;
      printf("%ld ", random()%128 );
    }
    printf("\n\nLa tua stringa criptata è: " );
    for (i=0;i<strlen(M);i++){        //xor con k generata
      C[i]=M[i]^K[i];
      printf("%c", C[i]+32);        //+32 per evitare i caratteri "speciali"
    }
    printf("\nLa tua stringa è: " );
    for (i=0;i<strlen(M);i++){      //xor per riavere la stringa M
      M[i]=C[i]^K[i];
      printf("%c",M[i]);
    }
    break;
  }

  default :
      printf("Hai inserito una scelta non valida. \n");
      break;
    }

  return 0;
}
