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
   unsigned long long int j, s = 0; 


      
   for (j = 1; j < d; j++)
   {  s -= n; 
      if (s < 0) s += d; 
      if (!s) return 0LL; // ?
      if (s > d - n) 
            num += f << j; // The result is equivalent to multiplying the integer by a power of two.
   }
   return num;
   
}

void mpq_wake_str(mpq_t rop, char *str, int base )
{
   mpq_t q;   // internal angle = rational number q = n/d
  // arbitrary precision variables from GMP library
   mpz_t  n ; // numerator of q
   mpz_t  d ; // denominator of q


   mpz_t  num ; // numerator of rop
   mpz_t  den ; // denominator of rop
   unsigned long int id;
   unsigned long int in;
   unsigned long int inum;
   unsigned long int b = 2;


   mpz_inits(n,d,num,den,NULL);  

   // q
   mpq_init (q); //
   mpq_set_str(q, str, base);
  
   mpq_get_num(n,q);
   mpq_get_den(d,q);
   //  if (n <= 0 || n >= n ) error !!!!
   mpq_canonicalize (q); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable. 
   id = mpz_get_ui(d);
   in = mpz_get_ui(n);
   

   


    // rop  
    // num = numerator(rop)
    inum = GiveNum(in, id);
    mpz_set_ui(num, inum);
   // denominator = den(rop) = (2^i) -1 
   mpz_ui_pow_ui(den, b, id) ;  // den = b^i
   mpz_sub_ui(den, den, 1);   // den = den-1
   // rop = external angle 
   mpq_set_num(rop,num);
   mpq_set_den(rop,den);
   mpq_canonicalize (rop); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable. 


   //
   gmp_printf ("internal angle = %Qd\n",q); // 
   gmp_printf ("external angle = %Qd\n",rop); // 

    
   // clear memory
   mpq_clear (q);
   mpz_clears(n, d, num,den,  NULL);

}




int main ()
{
        
        
       
        
        mpq_t q;   // rational number q = n/d
        
        

        // init and set variables 
         mpq_init (q); //
         mpq_wake_str(q,"4/5",10);   
       
        
       
        


         
       
        
        
        // clear memory
        mpq_clear (q);
        
        
        
        return 0;
}

