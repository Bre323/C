#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

/*
Inicialmente é declarado um struct contendo uma variavel
e um ponteiro que irá apontar para o proximo elemento da lista
*/

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node no;  //Com o typedef, define-se struct Node como sendo uma variavel "no"

int tam;  //tam = tamanho da lista


//Declarando as funções que serão utilizadas no programa

void inicia(no *lista);
int menu(void);
void opcao(no *lista, int op);
no *criaNo();
void insereFim(no *lista);
void insereInicio(no *lista);
void exibe(no *lista);
void libera(no *lista);
void insere (no *lista);
no *retiraInicio(no *lista);
no *retiraFim(no *lista);
no *retira(no *lista);



/*
A função main será responsavel por checar se há espaço
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele irá iniciar a lista para o usuario,
a variavel opt será a alternativa que será selecionada pelo usuario
*/

int main()
{
	no *lista = (no *) malloc(sizeof(no));
	if(!lista){
		cout << "Sem memoria disponivel!\n" << endl;
		exit(1);
	}else{
	inicia(lista);
	int opt;
	
	do{
		opt=menu();
		opcao(lista,opt);
	}while(opt);

	free(lista);
	return 0;
	}
}



/*
A função inicia é a função que se responsabilizará de preparar a lista inicial, que começará vazia (tam = 0),
além da lista inicial conter apenas um elemento com o valor de NULL
*/

void inicia(no *lista)
{
	lista->prox = NULL;
	tam=0;
}



/*
A função menu vai mosatrar o menu inicial para o usuario e terá varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas irá ser retornado o valor de opt que é o valor selecionado que corresponde 
a uma das alternativas mostradas no menu inicial
*/

int menu()
{
	int opt;
	
	cout << "Escolha uma das alternativas" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Zerar lista" << endl;
	cout << "2. Exibir lista" << endl;
	cout << "3. Adicionar node no inicio" << endl;
	cout << "4. Adicionar node no final" << endl;
	cout << "5. Escolher onde inserir" << endl;
	cout << "6. Retirar do inicio" << endl;
	cout << "7. Retirar do fim" << endl;
	cout << "8. Escolher de onde tirar" << endl;
	cout << "\nAlternativa: " << endl;
	cin >> opt;
	
	return opt;
}



/*
A função opcao irá pegar a variavel op, que e o valor escolhido pelo usuario
para uma das alternativas, e escolherá as funções a serem usadas caso seja escolhida a
respectiva alternativa.

A variavel op armazena o mesmo valor da variavel opt, porém so será usada na escolha das alternativas do 
usuario dentro da função opcoo, diferentemente da variavel opt que será usado em varias outras funções
e trabalhando com finalidades diferentes dependendo da função 
*/

void opcao(no *lista, int op)
{
	no *tmp;
	switch(op){
		case 0:
			libera(lista);
			system("cls");
			break;
			
		case 1:
			libera(lista);
			inicia(lista);
			system("cls");
			break;
		
		case 2:
			exibe(lista);
			getch();
			system("cls");
			break;
		
		case 3:
			insereInicio(lista);
			system("cls");
			break;		
			
		case 4:
			insereFim(lista);
			system("cls");
			break;
			
		case 5:
			insere(lista);
			system("cls");
			break;
		
		case 6:
			tmp= retiraInicio(lista);
			cout << "Retirado: " << tmp->num << endl;
			getch();
			system("cls");
			break;
			
		case 7:
			tmp= retiraFim(lista);
			cout << "Retirado: " << tmp->num << endl;
			getch();
			system("cls");
			break;
		
		case 8:
			tmp= retira(lista);
			cout << "Retirado: " << tmp->num << endl;
			getch();
			system("cls");
			break;
		
		default:
			cout << "Comando invalido\n\n";
			getch();
			system("cls");
	}
}



/*
A função vazia é responsavel apenas por verificar se a lista esta vazia
Se a lista for NULL a função irá considerar a lista como sendo vazia,
caso contrario a lista possui elemento dentro dela
*/

int vazia(no *lista)
{
	if(lista->prox == NULL)
		return 1;
	else
		return 0;
}



/*
A função aloca é encarregado de reservar espaço na memoria 
através da alocação dinamica de memória para o novo elemento que será definido pelo usuário

Essa função será usada nas funções que irão inserir na lista os elementos que serão
definidos pelo usuário
*/

no *aloca()
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		cout << "Sem memoria disponivel!" << endl;
		exit(1);
	}else{
		cout << "Novo elemento: ";
		cin >> novo->num;
		return novo;
	}
}



