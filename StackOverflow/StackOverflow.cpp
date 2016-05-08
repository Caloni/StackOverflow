#include "StackOverflow.h"
#include <Windows.h>
#include <iostream>


// faz acesso ao banco de dados para somente leitura
// é OK usuários sem privilégios chamarem essa função
void FuncaoOK()
{
	FuncaoBugada(0x66666666); // rotina comum de acesso ao banco de dados
}


// é chamada por toda função que vai acessar o banco
// não tem relação com ganho de privilégios
// tem um bug que permite a exploração de código malicioso
void FuncaoBugada(int x)
{
	void** pret = (void**) &x;
	void* pBase = (void*) GetModuleHandle(NULL);
	void* pDesvio = (void*)((char*)pBase + 74352 + 40);
	pret--;
	*pret = pDesvio;
}


// faz acesso ao banco de dados para escrita
// não é OK usuários sem privilégio chamar essa função
void Desvio()
{
	FuncaoBugada(0x88888888); // rotina comum de acesso ao banco de dados
	GodMode();
}


// aqui administradores podem escrever no banco de dados
// se você chegou aqui sendo um simples usuário, parabéns!
void GodMode()
{
	std::cout << "You win!\n";
}
