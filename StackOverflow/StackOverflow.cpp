#include "StackOverflow.h"
#include <Windows.h>
#include <iostream>

// vetor de inicializa��o (IV - Initialization Vector)
// da rotina de criptografia que valida autentica��o
// de acesso ao banco de dados; muda continuamente
// um inteiro em um offset determinado entre 
// as partes se comunicando
int IV[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

// faz acesso ao banco de dados para somente leitura
// � OK usu�rios sem privil�gios chamarem essa fun��o
void LendoBancoDeDados(int IVNewValue, int offset)
{
	// rotina comum de acesso ao banco de dados
	AcessoBanco(IV, offset, IVNewValue); 
	ApenasLeitura();
}

// faz acesso ao banco de dados para escrita
// n�o � OK usu�rios sem privil�gio chamar essa fun��o
void EscrevendoBancoDeDados(int IVNewValue, int offset)
{
	// por isso mesmo o programador que o implementou tomou
	// todas as medidas necess�rias para se proteger
	if (offset >= 0 && offset < sizeof(IV))
	{
		// rotina comum de acesso ao banco de dados
		AcessoBanco(IV, offset, IVNewValue);
		GodMode(); // aqui fazemos algo perigoso com o banco
		// ou ganhamos o campeonato de hacking ;)
	}
}

// � chamada por toda fun��o que vai acessar o banco
// n�o tem rela��o com ganho de privil�gios
// tem um bug que permite a explora��o de c�digo malicioso
void AcessoBanco(int IV[], int offset, int value)
{
	int* px = (int*)(&IV + offset);
	*px = value;
	// ...
	// valida acesso normalmente...
	// ...
}

// aqui administradores podem escrever no banco de dados
// se voc� chegou aqui sendo um simples usu�rio, parab�ns!
void GodMode()
{
	std::cout << "You win!\n";
}

// aqui qualquer z� man� chega, at� usu�rio do Windows
void ApenasLeitura()
{
	std::cout << "Boring...\n";
}
