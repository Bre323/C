#include <iostream>
#include <locale.h>
#include "Animal.cpp"
#include "Cachorro.cpp"
#include "Gato.cpp"
#include "Rato.cpp"
using namespace std;



	
int main(){

	setlocale(LC_ALL, "Portuguese");
	
	cachorro cac;
	gato gat;
	rato rat;
	
	
	
	cac.get_altura(0.5);
	cac.get_peso(6.2);
	cac.get_nome("Cachorro");
	cac.get_raca("Pitbull");
	cac.get_sexo("Feminino");
	cac.get_cor("Branco");
	
	cout << "Raça do cachorro: " << cac.set_raca() << endl;
	cout << "Sexo: " << cac.set_sexo() << endl;
	cout << "Altura: " << cac.set_altura() << endl;
	cout << "Peso: " << cac.set_peso() << endl;
	
	
	gat.get_altura(0.6);
	gat.get_peso(5.6);
	gat.get_raca2("Persa");
	gat.get_sexo2("Masculino");
	gat.get_cor2("Preto");
	
	cout << "\n\n\nRaça do gato: " << gat.set_raca2() << endl;
	cout << "Sexo: " << gat.set_sexo2() << endl;
	cout << "Altura: " << gat.set_altura() << endl;
	cout << "Peso: " << gat.set_peso() << endl;
	

	rat.get_altura(0.1);
	rat.get_peso(0.65); 
	rat.get_raca3("Hamster");
	rat.get_sexo3("Feminino");
	rat.get_cor3("Amarelo");
	
	
	cout << "\n\n\nRaça do rato: " << rat.set_raca3() << endl;
	cout << "Sexo: " << rat.set_sexo3() << endl;
	cout << "Altura: " << rat.set_altura() << endl;
	cout << "Peso: " << rat.set_peso() << endl;
	
	
	
	return 0; 
}
