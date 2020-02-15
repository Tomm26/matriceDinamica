#include <iostream>
#include <string>
#include <fstream>
#include "funzioni.h"

using namespace std;

void leggiMatriceFile(int **matrice, string nomefile,int r,int c) {
//funzione per caricare la matrice
	fstream file;
	file.open(nomefile, fstream::in);
	if (!file) {
		cout << "Errore durante l'apertura del file"; exit(1);
	}
	while (!file.eof()) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				file >> matrice[i][j];
			}
		}
	} file.close();
}

void stampaMatrice(int **matrice, int r, int c) {
//funzione per stampare la matrice
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrice[i][j] << " ";
		}cout << endl;
	}
}
void caricaVettoreMatrix(int vettoreMatrix[], int **matrice, int n, int r, int c) {
//funzione per caricare il vettore che userò per ordinare la matrice
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			vettoreMatrix[k] = matrice[i][j];
			k++;
		}
	}
}

void ordinaVettore(int vettoreMatrix[], int n) {
//funzione per ordinare il vettore
	int temp;
	bool ordinato = false;
	for (int i = 0; i < n - 1 && !ordinato; i++) {
		ordinato = true;
		for (int j = n - 1; j > i; j--) {
			if (vettoreMatrix[j - 1] > vettoreMatrix[j]) {
				temp = vettoreMatrix[j - 1];
				vettoreMatrix[j - 1] = vettoreMatrix[j];
				vettoreMatrix[j] = temp;
				ordinato = false;
			}
		}
	}
}
void stampaVettore(int vettoreMatrix[], int n) {
//funzione per stampare il vettore
	for (int i = 0; i < n; i++) {
		cout << vettoreMatrix[i] << " ";
	}
}
void caricaMatrixVettore(int **matrice, int vettore[], int n, int r, int c) {
//funzione per caricare il vettore nella matrice
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			matrice[i][j] = vettore[k];
			k++;
		}
	}
}
void somma_righe(int **matrice, int r, int c) {
//funzione che stampa la somma di ogni riga
	int sum = 0;
	for (int i = 0; i < r; i++) {
		sum = 0;
		for (int j = 0; j < c; j++) {
			sum = sum + matrice[i][j];
		}cout << "la somma della " << i + 1 << " riga e': " << sum << endl;
	}
}

int somma_massima(int **matrice, int r, int c) {
//funzione che trova la riga con la somma massima e restituisce il suo indice
	int sum = 0;
	int sumtot = 0;
	int indice;
	for (int i = 0; i < r; i++) {
		sum = 0;
		for (int j = 0; j < c; j++) {
			sum = sum + matrice[i][j];
		}
		if (sum > sumtot) {
			sumtot = sum;
			indice = i;
		}
	}cout << "la somma massima e': " << sumtot << endl;
	return indice;
}

void cancellaRiga(int **matrice, int &r, int c) {
//funzione che cancella la riga scelta
	int indice = somma_massima(matrice, r, c);
	for (int i = indice; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			matrice[i][j] = matrice[i + 1][j];
		}
	} r--;
}

int leggiDim(string nomefile,int &r,int &c) {
//funzione che legge le dimensioni di righe e colonne della matrice
	fstream file;
	file.open(nomefile, fstream::in);
	if (!file) {
		cout << "Errore durante l'apertura del file"; exit(1);
	}
	else {
		file >> r>>c;
	}
	file.close();
	
}
