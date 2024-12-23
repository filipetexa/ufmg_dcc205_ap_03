#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/operations.h"

void print_time_and_result(const char *task, const char *method, int number, unsigned long long result, double cpu_time_used) {
    printf("%s de %d usando %s é %llu\n", task, number, method, result);
    printf("Tempo de CPU: %f segundos\n", cpu_time_used);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <task> <number>\n", argv[0]);
        printf("task: factorial, fibonacci ou all\n");
        printf("number: inteiro positivo\n");
        return 1;
    }

    char *task = argv[1];
    int number = atoi(argv[2]);
    unsigned long long result;
    clock_t start, end;
    double cpu_time_used;

    if (strcmp(task, "all") == 0) {
        // Executar todas as operações
        const char *tasks[2] = {"factorial", "fibonacci"};
        const char *methods[2] = {"recursive", "iterative"};

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                start = clock();
                if (strcmp(tasks[i], "factorial") == 0) {
                    result = (strcmp(methods[j], "recursive") == 0) ? factorial_recursive(number) : factorial_iterative(number);
                } else {
                    result = (strcmp(methods[j], "recursive") == 0) ? fibonacci_recursive(number) : fibonacci_iterative(number);
                }
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                print_time_and_result(tasks[i], methods[j], number, result, cpu_time_used);
            }
        }
    } else {
        // Executar uma operação específica
        const char *method = argv[2];  // Requer ajuste nos argumentos se não for "all"
        start = clock();
        if (strcmp(task, "factorial") == 0) {
            result = (strcmp(method, "recursive") == 0) ? factorial_recursive(number) : factorial_iterative(number);
        } else if (strcmp(task, "fibonacci") == 0) {
            result = (strcmp(method, "recursive") == 0) ? fibonacci_recursive(number) : fibonacci_iterative(number);
        } else {
            printf("Tarefa inválida. Escolha 'factorial', 'fibonacci' ou 'all'.\n");
            return 1;
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        print_time_and_result(task, method, number, result, cpu_time_used);
    }

    return 0;
}
