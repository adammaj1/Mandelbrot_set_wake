/*
gcc f.c -Wall
./a.out


Farey parents of p/q
---------------------------------------
 Suppose a/b and c/d 
 
 0< a/b < c/d < 1 
 
 are the Farey parents of p/q
 
 find a/b and c/d 
 
 https://mathr.co.uk/blog/2016-10-31_finding_parents_in_the_farey_tree.html
 
 farey_addition( a/b ; c/d ) = (a+c)/(b+d) = p/q
 so 
 p = a+c
 q = b+d
 
 find a,b,c,d such:
 p = a+c
 q = b+d
 0< a/b < p/q < c/d < 1 
 
 
 
 
 
 
 
if one knows one parent then the second parent can be found by undoing the Farey addition
a = p-c
b = q-d  


================== tests ========================================
1/4294967295 > INT_MAX = 2 147 483 647  so gives input error 
Farey parents (1/2147483647) = 0/1  and  1/2147483646		0/1 < 1/2147483647 < 1/2147483646 	0.000000 < 0.0000000004656613 < 0.0000000004656613
Farey parents (1/100) = 0/1  and  1/99				0/1 < 1/100 < 1/99 	 		0.000000 < 0.010000 < 0.010101 
Farey parents (3/100) = 2/67  and  1/33				2/67 < 3/100 < 1/33 	 		0.029851 < 0.030000 < 0.030303 
Farey parents (1/31) = 0/1  and  1/30				0/1 < 1/31 < 1/30 	 		0.0000000000000000 < 0.0322580645161290 < 0.0333333333333333 

Farey parents (1/3) = 0/1  and  1/2				0/1 < 1/3 < 1/2 	 		0.000000 < 0.333333 < 0.500000 
Farey parents (3/8) = 1/3  and  2/5				1/3 < 3/8 < 2/5 	 		0.333333 < 0.375000 < 0.400000 
Farey parents (2/5) = 1/3  and  1/2				1/3 < 2/5 < 1/2 	 		0.333333 < 0.400000 < 0.500000 
Farey parents (1/2) = 0/1  and  1/1				0/1 < 1/2 < 1/1 	 		0.000000 < 0.500000 < 1.000000 
Farey parents (2/3) = 1/2  and  1/1				1/2 < 2/3 < 1/1 	 		0.5000000000000000 < 0.6666666666666666 < 1.0000000000000000 
Farey parents (3/4) = 2/3  and  1/1				2/3 < 3/4 < 1/1 	 		0.666667 < 0.750000 < 1.000000 

Farey parents (1/2) = 0/1  and  1/1		0/1 < 1/2 < 1/1 	 0.0000000000000000 < 0.5000000000000000 < 1.0000000000000000 
Farey parents (1/3) = 0/1  and  1/2		0/1 < 1/3 < 1/2 	 0.0000000000000000 < 0.3333333333333333 < 0.5000000000000000 
Farey parents (2/3) = 1/2  and  1/1		1/2 < 2/3 < 1/1 	 0.5000000000000000 < 0.6666666666666666 < 1.0000000000000000 
Farey parents (1/4) = 0/1  and  1/3		0/1 < 1/4 < 1/3 	 0.0000000000000000 < 0.2500000000000000 < 0.3333333333333333 
Farey parents (3/4) = 2/3  and  1/1		2/3 < 3/4 < 1/1 	 0.6666666666666666 < 0.7500000000000000 < 1.0000000000000000 
Farey parents (1/5) = 0/1  and  1/4		0/1 < 1/5 < 1/4 	 0.0000000000000000 < 0.2000000000000000 < 0.2500000000000000 
Farey parents (2/5) = 1/3  and  1/2		1/3 < 2/5 < 1/2 	 0.3333333333333333 < 0.4000000000000000 < 0.5000000000000000 
Farey parents (3/5) = 1/2  and  2/3		1/2 < 3/5 < 2/3 	 0.5000000000000000 < 0.6000000000000000 < 0.6666666666666666 
Farey parents (4/5) = 3/4  and  1/1		3/4 < 4/5 < 1/1 	 0.7500000000000000 < 0.8000000000000000 < 1.0000000000000000 
Farey parents (1/6) = 0/1  and  1/5		0/1 < 1/6 < 1/5 	 0.0000000000000000 < 0.1666666666666667 < 0.2000000000000000 
Farey parents (5/6) = 4/5  and  1/1		4/5 < 5/6 < 1/1 	 0.8000000000000000 < 0.8333333333333334 < 1.0000000000000000 
Farey parents (1/7) = 0/1  and  1/6		0/1 < 1/7 < 1/6 	 0.0000000000000000 < 0.1428571428571428 < 0.1666666666666667 
Farey parents (2/7) = 1/4  and  1/3		1/4 < 2/7 < 1/3 	 0.2500000000000000 < 0.2857142857142857 < 0.3333333333333333 
Farey parents (3/7) = 2/5  and  1/2		2/5 < 3/7 < 1/2 	 0.4000000000000000 < 0.4285714285714285 < 0.5000000000000000 
Farey parents (4/7) = 1/2  and  3/5		1/2 < 4/7 < 3/5 	 0.5000000000000000 < 0.5714285714285714 < 0.6000000000000000 
Farey parents (5/7) = 2/3  and  3/4		2/3 < 5/7 < 3/4 	 0.6666666666666666 < 0.7142857142857143 < 0.7500000000000000 
Farey parents (6/7) = 5/6  and  1/1		5/6 < 6/7 < 1/1 	 0.8333333333333334 < 0.8571428571428571 < 1.0000000000000000 
Farey parents (1/8) = 0/1  and  1/7		0/1 < 1/8 < 1/7 	 0.0000000000000000 < 0.1250000000000000 < 0.1428571428571428 
Farey parents (3/8) = 1/3  and  2/5		1/3 < 3/8 < 2/5 	 0.3333333333333333 < 0.3750000000000000 < 0.4000000000000000 
Farey parents (5/8) = 3/5  and  2/3		3/5 < 5/8 < 2/3 	 0.6000000000000000 < 0.6250000000000000 < 0.6666666666666666 
Farey parents (7/8) = 6/7  and  1/1		6/7 < 7/8 < 1/1 	 0.8571428571428571 < 0.8750000000000000 < 1.0000000000000000 
Farey parents (1/9) = 0/1  and  1/8		0/1 < 1/9 < 1/8 	 0.0000000000000000 < 0.1111111111111111 < 0.1250000000000000 
Farey parents (2/9) = 1/5  and  1/4		1/5 < 2/9 < 1/4 	 0.2000000000000000 < 0.2222222222222222 < 0.2500000000000000 
Farey parents (4/9) = 3/7  and  1/2		3/7 < 4/9 < 1/2 	 0.4285714285714285 < 0.4444444444444444 < 0.5000000000000000 
Farey parents (5/9) = 1/2  and  4/7		1/2 < 5/9 < 4/7 	 0.5000000000000000 < 0.5555555555555556 < 0.5714285714285714 
Farey parents (7/9) = 3/4  and  4/5		3/4 < 7/9 < 4/5 	 0.7500000000000000 < 0.7777777777777778 < 0.8000000000000000 
Farey parents (8/9) = 7/8  and  1/1		7/8 < 8/9 < 1/1 	 0.8750000000000000 < 0.8888888888888888 < 1.0000000000000000 
Farey parents (1/10) = 0/1  and  1/9		0/1 < 1/10 < 1/9 	 0.0000000000000000 < 0.1000000000000000 < 0.1111111111111111 
Farey parents (3/10) = 2/7  and  1/3		2/7 < 3/10 < 1/3 	 0.2857142857142857 < 0.3000000000000000 < 0.3333333333333333 
Farey parents (7/10) = 2/3  and  5/7		2/3 < 7/10 < 5/7 	 0.6666666666666666 < 0.7000000000000000 < 0.7142857142857143 
Farey parents (9/10) = 8/9  and  1/1		8/9 < 9/10 < 1/1 	 0.8888888888888888 < 0.9000000000000000 < 1.0000000000000000 





*/

