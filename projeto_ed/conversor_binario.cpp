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
void separa(string cp)
{
	pessoa dado;
	int tam = cp.size(), vCont = 0, cCont = 0, aCont = 0;
	for(int i = 0; i < tam; i++)
	{
		if(cp[i] != ',' || aCont == 1)
		{
			//Este IF faz a verificacao se o dado está entre "", assim fazendo que a virgula dentro delas nao seja contada como virgula de separacao, mas sim como um caractere
			if(cp[i] == '"' && aCont == 0)
				aCont++; //Caso encontre uma " ele para de contar as virgulas como separacao e comeca a contar como caractere
			else if(cp[i] == '"' && aCont == 1)
				aCont--; //Identifica a segunda " para saber quando as virgulas deixam de ser caractere

			if(vCont == 0)
			{
				dado.id[cCont] = cp[i];
			}
			else if(vCont == 1)
			{
				dado.nome[cCont] = cp[i];
			}
			else if(vCont == 2)
			{
				dado.emprego[cCont] = cp[i];
			}
			else if(vCont == 3)
			{
				dado.salarioBase[cCont] = cp[i];
			}
			else if(vCont == 4)
			{
				dado.salarioExtra[cCont] = cp[i];
			}
			else if(vCont == 5)
			{
				dado.salarioOutros[cCont] = cp[i];
			}
			else if(vCont == 6)
			{
				dado.beneficios[cCont] = cp[i];
			}
			else if(vCont == 7)
			{
				dado.totalS[cCont] = cp[i];
			}
			else if(vCont == 8)
			{
				dado.totalSb[cCont] = cp[i];
			}
			else if(vCont == 9)
			{
				dado.ano[cCont] = cp[i];
			}
			cCont++;
		}
		else if(cp[i] == ',' || aCont == 0)
		{
			vCont++;
			cCont = 0;
		}
	}
	conversor(dado);
	/*cout << dado.id << ' ' << dado.nome << ' ' << dado.emprego << ' ' << dado.salarioBase << ' ' << dado.salarioExtra << ' ' << dado.salarioOutros << ' ' << dado.beneficios << ' ' << dado.totalS << ' ' << dado.totalSb << ' ' << dado.ano;*/
}


int main()
{
	ifstream leitura("san_francisco_payroll_dataset.csv");
	string cp;
	getline(leitura, cp);
	cout << "Aguarde..." << endl;
	while(!leitura.eof())
	{
		getline(leitura, cp);
		separa(cp);
	}
	cout << "Operacao Concluida";
	return 0;
}