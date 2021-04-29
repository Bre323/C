#include<iostream>
#include<locale.h>

using namespace std;


int main(){
	setlocale(LC_ALL, "Portuguese");
	int celsius, kelvin, fahreinheit;
	cout << "Digite a temperatura em graus" << endl;
	cin >> celsius;
	
	kelvin = celsius + 273;
	fahreinheit = celsius * 9/5 + 32;
	
	cout << "A temperatura é de " << kelvin << " Kelvin\n\n\n" << endl;
	cout << "A temperatura é de " << fahreinheit << " Fahreinheit\n\n\n" << endl;
	
	cin.get();
	return 0;
}

