/* 


 
This is not official program by W Jung,
but it usess his code ( I hope in a good way)
   These functions are part of Mandel 5.9 by Wolf Jung (C) 2007-2013,
   which is free software; you can
   redistribute and / or modify them under the terms of the GNU General
   Public License as published by the Free Software Foundation; either
   version 3, or (at your option) any later version. In short: there is
   no warranty of any kind; you must redistribute the source code as well.
   
   http://www.mndynamics.com/indexp.html

------- Git -----------------
cd existing_folder
git init
git remote add origin git@gitlab.com:adammajewski/wake_gmp.git
git add .
git commit -m ""
git push -u origin master
-------------------------------









   
   to compile from console:
   gcc w.c -lgmp -Wall

    to run from console : 

   ./a.out

   tested on Ubuntu 14.04 LTS


*/





#include <stdio.h>
#include <gmp.h>





/*

"Consider the example of 3/7. Label the components counterclockwise from
0 to 6. The critical value is in position 3, and the number is always
increased by 3 modulo 7.  This gives  3625140.  Now the next to last
component 4 contains the angle 1/2,  so it is separating the digits 0
and 1.  The algorithm says that positions <= 4 have digit 0 and numbers
0 or > 4 have digit 1:
3625140
0101001
So it is 41/127.  The first angle is always ending on 01 and the second
angle is 1 more, so ending on 10.

Note the number of the next-to-last position can be computed directly as
7 - 3 = 4.

In the implementation I have done the same thing with iterating
backwards for some reason ..."

"The algorithm is probably well-known,  maybe it is in Bruin-Schleicher or
in Douady angles ... or if no one has written it down,  certainly many people
have found it by drawing the petals and numbering them ..."

Comments by Wolf Jung

 



 type qulonglong  = unsigned long long int 
 n is a numerator of external angle that land on root point of the wake k/r
 d is a denominator 
 funcion mndAngle::wake from mndcombi.cpp  by Wolf Jung (C) 2007-2013

unsigned long long int wake(int k, int r, unsigned long long int  &n)
{  
   if (k <= 0 || k >= r || r > 64) return 0LL; // 
   unsigned long long int  d = 1LL; int j, s = 0; n = 1LL;
   
   for (j = 1; j < r; j++)
   {  s -= k; 
      if (s < 0) s += r;  // https://zasobygwp.pl/redirect?sig=20cc5fd3596d87ac6c59f59c2e45e2cf0c8dc92c4a9d5796d2f010036d98632d&url=aHR0cDovL3N0YWNrb3ZlcmZsb3cuY29tL3F1ZXN0aW9ucy8xMTE0MDkzNS9jaGVjay1pZi11bnNpZ25lZC1pcy1sZXNzLXRoYW4temVybw==
      if (!s) return 0LL;
      if (s > r - k) n += d << j;
   }
   d <<= (r - 1); 
   d--; 
   d <<= 1; 
   d++; //2^r - 1 for r <= 64
   
   return d;
}



mndcombi.cpp  by Wolf Jung (C) 2007-2015.   part of Mandel 5.13

qulonglong mndAngle::wake(int k, int r, qulonglong &n)
{  //bonds check for int type
   if (k <= 0 || k >= r || r > 64) return 0LL;

   // n 
   qulonglong d = 1LL; 
   int j, s = 0; n = 1LL;
   for (j = 1; j < r; j++)
   {  s -= k; if (s < 0) s += r; if (!s) return 0LL;
      if (s > r - k) n += d << j;
   }

   // d = 
   d <<= (r - 1); 
   d--; 
   d <<= 1; 
   d++; //2^r - 1 for r <= 64
   return d;
}



 ULLONG_MAX
*/


// input internal angle in turns = n/d
// output = numerator of external angle = num
unsigned long long int GiveNum(unsigned long long int n, unsigned long long int d)
{  
   unsigned long long int num = 1LL;
   unsigned long long int  f = 1LL; 
   long long int j, s = 0; 


      
   for (j = 1; j < d; j++)
   {  s -= n; 
      if (s < 0) s += d; 
      if (!s) return 0LL; // ?
      if (s > d - n) 
            num += f << j; // The result is equivalent to multiplying the integer by a power of two.
   }
   return num;
   
}


 // rotation map 
//the number  n  is always increased by n0 modulo d

