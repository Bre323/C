#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

/*
Inicialmente é declarado um struct contendo uma variavel
e um ponteiro que irá apontar para o proximo elemento da lista
*/

struct noLista{ 
        
       char valor;
        
       struct noLista *anterior;
	   struct noLista *proximo;
 
};
 
typedef struct noLista NOLISTA; 
typedef NOLISTA *NOLISTAPTR;


 
/* 
Função responsavel pela inserção de um no no inicio
da lista duplamente
*/

void insere_no_inicio(NOLISTAPTR *inicio, char valor){
      
     NOLISTAPTR novo;
      
     novo = (NOLISTAPTR) malloc(sizeof(NOLISTA)); 
      
     if(novo == NULL) 
         return;      
      
     if(*inicio == NULL){         
         novo->valor = valor;     
         novo->proximo = novo->anterior = NULL; 
         *inicio = novo; 
     }
     
     else{   
         novo->valor = valor; 
         novo->anterior = NULL; 
         novo->proximo = *inicio; 
         (*inicio)->anterior = novo; 
         *inicio = novo; 
     }
}

 
/*
Função que coloca os elementos no final da lista
duplamente encadeada
*/

void insere_no_final(NOLISTAPTR *inicio, char valor){
      
     NOLISTAPTR novo, atual;
      
     novo = (NOLISTA*)malloc(sizeof(NOLISTA));
      
     if(novo == NULL)
         return;
      
     if(*inicio == NULL){
         novo->valor = valor;
         novo->proximo = novo->anterior = NULL;
         *inicio = novo;
     }
     else{
         atual = *inicio; 
         while(atual->proximo != NULL) 
             atual = atual->proximo;    
          
         novo->valor = valor;
         novo->anterior = atual;  
         novo->proximo = NULL; 
         atual->proximo = novo; 
     }
}  


 
/*
A função retira remove o elemento da lista que é escolhido
pelo usuario para compor a lista 
*/

int retira(NOLISTAPTR *inicio, char valor){
     
    NOLISTAPTR temporario, atual;
     
    if(*inicio == NULL)
        return 0; 
     
    atual = *inicio; 
     
    if((*inicio)->valor == valor) 
        *inicio = (*inicio)->proximo;
     
    while(atual != NULL && atual->valor != valor) 
        atual = atual->proximo; 
     
    if(atual == NULL)
        return 0; 
        
    else{
        temporario = atual; 
         
        if(atual->anterior != NULL)
            atual->anterior->proximo = atual->proximo; 
         
        if(atual->proximo != NULL) 
            atual->proximo->anterior = atual->anterior; 
         
        free(temporario);
    }
     
    return 1;
}


 
/*
A função eliminano se encarrega de eliminar os elementos que
são escolhidos pelo usuario para não fazer parte da lista
*/

char elimina_no(NOLISTAPTR *inicio){
     
    NOLISTAPTR temporario;
    char c;     

    temporario = *inicio; 
    c = (*inicio)->valor; 
    *inicio = (*inicio)->proximo; 
    free(temporario); 
     
    return c;
}
 
int esta_vazia(NOLISTAPTR lista){
     
    return lista == NULL;
     
}
 
void imprime_lista_ordem_direta(NOLISTAPTR lista){
      
     if(esta_vazia(lista))
         cout << "\n\nA lista esta vazia.\n\n";
     else{
         cout << "\nLista na ordem direta:\n\n";
         while(lista != NULL){
             cout << "  " << lista->valor;
             lista = lista->proximo;
         }
     }
}
 
void imprime_lista_ordem_inversa(NOLISTAPTR lista){
      
     if(esta_vazia(lista))
         cout << "\n\nA lista esta vazia.\n\n";
     else{
         while(lista->proximo != NULL) 
             lista = lista->proximo;   
              
         cout << "\nLista na ordem invertida:\n\n";
         while(lista != NULL){
             cout << "  " << lista->valor;
             lista = lista->anterior;
         }
          
     }
}
 
void menu(){
      
     cout << "Alternativas\n\n";
     cout << "1. Inserir um elemento no inicio da lista" << endl;
     cout << "2. Inserir um elemento no final da lista" << endl;
     cout << "3. Remover um elemento da lista" << endl;
     cout << "4. Imprimir a lista na ordem direta" << endl;
     cout << "5. Imprimir a lista na ordem inversa" << endl;
     cout << "0. sair\n\n";
      
}
 
int main(){
     
    NOLISTAPTR lista = NULL;
    int opcao;
    char valor;
     
    menu();
    cout << "Escolha uma das opcoes: ";
    cin >> opcao;
     
    while(opcao != 0){
         
        switch(opcao){
             
            case 1:
                 cout << "\nDigite um caracetere: ";
                 cin >> valor;
                 insere_no_inicio(&lista, valor);
                 system("cls");
                 break;
             
            case 2:
                 cout << "\nDigite um caracetere: ";
                 cin >> valor;
                 insere_no_final(&lista, valor);
                 system("cls");
                 break;
             
            case 3:
                 cout << "\nDigite o valor a ser retirado: ";
                 cin >> valor;
                 if(! retira(&lista, valor)){
                     cout << "\nNo inexistente!\n\n";
                     getch();
                 }
                 system("cls");
                 break;
             
            case 4:
                 imprime_lista_ordem_direta(lista);
                 getch();
                 system("cls");
                 break;
             
            case 5:
                 imprime_lista_ordem_inversa(lista);
                 getch();
                 system("cls");
                 break;
             
            default:
                 cout << "\nOpcao invalida!!!\n\n";
                 getch();
                 system("cls");
                 break;
        }
        menu();
        cout << "Selecione uma das alternativas: ";
        cin >> opcao;
    }
    
    return 0;
}

