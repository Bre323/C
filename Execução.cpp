#include<iostream>
#include<locale.h>
#include "Pessoa.cpp"
#include "Aluno.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	pessoa pes;
	pessoa pe2;
	aluno alu;
	
	pes.getidade(18);
	pes.getnome("Breno");
	cout << "Sua idade: " << pes.exibiridade() << endl;
	cout << "Seu nome: " << pes.exibirnome() << endl;
	
	alu.getmatricula(342343);
	alu.getano(1997);
	alu.getrg(284824);
	cout << "Sua matrícula: " << alu.exibirmatricula() << endl;
	cout << "Seu ano de nascimento " << alu.exibirano() << endl;
	cout << "Seu registro geral: " << alu.exibirrg() << endl; 
	return 0;
}
