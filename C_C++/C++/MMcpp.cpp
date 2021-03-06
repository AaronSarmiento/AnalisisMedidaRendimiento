#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <chrono>

/* Para hacer la multiplicacion de matrices se trabajara con memoria dinamica por reserva*/

double** crear_matriz(int N){
    double** matriz = new double* [N];
    for (int i = 0; i < N; i++){
        matriz[i] = new double[N](); // Se crea la matriz con el tamaño N y se inicializa en cero
    }
    
    return matriz;
}

void init_matriz(double** &matriz_A, double** &matriz_B, int N){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            matriz_A[i][j] = 2.1 * (i + j);
            matriz_B[i][j] = 1.2 * (j - i);
        }
    }
}

void impresion_matriz(double** &matriz, int N){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%f    ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Se necesita liberar la memoria reservada por las matrices
void liberar_matrices(double** &matriz, int N){
    if(matriz){
        for(int i = 0; i < N; i++){
            delete[] matriz[i]; // Se borra cada fila 
        }
        delete[] matriz;

        matriz = nullptr; 
    }
}

double** multiplicacion_matrices(double** &matriz_A, double** &matriz_B, int N){
    double** matriz = crear_matriz(N);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                matriz[i][j] += matriz_A[i][k] * matriz_B[k][j];
            }
        }  
    }

    return matriz;
}

int main(int argc, char *argv[]){
    int T = strtol(argv[1], nullptr, 0);
    double** matriz_A = crear_matriz(T);
    double** matriz_B = crear_matriz(T);
    double** matriz_C = crear_matriz(T);

    init_matriz(matriz_A, matriz_B, T);
    
    /*
    impresion_matriz(matriz_A, T);
    printf("\n");
    impresion_matriz(matriz_B, T);
    */
    auto inicio = std::chrono::system_clock::now();
    matriz_C = multiplicacion_matrices(matriz_A, matriz_B, T);
    auto final = std::chrono::system_clock::now();
    
    std::chrono::duration<double> tiempo_total = final - inicio;

    std::cout<<tiempo_total.count()<<std::endl;

    /*
    printf("\n");
    impresion_matriz(matriz_C, T);
    */


    return 0;
}