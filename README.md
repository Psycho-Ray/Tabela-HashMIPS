# Tabela-HashMIPS
Uma tabela Hash implementada em Assembly MIPS para a matéria de Organização de Computadores Digitais

### Divisão:

Main/Menu - Bruno

Inserção - Cruz

Remoção - Cyrillo

Busca - Alex

Impressão - Bruno

### Formato da "struct":

(ponteiro anterior, valor , ponteiro posterior) = 32 bytes (end) -- 32 bytes (inteiro) -- 32 bytes (end).

### Informaçes:
Caso o primeiro elemento estiver vazio, terá como valor -1 armazenado nele.

No final da função, deêm um "j menu" (jump para o menu).

Qualquer registrador que forem usar, com exceção dos temporários, terá que primeiro ser empilhado na stack e depois desempilhado.

Para chamar uma função modularizada, tem que chamar com JAL (jump and link) para poder retornar para a sua função.

### Registradores fixos:

$s1 - Input do usuário no menu

$s0 - Endereço do primeiro nó, já apontando pro valor do meio (o valor).

