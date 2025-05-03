#include <stdio.h>


// Uso de struct para criar uma "classe" de carta
typedef struct {
    char estado;
    char codigoCarta[50];
    char nomeCidade[50];
    float populacao;
    float area;
    float PIB;
    int pontosTuristicos;

} CartaSuperTrunfo;

int main() {
    CartaSuperTrunfo cartas[2]; //Chamando a classe e definindo o array de cartas

    //Carta #01
    printf("\nCarta #01 \n");
    printf("Selecione um estado (A-H): ");
    scanf(" %c", &cartas[0].estado);
    printf("Selecione um codigo de caracteres (1-4): ");
    scanf("%s", cartas[0].codigoCarta);
    printf("Digite o nome da cidade: ");
    fscanf(stdin, " %[^\n]", cartas[0].nomeCidade);
    printf("Informe a população: ");
    scanf("%f", &cartas[0].populacao);
    printf("Informe a área (em Km²): ");
    scanf("%f", &cartas[0].area);
    printf("Informe o PIB: ");
    scanf("%f", &cartas[0].PIB);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cartas[0].pontosTuristicos);

    //Carta #02
    printf("\nCarta #02 \n");
    printf("Selecione um estado (A-H): ");
    scanf(" %c", &cartas[1].estado);
    printf("Selecione um codigo de caracteres (1-4): ");
    scanf("%s", cartas[1].codigoCarta);
    printf("Digite o nome da cidade: ");
    fscanf(stdin, " %[^\n]", cartas[1].nomeCidade);
    printf("Informe a população: ");
    scanf("%f", &cartas[1].populacao);
    printf("Informe a área (em Km²): ");
    scanf("%f", &cartas[1].area);
    printf("Informe o PIB: ");
    scanf("%f", &cartas[1].PIB);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cartas[1].pontosTuristicos);


    printf("\nResumo #01:\n");
    printf("Código: %c0%s\n", cartas[0].estado, cartas[0].codigoCarta );
    printf("Cidade: %s\n", cartas[0].nomeCidade);
    printf("População: %.2f habitantes\n", cartas[0].populacao);
    printf("Área: %.2f Km²\n", cartas[0].area);
    printf("PIB: %.2f bilhões de reais \n", cartas[0].PIB);
    printf("Número de pontos turísticos: %d\n", cartas[0].pontosTuristicos);

    printf("\nResumo #02:\n");
    printf("Código: %c0%s\n", cartas[1].estado, cartas[1].codigoCarta );
    printf("Cidade: %s\n", cartas[1].nomeCidade);
    printf("População: %.2f habitantes\n", cartas[1].populacao);
    printf("Área: %.2f Km²\n", cartas[1].area);
    printf("PIB: %.2f bilhões de reais \n", cartas[1].PIB);
    printf("Número de pontos turísticos: %d\n", cartas[1].pontosTuristicos);

    return 0;
}
