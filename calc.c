#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include <string.h>
#include <ctype.h>


/*	Takes in a string of decimal numbers and an integer denoting if that decimal is positive or negative.
 *	returns an unsigned int reprensentation of the string.
 */

unsigned int decStoi(char* change,int isneg){
	
	int end = strlen(change)-1;  								/*last index*/
	int i=0;										/*counter for for loop*/
	unsigned int num = 0;									/*number to be returned*/
	int exp;										/*keeps track of the decimal place*/
	int start=0;

	if(isneg==1){										/*ensures the '-' character if there is one does not get checked*/
		start++;
	}

	/*	itterates through the string from back to front, changing the character 
 		digit to an integer.
         */
	for(i =end;i>start;i--){
		if(!isdigit(change[i])){							/*checks to see if the charater is a digit, if not returns an error*/	
			fprintf(stderr,"Error: Vaule not in Decimal\n");
			exit(EXIT_FAILURE);
		}

		if((num>294967295&&((change[i]-48)>3)&&i==start+1)){				/*checks to make sure the integer is not larger than 32bits. returns an error if bigger.*/
			fprintf(stderr,"Error: Decimal Is Bigger Than 32 Bits\n");
			exit(EXIT_FAILURE);
		}
		exp=1;
		num += (change[i]-48)*exp;							/*changes character to integer*/
		exp*=10;									/*increases by power of ten*/
	}
	return num;
}

/*	dToB accepts and unsigned int and  a string bin.
 * 	
 * 	Converts int into a binary string.
 * 		
 * 	If it does not go through the full length of the string it fill the empty
 * 	space with '0' from back to front.
 * 	*/

void  dToB(unsigned int dec,char* bin){
	int last;
	int i=32;

	bin[i]='\0';
	i--;

	while(dec>0){
		if((dec%2)==0){
			bin[i]='0';
		}else{
			bin[i]='1';
		}	
		i--;
		dec /= 2;
	}
	for(last=i;last>=0;last--){
		bin[last]= '0';
	}		
	return;
}
/*	Parameters are the string in decimal, an int indicating the decimal's sign,
 *	and a BinaryArr* which will hold the binary representation
 *
 *	Turns the decimal into a unsigned integer and then into the binary string*/
void decToBin( char* dec, int isNeg, BinaryArr* DecInBin){
	unsigned int strToInt=0;
	char* binStr =(char*)malloc((sizeof(int)+1)*sizeof(char));


	strToInt = decStoi(dec,isNeg);
	dToB(strToInt,binStr);
	strcpy(DecInBin->binRep, binStr);
//	free(binStr);
	return;
}

/*	Parameters are the string in hexidecimal, an int indicating the hexidecimal's sign,
 *	and a BinaryArr* which will hold the binary representation
 *
 *	Turns the hexidecimalstring  into a binary string by realizing each character in 
 *	hex has a four bit representation in binary*/
void hexToBin(char* hex, int isNeg,BinaryArr* HexToBin){
	int i=strlen(hex)-1;
	int j;
	int start = 1;
	BinaryArr* temp=HexToBin;

	if(isNeg==1){
		start++;
	}
	if(hex[start]=='0'&&(hex[start+1]=='x'||hex[start+1]=='X')){			/*Covers the case where the hex string starts with 0x*/
		start+=2;
	}
	while(i>=start){
		char* hold = (char*)malloc((sizeof(int)+1)*sizeof(char));
		hold[32]='\0';
		for(j=31;j>=0;j-=4){
			if(hex[i]=='0'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='0';
				hold[j-3]='0';
			}else if(hex[i]=='1'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='0';
				hold[j-3]='0';
			}else if(hex[i]=='2'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='0';
				hold[j-3]='0';
			}else if(hex[i]=='3'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='0';
				hold[j-3]='0';
			}else if(hex[i]=='4'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='1';
				hold[j-3]='0';
			}else if(hex[i]=='5'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='1';
				hold[j-3]='0';
			}else if(hex[i]=='6'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='1';
				hold[j-3]='0';
			}else if(hex[i]=='7'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='1';
				hold[j-3]='0';
			}else if(hex[i]=='8'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='0';
				hold[j-3]='1';
			}else if(hex[i]=='9'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='0';
				hold[j-3]='1';
			}else if(hex[i]=='a'||hex[i]=='A'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='0';
				hold[j-3]='1';
			}else if(hex[i]=='b'||hex[i]=='B'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='0';
				hold[j-3]='1';
			}else if(hex[i]=='c'||hex[i]=='C'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='1';
				hold[j-3]='1';
			}else if(hex[i]=='d'||hex[i]=='D'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='1';
				hold[j-3]='1';
			}else if(hex[i]=='e'||hex[i]=='E'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='1';
				hold[j-3]='1';
			}else if(hex[i]=='f'||hex[i]=='F'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='1';
				hold[j-3]='1';
			}else{
				if(i<start){							/*Covers the case where the binary representation is smaller than 32 bit,
												 0 fills the free space*/
					while(j>=0){
						hold[j]='0';
						j--;
					}
					break;	
				}
				fprintf(stderr,"Error, Not in Hex\n\n");
				exit(EXIT_FAILURE);
			}
			i--;
		}
			strcpy(temp->binRep, hold);				        /*creates a new node with dynamic memory*/
			temp->next=(BinaryArr*)malloc(sizeof(BinaryArr*));
			temp=temp->next;
			temp->binRep= (char*)malloc((sizeof(int)+1)*sizeof(char));
	}


	temp->next=NULL;									/*frees temp when done*/
//	free(temp->binRep);
//	free(temp);
	return;		
}

