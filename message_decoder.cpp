/*
++++++++ Message decoder program, pag 41 "Think like a programmer" noStarch
++++++++ Gabriele, 09/02
*/

#include <iostream>
using namespace std;

//managing modes with enumerators
enum Mode {UPPER,LOWER,PUNCTUATION};
Mode mode=UPPER;    //variable shared with all functions

int read_number(bool&);  //if line feed found, report it to main
char int_to_charUpper(int);
char int_to_charLower(int);
char int_to_charPunctuation(int);

int main(){
    
    cout << "++++++++++ DECODER: put in your codified string\n";

    bool line_feed=false;
    int num;

    
    while(!line_feed){ 
        //reading the number        
         num=read_number(line_feed);
         //checking if read_number has detected a '\n'
         if (num==-1){
             line_feed=true;
             continue;
         }

         //branching based on the decoding mode
         switch(mode){
             case UPPER:
                cout << int_to_charUpper(num);
                break;
             case LOWER:
                cout << int_to_charLower(num);
                break;
             case PUNCTUATION:
                cout << int_to_charPunctuation(num);
         }
        
    }

return 0;
}


int read_number(bool& line_feed){

    //testing code to convert a X digits char number in a number
    int num=0;
    char cnum;
    cnum=cin.get();
    //Managin erros from user: necessary if a comma is lefted appended -> Example: 123,456, -> in this case ',' is eaten
    //by the function, and when it is recalled again the first char is \n
    if (cnum==10){
        line_feed=true;   
        return -1;
    }
    //identifying end of number with the ',' character
    //ASCII code of ',' is 44

    while(cnum!=44 && cnum!=10){    //while cnum is not the comma or the line feed
        num=num*10+(cnum-'0'); //magnitude of the number goes up, appending the just taken up digit to it
        cnum=cin.get();
        if(cnum==10){   //line feed detected
            line_feed=true;
        }
    }

    return num;
}



char int_to_charUpper(int num){
    
	//- map % 27 on UPPER letters of the alphabet
    //taking modulo, if equals zero change mode. Otherwise map the number in a character
    //1=A, 2=B ... offset is 64
    char cnum;
    
    //checking cases
    if (num%27==0){
        mode=LOWER;
        cnum=0; //if 'switch mode' has been triggered, return 0 (NUL char)
    }
    else cnum=num%27+64;
    return cnum;
}

char int_to_charLower(int num){
    
	//- map % 27 on LOWER letters of the alphabet
    //taking modulo, if equals zero change mode. Otherwise map the number in a character
    //1=a, 2=b ... offset is 96 
    char cnum;
    
    //checking cases
    if (num%27==0){
        mode=PUNCTUATION;
        cnum=0; //NUL character 
    }
    else{
         cnum=num%27+'a'-1; 
    }
    return cnum;
}


char int_to_charPunctuation(int num){
    //implementing the 'PUNCTUATION mode' -> no correlation founded between given table and ASCII, so need to save the
    //table in the program itself
    
    char punct_table[]={'!','?',',','.',' ',';','"','\''};
    char punct;

    if(num%9==0) {
        punct=0;    //null character
        mode=UPPER;
    }
    else punct=punct_table[(num%9)-1]; 

    return punct;
}
