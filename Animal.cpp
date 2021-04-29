//classe animal
#include <iostream>
using namespace std;

	namespace arquivo{
	void print(){
		cout << "Funcao de encapsulamento" << endl;
	}

	}
	
class animal{
	string nome;
	float altura;
	float peso;
	int idade;
	
	public:
		
	void get_nome(string n){nome = n;}
	void get_altura(float h){altura = h;}
	void get_peso(float kg){peso = kg;}
	float set_altura(){return altura;}
	float set_peso(){return peso;}
		
    private:
		string set_nome(){return nome;}

};

	
	
