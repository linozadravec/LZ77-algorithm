#include <iostream>
#include <cstring>

using namespace std;

char znakovi[50],ddekompresija[50];
int dO,dL,odluka;
char dC;
int izbor,duljina,searchduljina,lookaheadduljina,offset,maxoffset,duljinapodudaranja,maxduljinapodudaranja;

void unos(){
	cout<<"Unesi znakove: ";
			cin.ignore();
			cin.getline(znakovi,50);
			duljina = strlen(znakovi);
			cout<<"Unesi velicinu search buffera: ";
			cin>>searchduljina;
			cout<<"Unesi velicinu lookahead buffera: ";
			cin>>lookaheadduljina;
}
void dekompresija(){
	int i=0;
	do{	
		cout<<"1. za unos zapisa / 2. za ispis(treba bar jedan)";
		cin>>odluka;
		if(odluka==1){
			cout<<"Unesi offset(O): ";
			cin>>dO;
			cout<<"Unesi duljinu podudaranja(L): ";
			cin>>dL;
			cout<<"Unesi kodnu rijec(C): ";
			cin>>dC;
			if(dO==0){
				ddekompresija[i]=dC;
				i++;
			}
			else{
				int brojac=0;
				int j=i-dO;
				while(brojac<dL){
				
					ddekompresija[i]=ddekompresija[j];
					i++;
					j++;
					brojac++;
					}
				ddekompresija[i]=dC;
				i++;
				}
			}
		if(odluka==2){
			for(int k=0;k<strlen(ddekompresija);k++){
				cout<<ddekompresija[k];
			}
		}		
	}while(odluka!=2);
}


void kompresija(){
	
	cout<<"< 0, 0, C("<<znakovi[0]<<")>"<<endl;
	
	for(int i=1;i<duljina;){
		maxduljinapodudaranja=0;
		offset=0;
		for( int j=i-1;j>=i-searchduljina && j>=0;j--){
			duljinapodudaranja=0;
			if(znakovi[i]==znakovi[j]){
				duljinapodudaranja++;
				for(int k=1;k<=lookaheadduljina;k++){
					if(znakovi[j+k]==znakovi[i+k]){
						duljinapodudaranja++;
					}
					else{
						break;
					}
				}
				
				if(duljinapodudaranja>maxduljinapodudaranja){
					maxduljinapodudaranja=duljinapodudaranja;
					offset=i-j;
				}
				
			}
		}		
		cout<<"< "<< offset<<", "<<maxduljinapodudaranja<<", C("<<znakovi[i+maxduljinapodudaranja]<<")>"<<endl;
		i=i+maxduljinapodudaranja+1;
		
	}
}


int main(){
	
	
	
	do{
	
	cout<<"1. za kompresiju / 2. za dekompresiju / 9. izlaz"<<endl;
	cin>>izbor;
	
	switch(izbor){
		case 1:
			for(int i=0;i<50;i++){
				znakovi[i]='\0';
			}
			unos();
			kompresija();
			break;
		case 2:
			for(int i=0;i<50;i++){
				ddekompresija[i]='\0';
			}
			dekompresija();
			
			
	}
	
	}while(izbor!=9);
	return 0;
}
