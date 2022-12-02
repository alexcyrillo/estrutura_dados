#include <iostream>

using namespace std;

class noh
{
	friend class pilha;
	private:
		int nDado;
		noh *nProx;
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
		void empilhar(int &dado);
		int desempilhar();
		int menor(pilha &mPilha);
};


noh::noh(int &dado)
{
	this->nDado = dado;
	this->nProx = NULL;
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

void pilha::empilhar(int &dado)
{
	noh *novoNoh = new noh(dado);
	novoNoh->nProx = pTopo;
	pTopo = novoNoh;
	pTam++;
}

int pilha::desempilhar()
{
	if(pTam > 0)
	{
		int rDado = pTopo->nDado;
		noh *aux = pTopo;
		pTopo = pTopo->nProx;
		delete aux;
		pTam--;
		return rDado;
	}
	else
	{
		return 0;
	}
}

int pilha::menor(pilha &mPilha)
{
	int var, menor;
	pilha auxPilha;
	while (mPilha.pTam > 0)
	{
		var = mPilha.desempilhar();
		auxPilha.empilhar(var);
		if(var < menor)
			menor = var;
	}
	while (auxPilha.pTam > 0)
	{
		var = auxPilha.desempilhar();
		mPilha.empilhar(var);
	}
	return menor;
}


int main()
{
	pilha mPilha;
	char menu;
	int mDado, tam = 0;
	do
	{
		cin >> menu;
		switch (menu)
		{
			case 'e':
				cin >> mDado;
				mPilha.empilhar(mDado);
				tam++;
				break;
			case 'd':
				if(tam > 0)
				{
					cout << mPilha.desempilhar() << endl;
					tam--;
				}
				else
					cout << "VAZIA" << endl;
				break;
			case 'm':
				if(tam > 0)
				{
					cout << mPilha.menor(mPilha) << endl;
				}
				else
					cout << "VAZIA" << endl;
				
				break;
			case 's':
				for(int i = 0; i < tam; i++)
					cout << mPilha.desempilhar() << ' ';
				break;
			default:
				break;
		}
	}while(menu != 's');
	return 0;
}