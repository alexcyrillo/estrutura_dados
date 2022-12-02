#include <iostream>

using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
	private:
		int capacidade;
		Dado *dados;
		int tamanho;
		int posTopo;
	public:
		pilhav(int cap);
		~pilhav();
		void empilha(Dado valor);
		Dado desempilha();
		Dado espia(); // acessa elemento do topo, mas não retira
		void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
		void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int cap)
{
	capacidade = cap;
	dados = new Dado[cap];
	tamanho = 0;
	posTopo = -1;
}

pilhav::~pilhav()
{
	while(posTopo)
		desempilha();
}

void pilhav::empilha(Dado valor)
{
	if(capacidade > tamanho)
	{
		posTopo++;
		dados[posTopo] = valor;
		tamanho++;
	}
}

Dado pilhav::desempilha()
{
	Dado valor = dados[posTopo];
	posTopo--;
	tamanho--;
	return valor;
}

Dado pilhav::espia()
{
	return dados[posTopo];
}

void pilhav::depura()
{
	for(int i = 0; i < tamanho; i++)
	{
		cout << dados[i] << ' ';
	}
	cout << endl;
};

void pilhav::info()
{
	cout << tamanho << ' ' << posTopo << endl;
};

int main()
{
	Dado num;
	pilhav pilha(20);
	for(int i = 0; i < 5; i++)
	{
		cin >> num;
		pilha.empilha(num);
	}
	for(int i = 0; i < 3; i++)
	{
		cout << pilha.desempilha() << ' ';
	}
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		cin >> num;
		pilha.empilha(num);
	}
	for(int i = 0; i < 3; i++)
	{
		cout << pilha.desempilha() << ' ';
	}
	cout << endl << pilha.espia() << endl;
	pilha.depura();
	pilha.info();

	return 0;
}