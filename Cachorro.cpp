class cachorro : public animal{
	
	float altura;
	float peso;
	string raca;
	string sexo;
	string cor;
	
	public:
				
		void get_cor(string c){cor = c;}
		void get_sexo(string s){sexo = s;}
		void get_raca(string r){raca = r;}
		string set_sexo(){return sexo;}
		string set_raca(){return cor;}
		
    private:
    	string set_cor(){return raca;}
};