// input :  op = n/d ( rational number ) and n0 ( integer)
//  n = (n + n0 ) % d
// d = d
// output = rop = n/d
void mpq_rotation(mpq_t rop, const mpq_t op, const mpz_t n0)
{
  
  mpz_t n; // numerator
  mpz_t d; // denominator
  mpz_inits( n, d, NULL);

 
  //  
  mpq_get_num (n, op); // 
  mpq_get_den (d, op);
  
 
  // n = (n + n0 ) % d
  mpz_add(n, n, n0); 
  mpz_mod( n, n, d);
  
      
  // output
  mpq_set_num(rop, n);
  mpq_set_den(rop, d);
    
  mpz_clears( n, d, NULL);


}


void mpq_wake(mpq_t rop, mpq_t op)
{
   
  // arbitrary precision variables from GMP library
   mpz_t  n0 ; // numerator of q
   mpz_t  nc;
   mpz_t  n;
   mpz_t  d ; // denominator of q
   mpz_t  m; // 2^i

   mpz_t  num ; // numerator of rop
   mpz_t  den ; // denominator of rop
   long long int i;
   unsigned long int base = 2;
   unsigned long int id;
   int cmp; 

   mpz_inits(n, n0,nc,d,num,den,m, NULL);  


   mpq_get_num(n0,op);
   mpq_get_den(d,op);
   id = mpz_get_ui(d);
   //  if (n <= 0 || n >= d ) error !!!! bad input
   mpz_sub(nc, d, n0); // nc = d - n0
   mpz_set(n, n0);   
   mpz_set_ui(num, 0);
  


   // rop  
    // num = numerator(rop)
    
   
   // denominator = den(rop) = (2^i) -1 
   mpz_ui_pow_ui(den, base, id) ;  // den = base^id
   mpz_sub_ui(den, den, 1);   // den = den-1
   
  // numerator   
     for (i=0; i<id ; i++){  
       
       mpz_set_ui(m, 0);
       cmp = mpz_cmp(n,nc);// Compare op1 and op2. Return a positive value if op1 > op2, zero if op1 = op2, or a negative value if op1 < op2.
       if ( cmp>0 ) {
          mpz_ui_pow_ui(m, 2, id-i-1); // m = 2^(id-i   )
          mpz_add(num, num, m); // num = num + m
          if (mpz_cmp(num, den) >0) mpz_mod( num, num, den); // num = num % d ; if num==d gives 0
          gmp_printf("s = 1");

           }
         else gmp_printf("s = 0");
       gmp_printf (" i = %ld internal angle = %Zd / %Zd ea = %Zd / %Zd ; m = %Zd \n", i, n, d, num, den, m);    

        // n = (n + n0 ) % d = rotation 
       mpz_add(n, n, n0); 
       if (mpz_cmp(n, d)>0) mpz_mod( n, n, d);
       //
       
          
        // 
      }

   


    
   // rop = external angle 
   mpq_set_num(rop,num);
   mpq_set_den(rop,den);
   mpq_canonicalize (rop); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable. 


   

    
   // clear memory
   mpz_clears(n, n0, nc, d, num,den, m, NULL);

}




int main ()
{
        
        
       
        mpq_t  qExternalAngle;   // rational number q = n/d
        char  *sExternalAngle;

        int base = 10;
        char *sIntenalAngle = "13/34";
        mpq_t qInternalAngle;   // internal angle = rational number q = n/d
        mpz_t den;  
    

        // init variables 
        mpz_init(den);
        mpq_inits (qExternalAngle, qInternalAngle, NULL); //

        // set variables
        mpq_set_str(qInternalAngle, sIntenalAngle, base); // string is an internal angle
        mpq_canonicalize (qInternalAngle); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable.
        mpq_get_den(den,qInternalAngle); 
        
        mpq_wake(qExternalAngle, qInternalAngle); // internal -> external    
       // convertions
        sExternalAngle = mpq_get_str (NULL, 2, qExternalAngle); // rational number = fraction : from decimal to binary
        
        
        // print
        gmp_printf ("internal angle = %Qd\n", qInternalAngle); // 
        gmp_printf ("period = denominator of internal angle = %Zd\n", den); // 
        gmp_printf ("external angle as a decimal fraction = %Qd\n", qExternalAngle); // 
        gmp_printf ("external angle as a binary rational (string) : %s \n", sExternalAngle); // 
   
        
        // clear memory
        mpq_clears(qExternalAngle, qInternalAngle, NULL);
        mpz_clear(den);
        
        
        return 0;
}

