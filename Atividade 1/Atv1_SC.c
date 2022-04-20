#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int SOMA = 0, request = 0, respond = 0;

void secaoCritica() {
    int local = SOMA;
    sleep(rand() % 2);
    SOMA = local + 1;
}

void cliente(int i) {
    while (1) {
        while (respond != i) // Protocolo de entrada na seção crítica
            request = i;
            
        secaoCritica();
        printf("SOMA = %d\n", SOMA);
        
        respond = 0; // Protocolo de saída da seção crítica
    }
}

void servidor() {
    while (1) {
        while (request == 0) {} 
        respond = request; 
        while (respond != 0) {} 
        request = 0;
    }
}

int main() {
    int numeroThreads = 5; // 3 ou 5 (thread 0 para o servidor e duas ou quatro threads como processos clientes)
  
    omp_set_num_threads(numeroThreads); // define o número de threads

    printf("\tTotal de threads: %d\n", numeroThreads);
    printf("O servidor utiliza a thread 0\nExistem %d threads como processos clientes.\n\n", numeroThreads - 1);
 
#pragma omp parallel
    {
        int id = omp_get_thread_num(); // Retorna o ID da thread

        if (id == 0)
            servidor();
        else
            cliente(id);
    }
    
    return 0;
}
