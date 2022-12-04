#include <iostream>
#include <fstream>

using namespace std;

struct pessoa
{
	char id[10] = {' '};
	char nome[100] = {' '};
	char emprego[100] = {' '};
	char salarioBase[20] = {' '};
	char salarioExtra[20] = {' '};
	char salarioOutros[20] = {' '};
	char beneficios[20] = {' '};
	char totalS[20] = {' '};
	char totalSb[20] = {' '};
	char ano[20] = {' '};
};

//Funcao para escrita em binario
void conversor(pessoa dado)
{
	ofstream escrita("san_francisco_payroll_dataset.bin", ios::app);
	escrita.write((const char *)&dado, sizeof(pessoa));
	escrita.close();
}

//Funcao para conversao de csv para o registro pessoa
void separa(string linha)
{
	pessoa dado;
	int sTam = linha.size(), vCont = 0, cCont = 0, aCont = 0; //cCount conta a posicao dentro do dado do registro
	for(int i = 0; i < sTam; i++)
	{
		//Caso o char nao seja uma virgula ele é adicionado na devida variavel do registro
		if(linha[i] != ',' || aCont == 1)
		{
			//IF para verificar se o dado está entre aspas 
			//Caso haja virgula dentro delas, é considerada como um char, nao como separacao de informacao do csv
			if(linha[i] == '"' && aCont == 0)
				aCont++; //Caso encontre uma " ele para de contar as virgulas como separacao e comeca a contar como caractere
			else if(linha[i] == '"' && aCont == 1)
				aCont--; //Identifica a segunda " para saber quando as virgulas deixam de ser caractere

			//Muda o dado em relacao a posicao a quantidade de virgulas
			if(vCont == 0)
				dado.id[cCont] = linha[i];
			else if(vCont == 1)
				dado.nome[cCont] = linha[i];
			else if(vCont == 2)
				dado.emprego[cCont] = linha[i];
			else if(vCont == 3)
				dado.salarioBase[cCont] = linha[i];
			else if(vCont == 4)
				dado.salarioExtra[cCont] = linha[i];
			else if(vCont == 5)
				dado.salarioOutros[cCont] = linha[i];
			else if(vCont == 6)
				dado.beneficios[cCont] = linha[i];
			else if(vCont == 7)
				dado.totalS[cCont] = linha[i];
			else if(vCont == 8)
				dado.totalSb[cCont] = linha[i];
			else if(vCont == 9)
				dado.ano[cCont] = linha[i];
			cCont++;
		}
		else if(linha[i] == ',' || aCont == 0)
		{
			vCont++;
			cCont = 0; //Zera a posicao da variavel no registro quando ha mudanca de variavel
		}
	}
	conversor(dado); //Envia para funcao que escreve no arquivo em binario
}

int main()
{
	ifstream leitura("san_francisco_payroll_dataset.csv");
	ofstream escrita("san_francisco_payroll_dataset.bin");
	leitura.seekg(0);
	string linha;
	getline(leitura, linha); //Retira o cabecalho do csv
	cout << "Aguarde..." << endl;
	//Le cada linhas do arquivo
	while(!leitura.eof())
	{
		getline(leitura, linha);
		separa(linha);
	}
	cout << endl << "Operacao Concluida";
	return 0;
}