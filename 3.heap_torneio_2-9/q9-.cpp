#include <iostream>

using namespace std;

class maxHeap
{
	private:
		int hCap;
		int hTam;
		int *hDados;
	public:
		maxHeap(int *dados, int cap);
		~maxHeap();
		void corrigeDescendo(int pos);
		int fEsquerdo(int i) {return 2 * i + 1;}
		int fDireito(int i) {return 2 * i + 2;}
};

maxHeap::maxHeap(int *dados, int cap)
{
	hCap = cap;
	hTam = cap;
	hDados = dados;
}

maxHeap::~maxHeap()
{
	delete[] hDados;
}

void maxHeap::corrigeDescendo(int pos)
{
	int filhoE, filhoD, maior = pos;
	filhoE = fEsquerdo(pos);
	filhoD = fDireito(pos);
	if((filhoE <= hTam - 1) && (hDados[filhoE] > hDados[maior]))
	{
		maior = filhoE;
	}
	if((filhoD <= hTam - 1) && (hDados[filhoD] > hDados[maior]))
	{
		maior = filhoD;
	}
	if(maior != pos)
	{
		int aux;
		aux = hDados[pos];
		hDados[pos] = hDados[maior];
		hDados[maior] = aux;
		corrigeDescendo(maior);
	}
	else
	{
		for(int i = 0; i < hCap; i++)
		{
			cout << hDados[i] << ' ';
		}
		cout << endl;
	}
}


int main()
{
	int *vHeap;
	vHeap = new int[20];
	for(int i = 0; i < 15; i++)
	{
		cin >> vHeap[i];
	}
	maxHeap mHeap(vHeap, 15);
	/*for(int i = (qt - 2) / 2; i >= 0; i--)
	{
		cout << i << ": ";
		mHeap.corrigeDescendo(i);
	}*/
	return 0;
}