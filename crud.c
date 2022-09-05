// Código desenvolvido por: Eduardo dos Santos Langner, Leticia Benedet e Stéfanny Oliveira da Rosa;
// Curso: Ciência da Computação 1° período(Eduardo e Stéfanni) e Sistemas da Informação 1° período(Leticia);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#define VAGAS 15

int num = 0;// contador global

bool vagas[15];

struct veiculos {//novo tipo de dados denominado veiculo
    char marca[30];
    char modelo[20];
    char placa[10];
    int ano;
    int vaga;
} veiculo[VAGAS];// usando Vagas como vetor

void cadastro (int pos){ // int pos = novo parametro: usar parametros para chamar a função ela eu quiser no codigo de forma mais facil (não preciso ficar printando ela)
    bool salvou = 0;
    int vagaLida;

    system("cls");
    printf("Digite a marca do veículo: ");
    fflush(stdin);
    gets(veiculo[pos].marca);//usar o contador para contar os cadastros
    printf("\nDigite o modelo do veículo: ");
    fflush(stdin);
    gets(veiculo[pos].modelo);
    printf("\nDigite a placa do veículo: ");
    fflush(stdin);
    gets(veiculo[pos].placa);
    printf("\nDigite o ano do veículo: ");
    scanf("%d", &veiculo[pos].ano);
    while(salvou == 0){ //laço que não permite que eu estacione o carro em uma vaga já ocupada, utilizando comparação pelo tipo bool
        printf("\nDigite a vaga que deseja estacionar seu veículo: ");
        scanf("%d", &vagaLida);
        system("cls");
        if(vagas[vagaLida] == 0){ //vaga que ele digitou ainda não está ocupada
            veiculo[pos].vaga = vagaLida; // chamo a struct veiculos por meio do parametro e vejo se a vaga que ele quer estacionar está ocupada ou não
            vagas[vagaLida] = 1;
            salvou = 1; // quando ele digita tudo certo, o salvou que estava em 0 vai para 1 ou seja, ele cria o cadastro.
        }else{
            system("cls");
            printf("Vaga já ocupada, informe uma vaga válida!"); // se a vaga digitada está ocupada
        }
    }
}

void listar (){ //mostra todos os veícuos cadastrador

    int i;

    system("cls");
    for(i=0; i < num; i++){ //utilizo o contador global para contar os cadastros

        printf("%d - ", i+1); // i+1 para começar a contar do 1 e não do 0
        printf("\tVeículo estacionado na vaga: %d\n", veiculo[i].vaga); // mostrar em qual vaga o veiculo está, utilizando a struct interando com o for
        printf("\tMarca: %s\n", veiculo[i].marca);
        printf("\tModelo: %s\n", veiculo[i].modelo);
        printf("\tPlaca: %s\n", veiculo[i].placa);
        printf("\tAno: %d\n\n===========================================\n\n", veiculo[i].ano);
    }
}

void buscar (){ // função para localizar um carro estacionado em uma vaga
    int ops, posEncontrada;
    bool encontrou = 0;
    system("cls");
    printf("Informe qual vaga deseja visualizar: ");
    scanf("%d", &ops);
    system("cls");
    for(int i = 0; i<num; i++){
        if(veiculo[i].vaga == ops){
            posEncontrada = i;
            encontrou = 1;
            listarVeiculo(posEncontrada);
        }
    }
    if(encontrou == 0)
        printf("Vaga não ocupada\n\n");
}

void listarVeiculo (int pos){

    system("cls");
    printf("Veículo estacionado na vaga: %d\n", veiculo[pos].vaga); // mostrar em qual vaga o veiculo está, utilizando a struct interando com o for
    printf("Marca: %s\n", veiculo[pos].marca);
    printf("Modelo: %s\n", veiculo[pos].modelo);
    printf("Placa: %s\n", veiculo[pos].placa);
    printf("Ano: %d\n===========================================\n", veiculo[pos].ano);
}

void editar (){ //função para editar veículos cadastrados
    int busca;
        listar(); //chamo todos os carros cadastrados e esolho qual eu quero editar
        scanf("%d", &busca);
    cadastro(busca-1);
}

void deletar (){//função para excluir carros cadastrador

    int busca;
        listar();
        printf("\nVeículos cadastrados listados acima\n\n");
        printf("Qual que você deseja excluir? ");
        scanf("%d", &busca);
        system("cls");
        int pos = busca - 1; // ajusta a escolha do usuário a posição certa
        for(pos; pos < num; pos++){ //o laço paga os dados de um veículo, Sobrescrevendo ele com os do próximo e Caso n tenha nada depois apenas sobrescreve com nada
        veiculo[pos] = veiculo[pos + 1];
    }
    if(num > 0) num--; // contador global que itera com o vetor pos
    printf("Veículo removido com sucesso!!\n\n");
    system("PAUSE");
}

int menu(){
    int escolha; // faço a escolha e printo o menu na mesma função
    system("cls");
    printf("\n\n\t\t\t\t\tBem vindo a Garagem Ducar\n\n");
    printf("O que você deseja?\n\n");
    printf("-> 1 Cadastrar novo veículo\n");
    printf("-> 2 Listar veículos estacionados\n");
    printf("-> 3 Buscar veículo\n");
    printf("-> 4 Editar veículo\n");
    printf("-> 5 Excluir veículo\n\n");
    printf("Selecione uma opção ou pressione 6 para sair: \n\n");
    scanf("%d", &escolha);
    return escolha;
}

int main()
{
setlocale(LC_ALL,""); // função para ler acentuação

    int escolha;
    do{ // laço do menu
        escolha = menu();
        switch (escolha){

            case 1:
                cadastro(num); // aqui se usa a função global para contar os cadastros
                num++;
                break;

            case 2:
                listar();
                system("PAUSE");
                break;

            case 3:
                buscar();
                system("PAUSE");
                break;

            case 4:
                editar();
                break;

            case 5:
                deletar();
        }

    } while(escolha != 6); // o código fica rodando até ele digitar o numero 6 para sair

    return 0;
}
