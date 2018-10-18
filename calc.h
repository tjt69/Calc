#ifndef calc_h
#define calc_h

struct BinaryArr_ {

	char* binRep;
	struct	BinaryArr_* next;

};
typedef struct BinaryArr_ BinaryArr;

unsigned int decStoi(char* change,int isneg);
	
void  dToB(unsigned int dec,char* bin);

void decToBin(char* dec, int isNeg, BinaryArr* DecInBin);

void hexToBin(char* hex, int isNeg, BinaryArr* HexToBin);

void octToBin(char* oct, int isNeg, BinaryArr* OctInBin);

void binToBin(char* bin, int isNeg, BinaryArr* BinToBin);

void addbin(char* b1, char* b2, int neg1, int neg2, int carry,int lastNode1, int lastNode2);

void twoComp(char* orig, int islast,int carry);
	
BinaryArr* add(BinaryArr* b1, BinaryArr* b2, int neg1, int neg2);

unsigned int powd(unsigned int base, unsigned int exp);

void printbin(BinaryArr* bin);

void printdec(BinaryArr* dec,unsigned int total,unsigned int e);

void printoct(BinaryArr* oct, char* hold, int node);

void printhex(BinaryArr* hex);

void output(BinaryArr* solbin, char negfin, char* base);
	
#endif
