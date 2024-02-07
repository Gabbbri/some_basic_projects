/* Gabriele - 05/02
 */

#include <iostream>

using namespace std;

// task 3 -> treating each doubled number accordingly

int double_num(int);

int char_to_int(char);

bool luhn_checksum();

int main(){
	
	cout << "\n++++++ Inserisci il numero. Hai 3 tentativi\n"; 
	
	int tentativi=3;
	for(;tentativi>0;tentativi--){
		if(luhn_checksum()) break;
	}		
	if (!tentativi) cout << "\n\n+++++++++++ SEI BLOCCATO\n";

return 0;
}


int double_num(int num){
	int sum=0;
	//branching if num*2>=10
	if (num*2>=10) sum+=(num*2)%10+1;
	else sum+=num*2;
return sum;
}

bool luhn_checksum(){

	char digit;
	digit=cin.get();
		
	//ci organizziamo gli strumenti
	int counter=0;
	int sum_pari=0, sum_dispari=0;
	bool is_ID=false;
	bool err=false;
	
	while(digit!=10){	//quando digit='\n' -> ASCII = 10, allora esc
		counter++;	
		//step 1: converto la digit da char a intero
		int num=digit-'0';
		//se l'utente inserisce letterali, alza una flag di errore
		if(num<0 || num>9){
		       	err=true;
			break;
		}

		//step 2: aggiorno sia la somma pari che dispari
		if(counter%2==0){	//la cifra è pari
			sum_pari+=num;
			sum_dispari+= double_num(num);
		}
		else{
			sum_pari+=double_num(num);
			sum_dispari+=num;
		}

		digit=cin.get();
	}
	if (err) cout << "\n----- Errore: il codice deve essere completamente numerico\n";
	else {
		
		//qual'è la somma che interessa?
		int sum;
		if (counter%2==0) sum=sum_pari;
		else sum=sum_dispari;

		//facciamo il controllo del numero
		if (sum%10==0) {
			is_ID=true;
			cout << "\n\nIl numero è confermato\n";
		}
		else cout << "\n\n++++++Il numero è sbagliato\n";
	}

return is_ID;
}
