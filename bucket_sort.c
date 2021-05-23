#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6

// objeto que contem a quantidade de baldes e o tamanho de cada balde
struct balde
{
    int qtd; //quantidade de baldes
    int valores[TAM]; //tamanho do balde
}; 

void insertion_sort(int *vet, int num){
    //vet = vetor de baldes , num = quantidades de baldes
    int i,j, aux;
    for(i = 1; i<num; i++){
        aux = vet[i]; 
        for( j = i; (j>0) && (aux < vet[j-1]);j--){
            vet[j] = vet[j-1];
        }
        vet[j]= aux;
    }
}

void bucket_sort(int *vet, int num){
    int i, j, maior, menor, nroBaldes, pos;
    struct balde *bd;  // ponteiro para um futuro vetor de baldes
    maior = menor = vet[0]; // maior e o menor recebem o primeiro elemento do vetor
    for(i = 1; i < num; i++){
        if(vet[i] > maior) maior = vet[i];
        if(vet[i]< menor) menor = vet[i];
    } //aloca o mair valor na variavel *maior* e o menor valor na variavel *menor*
    
    nroBaldes= (maior - menor ) / TAM +1; //quantidade de baldes
    bd = (struct balde *)malloc(nroBaldes * sizeof(struct balde)); // vetor de baldes 
    for  (i =0; i < nroBaldes; i++){
        bd[i].qtd =0;
    } // para cada balde criado, setta o valor para 0
    for (i = 0; i<num; i++){
        pos = (vet[i] - menor)/TAM; 
        bd[pos].valores[bd[pos].qtd] = vet[i]; 
        bd[pos].qtd++;
    } //aloca o elemento em um determinado balde 
    pos = 0;
    for (i = 0; i < nroBaldes; i++){
        insertion_sort(bd[i].valores, bd[i].qtd); // orderna o vetor de cada de cada balde
        for(j=0; j< bd[i].qtd; j++){
            vet[pos] =  bd[i].valores[j];
            pos++;
        } // aloca os valores no vetor original
    }
    free(bd); 
}                 

int main(){

    int i, j,n = 1000, vet1[n],vet2[n],vet3[n],vet4[n],vet5[n];
    //srand(time(NULL));
    /*
    VETOR TOTALMENTE DESORDENADO 

    for(i = 0; i < n; i++){
        vet5[i] = rand();
    }
    --------------------------------
    VETOR ORDENADO DECRESCENTEMENTE

    for(i = n; i > 0; i--){
        vet1[i] = i;
    }
    --------------------------------
    VETOR ORDENADO CRESCENTEMENTE

    for(i = 0; i > n; i++){
        vet2[i] = i;
    }
    --------------------------------
    Primeira metade ordenada crescente, segunda metade ordenada decrescentemente

    for(i = 0; i < n/2; i++){
        vet3[i] = i;
        j = i;
        printf("%d\n",vet3[j]);
    }
    j++;
    for(i = n; i > (n/2)-1; i--){
        vet3[j] = i;
        printf("%d\n",vet3[j]);
        j++;
        
    }
    -------------------------------
    Primeira metade ordenada decrescente, segunda metade ordenada crescentemente
    */
    j=0;
    for(i = n; i > (n/2)-1; i--){
        vet4[j] = i;
        printf("%d\n",vet4[j]);
        j++;
    }

    for(i = 1; i < n/2; i++){
        vet4[j] = i;
        printf("%d\n",vet4[j]);
        j++;
    }

    bucket_sort(vet4,n);
    for(i = 0; i < n; i++){
        vet4[i] = i;
       printf("result %d\n",vet4[i]);
    }

    return 0;
   
}