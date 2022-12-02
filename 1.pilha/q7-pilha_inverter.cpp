#include <iostream>

using namespace std;

class noh
{
	friend class pilha;
	private:
		noh *nProx;
		int nDado;
	public:
		noh(int &dado);
};

class pilha
{
	private:
		int pTam;
		noh *pTopo;
	public:
		pilha();
		~pilha();
		void empilhar(int dado);
		int desempilhar();
		void inverter();
};

noh::noh(int &dado)
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

void pilha::empilhar(int dado)
{
	noh *novoNoh = new noh(dado);
	novoNoh->nProx = pTopo;
	pTopo = novoNoh;
	pTam++; 
}

int pilha::desempilhar()
{
	int rDado = pTopo->nDado;
	noh *aux = pTopo;
	pTopo = pTopo->nProx;
	delete aux;
	pTam--;
	return rDado;
}

void pilha::inverter()
{
	pilha altPilha;
	int tam = pTam;
	for(int i = 0; i < tam; i++)
	{
		altPilha.empilhar(desempilhar());
	}
	for(int i = 0; i < tam; i++)
	{
		cout << altPilha.desempilhar() << ' ';
	}
}


int main()
{
	int qt, dado;
	cin >> qt;
	pilha mPilha;
	for(int i = 0; i < qt; i++)
	{
		cin >> dado;
		mPilha.empilhar(dado);
	}
	mPilha.inverter();

	return 0;
}