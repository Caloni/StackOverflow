# Sobre ataques que mexem com a pilha

Um StackOverflow � definido pela escrita em uma regi�o n�o autorizada de mem�ria. Stack overflow, overrun, etc, n�o interessando a nomenclatura "oficial", o importante aqui � como um bug de acesso � mem�ria pode permitir acesso exclusivo a regi�es de mem�ria que n�o estariam dispon�veis para um atacante se n�o fosse por esse bug.

No exemplo do c�digo deste projeto, um usu�rio fict�cio utiliza um c�digo que possui controle de acesso, mas tamb�m possui um bug: ele escreve em uma regi�o da mem�ria inadvertidamente. Dessa forma, � poss�vel explorar essa falha no c�digo para escrever um novo endere�o de retorno na pilha (stack), ganhando acesso, dessa forma, a c�digo que n�o estaria dispon�vel em situa��es normais de temperatura e press�o.

Para explorar esse tipo de falha, primeiro devemos entender a execu��o do c�digo na arquitetura que se pretende atacar, al�m de alguns conceitos espec�ficos do sistema operacional alvo.

# T�picos abordados durante a palestra

## Abstra��o multi-camadas (a.k.a. Matrix Conspiracy Edition)

 - UML: Mundo real aplicado a engenharia.
 - Programa��o: Codifica��o do mundo real.
 - Assembly: Ponte entre ser humano e m�quina.
 - 1's e 0's: Codifica��o l�gica do computador.
 - Impulsos el�tricos: Voltamos para o mundo real.
 - Qubit: Voltamos para a Matrix.
 - ("IBM disponibiliza computador qu�ntico para p�blico")

## Assembly -> 1's e 0's: Sistema Operacional e Arquitetura
 - Mais abstra��es: Mem�ria Virtual, Threads, I/O.

## Assembly
 - Movimenta��o de mem�ria (mov, lea)
 - C�lculos matem�ticos (add, div)
 - Meta-comandos (push, pop, ret, jmp)

## Mem�ria
 - Registradores (e[abcd]x, [bs]sp, eip)
 - Endere�o Virtual ([Kernel|User] Space)
 - Endere�o F�sico (RAM, ROM, Storage, placas)

## EIP: Extended Interruption Pointer
 - Qual o sentido de apontar para a pr�xima instru��o?
 - R: Saber onde continuar a execu��o.
 - Demo: Chamada de fun��o.
 - Demo: Retorno de fun��o.

## E[BS]P: Extended Base|Stack Pointer
 - Qual o sentido de existir uma stack?
 - R: Conseguir chamar fun��es.
 - Demo: Chamada de fun��o.
 - Demo: Passagem de argumentos.
 - Demo: Retorno de fun��o.

## Sistema Operacional: Nascimento da Engenharia de Software
 - Escalonamento de threads
 - Virtualiza��o da mem�ria
 - Controle de acesso
 - Pagina��o
 - Plug and Play
 - Windows NT
 - Dave Cutler
 - xBox One
 - Hypervisor

## Processos: Prote��o (SO, Mem�ria Virtual, Hypervisor)
 - Thread: Uma ilus�o satisfat�ria.
 - Fibers, Co-Routines, Cores, Pipe Line, Branch Prediction.
 - Computa��o Qu�ntica: Hackeando o Universo.

## Fun��es: mais uma ilus�o satisfat�ria.
 - Python, F#, Lambdas C++11, M�todos, Fun��o Virtual.
 - Bloco de mem�ria chama... Outro bloco de mem�ria 

## Conven��o de Chamada: organizando a bagun�a.
 - [[[C]]]]decl e Std(?)call (M$).
 - Demo: Fun��o em C sendo chamada.
 - Demo: Fun��o da Microsoft sendo chamada.
 - Ou: Porque o printf precisa ser cdecl.

## Mem�ria Virtual: deixa eu adivinhar: ilus�o?
 - Page Tables, PTEntries, Page Fault, Memory Map.
 - Demo: Process Explorer.

## Hackeando Von Neymar: controle de acesso � mem�ria.
 - 2 bits: Quatro possibilidades.
 - Read-Only Memory, Execute Memory.

## Microsoft e o A Teoria do Caos
 - Ah, vamos para o BAR: Base Address Randomization.
 - Demo: Ver se isso funciona, mesmo.

## Visual Studio: Tentando controlar o caos.
 - ESP Verification.
 - Buffer overrun.
 - 0xCCCCCCCCCCCCCCCCCCCCC
