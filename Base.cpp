//classes
#include<iostream>
using namespace std;

class Rectangle{
	int width, height;
	
	public:
		void set_values(int x, int y);
		int area(){return width*height;}
};

void Rectangle::set_values(int x, int y){
		width = x;
		height = y;
	}
	
