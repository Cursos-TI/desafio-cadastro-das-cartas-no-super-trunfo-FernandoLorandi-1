#include <stdio.h>


// Uso de struct para criar uma "classe" de carta
typedef struct {
    char estado;
    char codigoCarta[50];
    char nomeCidade[50];
    float populacao;
    float area;
    float pib;
    int pontosTuristicos;

} CartaSuperTrunfo;

//Função para calcular a densidade populacional;
float densidadePopulacional(float populacao, float area) {
    return populacao / area;
}

//Função para calcular o Pib per Capito;
float pibPerCapita(float pib, float populacao) {
    return pib / populacao;
}

//Função de inserção de dados, recebe a referência da struct para de cartas e a posição dos dados no array;
int cadastroDeCartas(CartaSuperTrunfo cartas[], int i) {

    printf("\nCadastro de carta #0%d:\n", i);
    printf("Selecione um estado (A-H): ");
    scanf(" %c", &cartas[i].estado);
    printf("Selecione um codigo de caracteres (1-4): ");
    scanf("%s", cartas[i].codigoCarta);
    printf("Digite o nome da cidade: ");
    fscanf(stdin, " %[^\n]", cartas[i].nomeCidade);
    printf("Informe a população: ");
    scanf("%f", &cartas[i].populacao);
    printf("Informe a área (em Km²): ");
    scanf("%f", &cartas[i].area);
    printf("Informe o PIB: ");
    scanf("%f", &cartas[i].pib);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cartas[i].pontosTuristicos);


    return 0;
}

//Função de impressão dos dados, recebe a referência da struct para de cartas e a posição dos dados no array;
int impressaoDeCartas(CartaSuperTrunfo cartas[], int i) {

    printf("\nResumo #0%d:\n", i);
    printf("Código: %c0%s\n", cartas[i].estado, cartas[i].codigoCarta );
    printf("Cidade: %s\n", cartas[i].nomeCidade);
    printf("População: %.2f habitantes\n", cartas[i].populacao);
    printf("Área: %.2f Km²\n", cartas[i].area);
    printf("PIB: %.2f bilhões de reais \n", cartas[i].pib);
    printf("Número de pontos turísticos: %d\n", cartas[i].pontosTuristicos);

    float densidade = densidadePopulacional(cartas[i].populacao, cartas[i].area);
    printf("Densidade populacional: %.2f habitantes por Km²\n", densidade);

    double perCapita = pibPerCapita(cartas[i].pib, cartas[i].populacao);
    printf("PIB per Capita: %.2f reais\n", perCapita);

    return 0;
}


int main() {
    //Chama a struck e passa 3 arrays.
    //Ignorei a posição 0 para não existir nenhuma carta com "ID" #00;
    CartaSuperTrunfo cartas[3];

    cadastroDeCartas(cartas, 1);
    cadastroDeCartas(cartas, 2);

    impressaoDeCartas(cartas, 1);
    impressaoDeCartas(cartas, 2);


    return 0;


}