/*	Parameters are the string in binary of arbitrary length, an int indicating the binary's sign,
 *	and a BinaryArr* which will hold the binary linked list  representation
 *
 *	Splits the original string into 32 bit binary strings*/

void binToBin(char* bin, int isNeg,BinaryArr* BinToBin){
	int i=strlen(bin)-1;
	int j;
	int start = 1;
	BinaryArr* temp=BinToBin;

	if(isNeg==1){
		start++;
	}
	while(i>=start){
		char* hold = (char*)malloc((sizeof(int)+1)*sizeof(char));
		hold[32]='\0';
		for(j=31;j>=0;j--){
			if(bin[i]=='0'||bin[i]=='1'){
				hold[j]=bin[i];
			}else{
				if(i<start){
					while(j>=0){
						hold[j]='0';
						j--;
					}
					break;	
				}
				fprintf(stderr,"Error, Not in Bin\n\n");
				exit(EXIT_FAILURE);
			}
			i--;
		}
		strcpy(temp->binRep, hold);
		temp->next=(BinaryArr*)malloc(sizeof(BinaryArr*));				/*Creates the next node in dynamic Memory*/
		temp=temp->next;
		temp->binRep= (char*)malloc((sizeof(int)+1)*sizeof(char));
	}
	temp=NULL;										/*frees temp when done*/
	//free(temp);

	return;		
}
/*	Parameters are the string in octal, an int indicating the octal's sign,
 *	and a BinaryArr* which will hold the binary representation
 *
 *	Uses three cases to change an octal string into its binary representation
 *	By realizing that a octal digit can be directly translated into three binary bits.
 *
 *	Needs three cases because 3 does not go into 32 well so some bits will go into other 
 *	node's strings.*/

