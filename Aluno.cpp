class aluno{
	int matricula, ano, rg;
	public:
		void getmatricula(int m){matricula = m;}
		void getano(int a){ano = a;}
		void getrg(int r){rg = r;}
		int exibirmatricula(){return matricula;}
		int exibirano(){return ano;}
		int exibirrg(){return rg;}
};
