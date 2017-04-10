#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// operacoes a serem implementadas
#define insercao 0
#define remocao 1
#define busca 2
#define visualizacao 3
#define exit -1

#define maxTam 16
#define VAZIO -1

typedef struct Node {
	struct Node *prox;
	struct Node *ant;
	int element;
} t_node;


typedef t_node* t_lista;


void Busca(t_lista *lista) {
	/*
	TODO: Dúvida: "A operação de busca deve retornar o valor da entrada hash que o elemento buscado se encontra ou -1 caso o elemento não
	foi encontrado." Mas então desconsideramos a sua posicão na lista encadeada dupla?
	Se devemos chamar a função várias vezes, retornamos varios valores? Ou imprimimos eles na tela? */
	int num, pos;
	bool encontrado = false;
	
	printf("Digite o número que deseja buscar\n");
	scanf("%d", &num);
	
	while (num != -1) {
		if (num < 0) { // se nao for um numero valido, voltamos ao menu.
			printf("Esse não é um número válido! Abortando...\n");
			return;
		}
		
		pos = num % maxTam;
		t_node *aux = lista[pos];
		
		while(aux != NULL && aux->element != VAZIO && aux->element <= num) {  // verifica se o numero desejado existe
			if (aux->element == num) {
				printf("Encontrado na posição %d\n", pos);
				encontrado = true;
			}
			aux = aux->prox;
		}
		if (!encontrado) printf("Elemento não encontrado!\n");
	
		printf("Digite o proximo numero que deseja inserir ou -1 para voltar ao menu\n");
		scanf("%d", &num);
	}
}


void InsereElemento(t_lista *lista) {
	/* TODO: Dúvida: Podemos considera que a primeria chave é sempre válida? Se não do while não é uma boa ideia....
	Se não for um inteiro positivo digitado, podemos abortar ou pedimos de novo? */
	int num, pos;
	
	printf("Digite o número que deseja inserir\n");
	scanf("%d", &num);
	
	while (num != -1) {
	
		if (num < 0) { // se nao for um numero valido, voltamos ao menu.
			printf("Esse não é um número válido! Abortando...\n");
			return;
		}
		pos = num % maxTam;
		t_node *aux = lista[pos];	
	
		// encontra a posicao para inserir
		while (aux != NULL && aux->prox != NULL  && aux->prox->element < num) aux = aux->prox;
	
		if (aux->element == VAZIO) // se essa posicao estiver vazia
			aux->element = num;
		
		else if (aux->element > num) {		// caso precisamos inserir como o primeiro elemento 
			t_node *new = calloc(1, sizeof(t_node));
			new->element = num;
			new->prox = aux;
			aux->ant = new;
			lista[pos] = new;
		}
		
		else { 	// qualquer outra posicão
			t_node *next = aux->prox;
		
			t_node *new = calloc(1, sizeof(t_node));  // cria o novo nó
			new->element = num;
			new->prox = next;
			new->ant = aux;
		
			if (next != NULL)
				next->ant = new;
			aux->prox = new;
		}
		printf("Digite o proximo numero que deseja inserir ou -1 para voltar ao menu\n");
		scanf("%d", &num);
	}
}


void Visualizacao(t_lista *lista) {
	int i;
	t_node *aux;
	
	for (i = 0; i < maxTam; i += 1) { // percore as posicoes da Hash
		aux = lista[i];
		if (aux->element != VAZIO)
			while (aux != NULL) { 	// percore a lista duplamente encadeada
				printf("%d ", aux->element);
				aux = aux->prox;
			}
		else
			printf("--vazio--");
		printf("\n");
	}
}


void RemoveElemento(t_lista *lista) {
	/*
	TODO: Dúvida: Sempre sera passado um elemento que existe...? Vou considerar que sim por enquanto...
	*/
	int num, pos;
	
	printf("Digite o número que deseja remover\n");
	scanf("%d", &num);
	
	while (num != -1) {
		if (num < 0) { // se nao for um numero valido, voltamos ao menu.
			printf("Esse não é um número válido! Abortando...\n");
			return;
		}
		
		pos = num % maxTam;
		t_node *aux = lista[pos];
		while (aux->element != num)	// encontra a posicao para remover
			aux = aux->prox;
			
		if (aux == lista[pos]) {	// se for o primeiro elemento
			lista[pos] =  aux->prox;
			if (aux->prox != NULL)
				aux->prox->ant = NULL;
		}
		else {
			aux->ant->prox = aux->prox;
			if (aux->prox != NULL)
				aux->prox->ant = aux->ant;
		}	
	
		printf("Digite o proximo numero que deseja inserir ou -1 para voltar ao menu\n");
		scanf("%d", &num);
	}
}


int main (int argc, char *argv[]) {
	int i, opcao;
	
	// Inicializa a struct
	t_lista *lista = calloc(maxTam, sizeof(t_node*));
	for (i = 0; i < maxTam; i += 1) {
		lista[i] = calloc(1, sizeof(t_node));
		lista[i]->element = VAZIO;
	}

	do {
		printf("Digite 0 para insercao, 1 para remocao, 2 para busca, 3 para visualizacao e -1 para sair\n");
		scanf("%d", &opcao);
		
		if (opcao == insercao) 
			InsereElemento(lista);
		else if (opcao == remocao)
			RemoveElemento(lista);
		else if (opcao == busca)
			Busca(lista);
		else if (opcao == visualizacao)
			Visualizacao(lista);
	} while ( opcao != exit);	

	// Não liberei a memoria mas foda-se, é assembly essa porra.
	return 0;
}
