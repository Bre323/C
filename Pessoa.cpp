#include<iostream> 
using namespace std;

class pessoa{
	int idade;
	string nome;
	
	public:
		void getidade(int i){idade = i;}
		void getnome(string n){nome = n;}
		int exibiridade(){return idade;}
		string exibirnome(){return nome;}
};