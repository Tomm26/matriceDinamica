#include "funzioni.h"
#include <iostream>


using namespace std;

int main()
{
	string nomefile;
	int **matrice;
	int *vettoreMatrix;
	int r, c;
	int n;
	cout << "inserire nome file: ";
	cin >> nomefile;

	//ricavo le dimensioni della matrice dal file
	leggiDim(nomefile, r, c);
	n = r * c;
	//alloco dinamicamente la matrice
	matrice = new int*[r];
	for (int i = 0; i < r; i++) {
		matrice[i] = new int[c];
	}
	//alloco il vettore
	vettoreMatrix = new int[n];

	//carico matrice
	leggiMatriceFile(matrice, nomefile,r,c);


	//stampo matrice
	stampaMatrice(matrice, r, c);
	cout << endl;

	//carico il vettore r*c per ordinare la matrice
	caricaVettoreMatrix(vettoreMatrix, matrice, n, r, c);
	ordinaVettore(vettoreMatrix, n);
	cout << "il vettore ordinato e': ";

	stampaVettore(vettoreMatrix, n);
	cout << endl;

	//carico il vettore ordinato nella matrice
	caricaMatrixVettore(matrice, vettoreMatrix, n, r, c);

	//stampo la matrice
	cout << endl;
	cout << "la matrice ordinata e': " << endl;
	stampaMatrice(matrice, r, c);

	//calcolo la somma delle righe, cancello la riga prescelta e stampo la nuova matrice
	somma_righe(matrice, r, c);
	cancellaRiga(matrice, r, c);
	stampaMatrice(matrice, r, c);

	//dealloco la memoria allocata dalla matrice e dal vettore
	for (int i = 0; i < r; i++) {
		delete[] matrice[i];
	}
	delete[] matrice;
	delete[] vettoreMatrix;
}


