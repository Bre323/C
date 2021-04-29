class gato : public animal{
	
	float altura;
	float peso;
	string raca2;
	string cor2;
	string sexo2;
	
	public: 
		
		void get_raca2(string r2){raca2 = r2;}
		void get_cor2(string c2){cor2 = c2;}
		void get_sexo2(string s2){sexo2 = s2;}
		string set_raca2(){return cor2;}
		string set_sexo2(){return sexo2;}
	
		
    private:
    	string set_cor2(){return raca2;}
};