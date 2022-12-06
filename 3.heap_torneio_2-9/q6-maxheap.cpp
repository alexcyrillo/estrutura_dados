/*
Implemente uma classe MaxHeap que tem um construtor que recebe um vetor de elementos. Durante a criação do MaxHeap, alguns elementos deverão ser reposicionados para que passem a ter as propriedades de um max heap. O construtor (ou método usado no construtor) deverá escrever passo a passo como fica o armazenamento após a correção descendo de cada posição.

Note que não é para escrever os valores do heap após cada troca, os valores do heap devem ser escritos após todas as trocas (zero ou mais) realizadas para a correção de uma posição.

Implemente a função principal que cria um heap a partir do vetor.

Entradas:

A quantidade de elementos a serem lidos.
Os elementos (números inteiros) a serem armazenados no heap.
Saídas:

Para cada posição a ser corrigida:

A posição, seguida de dois pontos;
Todos os elementos armazenados após a reorganização iniciada na posição em questão.
Note a ausência de espaço antes do dois pontos e a presença do espaço depois, como em qualquer sinal de pontuação.

Exemplo de Entrada:

6
-3 -1 5 7 8 9
Exemplo de Saída:

2: -3 -1 9 7 8 5
1: -3 8 9 7 -1 5 
0: 9 8 5 7 -1 -3
*/
#include <iostream>

using namespace std;

class maxHeap
{
	private:
		int hCap;
		int hTam;
		int *hDados;
	public:
		maxHeap(int *dados, int cap);
		~maxHeap();
		void corrigeDescendo(int pos);
		int fEsquerdo(int i) {return 2 * i + 1;}
		int fDireito(int i) {return 2 * i + 2;}
};

maxHeap::maxHeap(int *dados, int cap)
{
	hCap = cap;
	hTam = cap;
	hDados = dados;
}

maxHeap::~maxHeap()
{
	delete[] hDados;
}

void maxHeap::corrigeDescendo(int pos)
{
	int filhoE, filhoD, maior = pos;
	filhoE = fEsquerdo(pos);
	filhoD = fDireito(pos);
	if((filhoE <= hTam - 1) && (hDados[filhoE] > hDados[maior]))
	{
		maior = filhoE;
	}
	if((filhoD <= hTam - 1) && (hDados[filhoD] > hDados[maior]))
	{
		maior = filhoD;
	}
	if(maior != pos)
	{
		int aux;
		aux = hDados[pos];
		hDados[pos] = hDados[maior];
		hDados[maior] = aux;
		corrigeDescendo(maior);
	}
	else
	{
		for(int i = 0; i < hCap; i++)
		{
			cout << hDados[i] << ' ';
		}
		cout << endl;
	}
}


int main()
{
	int qt, *vHeap;
	cin >> qt;
	vHeap = new int[qt];
	for(int i = 0; i < qt; i++)
	{
		cin >> vHeap[i];
	}
	maxHeap mHeap(vHeap, qt);
	for(int i = (qt - 2) / 2; i >= 0; i--)
	{
		cout << i << ": ";
		mHeap.corrigeDescendo(i);
	}
	return 0;
}