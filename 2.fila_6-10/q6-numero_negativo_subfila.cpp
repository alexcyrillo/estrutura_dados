#include <iostream>

using namespace std;

class noh
{
	friend class fila;
	private:
		int nDado;
		noh *nProx;
	public:
		noh(int dado);
};

class fila
{
	private:
		noh *fInicio;
		noh *fFim;
		unsigned fTam;
	public:
		fila();
		~fila();
		void enfileirar(int dado);
		int desenfileirar();
		bool vazia();
		int espiar();
};

noh::noh(int dado)
{
	nDado = dado;
	nProx = NULL;
}

fila::fila()
{
	fInicio = NULL;
	fFim = NULL;
	fTam = 0;
}

fila::~fila()
{
	while(fTam)
		desenfileirar();
}

void fila::enfileirar(int dado)
{
	noh *novoNoh = new noh(dado);
	if(fTam == 0)
		fInicio = novoNoh;
	else
		fFim->nProx = novoNoh;
	fFim = novoNoh;
	fTam++; 
}

int fila::desenfileirar()
{
	int dado = fInicio->nDado;
	noh *aux = fInicio;
	fInicio = fInicio->nProx;
	delete aux;
	fTam--;
	if(fTam == 0)
		fFim = NULL;
	return dado;
}

bool fila::vazia()
{
	if(fFim == NULL)
		return 1;
	else
		return 0;
}

int fila::espiar()
{
	return fInicio->nDado;
}

int main()
{
	int tamFila, dado, tamSub, neg, inter;
	fila mFila, mFila2;
	cin >> tamFila;
	for(int i = 0; i < tamFila; i++)
	{
		cin >> dado;
		mFila.enfileirar(dado);
	}
	cin >> tamSub;
	inter = tamFila - tamSub + 1;
	for(int i = 0; i < inter; i++)
	{
		neg = 0;
		for(int j = 0; j < tamSub; j++)
		{
			if(mFila.espiar() < 0 && neg == 0)
			{
				neg = mFila.desenfileirar();
				mFila2.enfileirar(neg);
			}
			else
				mFila2.enfileirar(mFila.desenfileirar());
		}
		while(!mFila.vazia())
			mFila2.enfileirar(mFila.desenfileirar());
		mFila2.desenfileirar();
		tamFila--;
		for(int j = 0; j < tamFila; j++)
			mFila.enfileirar(mFila2.desenfileirar());
		if(neg >= 0)
			cout << "inexistente" << ' ';
		else
			cout << neg << ' ';
	}
	return 0;
}