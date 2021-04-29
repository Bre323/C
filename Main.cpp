#include<iostream>
#include "Base.cpp"

using namespace std;

int main(){
	Rectangle rect;
	rect.set_values(5, 7);
	cout << "Calculo da area do retangulo \n\n" << endl;
	cout << "Area = " << rect.area() << endl;
	return 0;
}
