/* 




------- Git -----------------
cd existing_folder
git init
git remote add origin git@gitlab.com:adammajewski/wake_gmp.git
git add .
git commit -m ""
git push -u origin master
-------------------------------





?? http://stackoverflow.com/questions/2380415/how-to-cut-a-mpz-t-into-two-parts-using-gmp-lib-on-c



   
   to compile from console:
   gcc w.c -lgmp -lmpfr -Wall

    to run from console : 

   ./a.out

   tested on Ubuntu 14.04 LTS


uiIADenominator = 89 
Using MPFR-3.1.2-p3 with GMP-5.1.3 with precision = 200 bits 
internal angle = 34/89
first external angle : 
period = denominator of internal angle = 89
external angle as a decimal fraction = 179622968672387565806504265/618970019642690137449562111 = 179622968672387565806504265 /( 2^89 - 1) 
External Angle as a floating point decimal number =  2.9019655713870868535821260055542440298749779423213948304299730531995503353103626302473331181359966368582651105245850405837027542373052381532777325121338632071561064451614697645709384232759475708007812e-1
external angle as a binary rational (string) : 1001010010010100101001001010010010100101001001010010100100101001001010010100100101001001/11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 
external angle as a binary floating number in exponential form =0.10010100100101001010010010100100101001010010010100101001001010010010100101001001010010010100101001001010010100100101001001010010100100101001010010010100100101001010010010100100101001010010010100101001*2^-1
external angle as a binary floating number in periodic form =0.(01001010010010100101001001010010010100101001001010010100100101001001010010100100101001001)

                                                             .(01001010010010100101001001010010010100101001001010010100100101001001010010100100101001001)

*/




#include <stdlib.h> // malloc
#include <stdio.h>
#include <gmp.h>  // for rational numbers 
#include <mpfr.h> // for floating point mumbers





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
          //gmp_printf("s = 1");

           }
        // else gmp_printf("s = 0");
       //gmp_printf (" i = %ld internal angle = %Zd / %Zd ea = %Zd / %Zd ; m = %Zd \n", i, n, d, num, den, m);    

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

/*


http://stackoverflow.com/questions/9895216/remove-character-from-string-in-c

"The idea is to keep a separate read and write pointers (pr for reading and pw for writing), 
always advance the reading pointer, and advance the writing pointer only when it's not pointing to a given character."

modified 



 remove first length2rmv chars and after that take only length2stay chars from input string
 output = input string 
*/
void extract_str(char* str, unsigned int length2rmv, unsigned long int length2stay) {
    // separate read and write pointers 
    char *pr = str; // read pointer
    char *pw = str; // write pointer
    int i =0; // index

    while (*pr) {
        if (i>length2rmv-1 && i <length2rmv+length2stay)
          pw += 1; // advance the writing pointer only when 
        pr += 1;  // always advance the reading pointer
        *pw = *pr;    
        i +=1;
    }
    *pw = '\0';
}



int main ()
{	

	

         // notation : 
        //number type : s = string ; q = rational ; z = integer, f = floating point
        // base : b = binary ; d = decimal 


        
        char *sqdInternalAngle = "13/34";
        mpq_t qdInternalAngle;   // internal angle = rational number q = n/d
        mpz_t den;  
        unsigned long int uiIADenominator;
        
       
        mpq_t  qdExternalAngle;   // rational number q = n/d
        char  *sqbExternalAngle;
        mpfr_t  fdExternalAngle ;  // 
        char  *sfbExternalAngle; // 
        
        mp_exp_t exponent ; // holds the exponent for the result string
        mpz_t zdEANumerator;
        mpz_t zdEADenominator;
        mpfr_t EANumerator;
        mpfr_t EADenominator;
        mpfr_prec_t p = 200; // in bits , should be > denominator of internal angle 
        
    

         mpfr_set_default_prec (p); // but previously initialized variables are unaffected.
        //mpfr_set_default_prec (precision);

        // init variables 
        //mpf_init(fdExternalAngle);
        mpz_inits(den, zdEANumerator,zdEADenominator, NULL);
        mpq_inits (qdExternalAngle, qdInternalAngle, NULL); //
        mpfr_inits(fdExternalAngle, EANumerator, EADenominator, NULL);
        

        // set variables
        mpq_set_str(qdInternalAngle, sqdInternalAngle, 10); // string is an internal angle
        mpq_canonicalize (qdInternalAngle); // It is the responsibility of the user to canonicalize the assigned variable before any arithmetic operations are performed on that variable.
        mpq_get_den(den,qdInternalAngle); 
        uiIADenominator = mpz_get_ui(den);
        printf("uiIADenominator = %lu \n", uiIADenominator);
        

        if ( p < uiIADenominator) printf("increase precision !!!!\n");         
        mpfr_printf("Using MPFR-%s with GMP-%s with precision = %u bits \n", mpfr_version, gmp_version, (unsigned int) p);






        //        
        mpq_wake(qdExternalAngle, qdInternalAngle); // internal -> external 
        

  


        mpq_get_num(zdEANumerator  ,qdExternalAngle);
        mpq_get_den(zdEADenominator,qdExternalAngle); 
        // conversions
        mpfr_set_z (EANumerator,   zdEANumerator,   GMP_RNDN);
        mpfr_set_z (EADenominator, zdEADenominator, GMP_RNDN);

        

        sqbExternalAngle = mpq_get_str (NULL, 2, qdExternalAngle); // rational number = fraction : from decimal to binary
        
        mpfr_div (fdExternalAngle, EANumerator, EADenominator, GMP_RNDN);
        
        
        
        


        sfbExternalAngle = (char*)malloc((sizeof(char) * uiIADenominator*2*4) + 3);
        // mpfr_get_str (char *str, mpfr_exp_t *expptr, int b, size_t n, mpfr_t op, mpfr_rnd_t rnd)
        if (sfbExternalAngle==NULL ) {printf("sfbExternalAngle error \n"); return 1;}
        mpfr_get_str(sfbExternalAngle, &exponent, 2,200, fdExternalAngle, GMP_RNDN);

        // print
        gmp_printf ("internal angle = %Qd\n", qdInternalAngle); // 
        printf("first external angle : \n");
        gmp_printf ("period = denominator of internal angle = %Zd\n", den); // 

        gmp_printf ("external angle as a decimal fraction = %Qd = %Zd /( 2^%Zd - 1) \n", qdExternalAngle, zdEANumerator, den); // 
        printf ("External Angle as a floating point decimal number =  ");
        mpfr_out_str (stdout, 10, p, fdExternalAngle, MPFR_RNDD); putchar ('\n');
        gmp_printf ("external angle as a binary rational (string) : %s \n", sqbExternalAngle); // 
        
        printf ("external angle as a binary floating number in exponential form =0.%s*%d^%ld\n", sfbExternalAngle, 2, exponent); 
        extract_str(sfbExternalAngle,  uiIADenominator+exponent, uiIADenominator); 
        printf ("external angle as a binary floating number in periodic form =0.(%s)\n", sfbExternalAngle); 
       



         


        // clear memory
        //mpf_clear(fdExternalAngle);
        mpq_clears(qdExternalAngle, qdInternalAngle, NULL);
        mpz_clears(den, zdEANumerator, zdEADenominator, NULL);
        mpfr_clears(fdExternalAngle, EANumerator, EADenominator, NULL);
        free(sfbExternalAngle);        

        return 0;
}

