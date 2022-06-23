#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    char portas[3] = {1,2,3};
    char escolha[1];
    int porta_escolhida, porta_premio, porta_aberta, porta_troca;

    printf("Escolha uma porta de 1 a 3: ");
    scanf("%d", &porta_escolhida);   //valor da porta escolhida

    srand(time(NULL));
    porta_premio = rand()%3;   //retorna o índice da porta com prêmio

    porta_aberta = rand()%3;   //retorna o índice da porta aberta
    while(porta_aberta+1 == porta_escolhida || porta_aberta == porta_premio)   //porta aberta diferente do prêmio e porta escolhida
        porta_aberta = rand()%3;

    if(porta_escolhida != porta_premio+1)   //única opção para porta_premio
        porta_troca = porta_premio;
    else{
        porta_troca = rand()%3;
        while(porta_troca == porta_premio || porta_troca == porta_aberta)   //rand até porta_troca != porta_aberta e porta_premio
            porta_troca = rand()%3;
    }

    printf("\nVoce escolheu a porta %d e a porta %d que nao contem o premio foi aberta.", porta_escolhida, porta_aberta+1);
    printf("\nGostaria de trocar para a porta %d? [s/n] ", porta_troca+1);

    scanf("%s", escolha);   //recebe o valor s/n para trocar de porta
    if(escolha[0] == 's'){   //caso a pessoa queira trocar de porta
        porta_escolhida = porta_troca+1;

        if(porta_escolhida == porta_premio+1)
            printf("\nPARABENS VOCE TROCOU PARA PORTA %d E ACERTOU O PREMIO!!!\n", porta_troca+1);
        else
            printf("\nInfelizmente o premio estava na porta %d. VOCE ERROU.\n", porta_premio+1);
    }
    else{   //caso a pessoa nao troque de porta
        if(porta_escolhida == porta_premio+1)
            printf("\nPARABENS O PREMIO ESTA NA PORTA %d, VOCE GANHOU!!!\n", porta_premio+1);
        else
            printf("\nInfelizmente o premio estava na porta %d. VOCE ERROU.\n", porta_troca+1);
    }
}
