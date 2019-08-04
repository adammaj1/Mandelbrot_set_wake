/*
gcc f.c -Wall
./a.out
./a.out >fp30.txt


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
==========================


{1 , 2 , 1},
{1 , 3 , 1},
{2 , 3 , 2},
{1 , 4 , 1},
{3 , 4 , 3},
{1 , 5 , 1},
{2 , 5 , 3},
{3 , 5 , 2},
{4 , 5 , 4},
{1 , 6 , 1},
{5 , 6 , 5},
{1 , 7 , 1},
{2 , 7 , 4},
{3 , 7 , 5},
{4 , 7 , 2},
{5 , 7 , 3},
{6 , 7 , 6},
{1 , 8 , 1},
{3 , 8 , 3},
{5 , 8 , 5},
{7 , 8 , 7},
{1 , 9 , 1},
{2 , 9 , 5},
{4 , 9 , 7},
{5 , 9 , 2},
{7 , 9 , 4},
{8 , 9 , 8},
{1 , 10 , 1},
{3 , 10 , 7},
{7 , 10 , 3},
{9 , 10 , 9},





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


int print_farey_row(int p, int q, int b){

	printf("{%d , %d , %d},\n", p,q,b); // list for initializig the array 
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
	
	//print_farey( a,  b,  p,  q,  c, d); //  0< a/b < p/q < c/d < 1 
	print_farey_row(p,q,b); // 
	
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
	FindFareyParentsUpTo(30); // find for many p/q values
	
	return 0;
}
