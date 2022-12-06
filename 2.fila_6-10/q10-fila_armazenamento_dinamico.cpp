#include <iostream>

typedef int Dado;

class Noh {
	friend class Fila;
	private:
		Dado mDado;
		Noh* mPtProx;
	public:
		Noh(Dado mDado);
};

class Fila {
	 public:
		// Constroi uma fila vazia.
		Fila();
		// Desaloca memória de todos os nós da fila.
		~Fila();
		// Remove e retorna o primeiro item da fila.
		Dado Remover();
		// Insere um item no final da fila.
		void Inserir(const Dado& d);
		// Retorna o primeiro item da fila sem remover.
		Dado Proximo() const;
		// Remove todos os itens da fila.
		void LimparTudo();
		// Consulta a quantidade de itens na fila.
		unsigned Tamanho() const { return mTamanho; }
		// Consulta se a fila está vazia.
		bool Vazia() const;
	private:
		Noh* mPrimeiro;
		Noh* mUltimo;
		unsigned mTamanho;
};

using namespace std;

Noh::Noh(Dado dado)
{
	mDado = dado;
	mPtProx = NULL;
}

Fila::Fila() {
	mPrimeiro = NULL;
	mUltimo = NULL;
	mTamanho = 0;
}

Fila::~Fila() {
}

void Fila::Inserir(const Dado& d) {
	Noh *novoNoh = new Noh(d);
	if(mTamanho == 0)
	{
		mPrimeiro = novoNoh;
	}
	else
	{
		mUltimo->mPtProx = novoNoh;
	}
	mUltimo = novoNoh;
	mTamanho++;
}

Dado Fila::Remover() {
	Noh *aux = mPrimeiro;
	Dado dado = aux->mDado;
	mPrimeiro = aux->mPtProx;
	delete aux;
	mTamanho--;
	if(mTamanho == 0)
		mUltimo = NULL;
	return dado;
}

Dado Fila::Proximo() const {
	return mPrimeiro->mDado;
}

void Fila::LimparTudo() {
	while(mTamanho > 0)
		Remover();
}

bool Fila::Vazia() const {
	if(mTamanho)
		return 0;
	else
		return 1;
}

int main() {
	Fila fila;
	Dado valor;
	char comando;
	do {
		cin >> comando;
		switch (comando) {
			case 'i': // inserir
					cin >> valor;
					fila.Inserir(valor);
					break;
			case 'r': // remover
					cout << fila.Remover() << endl;
					break;
			case 'l': // limpar tudo
					fila.LimparTudo();
					break;
			case 't': // escrever tamanho
					cout << fila.Tamanho() << endl;
					break;
			case 'e': // espiar proximo
					cout << fila.Proximo() << endl;
					break;
			case 'f': // finalizar
					// vai verificar adiante
					break;
			default:
					cerr << "comando inválido\n";
		}
	} while (comando != 'f'); // finalizar execução
	while (not fila.Vazia()) {
		cout << fila.Remover() << ' ';
	}
	cout << endl;
	return 0;
}