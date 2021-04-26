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
typedef struct Node no;  //Com o typedef, define-se struct Node como sendo uma variavel "no"

int tam;  //tam = tamanho da lista


//Declarando as fun��es que ser�o utilizadas no programa

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
A fun��o main ser� responsavel por checar se h� espa�o
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele ir� iniciar a lista para o usuario,
a variavel opt ser� a alternativa que ser� selecionada pelo usuario
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
A fun��o inicia � a fun��o que se responsabilizar� de preparar a lista inicial, que come�ar� vazia (tam = 0),
al�m da lista inicial conter apenas um elemento com o valor de NULL
*/

void inicia(no *lista)
{
	lista->prox = NULL;
	tam=0;
}



/*
A fun��o menu vai mosatrar o menu inicial para o usuario e ter� varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas ir� ser retornado o valor de opt que � o valor selecionado que corresponde 
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
A fun��o opcao ir� pegar a variavel op, que e o valor escolhido pelo usuario
para uma das alternativas, e escolher� as fun��es a serem usadas caso seja escolhida a
respectiva alternativa.

A variavel op armazena o mesmo valor da variavel opt, por�m so ser� usada na escolha das alternativas do 
usuario dentro da fun��o opcoo, diferentemente da variavel opt que ser� usado em varias outras fun��es
e trabalhando com finalidades diferentes dependendo da fun��o 
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
A fun��o vazia � responsavel apenas por verificar se a lista esta vazia
Se a lista for NULL a fun��o ir� considerar a lista como sendo vazia,
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
A fun��o aloca � encarregado de reservar espa�o na memoria 
atrav�s da aloca��o dinamica de mem�ria para o novo elemento que ser� definido pelo usu�rio

Essa fun��o ser� usada nas fun��es que ir�o inserir na lista os elementos que ser�o
definidos pelo usu�rio
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
inserefim � a fun��o que cuidar� da inser��o de elementos definidos pelo
usu�rio no fim da lista

Inicialmente � usado a fun��o aloca para reservar a memoria para
o novo elemento que ser� definido pelo usuario

tmp ser� utilizado para definir um elemento apontando para outro
e buscar� sempre pelo ultimo elemento da lista que ser� NULL, ou seja,
enquanto o elemento que aponta para o proximo n�o for NULL, o elemento 
definido pelo usuario ir� sempre apontar para o proximo. Alem disso,
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
insereinicio ir� inserir elementos definidos pelo usuario no 
inicio da lista.

Com a remo��o do elemento do inicio da lista, a cabe�a da 
lista sofre altera��es, e passar� a ser composta pelo elemento
que n�o era apontado por ninguem
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
A fun��o exibe ir� mostrar a lista ao usuario, se n�o tiver elementos
o programa ir� considerar a lista como vazia.

Caso houver elementos ent�o a fun��o ir� mostrar os elementos que 
fazem parte da lista nas suas respectivas posi��es
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
A fun��o libera � responsavel pela libera��o da memoria que � 
ocupada pelo elemento.

Ser� utilizado para a remo��o dos elementos na lista
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
A fun��o insere ir� adicionar elementos em qualquer posi��o que o usuario
deseja dentro da lista, por�m, se a posi��o escolhida for 1 � usado a fun��o insereinicio
que vai colocar o elemento no inicio da lista. Se a posi��o for outra, a fun��o insere
ir� colocar o elemento na respectiva posi��o que foi definida.
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
retirainicio vai ser a fun��o de remo��o de elementos no inicio da lista
com isso a variavel tam (tamanho da lista) ter� o seu valor reduzido, o 
que representa a redu��o da lista

Caso a lista ja estiver vazia, ou seja, contendo apenas NULL, ser� 
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
A fun��o retirafim � a fun��o que ir� fazer a remo��o de elementos no fim da lista,
e o elemento que apontava para NULL passar� a ser o elemento anterior e se n�o houver 
nenhum elemento anterior ao removido indica que a lista so continha aquele elemento,
ou seja, a lista ficar� vazia depois da remo��o
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
A fun��o retira ser� responsavel pela remo��o de elementos em qualquer posi��o
indicada pelo usuario

Para ler a posi��o definida pelo usuario � utilizado novamente a variavel opt
e caso essa variavel tenha o valor de 1, � utilizado a fun��o retirainicio para 
a remo��o do primeiro elemento da lista

Caso a posi��o determinada n�o estiver conforme os requisitos
(0 < opt <= tam) ser� passado a mensagem de elemento invalido
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

