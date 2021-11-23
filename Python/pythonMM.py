#Aaron Sarmiento
#10 de Noviembre 2021
#Programa multiplicacion de matrices en python
#Se ingresa la dimensión de la matriz (NxN) por argumento

import sys
import time
import numpy

#Se ingresa dimensión de la matriz
N= int(sys.argv[1])

#Se crean las matrices (NxN) con numpy inicializadas aleatoriamente

matA = numpy.random.uniform(low=0.75, high = 1.25, size = (N,N))
matB = numpy.random.uniform(low=0.75, high = 1.25, size = (N,N))
matC = numpy.zeros([N,N])

#Se crea la funcion para imprimir la matriz
def imprimirMatriz(matriz, T):
	for i in range(T):
		for j in range(T):
			print(round(matriz[i][j], 3), end = ' ')
		print("\n")	
			
def multiplicacionMatrices(matrizA,matrizB,tamanio):
    matrizC = numpy.zeros([tamanio,tamanio]);

    for i in range(tamanio):
        for j in range(tamanio):
            for k in range(tamanio):
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
    return matrizC

'''	
print("===============\n")
imprimirMatriz(matA, N)
print("===============\n")
imprimirMatriz(matB, N)	
print("===============\n")
'''
inicio = time.time()
matC = multiplicacionMatrices(matA, matB, N)
final = time.time() 
print(final - inicio)



#imprimirMatriz(matC, N)
		
	
 
 
