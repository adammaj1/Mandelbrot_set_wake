/*

c console program
checks n/d irreducebility

gcc i.c -Wall
./a.out


n/d = 1/2
n/d = 1/3
n/d = 2/3
n/d = 1/4
n/d = 3/4
n/d = 1/5
n/d = 2/5
n/d = 3/5
n/d = 4/5
n/d = 1/6
n/d = 5/6
n/d = 1/7
n/d = 2/7
n/d = 3/7
n/d = 4/7
n/d = 5/7
n/d = 6/7
n/d = 1/8
n/d = 3/8
n/d = 5/8
n/d = 7/8
n/d = 1/9
n/d = 2/9
n/d = 4/9
n/d = 5/9
n/d = 7/9
n/d = 8/9
n/d = 1/10
n/d = 3/10
n/d = 7/10
n/d = 9/10
n/d = 1/11
n/d = 2/11
n/d = 3/11
n/d = 4/11
n/d = 5/11
n/d = 6/11
n/d = 7/11
n/d = 8/11
n/d = 9/11
n/d = 10/11
n/d = 1/12
n/d = 5/12
n/d = 7/12
n/d = 11/12
n/d = 1/13
n/d = 2/13
n/d = 3/13
n/d = 4/13
n/d = 5/13
n/d = 6/13
n/d = 7/13
n/d = 8/13
n/d = 9/13
n/d = 10/13
n/d = 11/13
n/d = 12/13
n/d = 1/14
n/d = 3/14
n/d = 5/14
n/d = 9/14
n/d = 11/14
n/d = 13/14
n/d = 1/15
n/d = 2/15
n/d = 4/15
n/d = 7/15
n/d = 8/15
n/d = 11/15
n/d = 13/15
n/d = 14/15
n/d = 1/16
n/d = 3/16
n/d = 5/16
n/d = 7/16
n/d = 9/16
n/d = 11/16
n/d = 13/16
n/d = 15/16
n/d = 1/17
n/d = 2/17
n/d = 3/17
n/d = 4/17
n/d = 5/17
n/d = 6/17
n/d = 7/17
n/d = 8/17
n/d = 9/17
n/d = 10/17
n/d = 11/17
n/d = 12/17
n/d = 13/17
n/d = 14/17
n/d = 15/17
n/d = 16/17

*/

#include <stdio.h>

/*
https://stackoverflow.com/questions/19738919/gcd-function-for-c
The GCD function uses Euclid's Algorithm. 
It computes A mod B, then swaps A and B with an XOR swap.
*/

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}



int main (){

	// internal angle = n/m  in turns
	int n;  // numerator
	int d;  // denominator

 	int dMax = 17;  
     
 	 
 	
 	for (d = 2; d <= dMax; ++d )
   		for (n = 1; n < d; ++n )
     			if (gcd(n,d)==1 ){ 
     				     			
         			printf("n/d = %d/%d\n", n,d);	// irreducible fraction  
       			} 
   
	return 0;       
} 
   
