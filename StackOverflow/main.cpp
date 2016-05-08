#include "StackOverflow.h"
#include <iostream>

using namespace std;

// programa inocente de leitura de banco de dados
// mas que usa a mesma lib que faz escritas perigosas
int main()
{
	int offset = 0, value = 0;
	cout << "Digite sua chave seguida do token de acesso: ";
	cin >> value >> offset;
	// acessando o banco de dados como usuário 
	// SEM direitos administrativos
	LendoBancoDeDados(value, offset);
}
