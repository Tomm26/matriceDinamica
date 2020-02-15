#include <string>

using namespace std;

void leggiMatriceFile(int **matrice, string nomefile,int r,int c);
void stampaMatrice(int **matrice, int r, int c);

void caricaVettoreMatrix(int vettoreMatrix[], int **matrice, int n, int r, int c);
void ordinaVettore(int vettoreMatrix[], int n);
void stampaVettore(int vettoreMatrix[], int n);

void caricaMatrixVettore(int **matrice, int vettore[], int n, int r, int c);

void somma_righe(int **matrice, int r, int c);
int somma_massima(int **matrice, int r, int c);
void cancellaRiga(int **matrice, int &r, int c);

int leggiDim(string nomefile,int &r,int&c);
