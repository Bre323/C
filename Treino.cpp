#include<iostream>
#include<locale.h>

using namespace std;

int calculo(){
	setlocale(LC_ALL, "Portuguese");
	cout << "O resultado de um calculo aleatorio � igual a " << 5+6+8+1+2 << endl;
}

int mensagem(){
	setlocale(LC_ALL, "Portuguese");
	cout << "Essa � uma mensagem aleatoria em um programa de C++" << endl;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	calculo();
	mensagem();
	cout << "Programa��o conclu�da!!!" << endl;
	cin.get();
	return 0;
}

