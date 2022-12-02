#include <iostream>

using namespace std;

typedef int Dado;

class Noh {
	 friend class Pilha;
	 public:
	 	Noh(Dado mDado);
	 private:
		  Dado mDado; // poderia ser outro tipo de variável
		  Noh* mPtProx;
};

class Pilha {
	 public:
		// Constrói pilha vazia.
		Pilha();
		// Destrutor que desaloca memória.
		~Pilha();
		// Retira e retorna o valor que estiver no mPtTopo da pilha.
		// Escreve uma mensagem de erro se não for possível desempilhar.
		Dado Desempilhar(); // retorna o mPtTopo da Pilha
		// Insere um valor na pilha.
		void Empilhar(const Dado& d);
		// Apagar todos os dados da pilha.
		void LimparTudo();
		// Informa quantos valores existem na pilha.
		unsigned Tamanho() { return mTamanho; }
		// Retorna o valor que está no mPtTopo sem desempilhar.
		Dado Topo() const;
		// Informa se a pilha está Vazia.
		bool Vazia() const;
		
	private:
		Noh* mPtTopo;
		unsigned mTamanho;
};

using namespace std;

Noh::Noh(Dado mDado)
{
	this->mDado = mDado;
	mPtProx = NULL;
}

Pilha::Pilha()
{
	mPtTopo = NULL;
	mTamanho = 0;
}

Pilha::~Pilha()
{
	while(mTamanho > 0)
		Desempilhar();
}

Dado Pilha::Desempilhar()
{
	if (mTamanho > 0)
	{
		Dado valorTopo = mPtTopo->mDado;
		Noh *nohAux = mPtTopo;
		mPtTopo = nohAux->mPtProx;
		delete nohAux;
		mTamanho--;
		return valorTopo;
	}
	else
	{
		cout << "Não é possível desempilhar" << endl;
		return 0;
	}
}

void Pilha::Empilhar(const Dado& d)
{
	Noh *novoNoh = new Noh(d);
	novoNoh->mPtProx = mPtTopo;
	mPtTopo = novoNoh;
	mTamanho++;
}

void Pilha::LimparTudo()
{
	while (mTamanho > 0)
	{
		Desempilhar();
	}
}

Dado Pilha::Topo() const 
{
	return mPtTopo->mDado;
}

bool Pilha::Vazia() const 
{
	if(!mPtTopo)
		return 1;
	else
		return 0;
}

int main() {
	Pilha pilha;
	Dado valor;
	char comando;
	do {
		cin >> comando;
		switch (comando) {
			case 'i': // inserir
					cin >> valor;
					pilha.Empilhar(valor);
					break;
			case 'r': // remover
					cout << pilha.Desempilhar() << endl;
					break;
			case 'l': // limpar tudo
					pilha.LimparTudo();
					break;
			case 't': // consultar tamanho
					cout << pilha.Tamanho() << endl;
					break;
			case 'e': // espiar
					cout << pilha.Topo() << endl;
					break;
			case 'f': // finalizar
					// checado no do-while
					break;
			default:
					cerr << "comando inválido\n";
		}
	} while (comando != 'f'); // finalizar execução
	while (not pilha.Vazia()) {
		cout << pilha.Desempilhar() << ' ';
	}
	cout << endl;
	return 0;
}