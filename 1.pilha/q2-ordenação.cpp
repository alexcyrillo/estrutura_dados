#include <iostream>

using namespace std;

class noh
{
	friend class pilha;
	private:
		int dado;
		noh *prox;
	public:
		noh(int valor);
};

class pilha
{
	private:
		int tam;
		noh *topo;
	public:
		pilha();
		~pilha();
		void empilhar(int dado);
		int desempilhar();
		void ordenar(pilha &umaPilha);
};

noh::noh(int valor)
{
	dado = valor;
	prox = NULL;
}

pilha::pilha()
{
	topo = NULL;
	tam = 0;
}

pilha::~pilha()
{
	while(topo)
		desempilhar();
};

void pilha::empilhar(int dado)
{
	noh *nohNovo = new noh(dado);
	nohNovo->prox = topo;
	topo = nohNovo;
	tam++;
};

int pilha::desempilhar()
{
	int retorno = topo->dado;
	noh *aux = topo;
	topo = aux->prox;
	delete aux;
	tam--;
	return retorno;
};

void pilha::ordenar(pilha &umaPilha)
{
	pilha auxP;
	int maior, var, a;
	a = tam;
	for (int i = 0; i < tam; i++)
	{
		maior = umaPilha.topo->dado;
		for (int j = 0; j < a; j++)
		{
			var = umaPilha.desempilhar();
			if( var > maior)
			{
					auxP.empilhar(maior);
					maior = var;
			}
			else
					auxP.empilhar(var);
		}
		a--;
		umaPilha.empilhar(maior);
		for(int k = 0; k < a; k++)
		{
			umaPilha.empilhar(auxP.desempilhar());
		}
	}
};

int main()
{
	pilha umaPilha;
	int tamanho, dado, z = 0;
	cin >> tamanho;
	while(z < tamanho)
	{
		cin >> dado;
		umaPilha.empilhar(dado);
		z++;
	}
	umaPilha.ordenar(umaPilha);
	for(int j = 0; j < tamanho; j++)
	{
		cout << umaPilha.desempilhar() << ' ';
	}
	return 0;
};