#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    int opcao;
    double numero1, numero2, resultado;
    char resposta;
    char linha[100];
    char *fim;

    while (1) {

        printf("\n==============================\n");
        printf("       Simple Calculator\n");
        printf("==============================\n");
        printf("Select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        printf("Option: ");

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }

        long escolha = strtol(linha, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == linha || *fim != '\0' ||
            escolha < 1 || escolha > 5) {

            printf("Invalid option. Please choose a number from 1 to 5.\n");
            continue;
        }

        opcao = (int)escolha;

        if (opcao == 5) {
            printf("Thank you for using the calculator! See you next time.\n");
            break;
        }

        printf("Enter the first number: ");

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }

        numero1 = strtod(linha, &fim);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == linha || *fim != '\0') {
            printf("Invalid number. Please try again.\n");
            continue;
        }

        printf("Enter the second number: ");

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break;
        }

        numero2 = strtod(linha, &fim);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim == linha || *fim != '\0') {
            printf("Invalid number. Please try again.\n");
            continue;
        }

        switch (opcao) {

            case 1:
                resultado = numero1 + numero2;
                printf("Result: %g + %g = %g\n",
                       numero1, numero2, resultado);
                break;

            case 2:
                resultado = numero1 - numero2;
                printf("Result: %g - %g = %g\n",
                       numero1, numero2, resultado);
                break;

            case 3:
                resultado = numero1 * numero2;
                printf("Result: %g * %g = %g\n",
                       numero1, numero2, resultado);
                break;

            case 4:
                if (numero2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    resultado = numero1 / numero2;
                    printf("Result: %g / %g = %g\n",
                           numero1, numero2, resultado);
                }
                break;
        }

        while (1) {

            printf("\nDo you want to perform another operation? (y/n): ");

            if (fgets(linha, sizeof(linha), stdin) == NULL) {
                return 0;
            }

            char *inicio = linha;

            while (isspace((unsigned char)*inicio)) {
                inicio++;
            }

            resposta = tolower((unsigned char)*inicio);
            inicio++;

            while (isspace((unsigned char)*inicio)) {
                inicio++;
            }

            if (*inicio == '\0' &&
                (resposta == 'y' || resposta == 's')) {
                break;
            }

            if (*inicio == '\0' && resposta == 'n') {
                printf("Thank you for using the calculator! See you next time.\n");
                return 0;
            }

            printf("Invalid response. Please type 'y' for yes or 'n' for no.\n");
        }
    }

    return 0;
}