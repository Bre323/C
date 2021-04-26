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
typedef struct Node no; //Com o typedef, define-se struct Node como sendo uma variavel "no"

int tam; //tam = tamanho da lista


//Declarando as funções que serão utilizadas no programa

int menu(void);
void alternativa(no *fila, int alt);
void iniciar(no *fila);
int filavazia(no *fila);
no *aloca();
void enqueue(no *fila);
no *dequeue(no *fila);
void exibir(no *fila);
void liberar(no *fila);



/*
A função "main" será responsavel por checar se há espaço
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele irá iniciar a fila para o usuario,
a variavel "altern" será a alternativa que será selecionada pelo usuario
*/

int main(void)
{
	no *fila = (no *) malloc(sizeof(no));
	if(!fila){
		cout << "Memoria indisponivel!!" << endl;
		exit(1);
	}else{
	iniciar(fila);
	int altern;

	do{
		altern=menu();
		alternativa(fila,altern);
	}while(altern);

	free(fila);
	return 0;
	}
}



/*
A função menu vai mosatrar o menu inicial para o usuario e terá varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas irá ser retornado o valor da variavel "altern" que é o valor 
selecionado que corresponde a uma das alternativas mostradas no menu inicial e depois de selecionado a 
alternativa é retornado o valor de "altern"
*/

int menu(void)
{
	int altern;

	cout << "Escolha uma das alternativas" << endl;
	cout << "0. Sair" << endl;
	cout << "1. Zerar fila" << endl;
	cout << "2. Exibir fila" << endl;
	cout << "3. Adicionar um elemento na fila (QUEUE)" << endl;
	cout << "4. Retirar um elemento na (DEQUEUE)" << endl;
	cout << "\nAlternativa: ";
	cin >> altern;

	return altern;
}



/*
A função "alternativa" irá pegar a variavel "alt", que e o valor escolhido pelo usuario
para uma das alternativas, e escolherá as funções que serão utilizadas caso seja escolhida a
respectiva alternativa.

A variavel "alt" armazena o mesmo valor da variavel "altern", porém so será usada na escolha das alternativas do 
usuario dentro da função "alternativa", diferentemente da variavel "altern" que será usado em varias outras funções
e trabalhando com finalidades diferentes dependendo da função que é utilizado
*/

void alternativa(no *fila, int alt)
{
	no *tmp;
	switch(alt){
		case 0:
			liberar(fila);
			system("cls");
			break;

		case 1:
			liberar(fila);
			iniciar(fila);
			system("cls");
			break;

		case 2:
			exibir(fila);
			getch();
			system("cls");
			break;

		case 3:
			enqueue(fila);
			system("cls");
			break;

		case 4:
			tmp= dequeue(fila);
			if(tmp != NULL){
				cout << "Retirado: " <<  tmp->num << endl;
			}
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
A função "iniciar" é a função que se responsabilizará de preparar a fila inicial, que começará vazia (tam = 0),
além da fila inicial conter apenas um elemento com o valor de NULL
*/

void iniciar(no *fila)
{
	fila->prox = NULL;
	tam=0;
}



/*
A função "filavazia" é responsavel apenas por ver se a fila esta vazia
Se a fila for NULL a função irá considerar a fila como sendo vazia,
caso contrario a fila possui elemento dentro dela
*/

int filavazia(no *fila)
{
	if(fila->prox == NULL)
		return 1;
	else
		return 0;
}



/*
A função aloca é encarregado de reservar espaço na memoria 
através da alocação dinamica de memória para o novo elemento que será definido pelo usuário

Essa função será usada nas funções que irão colocar dentro da fila os elementos que serão
definidos pelo usuário
*/

no *aloca()
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		cout << "Memoria indisponivel!" << endl;
		exit(1);
	}else{
		cout << "Digite o elemento a ser adicionado: ";
		cin >> novo->num;
		return novo;
	}
}



/*
A função "liberar" é responsavel pela liberação da memoria que é 
ocupada pelo elemento. Será utilizado para a remoção dos elementos
que se encontram dentro da fila.
*/

void liberar(no *fila)
{
	if(!filavazia(fila)){
		no *proxNode,
			  *atual;

		atual = fila->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}



/*
A função "enqueue" cuidará da inserção de elementos definidos pelo
usuário no fim da fila. É usado a função aloca para reservar a memoria para
o novo elemento que será definido pelo usuario

tmp será utilizado para definir um elemento apontando para outro
e buscará sempre pelo NULL, ou seja, enquanto o elemento não for NULL, o elemento 
definido pelo usuario irá sempre apontar para o proximo. Alem disso,
a fila sofre um acrescimo no valor de tam, que indica o tamanho
*/

void enqueue(no *fila)
{
	no *novo=aloca();
	novo->prox = NULL;

	if(filavazia(fila))
		fila->prox=novo;
	else{
		no *tmp = fila->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	tam++;
}



/*
"dequeue" vai ser a função de remoção de elementos da fila,
com isso a variavel "tam" terá o seu valor reduzido, o 
que representa a redução da fila

Caso a fila ja estiver vazia, ou seja, contendo apenas NULL, será 
mostrado uma mensagem ao usuario dizendo que a fila ja esta vazia
*/

no *dequeue(no *fila)
{
	if(fila->prox == NULL){
		cout << "Fila ja esta vazia" << endl;
		return NULL;
	}else{
		no *tmp = fila->prox;
		fila->prox = tmp->prox;
		tam--;
		return tmp;
	}

}



/*
A função "exibir" irá mostrar a fila ao usuario, se não tiver elementos
o programa irá considerar a fila como vazia.

Caso houver elementos então a função irá mostrar os elementos que 
fazem parte da fila e em suas respectivas posições
*/

void exibir(no *fila)
{
	if(filavazia(fila)){
		cout << "Fila vazia!\n\n";
		return ;
	}

	no *tmp;
	tmp = fila->prox;
	cout << "Fila :";
	while( tmp != NULL){
		cout << "    " << tmp->num;
		tmp = tmp->prox;
}

	cout << "\n\n";
}

