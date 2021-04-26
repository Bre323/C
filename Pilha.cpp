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
void iniciar(no *pilha);
void alternativa(no *pilha, int alt);
void exibir(no *pilha);
void liberar(no *pilha);
void push(no *pilha);
no *pop(no *pilha);




/*
A fun��o "main" ser� responsavel por checar se h� espa�o
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele ir� iniciar a pilha para o usuario,
a variavel "altern" ser� a alternativa que ser� selecionada pelo usuario
*/

int main(void)
{
 no *pilha = (no *) malloc(sizeof(no));
 if(!pilha){
  cout << "Sem memoria disponivel!" << endl;
  exit(1);
 }else{
 iniciar(pilha);
 int altern;


 do{
  altern=menu();
  alternativa(pilha,altern);
 }while(altern);


free(pilha);
return 0;
 }
}



/*
A fun��o iniciar � a fun��o que ser� respons�vel por preparar a pilha inicial, que come�ar� vazia (tam = 0),
al�m de conter na pilha inicial um unico elemento com o valor de NULL
*/

void iniciar(no *pilha)
{
 pilha->prox = NULL;
 tam=0;
}



/*
A fun��o menu vai mosatrar o menu inicial para o usuario e ter� varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas ir� ser retornado o valor da variavel "altern" que � o valor 
selecionado que corresponde a uma das alternativas mostradas no menu inicial e depois de selecionado a 
alternativa � retornado o valor de altern
*/

int menu(void)
{
 int altern;

 cout << "Escolha uma das alternativas" << endl;
 cout << "0. Sair" << endl;
 cout << "1. Zerar PILHA" << endl;
 cout << "2. Exibir PILHA" << endl;
 cout << "3. inserir um elemento (PUSH)" << endl;
 cout << "4. retirar um elemento (POP)" << endl;
 cout << "Alternativa: ";
 
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

void alternativa(no *pilha, int alt)
{
 no *tmp;
 switch(alt){
  case 0:
   liberar(pilha);
   break;

  case 1:
   liberar(pilha);
   iniciar(pilha);
   system("cls");
   break;

  case 2:
   exibir(pilha);
   getch();
   system("cls");
   break;

  case 3:
   push(pilha);
   system("cls");
   break;

  case 4:
   tmp= pop(pilha);
   if(tmp != NULL)
   cout << "\n\nRetirado: " << tmp->num << endl;
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
A fun��o "pilhavazia" � responsavel apenas por ver se a pilha esta vazia
Se a pilha for NULL a fun��o ir� considerar a pilha como sendo vazia,
caso contrario a pilha possui elemento dentro dela
*/

int pilhavazia(no *pilha)
{
 if(pilha->prox == NULL)
  return 1;
 else
  return 0;
}



/*
A fun��o aloca � encarregado de reservar espa�o na memoria 
atrav�s da aloca��o dinamica de mem�ria para o novo elemento que ser� definido pelo usu�rio

Essa fun��o ser� usada nas fun��es que ir�o colocar dentro da pilha os elementos que ser�o
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
A fun��o "exibir" ir� mostrar a pilha ao usuario, se n�o tiver elementos
o programa ir� considerar a pilha como vazia.

Caso houver elementos ent�o a fun��o ir� mostrar os elementos que 
fazem parte da pilha e em suas respectivas posi��es
*/

void exibir(no *pilha)
{
 if(pilhavazia(pilha)){
  cout << "pilha vazia!\n\n";
  return ;
 }


 no *tmp;
 tmp = pilha->prox;
 cout << "pilha:";
 while( tmp != NULL){
  cout << "    " << tmp->num;
  tmp = tmp->prox;
}

 cout << "\n\n";
}



/*
A fun��o "liberar" � responsavel pela libera��o da memoria que � 
ocupada pelo elemento.

Ser� utilizado para a remo��o dos elementos que est�o 
contidos dentro da pilha.
*/

void liberar(no *pilha)
{
 if(!pilhavazia(pilha)){
  no *proxNode,
     *atual;

  atual = pilha->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}


/*
A fun��o "push" cuidar� da inser��o de elementos definidos pelo
usu�rio em uma pilha, que sao colocados no final. Inicialmente � usado
a fun��o aloca para reservar a memoria para o novo elemento que ser� definido pelo usuario

tmp ser� utilizado para definir um elemento apontando para outro
e buscar� sempre pelo NULL da pilha, ou seja, enquanto o elemento que aponta
para o proximo n�o for NULL, o elemento definido pelo usuario ir� sempre apontar
para o proximo. Alem disso, a pilha sofre um acrescimo no valor de tam, que indica o tamanho
*/

void push(no *pilha)
{
 no *novo=aloca();
 novo->prox = NULL;


 if(pilhavazia(pilha))
  pilha->prox=novo;
 else{
  no *tmp = pilha->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}



/*
A fun��o "pop" � a fun��o que ir� fazer a remo��o de elementos dentro de uma pilha,
pelo qual � retirado sempre o ultimo elemento que foi inserido na pilha

Caso nao tenha elemento na pilha, � exibido a mensagem de que a lista ja esta vazia
*/

no *pop(no *pilha)
{
 if(pilha->prox == NULL){
  cout << "A pilha ja esta vazia\n\n";
  return NULL;
 }else{
  no *ultimo = pilha->prox,
              *penultimo = pilha;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}
