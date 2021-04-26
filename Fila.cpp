#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

/*
Inicialmente � declarado um struct contendo uma variavel
e um ponteiro que ir� apontar para o proximo elemento da lista
*/

struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node no; //Com o typedef, define-se struct Node como sendo uma variavel "no"

int tam; //tam = tamanho da lista


//Declarando as fun��es que ser�o utilizadas no programa

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
A fun��o "main" ser� responsavel por checar se h� espa�o
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele ir� iniciar a fila para o usuario,
a variavel "altern" ser� a alternativa que ser� selecionada pelo usuario
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
A fun��o menu vai mosatrar o menu inicial para o usuario e ter� varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas ir� ser retornado o valor da variavel "altern" que � o valor 
selecionado que corresponde a uma das alternativas mostradas no menu inicial e depois de selecionado a 
alternativa � retornado o valor de "altern"
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
A fun��o "alternativa" ir� pegar a variavel "alt", que e o valor escolhido pelo usuario
para uma das alternativas, e escolher� as fun��es que ser�o utilizadas caso seja escolhida a
respectiva alternativa.

A variavel "alt" armazena o mesmo valor da variavel "altern", por�m so ser� usada na escolha das alternativas do 
usuario dentro da fun��o "alternativa", diferentemente da variavel "altern" que ser� usado em varias outras fun��es
e trabalhando com finalidades diferentes dependendo da fun��o que � utilizado
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
A fun��o "iniciar" � a fun��o que se responsabilizar� de preparar a fila inicial, que come�ar� vazia (tam = 0),
al�m da fila inicial conter apenas um elemento com o valor de NULL
*/

void iniciar(no *fila)
{
	fila->prox = NULL;
	tam=0;
}



/*
A fun��o "filavazia" � responsavel apenas por ver se a fila esta vazia
Se a fila for NULL a fun��o ir� considerar a fila como sendo vazia,
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
A fun��o aloca � encarregado de reservar espa�o na memoria 
atrav�s da aloca��o dinamica de mem�ria para o novo elemento que ser� definido pelo usu�rio

Essa fun��o ser� usada nas fun��es que ir�o colocar dentro da fila os elementos que ser�o
definidos pelo usu�rio
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
A fun��o "liberar" � responsavel pela libera��o da memoria que � 
ocupada pelo elemento. Ser� utilizado para a remo��o dos elementos
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
A fun��o "enqueue" cuidar� da inser��o de elementos definidos pelo
usu�rio no fim da fila. � usado a fun��o aloca para reservar a memoria para
o novo elemento que ser� definido pelo usuario

tmp ser� utilizado para definir um elemento apontando para outro
e buscar� sempre pelo NULL, ou seja, enquanto o elemento n�o for NULL, o elemento 
definido pelo usuario ir� sempre apontar para o proximo. Alem disso,
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
"dequeue" vai ser a fun��o de remo��o de elementos da fila,
com isso a variavel "tam" ter� o seu valor reduzido, o 
que representa a redu��o da fila

Caso a fila ja estiver vazia, ou seja, contendo apenas NULL, ser� 
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
A fun��o "exibir" ir� mostrar a fila ao usuario, se n�o tiver elementos
o programa ir� considerar a fila como vazia.

Caso houver elementos ent�o a fun��o ir� mostrar os elementos que 
fazem parte da fila e em suas respectivas posi��es
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

