/*

c console program

computes q angles of external rays landing on the principal Misiurewicz point 
of the wake p/q

https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/p_misiurewicz

input: 
* p/q
* b =  denomintor of smaller farey parent of p/q  =  step n of the shift map : n = n + dn; dn < length; it is also remainder of  div (n , Length);
* 2 angles of the wake p/q in the form of binary formatted strings of lentgh q:

Relation between input strings and angles of the wake:  
** sM -> 0.(sM) 
** sP -> 0.(sP)

output: 
* q angles of the principal Misiurewicz point of the wake p/q in the form of binary formatted strings



notes/ to do:
* wake angles can be computed from the p/q




===================================

gcc principal.c -Wall
./a.out
./a.out > p.txt

----------
~/c/string/shift/preper/p7




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

p/q = 1/31	b=1

(0000000000000000000000000000001)	 lower wake = S-
0000000000000000000000000000001(0000000000000000000000000000010)
0000000000000000000000000000001(0000000000000000000000000000100)
0000000000000000000000000000001(0000000000000000000000000001000)
0000000000000000000000000000001(0000000000000000000000000010000)
0000000000000000000000000000001(0000000000000000000000000100000)
0000000000000000000000000000001(0000000000000000000000001000000)
0000000000000000000000000000001(0000000000000000000000010000000)
0000000000000000000000000000001(0000000000000000000000100000000)
0000000000000000000000000000001(0000000000000000000001000000000)
0000000000000000000000000000001(0000000000000000000010000000000)
0000000000000000000000000000001(0000000000000000000100000000000)
0000000000000000000000000000001(0000000000000000001000000000000)
0000000000000000000000000000001(0000000000000000010000000000000)
0000000000000000000000000000001(0000000000000000100000000000000)
0000000000000000000000000000001(0000000000000001000000000000000)
0000000000000000000000000000001(0000000000000010000000000000000)
0000000000000000000000000000001(0000000000000100000000000000000)
0000000000000000000000000000001(0000000000001000000000000000000)
0000000000000000000000000000001(0000000000010000000000000000000)
0000000000000000000000000000001(0000000000100000000000000000000)
0000000000000000000000000000001(0000000001000000000000000000000)
0000000000000000000000000000001(0000000010000000000000000000000)
0000000000000000000000000000001(0000000100000000000000000000000)
0000000000000000000000000000001(0000001000000000000000000000000)
0000000000000000000000000000001(0000010000000000000000000000000)
0000000000000000000000000000001(0000100000000000000000000000000)
0000000000000000000000000000001(0001000000000000000000000000000)
0000000000000000000000000000001(0010000000000000000000000000000)
0000000000000000000000000000001(0100000000000000000000000000000)
0000000000000000000000000000001(1000000000000000000000000000000)
0000000000000000000000000000010(0000000000000000000000000000001)
(0000000000000000000000000000010)	 = S+ = higher wake 



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
    	asprintf(&sOut, "%s%s", s2, s1);
    	

	return sOut; 


} 


/* 

find q angles of rays landing on the principal Misiurewicz point of the wake p/q
https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/p_misiurewicz

input wake :
- wake angle p/q
- denominator of lower Farey parent of p/q
- angles : sM sPer

*/
int AnglesOfPrincipalMisiurewicz(int p, int q, int b, char *sM, char *sP){

	// sOut = sOutPre(sOutPer)
    	char *sPre ; // setting for the first ray
    	char *sPer ; 
    	// 
	 
	int n;
	int j;
	
	printf("p/q = %d/%d\tb=%d\n\n", p, q, b); // input 
	printf("(%s)\t lower wake = S-\n", sM); // lower wake = (S-)
	//
	printf("%s(%s)\n",sM, sP); // angle of the first Misiurewicz ray
	
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


// test if input is good
// 
int BadInput(int p, int q, int b, char *sM, char *sP ){

	if (	// length  of each string should be q
		strlen(sP) != q  || 
		strlen(sM) != q	 ||
		// only positive integers
		b<0 ||
		p<0 ||
		q<0 ||
		p>q // only proper fraction
		
		) { return 1;} 
	
	
	return 0; // OK

}


// =========================================================== 
int main(){

/* 

examples: 
  p q b sM   sP
  1 4 1 0001 0010
  1 31 1 0000000000000000000000000000001 0000000000000000000000000000010
 34 89 55  01001010010010100101001001010010010100101001001010010100100101001001010010100100101001001  	01001010010010100101001001010010010100101001001010010100100101001001010010100100101001010	
 
*/





	// p/q : p< q ; p>0 and q>0 
	int p = 34;
	int q = 89;
	
	// denomintor of smaller farey parent of p/q 
	// step n of the shift map : n = n + dn; dn < length; it is also remainder of  div (n , Length);
	int b = 55; // b < q
	
	//   = angles of 2 wake rays:  sM < sP 
	// length of each string = q
	char *sM = "01001010010010100101001001010010010100101001001010010100100101001001010010100100101001001"; // S- = smaller 
    	char *sP = "01001010010010100101001001010010010100101001001010010100100101001001010010100100101001010"; // S+ = higher
    	

	// check input 
	if (BadInput(p,q,b,sM,sP)) 
		{printf("bad input \n"); return 1;}
	//    	
    	AnglesOfPrincipalMisiurewicz(p,q,b,sM,sP);
    	
   	return 0;
   	
}