#include <stdio.h>
#include <stdlib.h> // abs


/*
 C function for extended Euclidean Algorithm 
 https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
 
 
*/ 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 



//Swap function definition
void swap(int *a, int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}


//Swap function definition
void swap_d(double *a, double *b)
{
   double t;
 
   t  = *b;
   *b = *a;
   *a = t;
}





/* 
print ordered list of farey fractions :  
0< a/b < p/q < c/d < 1  
*/
int print_farey(int a, int b, int p, int q, int c, int d){


	
	double p1 = (double)a/b; // floating point value of first parent
	double child = (double)p/q;
	double p2 = (double)c/d;
	
	printf("Farey parents (%d/%d) = %d/%d  and  %d/%d\t\t", p,q,a,b, c,d);
	printf("%d/%d < %d/%d < %d/%d \t", a,b, p,q,c,d); // ordered fractions
	printf(" %.16f < %.16f < %.16f \n", p1, child, p2);// ordered floating point values 	
	return 0;

}


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





int FareyParents( int p, int q){


	// check the input 
	if (p<0 || q< 0 || p>=q ) {
	
		printf("FareyParents error :  bad input\n ");
		return - 1;
	
	}
	
	// reduction to the lowest terms
	int g = gcd(p,q);
	if (g>1) { //  a fraction a⁄b is irreducible if and only if a and b are coprime, that is, if a and b have a greatest common divisor of 1.
		// printf("reduction to the lowest terms \n");
		p /= g;
		q /= g;
	
	}
	
	// first parent a/b
	int a;
	int b;
	double p1; // = (double)a/b;
	
	//second parent 
	int c;
	int d;
	double p2; //  = (double)c/d;
	
	
	// compute first parent 
	gcdExtended(p,q,&d,&c); // https://mathr.co.uk/blog/2016-10-31_finding_parents_in_the_farey_tree.html
	// result can be negative 
	c = abs(c);
	d = abs(d);
	p2 = (double)c/d;
	
	
	
	// second parent by undoing the Farey addition
	a = p-c;
	b = q-d; 
	p1 = (double)a/b;
	
	// check the order
	if( p1> p2){//bad order
		
		swap(&a, &c); // swap numerators
		swap(&b, &d); // swap denominators
		//
		swap_d(&p1,&p2);	
		
		} 
	
	print_farey( a,  b,  p,  q,  c, d); //  0< a/b < p/q < c/d < 1 
	
	return b; // return denoiminator of smaller parent
	
	
	

}

int FindFareyParentsUpTo(int qMax){

	// p/q = Farey child
	int p ;
	int q ; // 4294967295> (INT_MAX = 2 147 483 647) so gives error  
	//int qMax = 100;  
	
	
	
	// and smaller mutually and externally tangent circles 
 	// n/d = local angle in turns
 	for (q = 2; q <= qMax; ++q )
   		for (p = 1; p < q; ++p ){
     			if (gcd(p,q)==1 )// irreducible fraction
				{FareyParents(p,q); }}
	return 0;

}


int main ()
{
	
	// FareyParents(1,3); // find for one p/q
	FindFareyParentsUpTo(10); // find for many p/q values
	
	return 0;
}
