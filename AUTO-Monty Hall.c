#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    char portas[3] = {1,2,3};
    char escolha[1];   //recebe o valor se troca de porta
    int porta_escolhida, porta_premio, porta_aberta, porta_troca;   //recebem os índices de cada elemento
    int quant_jogos, i, win = 0, lose = 0;   //contadores

    printf("Numero de jogos: ");
    scanf("%d", &quant_jogos);
    printf("Trocar de porta? [s/n] ");
    scanf("%s", escolha);
    srand(time(NULL));

    for(i=0; i<quant_jogos; i++){
        porta_escolhida = (rand()%3) + 1;   //valor da porta aleatório para cada jogo
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

        if(escolha[0] == 's'){   //caso a pessoa queira trocar de porta
            porta_escolhida = porta_troca+1;
            if(porta_escolhida == porta_premio+1)
                win++;
            else
                lose++;
        }
        else{   //caso a pessoa nao troque de porta
            if(porta_escolhida == porta_premio+1)
                win++;
            else
                lose++;
        }
    }
    printf("\nwins/games: %f", (float)win/quant_jogos);
}
