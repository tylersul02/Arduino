//trs8x8.ino
#include <iostream>
#include <stdio.h>
int trs();

int main()
{
	trs();
	return 0;
}
// Tyler's Function
int trs (){
	int r,c;
	int red, green, blue;
	int val = 0;
	int m[8][8] = {
		{0,0,0,0,0,0,0,0} ,
		{0,0,1,0,0,1,0,0} ,
		{0,0,1,0,0,1,0,0} ,
		{0,0,1,0,0,1,0,0} ,
		{0,0,0,0,0,0,0,0} ,
		{0,1,0,0,0,0,1,0} ,
		{0,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0}
	};
	
		red = 0; green = 0; blue = 0;
		for (r = 0; r < 8; r++){
			for (c = 0; c < 8; c++){
				val = m[r][c];
				switch (val){
					case 0:
					red = 255; green = 255; blue = 0;
					break;
					case 1:
					red = 0; green = 0; blue = 0;
					break;
				}
				std::cout<<"["<<red<<" "<<green<<" "<<blue<<"]";
			}
			std::cout<<"\n";
	}
	return 0;
}
