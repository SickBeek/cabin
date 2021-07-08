#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int version_2();

int main (){
	int i=0;
	while (i++<81){
		if (i/9%3==i%9%3)
			continue;
		//cout<< "A="<< i/9+1<< ", B="<< i%9+1<<endl;
	}
	version_2();
	return 0;
}

struct {
	unsigned char a:4;
	unsigned char b:4;
} chess;

int version_2(){
	for (chess.a=1;chess.a<=9;chess.a++)
	for (chess.b=1;chess.b<=9;chess.b++)
		if (chess.a %3==chess.b %3)
			cout<< "A="<< chess.a<< ", B="<< chess.b<<endl;
	return 0;
}
