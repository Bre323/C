#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct arvore{
    char item;
    arvore *esq;
	arvore *dir;
};

arvore *Raiz;
int contador;

void arvore_Construtor(){
    Raiz=NULL;
    contador=0;
}

void arvore_Destrutor(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Destrutor(Raiz->esq);
        arvore_Destrutor(Raiz->dir);
        free(Raiz);
        Raiz=NULL;
    }
}

bool arvore_Vazia(){
    return Raiz==NULL;
}

int arvore_Tamanho(){
    return contador;
}

bool arvore_Inserir(char letra, arvore *&Raiz){
    if(Raiz==NULL){
        if((Raiz=(arvore *) malloc(sizeof(arvore)))==NULL)
            return false;
        else{
            Raiz->item=letra;
            Raiz->esq=Raiz->dir=NULL;
            contador++;
            return true;
        }
    }
    else{
        if(letra<Raiz->item)
            return arvore_Inserir(letra,Raiz->esq);
        else{
            if(letra>Raiz->item)
                return arvore_Inserir(letra,Raiz->dir);
            else
                return false;//letra já existe na árvore
        }
    }
}

//percorre a árvore em ordem
void arvore_Busca_em_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_em_Ordem(Raiz->esq);
        cout << Raiz->item << "  ";
        arvore_Busca_em_Ordem(Raiz->dir);
    }
}

//percorre a árvore na pre-ordem
void arvore_Busca_pre_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        cout << Raiz->item << "  ";
        arvore_Busca_pre_Ordem(Raiz->esq);
        arvore_Busca_pre_Ordem(Raiz->dir);
    }
}

//percorre a árvore na pos-ordem
void arvore_Busca_pos_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_pos_Ordem(Raiz->esq);
        arvore_Busca_pos_Ordem(Raiz->dir);
        cout << Raiz->item << "  ";
    }
}

int main(){
    char x,opcao;

    arvore_Construtor();

    do{
        cout << "\nDigite a letra a ser inserida: ";
        cin >> x;

        arvore_Inserir(x,Raiz);

        cout << "\nDeseja inserir mais elementos? (sim (s) / nao (n)):  ";
        cin >> opcao;
        
        
    }while ((opcao) !='n');

//  tamanho da árvore
    cout << "\nQuantidade de elementos na arvore: " << contador << endl;

//   impressão em ordem
    cout << "\nArvore ordenada:\n";
    arvore_Busca_em_Ordem(Raiz);
    cout << "\n\n";

//  impressão em pré-ordem
    cout << "Arvore preordenada:\n";
    arvore_Busca_pre_Ordem(Raiz);
    cout << "\n\n";

//  impressão em pós-ordem
    cout << "Arvore posordenada:\n";
    arvore_Busca_pos_Ordem(Raiz);
    cout << "\n\n";

//  liberando a memoria alocada
    arvore_Destrutor(Raiz);

    return 0;
}
