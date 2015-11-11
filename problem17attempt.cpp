#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;
int main()
{
	int one		=	3;
	int two		=	3;
	int three	=	5;
	int four	=	4;
	int five	=	4;
	int six		=	3;
	int seven	=	5;
	int eight	=	5;
	int nine	=	4;
	int ten		=	3;
	int eleven	=	6;
	int twelve	=	6;
	int thirteen	=	8;
	int fourteen	=	8;
	int fifteen	=	7;
	int sixteen	=	7;
	int seventeen	=	9;
	int eighteen	=	8;
	int nineteen	=	8;
	int twenty	=	6;
	int thirty	=	6;
	int forty	=	5;
	int fifty	=	5;
	int sixty	=	5;
	int seventy	=	7;
	int eighty	=	6;
	int ninety	=	6;
	int hundred	=	7;
	int thousand	=	8;
	
	int onesplace=one+two+three+four+five+six+seven+eight+nine;
	int teens=ten+eleven+twelve+thirteen+fourteen+fifteen+sixteen+seventeen+eighteen+nineteen;
	int upto1hundred = 9*onesplace+teens+twenty+thirty+forty+fifty+sixty+seventy+eighty+ninety;
	int total= upto1hundred*10+hundred+thousand+onesplace;
	printf("%i\n",total);
}
