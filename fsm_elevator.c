#include <stdio.h>
#include <stdlib.h>

#define StAberta 0
#define StFechada 1
#define StAbrindo 2
#define StFechando 3
#define StEmergencia 4


//Funções das entradas e do sinal de emergência
int entradaAbrir(){
    return rand() % 2;
}

int entradaFechar(){
    return rand() % 2;
}

int sinalEmergencia(){
    return rand() % 2;
}

//Print dos estados
void motorAbrindo(){
    printf("Motor abrindo...\n");
}

void motorFechando(){
    printf("Motor fechando...\n");
}

void motorAberto(){
    printf("Motor aberto...\n");
}

void motorFechado(){
    printf("Motor fechado...\n");
}

void emergencia(){
    printf("Emergência ativada! Motor parado.\n");
}

int main(void)
{
    int EstadoAtual = StFechada;
    int ProximoEstado = StFechada;
    int Sr_Emerg;

    while (1)
    {
        Sr_Emerg = sinalEmergencia(); // Atualizando o sinal de emergência

        // Estados possíveis
        switch (EstadoAtual){
        case StAberta:
            motorAberto();
            if (Sr_Emerg == 1)
            {
                ProximoEstado = StEmergencia;
            }
            else if (entradaFechar() == 1)
            {
                ProximoEstado = StFechando;
            }
            break;
        
        case StFechando:
            motorFechando();
            if (Sr_Emerg == 1)
            {
                ProximoEstado = StEmergencia;
            }
            else if (entradaFechar() == 1)
            {
                ProximoEstado = StFechada;
            }
            break;
        
        case StFechada:
            motorFechado();
            if (Sr_Emerg == 1)
            {
                ProximoEstado = StEmergencia;
            }
            else if (entradaAbrir() == 1)
            {
                ProximoEstado = StAbrindo;
            }
            break;

        case StAbrindo:
            motorAbrindo();
            if (Sr_Emerg == 1)
            {
                ProximoEstado = StEmergencia;
            }
            else if (entradaAbrir() == 1)
            {
                ProximoEstado = StAberta;
            }
            break;

        case StEmergencia:
            emergencia();
            if (Sr_Emerg == 0)  // Sai da emergência
            {
                ProximoEstado = StAbrindo;  // Vai para o estado de segurança, que é abrir a porta do elevador
            }
            break;
        }

        EstadoAtual = ProximoEstado;
    }

    return 0;
}