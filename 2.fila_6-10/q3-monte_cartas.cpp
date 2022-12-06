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
		void mesclar(fila &f2);
		bool vazia();
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

void fila::mesclar(fila &f2)
{
	fila fAux;
	int var1, var2 = 0;
	do
	{
		if(fInicio->nDado < f2.fInicio->nDado)
			fAux.enfileirar(desenfileirar());
		else if(f2.fInicio->nDado < fInicio->nDado)
			fAux.enfileirar(f2.desenfileirar());
		else if(fInicio->nDado == f2.fInicio->nDado)
		{
			fAux.enfileirar(desenfileirar());
			f2.desenfileirar();
		}
	}while(!vazia() && !f2.vazia());
	while(!vazia())
		fAux.enfileirar(desenfileirar());
	while(!f2.vazia())
		fAux.enfileirar(f2.desenfileirar());
	var1 = fAux.desenfileirar();
	while(!fAux.vazia())
	{
		var2 = var1;
		var1 = fAux.desenfileirar();
		if(var2 < var1)
		{
			enfileirar(var2);
		}
	}
	enfileirar(var1);
	while(!vazia())
	{
		cout << desenfileirar() << ' ';
	}
}


int main()
{
	unsigned tamF1, tamF2;
	int dado;
	fila f1, f2;
	cin >> tamF1;
	for(unsigned i = 0; i < tamF1; i++)
	{
		cin >> dado;
		f1.enfileirar(dado);
	}
	cin >> tamF2;
	for(unsigned i = 0; i < tamF2; i++)
	{
		cin >> dado;
		f2.enfileirar(dado);
	}
	f2.mesclar(f1);
	return 0;
}