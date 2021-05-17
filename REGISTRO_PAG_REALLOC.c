// REGISTRO DE PAGAMENTOS

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
 main ()
 { 
 	setlocale(LC_ALL, "");
 	char nome[15];
    int n, cont=0, condicao; 
    float media, ent, * numeros = NULL, * mais_numeros, soma = 0;
	float smaior, smenor;
	printf("\n  >>>____REGISTRO DE PAGAMENTOS____<<<  \n");
    do {
    	cont++;
        printf ("\n > Informe o nome do %d� funcion�rio: ", cont);
        scanf("%s", &nome);
        printf(" > Digite o sal�rio desse funcion�rio (ex = 1000*): ");
        scanf ("%f", &ent); 
        soma = soma + ent; 
        mais_numeros = (float*) realloc (numeros, cont * sizeof(float)); // usa-se realloc pois havia sido alocado NULL para numeros //  
            if (mais_numeros != NULL) 
            {
            numeros=mais_numeros;  // numeros recebe o resultado de cont*sizeof //
            numeros[cont-1]=ent;  // o resultado � usado como indice, e o numero lido anteriormente � o conte�do
                if (numeros[cont-1] > smaior)  // verifica se o valor digitado � maior que o armazenado em smaior
                {
                   smaior = numeros[cont-1];  // se sim, o valor � atribuido a variavel smaior //
                   smenor = numeros[cont-1];  // a variavel smenor tamb�m receber� o valor, por�m ser� alterado posteriormente
                }
            } 
            else
            {
               free (numeros);   // libera a mem�ria alocada
		       printf("Erro ao (re)alocar memoria");
               exit (1);   // para o sistema
            } 
            printf("\n_________________________________");
            printf("\nDESEJA REGISTRAR OUTRO FUNCION�RIO?\n");
            printf("\n  1 - REGISTRAR OUTRO\n");
            printf("\n  0 - FINALIZAR REGISTROS");
            printf("\n_________________________________");
            printf("\n Digite aqui >> ");
            scanf("%d", &condicao);
    } while (condicao!=0);     // o programa registrar� outro funcionario at� o usu�rio escolher finalizar os registros
   
    printf ("\n\n>> SAL�RIOS REGISTRADOS <<\n");
    for (n=0;n<cont;n++)
    {
      printf (" -> R$ %.2f\n",numeros[n]);
      if(numeros[n] <= smenor) // verifica se o valor armazenado no indice � menor ou igual ao armazenado anteriormente em smenor
       smenor = numeros[n];    //  se sim, o valor � atribuido a smenor
    }
    media = soma/cont;
    printf("\n - M�DIA DOS SAL�RIOS = R$ %.2f\n", media);
    printf(" - MAIOR SAL�RIO = R$ %.2f\n", smaior);
    printf(" - MENOR SAL�RIO = R$ %.2f\n\n", smenor);
    free (numeros);
    system("pause");
 }
