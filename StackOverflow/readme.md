# Sobre ataques que mexem com a pilha

Um StackOverflow é definido pela escrita em uma região não autorizada de memória. Stack overflow, overrun, etc, não interessando a nomenclatura "oficial", o importante aqui é como um bug de acesso à memória pode permitir acesso exclusivo a regiões de memória que não estariam disponíveis para um atacante se não fosse por esse bug.

No exemplo do código deste projeto, um usuário fictício utiliza um código que possui controle de acesso, mas também possui um bug: ele escreve em uma região da memória inadvertidamente. Dessa forma, é possível explorar essa falha no código para escrever um novo endereço de retorno na pilha (stack), ganhando acesso, dessa forma, a código que não estaria disponível em situações normais de temperatura e pressão.

Para explorar esse tipo de falha, primeiro devemos entender a execução do código na arquitetura que se pretende atacar, além de alguns conceitos específicos do sistema operacional alvo.

