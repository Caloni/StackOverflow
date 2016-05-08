#include "StackOverflow.h"
#include <Windows.h>
#include <iostream>

// vetor de inicialização (IV - Initialization Vector)
// da rotina de criptografia que valida autenticação
// de acesso ao banco de dados; muda continuamente
// um inteiro em um offset determinado entre 
// as partes se comunicando
int IV[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

// faz acesso ao banco de dados para somente leitura
// é OK usuários sem privilégios chamarem essa função
void LendoBancoDeDados(int IVNewValue, int offset)
{
	// rotina comum de acesso ao banco de dados
	AcessoBanco(IV, offset, IVNewValue); 
	ApenasLeitura();
}

// faz acesso ao banco de dados para escrita
// não é OK usuários sem privilégio chamar essa função
void EscrevendoBancoDeDados(int IVNewValue, int offset)
{
	// por isso mesmo o programador que o implementou tomou
	// todas as medidas necessárias para se proteger
	if (offset >= 0 && offset < sizeof(IV))
	{
		// rotina comum de acesso ao banco de dados
		AcessoBanco(IV, offset, IVNewValue);
		GodMode(); // aqui fazemos algo perigoso com o banco
		// ou ganhamos o campeonato de hacking ;)
	}
}

// é chamada por toda função que vai acessar o banco
// não tem relação com ganho de privilégios
// tem um bug que permite a exploração de código malicioso
void AcessoBanco(int IV[], int offset, int value)
{
	int* px = (int*)(&IV + offset);
	*px = value;
	// ...
	// valida acesso normalmente...
	// ...
}

// aqui administradores podem escrever no banco de dados
// se você chegou aqui sendo um simples usuário, parabéns!
void GodMode()
{
	std::cout << "You win!\n";
}

// aqui qualquer zé mané chega, até usuário do Windows
void ApenasLeitura()
{
	std::cout << "Boring...\n";
}
