#include <iostream>

using namespace std;

class fila
{
	private:
		unsigned fTam;
		unsigned fCap;
		int *fDado;
		int fInicio;
		int fFim;
	public:
		fila(unsigned tam);
		~fila();
		void enfileirar(int dado);
		int desenfileirar();
		void info();
};

fila::fila(unsigned cap)
{
	fTam = 0;
	fCap = cap;
	fDado = new int[cap];
	fInicio = -1;
	fFim = -1;
}

fila::~fila()
{
	while(fTam)
		desenfileirar();
}

void fila::enfileirar(int dado)
{
	if(fTam < fCap)
	{
		if(fInicio == -1)
			fInicio++;
		fFim = (fFim + 1) % fCap;
		fDado[fFim] = dado;
		fTam++;
	}
}

int fila::desenfileirar()
{
	int dado = fDado[fInicio];
	if(fInicio == fFim)
	{
		fFim = -1;
		fInicio = -1;
	}
	else
		fInicio = (fInicio + 1) % fCap;
	fTam--;
	return dado;
}

void fila::info()
{
	cout << "tamanho=" << fTam << ' '
		  << "capacidade=" << fCap << ' '
		  << "inicio=" << fInicio << ' '
		  << "fim=" << fFim << ' ' << endl;
	for(unsigned i = 0; i < fTam; i++)
	{
		if(i + fInicio < fCap)
		{
			cout << fDado[fInicio + i] << ' ';
		}
		else
		{
			cout << fDado[(fInicio + i) % fCap] << ' ';
		}
	}
	cout << endl;
}


int main()
{
	char menu;
	int mDado, mCap;
	cin >> mCap;
	fila mFila(mCap);
	do
	{
		cin >> menu;
		switch(menu)
		{
			case 'e':
				cin >> mDado;
				mFila.enfileirar(mDado);
			break;
			case 'd':
				cout << mFila.desenfileirar() << endl;
			break;
			case 'i':
				mFila.info();
			break;
			case 't':
			break;
			default:
			break;
		}
	}while(menu != 't');

	return 0;
}