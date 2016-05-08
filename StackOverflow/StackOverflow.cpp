#include "StackOverflow.h"
#include <Windows.h>
#include <iostream>


// faz acesso ao banco de dados para somente leitura
// � OK usu�rios sem privil�gios chamarem essa fun��o
void FuncaoOK()
{
	FuncaoBugada(0x66666666); // rotina comum de acesso ao banco de dados
}


// � chamada por toda fun��o que vai acessar o banco
// n�o tem rela��o com ganho de privil�gios
// tem um bug que permite a explora��o de c�digo malicioso
void FuncaoBugada(int x)
{
	void** pret = (void**) &x;
	void* pBase = (void*) GetModuleHandle(NULL);
	void* pDesvio = (void*)((char*)pBase + 74352 + 40);
	pret--;
	*pret = pDesvio;
}


// faz acesso ao banco de dados para escrita
// n�o � OK usu�rios sem privil�gio chamar essa fun��o
void Desvio()
{
	FuncaoBugada(0x88888888); // rotina comum de acesso ao banco de dados
	GodMode();
}


// aqui administradores podem escrever no banco de dados
// se voc� chegou aqui sendo um simples usu�rio, parab�ns!
void GodMode()
{
	std::cout << "You win!\n";
}
