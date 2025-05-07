#include <stdio.h>

// Uso de struct para criar uma "classe" de carta
typedef struct {
    char estado;
    char codigoCarta[50];
    char nomeCidade[50];
    double populacao;
    double area;
    double pib;
    int pontosTuristicos;
} CartaSuperTrunfo;

//Função de comparação normal
int compararCartas(double a, double b) {
    if (a > b) {
        return 1;
    } else if (b > a) {
        return 2;
    } else {
        return 0;
    }
}

//Função de comparação inverso
int compararCartasInverso(double a, double b) {
    if (a < b) {
        return 1;
    } else if (b > a) {
        return 2;
    }
}


//Função para calcular a densidade populacional;
double densidadePopulacional(double populacao, double area) {
    double densidade = populacao / area;
    return densidade;
}

//Função para calcular o Pib per Capito;
double pibPerCapita(double pib, double populacao) {
    double perCapita = (pib * 1000000000) / populacao;
    return perCapita;
}

//Função para calcular o superpoder
double calculaSuperPoder(CartaSuperTrunfo carta) {
    double perCapita = pibPerCapita(carta.pib, carta.populacao);
    double inversoDensidade = carta.area / carta.populacao;

    double superPoder = ((carta.populacao / 1000000.0) +
                         (carta.area) +
                         (carta.pib) +
                         carta.pontosTuristicos +
                         (perCapita / 10.0) +
                         (inversoDensidade * 10000000.0)) / 10;

    return superPoder;
}

//Função de inserção de dados, recebe a referência da struct para de cartas e a posição dos dados no array;
void cadastroDeCartas(CartaSuperTrunfo cartas[], int i) {
    printf("\nCadastro de carta #0%d:\n", i);
    printf("Selecione um estado (A-H): ");
    scanf(" %c", &cartas[i].estado);
    printf("Selecione um código de caracteres (1-4): ");
    scanf("%s", cartas[i].codigoCarta);
    printf("Digite o nome da cidade: ");
    fscanf(stdin, " %[^\n]", cartas[i].nomeCidade);
    printf("Informe a população: ");
    scanf("%lf", &cartas[i].populacao);
    printf("Informe a área (em Km²): ");
    scanf("%lf", &cartas[i].area);
    printf("Informe o PIB (em bilhões): ");
    scanf("%lf", &cartas[i].pib);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cartas[i].pontosTuristicos);

    return;
}

//Função de impressão dos dados, recebe a referência da struct para de cartas e a posição dos dados no array;
void impressaoDeCartas(CartaSuperTrunfo cartas[], int i) {
    printf("\nResumo #%02d:\n", i);
    printf("Código: %c0%s\n", cartas[i].estado, cartas[i].codigoCarta);
    printf("Cidade: %s\n", cartas[i].nomeCidade);
    printf("População: %.2f habitantes\n", cartas[i].populacao);
    printf("Área: %.2f Km²\n", cartas[i].area);
    printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
    printf("Número de pontos turísticos: %d\n", cartas[i].pontosTuristicos);

    double densidade = densidadePopulacional(cartas[i].populacao, cartas[i].area);
    double perCapita = pibPerCapita(cartas[i].pib, cartas[i].populacao);
    double inversoDensidade = cartas[i].area / cartas[i].populacao;
    double superPoder = calculaSuperPoder(cartas[i]);

    printf("Densidade populacional: %.2f habitantes por Km²\n", densidade);
    printf("PIB per Capita: %.2f reais\n", perCapita);
    printf("Inverso da Densidade: %.6f Km² por habitante\n", inversoDensidade);
    printf("Super Poder da cidade: %.f\n", superPoder);

    return;
}


int main() {
    //Chama a struck e passa 3 arrays.
    //Ignorei a posição 0 para não existir nenhuma carta com "ID" #00;
    CartaSuperTrunfo cartas[3];

    cadastroDeCartas(cartas, 1);
    cadastroDeCartas(cartas, 2);

    printf("\n-----------------------------------------------------------------\n");
    impressaoDeCartas(cartas, 1);
    impressaoDeCartas(cartas, 2);

    int populacao = compararCartas(cartas[1].populacao, cartas[2].populacao);
    int area = compararCartas(cartas[1].area, cartas[2].area);
    int pib = compararCartas(cartas[1].pib, cartas[2].pib);
    int pontosTuristicos = compararCartas(cartas[1].pontosTuristicos, cartas[2].pontosTuristicos);
    int densidade = compararCartasInverso(
        cartas[1].area / cartas[1].populacao,
        cartas[2].area / cartas[2].populacao
    );

    int perCapita = compararCartas(
        pibPerCapita(cartas[1].pib, cartas[1].populacao),
        pibPerCapita(cartas[2].pib, cartas[2].populacao)
    );

    int superPoder = compararCartas(
        calculaSuperPoder(cartas[1]),
        calculaSuperPoder(cartas[2])
    );

    printf("\n-----------------------------------------------------------------\n");
    printf("\nHora do duelo\n");
    printf("Vencedor População: Carta (%d)\n", populacao);
    printf("Vencedor Área: Carta (%d)\n", area);
    printf("Vencedor PIB: Carta (%d)\n", pib);
    printf("Vencedor Pontos Turísticos: Carta (%d)\n", pontosTuristicos);
    printf("Vencedor Densidade: Carta (%d)\n", densidade);
    printf("Vencedor PIB per Capita: Carta (%d)\n", perCapita);
    printf("Vencedor Super Poder: Carta (%d)\n", superPoder);


    return 0;
}
