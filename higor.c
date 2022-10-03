// NOMES : Pedro Henrique de Souza Ferreira , Higor do Nascimento Santos.

#include <stdio.h>
#define CAP 5
#define TRUE 1
#define FALSE 0

int funcInserir (int vetor[], int capacidade, int *quantidade, int numero);
int buscarvalor (int vetor[], int quantidade, int x);
void funcremover (int v[], int *quantidade, int numero);
int funcalterarvalor (int vett[], int tamanho, int A, int B);
int funcEncontrar (int vetorE[], int tamanho, int valorE);
void exibir (int v[], int quantidade);
 
void main()
{
    
   int vetor[CAP], quant, num, num1T, num2T, numeroP, respostaPosicao, numero, resultado, resp, recebe;
 
   int i;
   
 do
 {
   printf(" - Escolha (1) para inserir um numero na primeira posicao livre.\n - Escolha (2) para remover um numero do vetor. \n - Escolha (3) para trocar o valor de um numero no vetor. \n - Escolha (4) para encontrar a posicao de um numero do vetor.\n - Escolha (5) para exibir os elementos do vetor.\n - Escolha (6) para finalizar o programa -.\n ");
   scanf("%d", &i);
    switch(i)
    {
       
       
        case 1: printf ("Entre com o valor a ser inserido: OBS: Numeros repetidos nao serao inseridos!:\n");
        		scanf("%d", &numero);
        		resultado = funcInserir (vetor, CAP, &quant, numero);
        		if (resultado == FALSE)
        		{
        			printf ("Vetor cheio!\n");
				}
			
                break;
           		
        case 2 :  	printf ("Digite o numero que deseja remover:\n");
                  	scanf ("%d", &num);
                  	
                  	funcremover (vetor, &quant, num);
                       
                	break;
                  
        case 3 :    
              printf ("Qual numero sera trocado? ");
              scanf ("%d", &num1T);
              
              recebe = funcEncontrar (vetor, quant, num1T);
              
              if(recebe == -1)
              {
              		printf("Valor nao foi encontrado no vetor!\n");
              		break;
			  }
			
              printf ("Por qual valor sera alterado? ");
              scanf ("%d", &num2T);
              
              resp = funcalterarvalor (vetor, quant, num1T, num2T);
              
              if(resp == -1)
              {
              	  printf("Valor ja existe no vetor!\n");
			  }
			  
              break;
              
      case 4 : printf(" \n Escolha o numero para encontrar sua posicao.");
               scanf("%d", &numeroP);
               
               respostaPosicao = funcEncontrar (vetor, quant, numeroP);
               
               if (respostaPosicao == -1)
               {
               		printf ("\nValor nao encontrado\n");
			   }
			   else
			   		{
			   			printf("Posicao do valor encontrado :%d\n", respostaPosicao);
			   		}
               		break;
               
               
      case 5 : printf("Exibicao do vetor:\n");
                
               exibir (vetor, quant);
               break;
               
            
      case 6 :     printf("Programa finalizado.");       
                break;
               
      default :  printf("opcao invalida");
                break;
    }
    
  }while(i!=6);     
       
} 
int funcInserir (int vetor[], int capacidade, int *quantidade, int numero)
{
	
	int pos, i, j;
	
	if (*quantidade == capacidade)
	{
		return FALSE;
	}
	else
		{
			
			pos = buscarvalor (vetor, *quantidade, numero);
		
			for (i=*quantidade-1;i>=pos;i--)
			{
				
				if (vetor[i] == numero)
				{
					(*quantidade)--;
				}
				else
					{
						vetor[i+1] = vetor[i];				
					}
				
			}
			vetor[pos] = numero;
			
			(*quantidade)++;
		
			return TRUE;
	}
}
int buscarvalor (int vetor[], int quantidade, int x)
{
	int i, j;
	
	for (i=0;i<quantidade;i++)
	{
		
		if (vetor[i] >= x)
		{		
			return i;
		}
			
	}
	return quantidade;


}
void funcremover (int v[], int *quantidade, int numero)
{
    
    int i, pos;
    
    i=0;
    
    
	
    	while (i<(*quantidade))
    	{
    		
        	if (v[i] == numero)
        	{
           	 	for (pos=i+1;pos<(*quantidade);pos++)
            	{
                	v[pos-1] = v[pos];
            	}

            		(*quantidade)--;
            		return;
						      
        		}
        			i++;
		}
			
	
}
	//A = original B = numero novo
 int funcalterarvalor (int vett[], int tamanho, int A, int B)
 {
     
    //declaração de variáveis
    int i, j, pos, aux;
    
    
    pos = buscarvalor (vett, tamanho, B);
    if(B==vett[pos])
    {
    	return -1;
	}
    else
	{
		
		pos= buscarvalor (vett, tamanho, A);
		vett[pos] = B;
		if(vett[pos-1]>vett [pos]||pos==tamanho-1)
		{
			if(vett[pos]<vett[pos-1])
			{
				for (i=pos;i>0;i--)
		 		{
			 		
		        	if (vett[i-1]>vett[i] && vett[i]==B)
					{	
						aux = vett[i];
						vett[i]=vett[i-1];
						vett[i-1]=aux;
					}
		   		}
			}
		}
		else
		{
			if(vett[pos+1]<vett[pos])
			{
				for (i=pos, j=pos+1;j<tamanho;i++, j++)
			 	{
				 	
			        if (vett[j]<vett[i] && vett[i]==B)
					{	
						aux= vett[j];
						vett[j]=vett[i];
						vett[i]=aux;
					}
			   	}
			}
		}
	    
	}
}

int funcEncontrar (int vetorE[], int tamanho, int valorE)
{
        int i;
          
          for(i=0;i<tamanho;i++)
          {
                 if (vetorE[i] == valorE)
                  {
                    return i;
                  } 
          }
          return -1;
}
void exibir (int v[], int quantidade)
{
    
    int i;
    
    printf ("\n Elementos do vetor: ");
    
    for (i=0;i<quantidade;i++)
    {
        printf ("%d ", v[i]);
    }
    printf ("\n\n");
}
