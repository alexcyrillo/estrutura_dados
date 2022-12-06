#include <iostream>

using namespace std;

class pilha
{
	private:
		int *pDados;
		int pTopo;
		int pTam;
	public:
		pilha();
		~pilha();
		void empilhar(int dado);
		int desempilhar();
		int tamanho();
};

pilha::pilha()
{
	pDados = new int[254];
	pTopo = -1;
	pTam = 0;
}

pilha::~pilha()
{
	delete pDados;
}

void pilha::empilhar(int dado)
{
	pDados[pTopo] = dado;
	pTopo = pTam;
	pTam++;	
}

int pilha::desempilhar()
{
	pTopo--;
	pTam--;
	return pDados[pTopo - 1];
}

int pilha::tamanho() 
{
	return pTam; 
}

int main()
{
	int tam, i = -1, pos = 0;
	bool verif = 0;
	string frase;
	pilha mPilha;
	getline(cin, frase);
	tam = frase.size();
	while(i < tam && !verif)
	{
		i++;
		if (frase[i] == '(')
		{
			pos = i;
			mPilha.empilhar(i);
		}
		else if (frase[i] == ')' && mPilha.tamanho() > 0)
			pos = mPilha.desempilhar();
		else if (frase[i] == ')' && mPilha.tamanho() == 0)
		{
			verif = 1;
			pos = i;
		}
	}
	if(mPilha.tamanho() == 0 && !verif)
		cout << "correto" << endl;
	else 
		cout << pos;
	return 0;
}