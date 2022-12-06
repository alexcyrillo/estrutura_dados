#include <iostream>

using namespace std;

class noh
{
	friend class pilha;
	private:
		noh *nProx;
		char nDado;
	public:
		noh(char dado);
};

class pilha
{
	private:
		int pTam;
		noh *pTopo;
	public:
		pilha();
		~pilha();
		void empilhar(char dado);
		void desempilhar();
		int tamanho();
};

noh::noh(char dado)
{
	nDado = dado;
	nProx = NULL;
}

pilha::pilha()
{
	pTam = 0;
	pTopo = NULL;
}

pilha::~pilha()
{
	while(pTopo)
		desempilhar();
}

void pilha::empilhar(char dado)
{
	noh *novoNoh = new noh(dado);
	novoNoh->nProx = pTopo;
	pTopo = novoNoh;
	pTam++; 
}

void pilha::desempilhar()
{
	noh *aux = pTopo;
	pTopo = pTopo->nProx;
	delete aux;
	pTam--;
}

int pilha::tamanho()
{
	return pTam;
}


int main()
{
	char letra;
	pilha pA, pC;
	int i = 0, contB = 0;
	do
	{
		cin >> letra;
		if(letra == 'A')
			pA.empilhar(letra);
		else if(letra == 'B')
			contB++;
		else if(letra == 'C')
			pC.empilhar(letra);
		if(pA.tamanho() >= 1 && pC.tamanho() >= 2)
		{
			pA.desempilhar();
			pC.desempilhar();
			pC.desempilhar();
		}
		i++;
	}
	while(letra != 'X');

	if(contB == 1 && pA.tamanho() == 0 && pC.tamanho() == 0)
		cout << "sim" << ' ' << pA.tamanho() << ' ' << pC.tamanho();
	else
		cout << "nao" << ' ' << pA.tamanho() << ' ' << pC.tamanho();
	return 0;
}