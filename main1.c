#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mod(int i, int i1);

int main ()
{

    char buff[256];
    char buffResultA[256];
    char buffResultB[256];
    char buffResultC[256];
    char buffResultRefl[256];
    char a;
    char b;
    char c;
    //int i = 0;
    int j=0;
    printf ("inserisci la lettera della prima configurazione\n");
    scanf ("%c", &a);
    fflush (stdin);
    printf ("inserisci la lettera della seconda configurazione\n");
    scanf (" %c", &b);
    fflush (stdin);
    printf ("inserisci la lettera della terza configurazione\n");
    scanf (" %c", &c);
    fflush (stdin);
    printf ("inserisci la parola\n");
    scanf (" %s", buff);
    //gets(buff);
    char A[] = { 'd', 'm', 't', 'w', 's', 'i', 'l', 'r', 'u', 'y', 'q', 'n', 'k', 'f', 'e', 'j', 'c', 'a', 'z', 'b', 'p', 'g', 'x', 'o', 'h', 'v' };
    char B[] = { 'h', 'q', 'z', 'g', 'p', 'j', 't', 'm', 'o', 'b', 'l', 'n', 'c', 'i', 'f', 'd', 'y', 'a', 'w', 'v', 'e', 'u', 's', 'r', 'k', 'x' };
    char C[] = { 'u', 'q', 'n', 't', 'l', 's', 'z', 'f', 'm', 'r', 'e', 'h', 'd', 'p', 'x', 'k', 'i', 'b', 'v', 'y', 'g', 'j', 'c', 'w', 'o', 'a' };
    char riflettore[] = {'r', 'u', 'm', 'k', 'p', 'e', 'n', 'j', 'c', 'x', 'q', 'o', 'y', 'v', 'i', 'l', 'z', 'd', 's', 'b', 'g', 'w', 'h', 'f', 'a', 't'};
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };


    for (j = 0; j < strlen (buff); j++)
    {
        int index = mod((buff[j] - a),26);
        buffResultA[j] = A[ index ];
    }

    for (j = 0; j < strlen (buffResultA); j++)
    {
        int index2 = mod((buffResultA[j] - b),26);
        buffResultB[j] = B[index2];
    }

    for (j = 0; j < strlen (buffResultB); j++)
    {
        int index3 = mod((buffResultB[j] - c),26);
        buffResultC[j] = C[index3];
    }
    
    for (j = 0; j < strlen (buffResultC); j++)
    {
      buffResultRefl[j] = riflettore[(buffResultC[j]) % 26];
      printf("\n%d\n", (buffResultRefl[j]) % 26);
    }

    printf ("il testo base  %s\n", buff);
    printf ("il testo dopo il primo rotore  %s \n", buffResultA);
    printf ("il testo dopo il secondo rotore  %s \n", buffResultB);
    printf ("il testo dopo il terzo rotore  %s \n", buffResultC);
  	printf ("il testo dopo il riflettore  %s \n", buffResultRefl);

    
    char buffFinal[256];
    strcpy(buffFinal, buffResultC);

    char buffFinal1[256];
    char buffFinal2[256];
    char buffFinal3[256];

    for (j = 0; j < strlen (buffFinal); j++)
    {
    	int index4 = strchr(C, buffFinal[j]) - C;
    	buffFinal1[j] = c + index4;
    }

    for (j = 0; j < strlen (buffFinal1); j++)
    {
    	int index5 = strchr(B, buffFinal1[j]) - B;
    	buffFinal2[j] = b + index5;
    }

    for (j = 0; j < strlen (buffFinal2); j++)
    {
    	int index6 = strchr(A, buffFinal2[j]) - A;
    	buffFinal3[j] = a + index6;
    }


    printf ("il testo dopo il terzo rotore  %s \n", buffFinal);
    printf ("il testo dopo il secondo rotore  %s \n", buffFinal1);
    printf ("il testo dopo il primo rotore  %s \n", buffFinal2);
    printf ("il testo base  %s\n", buffFinal3); 

    return 0;
}

int mod(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

