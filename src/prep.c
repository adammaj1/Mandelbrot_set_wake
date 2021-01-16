/*

gcc prep.c -Wall
./a.out

----------
~/c/string/shift/preper/p5




======================

p/q = 2/5	b=3

(01001)	 lower wake = S-
01001(01010)
01001(10010)
01001(10100)
01010(00101)
01010(01001)
(01010)	 = S+ = higher wake 

========================
p/q = 1/4	b=1

(0001)	 lower wake = S-
0001(0010)
0001(0100)
0001(1000)
0010(0001)
(0010)	 = S+ = higher wake 

===================




*/

#define _GNU_SOURCE // asprintf
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen 



 
/*
C substring function: It returns a pointer to the substring 
https://www.programmingsimplified.com/c/source-code/c-substring
C substring program using pointers
To find substring we create a substring function which returns a pointer to string. String address, required length of substring and position from where to extract substring are the three arguments passed to function.


*/
 
char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;
 
   pointer = malloc(length+1); // remember to free
   
   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }

 
   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);      
      string++;  
   }
 
   *(pointer+c) = '\0';
 
   return pointer;
}


// shifting N places left
char *LeftShift(char *sIn, int n){

	// lengthIn = length1+length2
	int lengthIn= strlen(sIn);
	int length1 = n;
	int length2 = lengthIn - n+1 ;
	
	
	// sIn = s1s2 
	char *s1 = substring(sIn,1, length1); 
    	char *s2 = substring(sIn,n+1, length2 ); 
    	//
    	//printf("s1\t %s\n", s1);
 	//printf("s2\t %s\n", s2);
    	
    	// sOut = shift(sIn, n) = s2s1
    	char *sOut = ""; 
    	//int lengthOut = 
    	asprintf(&sOut, "%s%s", s2, s1);
    	

	return sOut; 


} 


/* 

find q angles of rays landing on the Misiurewicz point of the wake p/q
input wake :
- wake angle p/q
- denominator of lower Farey parent of p/q
- angles : sM sPer

*/
int MisiurewiczAngles(int p, int q, int b, char *sM, char *sP){

	// sOut = sOutPre(sOutPer)
    	char *sPre ; // setting for the first ray
    	char *sPer ; 
    	// 
	 
	int n;
	int j;
	
	printf("p/q = %d/%d\tb=%d\n\n", p, q, b); // input 
	printf("(%s)\t lower wake = S-\n", sM); // lower wake = (S-)
	//
	printf("%s(%s)\n",sM, sP); // angle of the first MIsiurewicz ray
	
	//
	 
	for (j = 1; j< q-1; j++){ // there are q rays ( from 0 to q-1), first and last rays are out the loop 
		
		n = (j*b) % q;
		
		
		// sPre
		if (j< q-p) 
			{ sPre = sM;}
			else { sPre = sP;}
		//	
		sPer = LeftShift(sP,n);
		// sOut
		printf("%s(%s)\n",sPre, sPer ); 
	
	}
	
	
	printf("%s(%s)\n",sP, sM); // angle of the last (q-1) Misiurewicz ray
	
	printf("(%s)\t = S+ = higher wake \n", sP); //
	
	return 0;	



}


// =========================================================== 
int main(){

	
	// p/q 
	int p = 1;
	int q = 4;
	
	// denomintor of smaller farey parent of p/q 
	// step n of the shift map : n = n + dn; dn < length; it is also remainder of  div (n , Length);
	int b = 1;
	
	//   = angles of 2 wake rays 
	char *sM = "0001"; // - = smaller 
    	char *sP = "0010"; // + = higher
    	
    	
    	MisiurewiczAngles(p,q,b,sM,sP);
    	
   	return 0;
   	
}

