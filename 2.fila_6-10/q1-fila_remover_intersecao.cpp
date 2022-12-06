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
		void inserir(int dado);
		int remover();
		unsigned remDuplicado(fila &f2);
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
		remover();
}

void fila::inserir(int dado)
{
	noh *novoNoh = new noh(dado);
	if(fTam == 0)
	{
		fInicio = novoNoh;
	}
	else
	{
		fFim->nProx = novoNoh;
	}
	fFim = novoNoh;
	fTam++;
}

int fila::remover()
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

unsigned fila::remDuplicado(fila &f2)
{
	int dadoF2, dadoF1;
	fila fAux;
	while(f2.fTam)
	{
		dadoF2 = f2.remover();
		while(fTam)
		{
			dadoF1 = remover();
			if(dadoF2 != dadoF1)
				fAux.inserir(dadoF1);
		}
		while(fAux.fTam)
			inserir(fAux.remover());
	}
	return fTam;
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
		f1.inserir(dado);
	}
	cin >> tamF2;
	for(unsigned i = 0; i < tamF2; i++)
	{
		cin >> dado;
		f2.inserir(dado);
	}
	tamF1 = f1.remDuplicado(f2);
	for(unsigned i = 0; i < tamF1; i++)
		cout << f1.remover() << ' ';
	return 0;
}