#include "iostream"
#include "string"
#include "fstream"
#include "ctime"

using namespace std;
char** p;
string pr ="";
char mov ='0';
int i, j, s, hp, x, xa, y, ya, port=0, dm=0, ap=0;
char ot;
int w, h;

void vivod (){
	for (i=0;i<w;i++){
		for (j=0;j<h;j++){
			cout << p[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << "HP: ";
	s=0;
	while (s<hp){
	    cout << "█";
	    s=s+1;
	}
	cout << hp << "0%" << endl;
}

int main(){
	
	cout << "Random pole ili net? r/n" << endl;
	cin >> ot;
	if(ot == 'n'){
			w=15;
			h=15;
			p=new char*[w];
			for (i=0; i<w;i++){
				p[i]=new char[h];
			}
			ifstream fin("../pole.txt");
			for (i=0;i<w;i++){
				for (j=0;j<h;j++){
					fin >> p[i][j];
				}
			}
			fin.close();
	}
	else{
			cout << "Ukajite razmer polya" << endl;
			cout << endl << "Visota:";
			cin >> h;
			cout << "Dlina:";
			cin >> w;
			cout << endl << endl;
			p=new char*[w];
			for (i=0; i<w;i++){
				p[i]=new char[h];
			}
			srand(time(0));
			for (i=0;i<w;i++){
				for (j=0;j<h;j++){
					s=1 + rand() % 100;
					if (s<=60){
						p[i][j]='_';
					}
					if (s<=80 and s>60){
						p[i][j]='*';
					}
					if (s<=95 and s>80){
						p[i][j]='0';
					}
					if (s<=99 and s>95){
						p[i][j]='+';
					}
					if (s>99){
						p[i][j]='|';
						port=port+1;
						if (port>2){
							p[i][j]='_';
						}
					}	
				}
				if (i==(w-1) and port<2){
					i=0;
					port=0;
				}
			}	
	}
	p[0][0]='@';
	p[w-1][h-1]='$';
	hp=10;
	s=0;
	vivod ();
	x=0;
	y=0;
	while (mov != 'e'){
		p[x][y]='m';
		cin >> mov;
		xa = x; 
		ya = y;
		switch(mov){
			case 'w':
				xa=x-1;
				break;
			case 'a':
				ya=y-1;
				break;
			case 's':
				xa=x+1;
				break;
			case 'd':
				ya=y+1;
				break;
		}
		if (xa>-1 and ya>-1 and xa<w and ya<h){
			x=xa;
			y=ya;
		}
		else{
			cout << "Kuda poper?" << endl;
			continue;
		}
		    if (p[x][y]=='*'){
			    hp=hp-1;
			    pr=pr+'d';
			}
			if (p[x][y]=='+'){
			    hp=10;
			    pr=pr+'a';
			    s=0;
			}
			if (p[x][y]=='$' or p[x][y]=='0' or hp==0){
			    if (p[x][y]=='$')
			    {
					cout << "Za brodyachih psov!" << endl;
				}
				else
				{
					cout << "ti lox" << endl;
				}
			    pr=pr+'f';
			    for(int i = 0; i<(int)pr.size(); i++){
					if (pr.at(i)=='d'){
						dm=dm+1;
					}
					if (pr.at(i)=='a'){
						ap=ap+1;
					}
				}
			    cout << "Damaga: " << dm << endl;
			    cout << "Aptechek: " << ap << endl;
			    break;
			}
			if (p[x][y]=='|'){
			    p[x][y]='m';
		    	for (i=0;i<w;i++){
					for (j=0;j<h;j++){
						if (p[i][j]=='|'){
							cout << '@' << ' ';
							x=i;
							y=j;
						}
						else{
							cout << p[i][j] << ' ';
						}
					}
					cout << endl;
				}
				cout << endl << "HP: ";
				s=0;
				while (s<hp){
					cout << "█";
					s=s+1;
				}
				cout << hp << "0%" << endl;
			}else{
				p[x][y]='@';
				vivod();
			}
	}
	return 0;
}
