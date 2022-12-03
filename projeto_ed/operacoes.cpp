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
//Função para imprimir o Menu de Opções
void menu()
{
	cout << "Escolha uma das seguintes operações a serem realizadas:" <<endl;
	cout << "(a) - Adicionar um novo elemento" << endl;
	cout << "(v) - Visualizar os registros entre determinado intervalo" << endl;
	cout << "(m) - Mudar dados de um registro" << endl;
	cout << "(t) - Trocar dois registros de posição" << endl;
	cout << "(i) - Imprimir todo o arquivo" << endl;
	cout << "(s) - Sair e encerrrar" << endl;
}
//Função responsável por adicionar um elemento, movendo todas as posições adiantes para frente.
void adicionar(pessoa &person, int pos)
{
		ofstream binario("san_francisco_payroll_dataset.bin", ios::app | ios::ate);
		ifstream leitura_binario("san_francisco_payroll_dataset.bin");
		pessoa registro;
		//Calcula-se o tamanho do arquivo com a função tellg.
		long int tam_byte = leitura_binario.tellg();
		//Assim, o calculo para a quantidade de registros é dado por:
		int quantidade_registro = (tam_byte / sizeof(pessoa));
		int cont = quantidade_registro;
		if(leitura_binario){
			//Atribui-se a quantidade de registro a um contador, por fins estéticos.
			//Basicamente, posiciona-se a cabeça de leitura no ultimo registro e ele é lido.
			//Após isso, posiciona-se a cabeça de escrita uma posicão após o  registro lido e escreve o registro em tal posição.
			//Essa repetição é feita até que chegue na posição informada pelo usuário.
			while(cont > pos){
					leitura_binario.seekg((cont-1) * sizeof(pessoa));
					leitura_binario.read((char*) &registro, sizeof(pessoa));
					binario.seekp(cont * sizeof(pessoa));
					binario.write((const char *) &registro, sizeof(pessoa));
					cont--;
			}
			//Após isso, é necessário apenas escrever o registro desejado na posição, após a mudança de posição dos registros.
			binario.seekp(pos * sizeof(pessoa));
			binario.write((const char *) (&person), sizeof(pessoa));
		}else{
			cout << "Arquivo não encontrado" << endl;
		}
		binario.close();
		leitura_binario.close();
}   
//Função que imprime um intervalo determinado pelo usuário.
void visualizar(int pos,int pos1)
{
	ifstream leitura_binario("san_francisco_payroll_dataset.bin");
	pessoa registro;
	cout << "Id    Nome do Empregado    Cargo     Salário Base    Salário Extra    Outros Pagamentos    Benefícios    Pagamento Total    Pagamento Total e Benefícios    Ano\n";
	//Lê o arquivo até que chegue na posição final do intervalo.
	//A medida que a leitura é feita, cada registro é imprimido.
	while(pos<=pos1){
		leitura_binario.seekg(pos * sizeof(pessoa));
		leitura_binario.read((char *)(&registro),sizeof(pessoa));
		cout << registro.id << "  " << registro.nome << "  " << registro.emprego << "  " << registro.salarioBase << "  " << registro.salarioExtra << "  " << registro.salarioOutros << "  " << registro.beneficios << "  " << registro.totalS << "  " << registro.totalSb << "  " << registro.ano << endl;
		pos++;
	}
	leitura_binario.close();
}
//Função que muda os dados de determinado registro, determinado pelo usuário.
void mudar(pessoa &novo,int pos)
{
	//A funçao posiciona a cabeça de escrita na posição desejada, escrevendo então as atualizações do registro.
	ofstream binario("san_francisco_payroll_dataset.bin",ios::app);
	binario.seekp(pos * sizeof(pessoa),ios::beg);
	binario.write((const char *)(&novo),sizeof(pessoa));
	binario.close();
}
//Função que troca de posição dois registros, esses que são determinado pelos usuários.
void trocar(int pos,int pos1)
//Primeiramente, é lido os registros das duas posições.
//Segundamente então, suas posições trocam e é feito a escrita.
{
	pessoa aux,aux1;
	ifstream leitura_binario("san_francisco_payroll_dataset.bin");
	ofstream binario("san_francisco_payroll_dataset.bin",ios::app);
	leitura_binario.seekg(pos * sizeof(pessoa),ios::beg);
	leitura_binario.read((char *)(&aux),sizeof(pessoa));
	leitura_binario.seekg(pos1 * sizeof(pessoa),ios::beg);
	leitura_binario.read((char *)(&aux1),sizeof(pessoa));
	binario.seekp(pos1 * sizeof(pessoa),ios::beg);
	binario.write((const char *)(&aux),sizeof(pessoa));
	binario.seekp(pos * sizeof(pessoa),ios::beg);
	binario.write((const char *)(&aux1),sizeof(pessoa));
	binario.close();
}
//Funçao que Imprime todos os registros presentes no arquivo binário.
void imprimir()
{
	ifstream leitura_binario("san_francisco_payroll_dataset.bin");
	long int tam_byte = leitura_binario.tellg();
	int quantidade_registro = (tam_byte / sizeof(pessoa));
	int contador;
	pessoa registro;
	cout << "Id    Nome do Empregado    Cargo     Salário Base    Salário Extra    Outros Pagamentos    Benefícios    Pagamento Total    Pagamento Total e Benefícios    Ano\n";
	//É calculado a quantidade de registro assim como explicado na função adicionar e então é feito um loop que termina quando chega no ultimo registro.Nessa repetição, imprime todos os registros.
	while(contador < quantidade_registro){
		leitura_binario.seekg(contador * sizeof(pessoa));
		leitura_binario.read((char *)(&registro),sizeof(pessoa));
		cout << registro.id << "  " << registro.nome << "  " << registro.emprego << "  " << registro.salarioBase << "  " << registro.salarioExtra << "  " << registro.salarioOutros << "  " << registro.beneficios << "  " << registro.totalS << "  " << registro.totalSb << "  " << registro.ano << endl;
		contador++;
	}
	leitura_binario.close();
}

