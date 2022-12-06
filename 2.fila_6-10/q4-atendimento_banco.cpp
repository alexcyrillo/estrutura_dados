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
		bool vazia();
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
	while(!vazia())
		desenfileirar();
}

void fila::enfileirar(string dado)
{
	noh *novoNoh = new noh(dado);
	if(vazia())
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

bool fila::vazia()
{
	if(fFim == NULL)
		return 1;
	else
		return 0;
}


int main()
{
	unsigned cont = 0;
	fila fPrioridade, fNormal;
	string menu, nome;
	do
	{
		cin >> menu;
		if(menu == "normal")
		{
			cin >> nome;
			fNormal.enfileirar(nome);
		}
		else if(menu == "prioridade")
		{
			cin >> nome;
			fPrioridade.enfileirar(nome);
		}
		else if(menu == "atender")
		{
			if(cont == 3)
			{
				if(!fNormal.vazia())
				{
					cout << fNormal.desenfileirar() << endl;
					cont = 0;
				}
				else if(!fPrioridade.vazia())
				{
					cout << fPrioridade.desenfileirar() << endl;
					cont++;
				}
				else
					cout << "AGUARDE" << endl;
			}
			else
			{
				if(!fPrioridade.vazia())
				{
					cout << fPrioridade.desenfileirar() << endl;
					cont++;
				}
				else if(!fNormal.vazia())
				{
					cout << fNormal.desenfileirar() << endl;
					cont = 0;
				}
				else
					cout << "AGUARDE" << endl;
			}
		}
	}while(menu != "fim");
	
	return 0;
}