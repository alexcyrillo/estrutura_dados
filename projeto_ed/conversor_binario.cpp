#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream leitura("san_francisco_payroll_dataset.csv");
	ofstream escrita("san_francisco_payroll_dataset.bin");
	string cp;
	while(leitura >> cp)
	{
		cout << cp << endl;
	}
	return 0;
}