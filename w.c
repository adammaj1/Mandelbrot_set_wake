/* 




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

         // notation : 
        //number type : s = string ; q = rational ; z = integer, f = floating point
        // base : b = binary ; d = decimal 


        
        char *sqdInternalAngle = "1/7";
        mpq_t qdInternalAngle;   // internal angle = rational number q = n/d
        mpz_t den;  
        
       
        mpq_t  qdExternalAngle;   // rational number q = n/d
        char  *sqbExternalAngle;
        mpf_t  fd ;
        char  *sfb;
        mp_exp_t exponent ; // holds the exponent for the result string

       

        
    

        // init variables 
        mpf_init(fd);
        mpz_init(den);
        mpq_inits (qdExternalAngle, qdInternalAngle, NULL); //

        // set variables
        mpq_set_str(qdInternalAngle, sqdInternalAngle, 10); // string is an internal angle
        mpq_canonicalize (qdInternalAngle); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable.
        mpq_get_den(den,qdInternalAngle); 
        
        mpq_wake(qdExternalAngle, qdInternalAngle); // internal -> external 
        mpf_set_q(fd,qdExternalAngle); // qd -> fd


  
       // convertions
        sqbExternalAngle = mpq_get_str (NULL, 2, qdExternalAngle); // rational number = fraction : from decimal to binary
        
        
        sfb = mpf_get_str (NULL, &exponent, 2, 0, fd); // floating point number : from decimal fd to binary floating point string sfb
        //  If n_digits is 0 then that accurate maximum number of digits are generated. 



        // print
        gmp_printf ("internal angle = %Qd\n", qdInternalAngle); // 
        gmp_printf ("period = denominator of internal angle = %Zd\n", den); // 
        gmp_printf ("external angle as a decimal fraction = %Qd\n", qdExternalAngle); // 
        gmp_printf ("external angle as a binary rational (string) : %s \n", sqbExternalAngle); // 
        printf ("external angle as a binary floating number in exponential form =0.%s*%d^%ld\n", sfb, 2, exponent); 
        
        // clear memory
        mpf_clear(fd);
        mpq_clears(qdExternalAngle, qdInternalAngle, NULL);
        mpz_clear(den);
        
        
        return 0;
}