/*
inserefim é a função que cuidará da inserção de elementos definidos pelo
usuário no fim da lista

Inicialmente é usado a função aloca para reservar a memoria para
o novo elemento que será definido pelo usuario

tmp será utilizado para definir um elemento apontando para outro
e buscará sempre pelo ultimo elemento da lista que será NULL, ou seja,
enquanto o elemento que aponta para o proximo não for NULL, o elemento 
definido pelo usuario irá sempre apontar para o proximo. Alem disso,
a lista sofre um acrescimo no valor de tam, que indica o tamanho da lista
*/

void insereFim(no *lista)
{
	no *novo=aloca();
	novo->prox = NULL;
	
	if(vazia(lista))
		lista->prox=novo;
	else{
		no *tmp = lista->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	tam++;
}



/*
insereinicio irá inserir elementos definidos pelo usuario no 
inicio da lista.

Com a remoção do elemento do inicio da lista, a cabeça da 
lista sofre alterações, e passará a ser composta pelo elemento
que não era apontado por ninguem
*/

void insereInicio(no *lista)
{
	no *novo=aloca();	
	no *oldHead = lista->prox;
	
	lista->prox = novo;
	novo->prox = oldHead;
	
	tam++;
}



/*
A função exibe irá mostrar a lista ao usuario, se não tiver elementos
o programa irá considerar a lista como vazia.

Caso houver elementos então a função irá mostrar os elementos que 
fazem parte da lista nas suas respectivas posições
*/

void exibe(no *lista)
{
	if(vazia(lista)){
		cout << "Lista vazia!\n\n";
		return ;
	}
	
	no *tmp;
	tmp = lista->prox;
	cout << "Lista:";
	while( tmp != NULL){
		cout << "    " << tmp->num;
		tmp = tmp->prox;
	}
	
}



/*
A função libera é responsavel pela liberação da memoria que é 
ocupada pelo elemento.

Será utilizado para a remoção dos elementos na lista
*/

void libera(no *lista)
{
	if(!vazia(lista)){
		no *proxNode,
			  *atual;
		
		atual = lista->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}




/*
A função insere irá adicionar elementos em qualquer posição que o usuario
deseja dentro da lista, porém, se a posição escolhida for 1 é usado a função insereinicio
que vai colocar o elemento no inicio da lista. Se a posição for outra, a função insere
irá colocar o elemento na respectiva posição que foi definida.
*/

void insere(no *lista)
{
	int pos,
		count;
	cout << "Em que posicao, [de 1 ate " << tam << "] voce deseja inserir: ";
	cin >> pos;
	
	if(pos>0 && pos <= tam){
		if(pos==1)
			insereInicio(lista);
		else{
			no *atual = lista->prox,
				 *anterior=lista; 
			no *novo=aloca();
				 
			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			anterior->prox=novo;
			novo->prox = atual;
			tam++;
		}
			
	}else
		cout << "Elemento invalido\n\n";		
}




/*
retirainicio vai ser a função de remoção de elementos no inicio da lista
com isso a variavel tam (tamanho da lista) terá o seu valor reduzido, o 
que representa a redução da lista

Caso a lista ja estiver vazia, ou seja, contendo apenas NULL, será 
mostrado uma mensagem ao usuario dizendo que a lista ja esta vazia
*/

no *retiraInicio(no *lista)
{
	if(lista->prox == NULL){
		cout << "Lista ja esta vazia" << endl;
		return NULL;
	}
	else{
		no *tmp = lista->prox;
		lista->prox = tmp->prox;
		tam--;
		return tmp;
	}
				
}



/*
A função retirafim é a função que irá fazer a remoção de elementos no fim da lista,
e o elemento que apontava para NULL passará a ser o elemento anterior e se não houver 
nenhum elemento anterior ao removido indica que a lista so continha aquele elemento,
ou seja, a lista ficará vazia depois da remoção
*/

no *retiraFim(no *lista)
{
	if(lista->prox == NULL){
		cout << "Lista ja vazia\n" << endl;
		return NULL;
	}else{
		no *ultimo = lista->prox,
			 *penultimo = lista;
			 
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
			 
		penultimo->prox = NULL;
		tam--;
		return ultimo;		
	}
}




/*
A função retira será responsavel pela remoção de elementos em qualquer posição
indicada pelo usuario

Para ler a posição definida pelo usuario é utilizado novamente a variavel opt
e caso essa variavel tenha o valor de 1, é utilizado a função retirainicio para 
a remoção do primeiro elemento da lista

Caso a posição determinada não estiver conforme os requisitos
(0 < opt <= tam) será passado a mensagem de elemento invalido
*/

no *retira(no *lista)
{
	int opt,
		count;
	cout << "Que posicao, [de 1 ate " << tam << "] voce deseja retirar: ";
	cin >> opt;
	
	if(opt>0 && opt <= tam){
		if(opt==1)
			return retiraInicio(lista);
		else{
			no *atual = lista->prox,
				 *anterior=lista; 
				 
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tam--;
		return atual;
		}
			
	}else{
		cout << "Elemento invalido\n" << endl;
		return NULL;
	}
}

