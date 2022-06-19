#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    system("chcp 65001");
    system("cls");
    int op;
    void criptografar();
    void descripto();
    int i=1;
    while (i == 1)
    {
        system("cls");
        printf("--------------------------------------\n");
        printf("| 1 - Criptografar                   |\n");
        printf("| 2 - descriptografar                |\n");
        printf("| 3 - Sair                           |\n");
        printf("--------------------------------------\n");
        printf("Opção: ");
        scanf("%i", &op);
        
        switch (op)
        {
        case 1:
            criptografar();
        break;
        case 2:
            descripto();
            break;
        case 3:
            i = 0;
            break;
            break;
        default:
            printf("Opção inválida");
            break;
        }
    }
    return 0;
}

void descripto(){
    system("cls");
    FILE *origem, *dest;
    origem = fopen("textoCripto.txt", "r");
    dest = fopen("textoDescripto.txt", "w");

    if (origem == NULL || dest == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    char chave[100];
    int numControl=0, codcripto=0;

    printf("Informe a chave: ");
    fflush(stdin);
    fgets(chave, 100, stdin);
    printf("Informe o número de controle: ");
    scanf("%i", &numControl);

    for (int i=0; i < strlen(chave); i++){
        codcripto += chave[i] * numControl;
    }

    char x[10000];
    int i=0;

    while (!feof(origem)){
        fgets(x, 10000, origem);
    }
    
    int cont = 0;
    char t[100], tp[100];
    int ct = 0, cp = 0;

    for (int i=0; i < strlen(x); i++){
        if (x[i] != 45 && x[i] != 32 && x[i] != '\n'){
            
            t[ct] = x[i];
            ct++;
        }
        else{
            if (x[i] == 45){
                if (x[i] == 32){
                    tp[cp] = 32;
                }
                int n = (atoi(t)) / codcripto;
                tp[cp] = n;
                cp++;
                ct=0;
                memset(t, 0, ct);
            }

        }
    }
    fflush(stdin);
    fprintf(dest, "%s", tp);
    printf("Texto descriptografado com sucesso!");
    fclose(origem);
    fclose(dest);
}

void criptografar(){

    FILE *arquivo;
    arquivo = fopen("textoCripto.txt", "w");

    char chave[100], texto[10000];
    int numControl=0;
    unsigned long long int codCripto=0;

    printf("Informe a chave: ");
    fflush(stdin);
    fgets(chave, 100, stdin);
    printf("Informe o numero de controle: ");
    scanf("%i", &numControl);

    for(int i = 0; i < strlen(chave); i++){
        codCripto += chave[i];
    }
    codCripto *= numControl;

    printf("Informe o texto: ");
    fflush(stdin);
    fgets(texto, 10000, stdin);

    for(int i = 0; i < strlen(texto); i++){
        long long int cripto = texto[i] * codCripto;

        if (texto[i] != '\n'){
            fprintf(arquivo, "%lli-", cripto);
        }

    }
    printf("Texto criptografado com sucesso!");

    fclose(arquivo);
}
