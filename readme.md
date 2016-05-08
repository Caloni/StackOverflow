# Sobre ataques que mexem com a pilha

Um StackOverflow � definido pela escrita em uma regi�o n�o autorizada de mem�ria. Stack overflow, overrun, etc, n�o interessando a nomenclatura "oficial", o importante aqui � como um bug de acesso � mem�ria pode permitir acesso exclusivo a regi�es de mem�ria que n�o estariam dispon�veis para um atacante se n�o fosse por esse bug.

No exemplo do c�digo deste projeto, um usu�rio fict�cio utiliza um c�digo que possui controle de acesso, mas tamb�m possui um bug: ele escreve em uma regi�o da mem�ria inadvertidamente. Dessa forma, � poss�vel explorar essa falha no c�digo para escrever um novo endere�o de retorno na pilha (stack), ganhando acesso, dessa forma, a c�digo que n�o estaria dispon�vel em situa��es normais de temperatura e press�o.

Para explorar esse tipo de falha, primeiro devemos entender a execu��o do c�digo na arquitetura que se pretende atacar, al�m de alguns conceitos espec�ficos do sistema operacional alvo.

