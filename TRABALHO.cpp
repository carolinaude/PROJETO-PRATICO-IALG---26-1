#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

struct Pais{
	int identificador; 
	char nome[50];
	int populacao; 
	char idioma[50];
	char continente[50];  
};

//Redimensionamento do vetor para adicionar posições 
void redimensiona(Pais *paises,int &quantidade,int &capacidade){
	int nova_capacidade = capacidade + 10;
	Pais *novo = new Pais[nova_capacidade];
	for (int i = 0; i < capacidade; i++)
	{
		novo[i] = paises[i];
	}
	
	delete[] paises;
	paises = novo; 
}

//Leitura do arquivo CSV
void leituraCSV(string nome_do_arquivo){
	ifstream arquivo(nome_do_arquivo);
	string cabecalho[5];
	for (int i = 0; i < 5; i++)
	{
		arquivo >> cabecalho[i];
	}
	int capacidade = 40;
	int quantidade = 0; 
	Pais *paises = new pais[capacidade]; 
	
	
	while (arquivo >> paises[quantidade].identificador){
		if(quantidade == capacidade){
			redimensiona(paises, quantidade, capacidade);
		}
		arquivo >> paises[quantidade].nome;
		arquivo >> paises[quantidade].populacao;
		arquivo >> paises[quantidade].idioma;
		arquivo >> paises[quantidade].continente;
		quantidade++;
	}
}
