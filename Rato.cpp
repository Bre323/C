class rato : public animal{
	
	float altura;
	float peso;
	string raca3;
	string sexo3;
	string cor3;
	
	public:
		
		void get_cor3(string c3){cor3 = c3;}
		void get_raca3(string r3){raca3 = r3;}
		void get_sexo3(string s3){sexo3 = s3;}
		string set_sexo3(){return sexo3;}
		string set_raca3(){return cor3;}
	
    private: 
    	string set_cor3(){return sexo3;}
};

