/*Tarefa Hash Generica TPA */
/*Italo Lourenço*/

#include <stdlib.h>
#include <stdio.h>

/*Definindo a estrutura da hash*/

typedef struct Hash {
	
	int tamanho;
	void **tabela;
}hash;

/*Criando e inicializando a tabela hash*/

hash *cria_hash(int limite){
	
	//Criando a estrutura hash
	hash *h = (hash*) malloc(sizeof(hash)); 
	
	//Definindo suas variaveis
	h->tamanho = limite;
	h->tabela = (void **) malloc(sizeof(void*)*limite);
	
	//Inicializando cada ponteiro da estrutua
	for(int i = 0; i < limite; i++) h->tabela[i] = NULL;
	
	return h;
}

/* Função Hash */

int funcao_hash(hash *h, int chave){
	
	//Como verificar o tipo de um ponteiro/variavel em c?
	printf("%d", chave);
	return (chave * 7) % h->tamanho;
	
}

void insert_hash(hash *h, int chave){
	
	int chave_insert = funcao_hash(h,chave);
	
	//Verificando e tratando colisoes
	printf("CHAVE = %d", chave_insert);
	printf("\n");
	
	if(h->tabela[chave_insert] != NULL) printf("Colisao na chave %d\n", chave);
	else
	{
		h->tabela[chave_insert] = malloc(sizeof(chave));
		h->tabela[chave_insert] = (void *)chave;
		
		printf("Inserindo a chave %d \n", chave);
	}
	
}

void free_hash(hash *h){
	
	int i;
	for(i = 0; i < h->tamanho; i++) if(h->tabela[i] != NULL) free(h->tabela[i]);
	
	free(h->tabela);
	
}

int main(){
	
	hash *h_1;
	
	int vet[] = {0, 2, 4, 5, 6, 7};
	
	h_1 = cria_hash(7); // Verificar se exsite função para ver o tamanho de um vet
	
	for(int i = 0; i < 6; i++){	
		insert_hash(h_1, vet[i]);
		
	};
	
	free_hash(h_1);
	free(h_1);
	return 0;
}





