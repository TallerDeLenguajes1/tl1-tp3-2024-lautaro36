#include <stdio.h>
#include <stdlib.h>
#define ANIO 5
#define MES 12

void cargarMatriz(int matriz[ANIO][MES], int m, int n) {
    int inf=10000, sup=50000;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            matriz[i][j] = rand() % (sup+1-inf) + 10000;
        }
    }
}

void mostrarMatriz(int matriz[ANIO][MES], int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf(" %d", matriz[i][j]);
        }
        puts("\n");
    }
}

float promedios(int matriz[ANIO][MES], int m, int n, float matrizProm[]) {
    float prom;
    int mayor=0, menor=200000, mejMes, peorMes, mejorAnio, peorAnio;
    for(int i=0; i<m; i++) {
        prom = 0;
        for(int j=0; j<n; j++) {
            if(matriz[i][j]>mayor) {
                mayor=matriz[i][j];
                mejorAnio=i;
                mejMes=j;
            }
            if(matriz[i][j]<menor) {
                menor=matriz[i][j];
                peorAnio=i;
                peorMes=j;
            }
            prom += matriz[i][j];
        }
        matrizProm[i] = prom / n;
        printf("\nPeriodo %d: %.2f", i+1, matrizProm[i]);
    }
    printf("\nMejor rendimiento %d/%d", mejMes+1, mejorAnio+1);
    printf("\nPeor rendimiento %d/%d", peorMes+1, peorAnio+1);
}

int main() {
    int prod[ANIO][MES];
    float matrizProm[ANIO];

    cargarMatriz(prod, ANIO, MES);
    mostrarMatriz(prod, ANIO, MES);
    promedios(prod, ANIO, MES, matrizProm);

    return 0;
}