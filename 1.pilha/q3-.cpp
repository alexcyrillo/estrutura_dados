#include <iostream>
//#include <string>

using namespace std;

class pilha
{
	private:
		int mTopo;
		int mPos;
		int mTam;
	public:
		pilha(int tam);
		int verificar(string frase);
		int empilhar();
		int desempilhar();
};

pilha::pilha(int tam)
{
	mTam = tam;
	mPos = 0;
	mTopo = 0;
}

int pilha::verificar(string frase)
{
	do
	{
		char verif = frase[mPos];
		if(frase[mPos] == '(')
		{
			empilhar();
			mPos++;
		}
		else if(frase[mPos] == ')')
		{
			desempilhar();
			mPos++;
		};
	}while(mPos >= 0 || mPos != mTam);
}

int pilha::empilhar()
{
	mTopo = mPos;;
}

int pilha::desempilhar()
{
	mTopo--;
}

int main()
{
	int tam;
	string frase;
	getline(cin, frase);
	tam = frase.size();
	pilha teste(tam);
	teste.verificar(frase);

	return 0;
}