int main (){
	char opcao;
	int pos,pos1;
	pessoa person;
	menu();
	cin>>opcao;
	do{
		switch (opcao){

		case 'a':
			cout << "Informações do novo registro:\n" << "Id: ";
			cin.getline(person.id, 10);
			cout << "Nome do Empregado: ";
			cin.getline(person.nome,100);
			cout << "Cargo: ";
			cin.getline(person.emprego,100);
			cout << "Salário Base: ";
			cin.getline(person.salarioBase,20);
			cout << "Salário Extra: ";
			cin.getline(person.salarioExtra,20);
			cout << "Outros Pagamentos: ";
			cin.getline(person.salarioOutros,20);
			cout << "Benefícios: ";
			cin.getline(person.beneficios,20);
			cout << "Pagamento Total: ";
			cin.getline(person.totalS,20);
			cout << "Pagamento Total e Benefícios: ";
			cin.getline(person.totalSb,20);
			cout << "Ano: ";
			cin.getline(person.ano,20);
			cout << "Defina a posição onde adicionar o registro: ";
			cin >> pos;
			adicionar(person,pos);
			
			cout << "Arquivo adicionado com sucesso!" << endl;
			break;
		case 'v':
			cout << "Defina o intervalor para visualização: ";
			cin >> pos >> pos1;
			visualizar(pos,pos1);
			break;
		case 'm':   
			cout << "Informações do novo registro a ser mudado\n" << "Id: ";
			cin.getline(person.id, 10);
			cout << "Nome do Empregado: ";
			cin.getline(person.nome,100);
			cout << "Cargo: ";
			cin.getline(person.emprego,100);
			cout << "Salário Base: ";
			cin.getline(person.salarioBase,20);
			cout << "Salário Extra: ";
			cin.getline(person.salarioExtra,20);
			cout << "Outros Pagamentos: ";
			cin.getline(person.salarioOutros,20);
			cout << "Benefícios: ";
			cin.getline(person.beneficios,20);
			cout << "Pagamento Total: ";
			cin.getline(person.totalS,20);
			cout << "Pagamento Total e Benefícios: ";
			cin.getline(person.totalSb,20);
			cout << "Ano: ";
			cin.getline(person.ano,20);
			cout << "Defina a posição onde onde será substituído o registro: ";
			cin >> pos;
			mudar(person,pos);
			cout << "Arquivo mudado com sucesso!" << endl;
			break;
		case 't':
			cout << "Escolha as posições dos dois registros a serem trocados: ";
			cout << "Posição do primeiro registro: ";
			cin >> pos;
			cout << "Posição do outro registro: ";
			cin >> pos1;
			trocar(pos,pos1);
			break;
		case 'i':
			imprimir();
			break;
		case 's':
			break;
		default:
			cout << "Operação inválida" << endl;
			break;
		}
		menu();
		cin>>opcao;
	}while(opcao!='s');
	return 0;
}