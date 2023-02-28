#include "iostream"
#include "string"
#include "fstream"

using namespace std;
char** p,pr;
int i, j, s;
int w=15, h=15;

int main(){
ofstream fout("pole.txt");
for (i=0;i<w;i++){
		for (j=0;j<h;j++){
			s=1 + rand() % 100;
			if (s<=60)
			{
				fout << '_';
			}
			if (s<=80 and s>60)
			{
				fout << '*';
			}
			if (s<=95 and s>80)
			{
				fout << '0';
			}
			if (s<=99 and s>95)
			{
			    fout << '+';
			}
			if (s>99)
			{
			    fout << '|';
			}
		}
		fout << endl;
	}
	fout.close();
}