void octToBin(char* oct, int isNeg,BinaryArr* OctToBin){
	int maxind= 31;
	int i=strlen(oct)-1;
	int j;
	int start = 1;
	char next0='o';
	char next1='o';
	int node = 0;
	BinaryArr* temp=OctToBin;

	if(isNeg==1){
		start++;
	}
	while(i>=start){
		char* hold = (char*)malloc((sizeof(int)+1)*sizeof(char));
		hold[32]='\0';
		if(node%3==1){
			hold[31]=next0;
			maxind--;
		}else if(node%3==2){
			hold[31]=next0;
			hold[30]=next1;
			maxind-=2;
		}
		for(j=maxind;j>1;j-=3){					/*Case 1: Similar to hex to Bin*/			
			if(oct[i]=='0'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='0';
			}else if(oct[i]=='1'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='0';
			}else if(oct[i]=='2'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='0';
			}else if(oct[i]=='3'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='0';
			}else if(oct[i]=='4'){
				hold[j]='0';
				hold[j-1]='0';	
				hold[j-2]='1';
			}else if(oct[i]=='5'){
				hold[j]='1';
				hold[j-1]='0';	
				hold[j-2]='1';
			}else if(oct[i]=='6'){
				hold[j]='0';
				hold[j-1]='1';	
				hold[j-2]='1';
			}else if(oct[i]=='7'){
				hold[j]='1';
				hold[j-1]='1';	
				hold[j-2]='1';
			}else{
				if(i<start){
					while(j>=0){
						hold[j]='0';
						j--;
					}
					break;	
				}
				fprintf(stderr,"Error, Not in Oct\n\n");
				exit(EXIT_FAILURE);
			}
			i--;
		}

		if(node%3==0){							/*Case 2: saves the leading bit for the next node*/
			if(oct[i]=='0'){
				hold[1]='0';
				hold[0]='0';	
				next0='0';
			}else if(oct[i]=='1'){
				hold[1]='1';
				hold[0]='0';	
				next0='0';	
			}else if(oct[i]=='2'){
				hold[1]='0';
				hold[0]='1';	
				next0='0';	
			}else if(oct[i]=='3'){
				hold[1]='1';
				hold[0]='1';	
				next0='0';
			}else if(oct[i]=='4'){
				hold[1]='0';
				hold[0]='0';	
				next0='1';
			}else if(oct[i]=='5'){
				hold[1]='1';
				hold[0]='0';	
				next0='1';
			}else if(oct[i]=='6'){
				hold[1]='0';
				hold[0]='1';	
				next0='1';
			}else if(oct[i]=='7'){
				hold[1]='1';
				hold[0]='1';	
				next0='1';	
			}
		}else if(node%3==1){							/*Case 3: Same as 2, but now saving 2 bits for next node*/
			if(oct[i]=='0'){
				hold[0]='0';
				next0='0';	
				next1='0';
			}else if(oct[i]=='1'){
				hold[0]='1';
				next0='0';	
				next1='0';	
			}else if(oct[i]=='2'){
				hold[0]='0';
				next0='1';	
				next1='0';	
			}else if(oct[i]=='3'){
				hold[0]='1';
				next0='1';	
				next1='0';
			}else if(oct[i]=='4'){
				hold[0]='0';
				next0='0';	
				next1='1';
			}else if(oct[i]=='5'){
				hold[0]='1';
				next0='0';	
				next1='1';
			}else if(oct[i]=='6'){
				hold[0]='0';
				next0='1';	
				next1='1';
			}else if(oct[i]=='7'){
				hold[0]='1';
				next0='1';	
				next1='1';	
			}
		}
		node++;
		strcpy(temp->binRep, hold);
		temp->next=(BinaryArr*)malloc(sizeof(BinaryArr*));				/*Creates new node dynamically*/
		temp=temp->next;
		temp->binRep= (char*)malloc((sizeof(int)+1)*sizeof(char));
	}

	temp=NULL;										/*Frees the temperary node*/
//	free(temp);
	return;		
}

/*	Parameters are a string, an int indicating if its the last node (in this
 *	implementation the last node is the head), and an integer that holds the carry
 *	
 *	takes the twos complement and adds one if it is the last node.
 */

void twoComp(char* orig, int islast,int carry){
	int i;
	for(i=31;i>=0;i--){
		if(orig[i]=='0'){
			orig[i]='1';
		}else if(orig[i]=='1'){
			orig[i]='0';
		}else{
		/*	fprintf(stderr,"ERROR Cannot take Two's Complement of non-Binary Number\n");*/
		/*	exit(EXIT_FAILURE);*/
		}
	}
	if(islast==1){				
		addbin(orig,"00000000000000000000000000000001",0,0,carry,0,0);
	}
	return;
}

/*	Parameters are the strings that are to be added, ints representing the signs of those strings,
 *	an int to hold the carry, and ints to note when the strings are part of the last node.
 *
 *	b1 is the solution between the two strings*/

void addbin(char* b1, char* b2, int neg1, int neg2, int carry,int lastNode1, int lastNode2){
	int i;
	int j = strlen(b2)-1;
	int larger=0;	
	if(neg1==1&&neg2==0){							/*Keeps track of which number is bigger and what their sign is*/
		if(strcmp(b1,b2)>0){
			larger=1;
		}
		twoComp(b1,lastNode1,carry);					/*takes twos complement of a number if it's negative*/
	}else if(neg1==0&&neg2==1){
		if(strcmp(b1,b2)<0){
			larger=1;
		}
		twoComp(b2,lastNode2,carry);
	}
	for(i = strlen(b1)-1;i >= 0;i--){								/*adds*/
		if(b1[i]=='0'&&b2[j]=='0'){
			if(carry==0){
				b1[i]='0';
			}else{
				b1[i]='1';
				carry=0;
			}
		}else if((b1[i]=='1'&&b2[j]=='0')||(b1[i]=='0'&&b2[j]=='1')){
			if(carry==1){
				b1[i]='0';
			}else{
				b1[i]='1';
			}
		}else if(b1[i]=='1'&&b2[j]=='1'){
			if(carry==0){
				b1[i]='0';
				carry=1;
			}
		}else{
			fprintf(stderr,"Error: String did not convert to binary\n\n");
			exit(EXIT_FAILURE);
		}
		j--;
	}
	if(larger==1){										/*if the bigger number was negative then */
		twoComp(b1,lastNode1,carry);
	}
	return;
}

