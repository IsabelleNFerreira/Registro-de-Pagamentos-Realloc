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
        printf ("\n > Informe o nome do %dº funcionário: ", cont);
        scanf("%s", &nome);
        printf(" > Digite o salário desse funcionário (ex = 1000*): ");
        scanf ("%f", &ent); 
        soma = soma + ent; 
        mais_numeros = (float*) realloc (numeros, cont * sizeof(float)); // usa-se realloc pois havia sido alocado NULL para numeros //  
            if (mais_numeros != NULL) 
            {
            numeros=mais_numeros;  // numeros recebe o resultado de cont*sizeof //
            numeros[cont-1]=ent;  // o resultado é usado como indice, e o numero lido anteriormente é o conteúdo
                if (numeros[cont-1] > smaior)  // verifica se o valor digitado é maior que o armazenado em smaior
                {
                   smaior = numeros[cont-1];  // se sim, o valor é atribuido a variavel smaior //
                   smenor = numeros[cont-1];  // a variavel smenor também receberá o valor, porém será alterado posteriormente
                }
            } 
            else
            {
               free (numeros);   // libera a memória alocada
		       printf("Erro ao (re)alocar memoria");
               exit (1);   // para o sistema
            } 
            printf("\n_________________________________");
            printf("\nDESEJA REGISTRAR OUTRO FUNCIONÁRIO?\n");
            printf("\n  1 - REGISTRAR OUTRO\n");
            printf("\n  0 - FINALIZAR REGISTROS");
            printf("\n_________________________________");
            printf("\n Digite aqui >> ");
            scanf("%d", &condicao);
    } while (condicao!=0);     // o programa registrará outro funcionario até o usuário escolher finalizar os registros
   
    printf ("\n\n>> SALÁRIOS REGISTRADOS <<\n");
    for (n=0;n<cont;n++)
    {
      printf (" -> R$ %.2f\n",numeros[n]);
      if(numeros[n] <= smenor) // verifica se o valor armazenado no indice é menor ou igual ao armazenado anteriormente em smenor
       smenor = numeros[n];    //  se sim, o valor é atribuido a smenor
    }
    media = soma/cont;
    printf("\n - MÉDIA DOS SALÁRIOS = R$ %.2f\n", media);
    printf(" - MAIOR SALÁRIO = R$ %.2f\n", smaior);
    printf(" - MENOR SALÁRIO = R$ %.2f\n\n", smenor);
    free (numeros);
    system("pause");
 }
