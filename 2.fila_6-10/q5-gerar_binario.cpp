#include <iostream>

using namespace std;

class noh
{
	friend class fila;
	private:
		string nDado;
		noh *nProx;
	public:
		noh(string dado);
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
		void enfileirar(string dado);
		string desenfileirar();
};

noh::noh(string dado)
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
	while(fTam != 0)
		desenfileirar();
}

void fila::enfileirar(string dado)
{
	noh *novoNoh = new noh(dado);
	if(fTam == 0)
		fInicio = novoNoh;
	else
		fFim->nProx = novoNoh;
	fFim = novoNoh;
	fTam++; 
}

string fila::desenfileirar()
{
	string dado = fInicio->nDado;
	noh *aux = fInicio;
	fInicio = fInicio->nProx;
	delete aux;
	fTam--;
	if(fTam == 0)
		fFim = NULL;
	return dado;
}

int main()
{
	int qt;
	string binario = "1";
	fila fBinario, fBinario2;
	
	cin >> qt;

	fBinario.enfileirar(binario);
	for(int i = 0; i < qt; i++)
	{
		fBinario.enfileirar(binario + "0");
		fBinario.enfileirar(binario + "1");
		fBinario2.enfileirar(binario + "0");
		fBinario2.enfileirar(binario + "1");
		binario = fBinario2.desenfileirar();
	}

	for(int i = 0; i < qt; i++)
	{
		cout << fBinario.desenfileirar() << ' ';
	}

	return 0;
} 