/*	Adds Node 2 to node 1 by traversing through the list linearly
 *	If node2 has more nodes, identical nodes are added onto node 1*/

BinaryArr* add(BinaryArr* b1, BinaryArr* b2, int neg1, int neg2){
	int carry=0;
	BinaryArr* temp1= b1;
	BinaryArr* temp2= b2;
	BinaryArr* prev1 =temp1;
	addbin(temp1->binRep, temp2->binRep, neg1, neg2,carry,1 ,1);
	temp1=temp1->next;
	temp2=temp2->next;
	while(temp1!=NULL&&temp2!=NULL){
		addbin(temp1->binRep, temp2->binRep, neg1, neg2,carry,0 ,0);
		prev1=temp1;
		temp1= temp1->next;
		temp2= temp2->next;
	}	
	while(temp2!=NULL){
		prev1->next= (BinaryArr*)malloc(sizeof(BinaryArr*));
		strcpy(prev1->next->binRep,temp2->binRep);
		prev1= prev1->next;
		temp2= temp2->next;
	}
	return b1;
}

/*	Function meant to raise base to exponent exp and return the solution*/
unsigned int powd(unsigned int base, unsigned int exp){
	int i;
	if(exp==0){
		return 1;
	}
	for(i=1;i<exp;i++){
		base*=2;	
	}
	return base;
}

/*	Loops through the nodes recursively and prints the binRep strings starting with the tail's string*/

void printbin(BinaryArr* bin){
	if(bin==NULL){
		return;
	}
	printbin(bin->next);
	printf("%s",bin->binRep);
	return;
}

/*	Prints solution in decimal by simple recursive conversion*/

void printdec(BinaryArr* dec,unsigned int total,unsigned int e){
	int i;
	for(i=strlen(dec->binRep)-1;i>=0;i--){
		total+=(dec->binRep[i]-48)*powd(2,e);
		e++;
	}
	if(dec->next==NULL){
		printf("%d",total);
		return;
	}
	printdec(dec->next,total,e);
	return;
}
/*	Should Print solution in octal by checking 3 indices at a time*/

void printoct(BinaryArr* oct,char* hold,int node){

	if(oct==NULL){
		return;
	}
	printoct(oct->next,hold,node);
	if(node==2){
		printf("%s",hold);
		node=0;
	}
	hold[node]=oct->binRep[node];
	node++;
	
	return;	
}
/*	Prints solution in hex by checking 4 indices at a time*/

void printhex(BinaryArr* hex){
	int i;
	int j=0;
	char* hold=(char*)malloc(sizeof(char*)*8);
	if(hex==NULL){
		return;
	}
	printhex(hex->next);

	for(i=0;i<32;i+=4){
		if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='0'){
			hold[j]='0';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='1'){
			hold[j]='1';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='0'){
			hold[j]='2';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='1'){
			hold[j]='3';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='0'){
			hold[j]='4';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='1'){
			hold[j]='5';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='0'){
			hold[j]='6';
		}else if(hex->binRep[i]=='0'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='1'){
			hold[j]='7';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='0'){
			hold[j]='8';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='1'){
			hold[j]='9';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='0'){
			hold[j]='A';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='0'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='1'){
			hold[j]='B';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='0'){
			hold[j]='C';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='0'&&hex->binRep[i+3]=='1'){
			hold[j]='D';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='0'){
			hold[j]='E';
		}else if(hex->binRep[i]=='1'&&hex->binRep[i+1]=='1'&&hex->binRep[i+2]=='1'&&hex->binRep[i+3]=='1'){
			hold[j]='F';
		}
		j++;
	}

	printf("%s",hold);
	return;
}

/*	Prints the solution in the user specified base*/

void output(BinaryArr* solbin, char negfin, char* base){
	unsigned int total=0;
	if(negfin=='-'){					/*prints the sign if negative*/ 
		printf("%c",negfin);
	}
	if(base[0]=='b'){
		printf("b");
		printbin(solbin);
	}else if(base[0]=='d'){
		printf("d");
		printdec(solbin,total,0);
	}else if(base[0]=='o'){
		char* hold= (char*)malloc(sizeof(char)*4);	/*Currently does not work*/
		hold[3]='\0';
		printoct(solbin, hold, 0);
	}else if(base[0]=='x'){
		printf("x");
		printhex(solbin);
	}else{
		fprintf(stderr,"Error: base is not is octal, binary, hexidecimal, or decimal\n\n");
		return;
	} 

	printf("\n\n");	
	return;
}

