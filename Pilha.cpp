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
void iniciar(no *pilha);
void alternativa(no *pilha, int alt);
void exibir(no *pilha);
void liberar(no *pilha);
void push(no *pilha);
no *pop(no *pilha);




/*
A função "main" será responsavel por checar se há espaço
na memoria do computador para ser reservada para o programa,
se tiver memoria disponivel ele irá iniciar a pilha para o usuario,
a variavel "altern" será a alternativa que será selecionada pelo usuario
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
A função iniciar é a função que será responsável por preparar a pilha inicial, que começará vazia (tam = 0),
além de conter na pilha inicial um unico elemento com o valor de NULL
*/

void iniciar(no *pilha)
{
 pilha->prox = NULL;
 tam=0;
}



/*
A função menu vai mosatrar o menu inicial para o usuario e terá varias alternativas para serem selecionadas,
caso o usuario selecione uma das alternativas irá ser retornado o valor da variavel "altern" que é o valor 
selecionado que corresponde a uma das alternativas mostradas no menu inicial e depois de selecionado a 
alternativa é retornado o valor de altern
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
A função "alternativa" irá pegar a variavel "alt", que e o valor escolhido pelo usuario
para uma das alternativas, e escolherá as funções que serão utilizadas caso seja escolhida a
respectiva alternativa.

A variavel "alt" armazena o mesmo valor da variavel "altern", porém so será usada na escolha das alternativas do 
usuario dentro da função "alternativa", diferentemente da variavel "altern" que será usado em varias outras funções
e trabalhando com finalidades diferentes dependendo da função que é utilizado
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
A função "pilhavazia" é responsavel apenas por ver se a pilha esta vazia
Se a pilha for NULL a função irá considerar a pilha como sendo vazia,
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
A função aloca é encarregado de reservar espaço na memoria 
através da alocação dinamica de memória para o novo elemento que será definido pelo usuário

Essa função será usada nas funções que irão colocar dentro da pilha os elementos que serão
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
A função "exibir" irá mostrar a pilha ao usuario, se não tiver elementos
o programa irá considerar a pilha como vazia.

Caso houver elementos então a função irá mostrar os elementos que 
fazem parte da pilha e em suas respectivas posições
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
A função "liberar" é responsavel pela liberação da memoria que é 
ocupada pelo elemento.

Será utilizado para a remoção dos elementos que estão 
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
A função "push" cuidará da inserção de elementos definidos pelo
usuário em uma pilha, que sao colocados no final. Inicialmente é usado
a função aloca para reservar a memoria para o novo elemento que será definido pelo usuario

tmp será utilizado para definir um elemento apontando para outro
e buscará sempre pelo NULL da pilha, ou seja, enquanto o elemento que aponta
para o proximo não for NULL, o elemento definido pelo usuario irá sempre apontar
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
A função "pop" é a função que irá fazer a remoção de elementos dentro de uma pilha,
pelo qual é retirado sempre o ultimo elemento que foi inserido na pilha

Caso nao tenha elemento na pilha, é exibido a mensagem de que a lista ja esta vazia
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