/*SEE README*/
int main(int argc, char **argv){
	
	char* op = argv[1];
	char* num1 = argv[2];
	char* num2 = argv[3];
	char* base = argv[4];
	char negfin;
        int neg1 = 0;
	int neg2 = 0;

	BinaryArr* bnum1 =(BinaryArr*)malloc(sizeof(BinaryArr*));
	bnum1->binRep = (char*)malloc((sizeof(int)+1)*sizeof(char));

	BinaryArr* sol;	

	if(op==NULL||num1==NULL||num2==NULL||base==NULL){
		fprintf(stderr, "Error: MISSING INPUT\n Please enter in Correct Format:  OPERATION BASE-NUMBER1 BASE-NUMBER2 OUTPUT-BASE\n\n");
		return 0;
	}
	
	if(num1[0]=='-'){
		neg1 = 1;
		if(num1[1]=='d'){
	          	decToBin(num1,neg1,bnum1);
		}else if(num1[1]=='b'){
			binToBin(num1,neg1,bnum1);
		}else if(num1[1]=='o'){
			octToBin(num1,neg1,bnum1);
		}else if(num1[1]=='x'){
			hexToBin(num1,neg1,bnum1);
		}else{
			fprintf(stderr, "Error: INVALID INPUT\n Please enter in Correct Format: OPERATION BASE-NUMBER1 BASE-NUMBER2 OUTPUT-BASE\n");
			return 0;
		} 
	}else{
		if(num1[0]=='d'){
	        	decToBin(num1,neg1,bnum1);
		}else if(num1[0]=='b'){
			binToBin(num1,neg1,bnum1);
		}else if(num1[0]=='o'){
			octToBin(num1,neg1,bnum1);
		}else if(num1[0]=='x'){
			hexToBin(num1,neg1,bnum1);
		}else{
			fprintf(stderr, "Error: INVALID INPUT\n Please enter in Correct Format: OPERATION BASE-NUMBER1 BASE-NUMBER2 OUTPUT-BASE\n");
			return 0;
		}
	}

	BinaryArr* bnum2 =(BinaryArr*)malloc(sizeof(BinaryArr*));
	bnum2->binRep = (char*)malloc((sizeof(int)+1)*sizeof(char));

	if(num2[0]=='-'){
		neg2 = 1;
		if(num2[1]=='d'){
	          	decToBin(num2,neg2,bnum2);
		}else if(num2[1]=='b'){
			binToBin(num2,neg2,bnum2);
		}else if(num2[1]=='o'){
			octToBin(num2,neg2,bnum2);
		}else if(num2[1]=='x'){
			hexToBin(num2,neg2,bnum2);
		}else{
			fprintf(stderr, "Error: INVALID INPUT\n Please enter in Correct Format: OPERATION BASE-NUMBER1 BASE-NUMBER2 OUTPUT-BASE\n");
			return 0;
		}
	}else{
		if(num2[0]=='d'){
	          	decToBin(num2,neg2,bnum2);
		}else if(num2[0]=='b'){
			binToBin(num2,neg2,bnum2);
		}else if(num2[0]=='o'){
			octToBin(num2,neg2,bnum2);
		}else if(num2[0]=='x'){
			hexToBin(num2,neg2,bnum2);
		}else{
			fprintf(stderr, "Error: INVALID INPUT\n Please enter in Correct Format: OPERATION BASE-NUMBER1 BASE-NUMBER2 OUTPUT-BASE\n");
			return 0;
		}
	}	

	
	if(op[0]== '+'){
		if(neg1==0&&neg2==0){
			negfin='+';
		}else if(neg1==1&&neg2==1){
			negfin='-';
		}else{
			if(strcmp(bnum1->binRep,bnum2->binRep)<0){
				if(neg2==0){
					negfin='+';
				}else if(neg2==1){
					negfin='-';
				}
				
			}else{
			
				if(neg1==0){
					negfin='+';
				}else if(neg1==1){
					negfin='-';
				}
			
			}
		}
		

		sol=add(bnum1,bnum2,neg1,neg2);
		output(sol,negfin,base);
	}else if(op[0]== '-'){
		if(neg2==1){
			neg2=0;
		}else if(neg2==0){
			neg2=1;
		}
		if(neg1==0&&neg2==0){
			negfin='+';
		}else if(neg1==1&&neg2==1){
			negfin='-';
		}else{
			if(strcmp(bnum1->binRep,bnum2->binRep)<0){
				negfin=neg2+48;
			}else{
				negfin=neg1+48;
			}
		}
		sol = add(bnum1,bnum2,neg1,neg2);
		output(sol,negfin,base);
	}else{
		fprintf(stderr,"Error: Enter correct operator\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
