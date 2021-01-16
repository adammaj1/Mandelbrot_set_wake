/* 


Algorithm
- ------------- start on the parameter plane -------------------
- internal angle ( rotation number) k/r = 1/r
- wake 1/r : angles of 2 external rays landig on the root point of the wake
- c = principal misiurewicz point  of the wake. It has a preperiod = r and  period = 1 
- angle = nm/dm of external angle  that land on the c (angle has preperiod = r, period = r ) = Mis

- ------------ switch to the dynamic plane -----------------
- dendritic Julia set for c
- external angle of the ray that land on the z= c ( critical value) =  nm/dm
- external angles : nz1/dz and nz2/dz of rays lanfin on the critical point zcr = 0











cpp program
- for console
- interactive ( reads from keybord )
- one file program
- multiplatform ( I hope (:-) )
- output is in console
- licence : 

   This is free software; you can
   redistribute and / or modify it under the terms of the GNU General
   Public License as published by the Free Software Foundation; either
   version 3, or (at your option) any later version. In short: there is
   no warranty of any kind; you must redistribute the source code as well."
   http://www.gnu.org/licenses/gpl.html

by Adam Majewski with help of Wolf Jung
fraktal.republika.pl ( www archive)
2010.10.27 - 2013.8.14 - now

open console,
go to directory where this file is,

to compile : 
g++ p.cpp -lm -Wall

to run :
./a.out

You will be asked to input two integers separately :
numerator and denominator of angle 

to quit ( only when problems) :
Ctrl-c



based on : 
   mndcombi.cpp  by Wolf Jung (C) 2010. 
   http://mndynamics.com/indexp.html 
   which is the part of Mandel 5.5 
   multiplatform C++ GUI program using QT 
   on the same licence as above 
  
---------------------- output ------------------------------------
k/r = 1/2	wake 1 ; 2/3			Mis 5/12				zcr 5 ; 17	/24						c -0.2281554936539618 ; 1.115142508039937
k/r = 1/3	wake 1 ; 2/7			Mis 9/56				zcr 9 ; 65	/112						c -0.1010963638456222 ; 0.9562865108091415
k/r = 1/4	wake 1 ; 2/15			Mis 17/240				zcr 17 ; 257	/480						c -0.01718797733835019 ; 1.037652343793215
k/r = 1/5	wake 1 ; 2/31			Mis 33/992				zcr 33 ; 1025	/1984						c -0.01660571692147523 ; 1.006001828834065
k/r = 1/6	wake 1 ; 2/63			Mis 65/4032				zcr 65 ; 4097	/8064						c 0.002241106093233115 ; 1.006987004324957
k/r = 1/7	wake 1 ; 2/127			Mis 129/16256				zcr 129 ; 16385	/32512						c -0.001369133815686842 ; 1.002755660363466
k/r = 1/8	wake 1 ; 2/255			Mis 257/65280				zcr 257 ; 65537	/130560						c 0.001159450074256577 ; 1.000609019839529
k/r = 1/9	wake 1 ; 2/511			Mis 513/261632				zcr 513 ; 262145	/523264					c 0.0001701882004481036 ; 1.000517331884371
k/r = 1/10	wake 1 ; 2/1023			Mis 1025/1047552			zcr 1025 ; 1048577	/2095104				c 0.0002217350415235168 ; 0.9999309294242422
k/r = 1/11	wake 1 ; 2/2047			Mis 2049/4192256			zcr 2049 ; 4194305	/8384512				c 8.600871635354104e-05 ; 1.000043520609493
k/r = 1/12	wake 1 ; 2/4095			Mis 4097/16773120			zcr 4097 ; 16777217	/33546240				c 1.907198794976112e-05 ; 0.9999636227152136
k/r = 1/13	wake 1 ; 2/8191			Mis 8193/67100672			zcr 8193 ; 67108865	/134201344				c 1.619607246569189e-05 ; 0.9999946863543573
k/r = 1/14	wake 1 ; 2/16383		Mis 16385/268419072			zcr 16385 ; 268435457	/536838144				c -2.164159763572468e-06 ; 0.9999930692712914
k/r = 1/15	wake 1 ; 2/32767		Mis 32769/1073709056			zcr 32769 ; 1073741825	/2147418112				c 1.36020585022823e-06 ; 0.9999973111035358
k/r = 1/16	wake 1 ; 2/65535		Mis 65537/4294901760			zcr 65537 ; 4294967297	/8589803520				c -1.136844998313359e-06 ; 0.9999994042152635
k/r = 1/17	wake 1 ; 2/131071		Mis 131073/17179738112			zcr 131073 ; 17179869185	/34359476224			c -1.660928890362016e-07 ; 0.9999994938657326
k/r = 1/18	wake 1 ; 2/262143		Mis 262145/68719214592			zcr 262145 ; 68719476737	/137438429184			c -2.165774171377629e-07 ; 1.000000067631949
k/r = 1/19	wake 1 ; 2/524287		Mis 524289/274877382656			zcr 524289 ; 274877906945	/549754765312			c -8.402826966472988e-08 ; 0.9999999574950604
k/r = 1/20	wake 1 ; 2/1048575		Mis 1048577/1099510579200		zcr 1048577 ; 1099511627777	/2199021158400			c -1.861820421561348e-08 ; 1.000000035526125
k/r = 1/21	wake 1 ; 2/2097151		Mis 2097153/4398044413952		zcr 2097153 ; 4398046511105	/8796088827904			c -1.581664298449309e-08 ; 1.000000005190412
k/r = 1/22	wake 1 ; 2/4194303		Mis 4194305/17592181850112		zcr 4194305 ; 17592186044417	/35184363700224			c 2.11348855536603e-09 ; 1.000000006768042
k/r = 1/23	wake 1 ; 2/8388607		Mis 8388609/70368735789056		zcr 8388609 ; 70368744177665	/140737471578112		c -1.32827905765734e-09 ; 1.000000002625882
k/r = 1/24	wake 1 ; 2/16777215		Mis 16777217/281474959933440		zcr 16777217 ; 281474976710657	/562949919866880		c 1.110191297822782e-09 ; 1.000000000581819
k/r = 1/25	wake 1 ; 2/33554431		Mis 33554433/1125899873288192		zcr 33554433 ; 1125899906842625	/2251799746576384		c 1.62200284270896e-10 ; 1.00000000049427
k/r = 1/26	wake 1 ; 2/67108863		Mis 67108865/4503599560261632		zcr 67108865 ; 4503599627370497	/9007199120523264		c 2.115013311798569e-10 ; 0.9999999999339535
k/r = 1/27	wake 1 ; 2/134217727		Mis 134217729/18014398375264256		zcr 134217729 ; 18014398509481985	/36028796750528512	c 8.205882795347896e-11 ; 1.000000000041509
k/r = 1/28	wake 1 ; 2/268435455		Mis 268435457/72057593769492480		zcr 268435457 ; 72057594037927937	/144115187538984960	c 1.818186256603596e-11 ; 0.9999999999653065
k/r = 1/29	wake 1 ; 2/536870911		Mis 536870913/288230375614840832	zcr 536870913 ; 288230376151711745	/576460751229681664	c 1.544590637441404e-11 ; 0.9999999999949313
k/r = 1/30	wake 1 ; 2/1073741823		Mis 1073741825/1152921503533105152	zcr 1073741825 ; 1152921504606846977	/2305843007066210304	c -2.063955458366402e-12 ; 0.9999999999933906
k/r = 1/31	wake 1 ; 2/2147483647		Mis 2147483649/4611686016279904256	zcr 2147483649 ; 4611686018427387905	/9223372032559808512	c 1.29718610843552e-12 ; 0.9999999999974356
k/r = 1/32	wake 1 ; 2/4294967295		Mis 4294967297/18446744069414584320	zcr 4294967297 ; 1	/18446744065119617024			c -1.084197223871117e-12 ; 0.9999999999994318
k/r = 1/33	wake 1 ; 2/8589934591		unsigned integer overflow 
k/r = 1/34	wake 1 ; 2/17179869183		unsigned integer overflow 
k/r = 1/35	wake 1 ; 2/34359738367		unsigned integer overflow 
k/r = 1/36	wake 1 ; 2/68719476735		unsigned integer overflow 
k/r = 1/37	wake 1 ; 2/137438953471		unsigned integer overflow 
k/r = 1/38	wake 1 ; 2/274877906943		unsigned integer overflow 
k/r = 1/39	wake 1 ; 2/549755813887		unsigned integer overflow 
k/r = 1/40	wake 1 ; 2/1099511627775	unsigned integer overflow 
k/r = 1/41	wake 1 ; 2/2199023255551	unsigned integer overflow 
k/r = 1/42	wake 1 ; 2/4398046511103	unsigned integer overflow 
k/r = 1/43	wake 1 ; 2/8796093022207	unsigned integer overflow 
k/r = 1/44	wake 1 ; 2/17592186044415	unsigned integer overflow 
k/r = 1/45	wake 1 ; 2/35184372088831	unsigned integer overflow 
k/r = 1/46	wake 1 ; 2/70368744177663	unsigned integer overflow 
k/r = 1/47	wake 1 ; 2/140737488355327	unsigned integer overflow 
k/r = 1/48	wake 1 ; 2/281474976710655	unsigned integer overflow 
k/r = 1/49	wake 1 ; 2/562949953421311	unsigned integer overflow 
k/r = 1/50	wake 1 ; 2/1125899906842623	unsigned integer overflow 
k/r = 1/51	wake 1 ; 2/2251799813685247	unsigned integer overflow 
k/r = 1/52	wake 1 ; 2/4503599627370495	unsigned integer overflow 
k/r = 1/53	wake 1 ; 2/9007199254740991	unsigned integer overflow 
k/r = 1/54	wake 1 ; 2/18014398509481983	unsigned integer overflow 
k/r = 1/55	wake 1 ; 2/36028797018963967	unsigned integer overflow 
k/r = 1/56	wake 1 ; 2/72057594037927935	unsigned integer overflow 
k/r = 1/57	wake 1 ; 2/144115188075855871	unsigned integer overflow 
k/r = 1/58	wake 1 ; 2/288230376151711743	unsigned integer overflow 
k/r = 1/59	wake 1 ; 2/576460752303423487	unsigned integer overflow 
k/r = 1/60	wake 1 ; 2/1152921504606846975	unsigned integer overflow 
k/r = 1/61	wake 1 ; 2/2305843009213693951	unsigned integer overflow 
k/r = 1/62	wake 1 ; 2/4611686018427387903	unsigned integer overflow 
k/r = 1/63	wake 1 ; 2/9223372036854775807	unsigned integer overflow 

=======
The angle  2147483649/4611686016279904256  or  0000000000000000000000000000001p0000000000000000000000000000010
has  preperiod = 31  and  period = 31.
The corresponding parameter ray is landing
at a Misiurewicz point of preperiod 31 and
period dividing 31.
Do you want to draw the ray and to shift c
to the landing point?

*/



#include <iostream>
#include <math.h>       /* pow */

// bits of integer type = precision of unsigned long long int 
#define RMAX 64 // if r = RMAX then 2^r is zero ( unsigned integer oveflow = wrap )


// n is a numerator
// d is a denominator
// f = n/d is a rational fraction ( angle in turns )
// twice is doubling map = (2*f) mod 1
// n and d are changed ( Arguments passed to function by reference)

void twice(unsigned long long int &n, unsigned long long int &d)
{  if (n >= d) return;
   if (!(d & 1)) { d >>= 1; if (n >= d) n -= d; return; }
   unsigned long long int large = 1LL; 
   large <<= 63; //avoid overflow:
   if (n < large) { n <<= 1; if (n >= d) n -= d; return; }
   n -= large; 
   n <<= 1; 
   large -= (d - large); 
   n += large;
}

// "The function is computing the preperiod and period (of n/d under doubling map)
// and setting the denominator to  2^preperiod*(2^period - 1) if possible.
// So 1/5 becomes 3/15 and 2/10 becomes 3/15 as well.
// The period is returned as the value of the function, 
// n and d are changed ( Arguments passed to function by reference)
// and the preperiod is returned in k." (Wolf Jung)
// Question : if result is >=0 why do not use unsigneg char or unsigned int for type of result ???
int normalize(unsigned long long int &n, unsigned long long int &d, int &k)
{  if (!d) return 0; // d==0 error
   n %= d; 
   while (!(n & 1) && !(d & 1)) { n >>= 1; d >>= 1; }
   int p; 
   unsigned long long int n0, n1 = n, d1 = d, np;
   k = 0; 
   while (!(d1 & 1)) { k++; d1 >>= 1; if (n1 >= d1) n1 -= d1; }
   n0 = n1;
   for (p = 1; p <= 65 - k; p++) 
	{ twice(n1, d1); 
	  if (n1 == n0) break; }
   if (k + p > 64) return 0; // more then max unsigned long long int
   np = 1LL; 
   np <<= (p - 1); 
   np--; np <<= 1; 
   np++; //2^p - 1 for p <= 64
   n0 = np; 
   d >>= k; n1 = d; 
   if (n1 > n0) { n1 = n0; n0 = d; }
   while (1) { d1 = n0 % n1; if (!d1) break; 
   n0 = n1; n1 = d1; } //gcd n1
   n /= d/n1; 
   n *= np/n1; 
   d = np << k;
   return p;
}



// finds conjugate angle
// uses algorithm 13.3 page 108 from 
// Symbolic Dynamics of Quadratic Polynomials by Henk Bruin , Dierk Schleicher
// http://www.ml.kva.se/preprints/archive/2001-2002/2001-2002-07.pdf
// n and d are changed ( Arguments passed to function by reference)
// Question : if result is >=0 why do not use unsigneg char or unsigned int for type of result ???
//  // conjugate fails for d = 8589934591 (r = 33) and higher

int conjugate(unsigned long long int &n, unsigned long long int &d)


{  int i, 
       k, // preperiod of n/d under doubling map
       p = normalize(n, d, k);  // p is a period of n/d under doubling map
   
   // this function shoud not be used when :
   // if period=0 and then angle is not periodic so has no conjugate angle
   // or 
   // period>32  ( ? because denominator = 2^period is unsigned long long int which is from 0 to 18 446 744 073 709 551 615 )
   //             and 2^32 = 4 294 967 296 so .....	
   // "When the period is p, the last computed preperiodic angle has
   //preperiod p. So for p = 32, period+preperiod = 64 and the
   //numbers are almost 2^64. No larger period is possible with
  //8-byte long long integers"
  //
   // or preperiod is not 0 ( then angle is preperiodic and have no conjugate angle )
   // 
   if (!p || p > 32 || k) return 0; //  
   
   // 1 <= period <= 2
   if (p == 2) n = 3 - n; 
   if (p <= 2) return 1;
   
   // 2 < period <= 32  
   unsigned long long int n1, 
     d1 = (d << 1), // multiplying by 2
     np, 
     na = n, 
     nb = n + d;
   if (n & 1LL) n1 = na; else n1 = nb; //A is na/d1 ... nb/d1
   //compute preimages of n1/d1 on the same side as forward orbit
   // = for k from 2 to p find fk ( preimage of f(k-1) ) such that pairs of
   // angles (f0 * 2^(p-k), fk) and (f0 * 2^(p-1), f1) are unlinked 

   for (i = 2; i <= p; i++)
   {  d1 <<= 1; // d1= d1 << 1
      na <<= 1; 
      nb <<= 1;
      np = n; 
      for (k = i; k < p; k++) twice(np, d); // p forward iteration  of  
      np <<= i;
      if (na < np && np < nb) 
      	{ if (n1 < na || nb < n1) n1 += (d1 >> 1); }
      	else { if (na < n1 && n1 < nb) n1 += (d1 >> 1); }
   }
   // Comment by Wolf Jung : 
   // Note that the iterates of the first angle np/d are compared to the second
  // angle n1/d.
  // Example: the orbits of 3/15 and 4/15 do not meet, it is a primitive
  // component. 
  // The orbits of 6/15 and 9/15 meet after two iterations. The dynamic rays
  // are landing at a 2-periodic point. The period-4 component is a satellite
  // component. 
  // The function returns the period of the landing point. 
  // If it is smaller than the period of the angles, there is a satellite component.


   np = n; 
   n1 = (n1 - n)/d; 
   n = n1; 
   k = 0;
   for (i = 1; i <= p; i++) { twice(n1, d); if (n1 == np) break; }
   if (i >= p) return p; // returns period of the landing point which is greater or equal to the period of rays= this is a primitive component
   
   // Comment by Wolf Jung : 
   // Compute the greatest common divisor of p and i with Euclid algorithm.
   // Example: period 4 bifurcates to period 12. Then p = 12 and i = 4 or i = 8,
   //depending on the rotation number 1/3 or 2/3 and on the question, whether
   // the first angle was the smaller or the larger one. By taking the gcd of p
   // and i, we get 4 in both cases.

   while (1) // allways 
	{ k = p % i; 
          if (!k) break; 
          p = i; 
          i = k; } //gcd i
   return i; // returns period of the landing point, which is smaller then period of rays
   // it is a  satellite component of Mandelbrot set
}


// print orbit of point
int orbit(unsigned long long int n, unsigned long long int d)
{
  int i,
      k, // preperiod of n/d under doubling map
      p = normalize(n, d, k);  // p is a period of n/d under doubling map
  if (p==0) return 1; // error
  std::cout  << n << "/" << d << "\n"; // print initial value
  for (i = 0; i < (p+k-1); i++)  // p forward iteration  
   { twice(n, d);  
     std::cout  << n << "/" << d << "\n"; 
    }
  return 0;

}

/*

Determine the wake of a limb at the main cardioid.
Enter a fraction  k/r  for the rotation number,
in lowest terms, with  1 ≤ k < r ≤ 64 :
------------------------------------------
The 1/3-wake of the main cardioid is
bounded by the parameter rays with the angles
1/7  or  p001  and
2/7  or  p010 .
Do you want to draw the rays and to shift c
to the center of the satellite component?
---------------------------------------------

function qulonglong mndAngle::wake(int k, int r, qulonglong &n)
from the file mndcombi.cpp  
which is apart of Mandel 5.16 by Wolf Jung (C) 2007-2018.
   

input : k/r
output n/d ( d is returned by a function, n is   Arguments passed to function by reference)




*/

unsigned long long int wake(long long int k, long long int r, unsigned long long int &n)
{  
	// check input
	if (k <= 0 || k >= r || r > RMAX) 
		{ 	std::cout << "wake error : bad input "<< "\n";

			return 0LL;}
	
	unsigned long long int d = 1LL; 
	long long int j;
	long long int s = 0; 
	
	
	n = 1LL;

	for (j = 1; j < r; j++)
   		{  	s -= k; 
   			if (s < 0) s += r; 
   			if (!s) return 0LL;
      			if (s > r - k) n += d << j;
   		}
   	d <<= (r - 1); // 
   	d--; 
   	d <<= 1; // Shift d left by 1 bit ( bitwise left shift assignment) 
   	d++; //2^r - 1 for r <= 64
   	return d;
}


/*
  find numerically angle of external ray that lands on the principal Misiurewicz point 
  it must be inside wake 
  
*/
unsigned long long int principal_M(unsigned long long int dm, unsigned long long int nw1, unsigned long long int nw2, unsigned long long int dw){

	//unsigned long long int nm;
	unsigned long long int n;
	double w1 = ((double) nw1)/dw;
	double w2 = ((double) nw2)/dw;
	double m;
	
	//printf("w1 = %f\n ", w1);
	//printf("w2 = %f\n ", w2);
	
	for (n = 1; n < dm; n++){
		m = ((double) n)/dm;
		//printf("n = %d\tm = %f\n ",n, m);
		if (w1<m  && m<w2){
			return n;
		
		}
	
	}

	return 0;


}



/* 
   function from mndlbrot.cpp  by Wolf Jung (C) 2007-2017 ...
   part of Mandel 5.14, which is free software; you can
   redistribute and / or modify them under the terms of the GNU General
   Public License as published by the Free Software Foundation; either
   version 3, or (at your option) any later version. In short: there is
   no warranty of any kind; you must redistribute the source code as well.
   
   http://www.mndynamics.com/indexp.html
   ----------------------------------------------
   
   it is used to find :
   * periodic or preperiodic points on dynamic plane 
   * on parameter plane 
   ** centers ( periodic)
   ** Misiurewicz points ( preperiodic)
   
   using Newton method
   
   
   c = -0.050000000000000  +1.240000000000000 i    period = 0
   
*/
int find(int sg, unsigned int preper, unsigned int per, double &x, double &y) 
{  double a = -0.5, b = 1.3, fx, fy, px, py, w;
  unsigned int  i, j;
   
  for (i = 0; i < 30; i++)
    { if (sg > 0) // parameter plane
	{ a = x; b = y; } 
         
      if (!preper) // preperiod==0
	{  if (sg > 0) // parameter plane
	    { fx = 0; 
	      fy = 0; 
	      px = 0; 
	      py = 0; }
	       
	  else // dynamic plane
	    { fx = -x; 
	      fy = -y; 
	      px = -1; 
	      py = 0; }
	}
	
      else // preperiod > 0
	{ fx = x; 
	  fy = y; 
	  px = 1.0; 
	  py = 0;
	  
	  for (j = 1; j < preper; j++)
	    {  if (px*px + py*py > 1e100) return 1; // escaping 
	      w = 2*(fx*px - fy*py); 
	      py = 2*(fx*py + fy*px);
	      px = w; 
	      if (sg > 0) px++; // parameter plane
	      w = fx*fx - fy*fy + a; 
	      fy = 2*fx*fy + b; 
	      fx = w;
	    }
	}
	
      double Fx = fx, Fy = fy, Px = px, Py = py;
      
     
      for (j = 0; j < per; j++)
	{  if (px*px + py*py > 1e100) return 2;
	
	  //std::cout << "j = " << j<< ";\t f = "<< fx << " ;\t " << fy << "\t p = "<< px <<" ; " << py <<  ":\n";
	  w = 2*(fx*px - fy*py); 
	  py = 2*(fx*py + fy*px);
	  px = w; 
	  if (sg > 0) px++; // parameter plane
	  w = fx*fx - fy*fy + a; 
	  fy = 2*fx*fy + b; 
	  fx = w;
	  
	}
	
      fx += Fx; 
      fy += Fy; 
      px += Px; 
      py += Py;
      w = px*px + py*py; 
      if (w < 1e-100) return -1;
      x -= (fx*px + fy*py)/w; 
      y += (fx*py - fy*px)/w;
    }
  return 0;
}












// =====================================================================================================================
// ====================================================================================================================
// ========================================================================================================================

int main()
{
	// parameter plane
	// input k/r = rotation number	
  	unsigned long long int k = 1;
  	unsigned long long int r;
  	// unsigned long long int rMax = 100;
  	//wake of the Mandelbrot set with 2 external angles nw1/dw and nw2/dw ( conjugate angles)
  	unsigned long long int nw1;
  	unsigned long long int nw2;
  	unsigned long long int dw;
  	// lowest angle of the principal Misiurewicz point 
  	unsigned long long int nm = 1; // 
  	unsigned long long int dm; //  d = (2^r)*(2^r - 1)
  	// c = cre + cim*I ; inital point for Newton method ( find  ) must be in the exterior, it is also output for find 
  	double cre = -0.5;
  	double cim = 1.25;
  	
  	
  	
  	// dynamic plane 
  	unsigned long long int nz1 ; // nz1 = nm
  	unsigned long long int nz2 ; // nz2 = (nm +dm) mod dm 
  	unsigned long long int dz; //  dz = dm*2
  	//
  	unsigned long long int pow2r; //  2^r
  	
  	
  	//
  	int plane = 1; // positive is parameter plane, negative is dynamic plane.
  	int period;
  	int preperiod;
  	int period_landing; //   	int result_conjugate;
  	//int  result_normalize;
  	int result_find;
  
  
  
  for ( r = 2; r < RMAX; ++r){
  	
  	std::cout << "k/r = " << k << "/" << r << "\t"; // The rotation number
  	
  	
  	pow2r = pow(2,r); // it works ut to r = 63 because log2(pow2r) = r
  	// wake
  	// first angle of the wake
  	dw = pow2r - 1; // d = ( 2^r - 1)
  	nw1 = 1;
  	//second angle of the wake = conjugate angle
  	nw2 = 2;
  	period_landing = 1; 	 	
  	std::cout << "wake " << nw1 << " ; " << nw2 << "/" << dw<< "\t";
  	
  	
  	// angle of the principal Misiurewicz on parameter plane = critical point z=c on dynamical plane 
  	// it works up to r = 32 because log2(d(32)) = 64 = 2*r
  	// float(log(18446744073709551615)/log(2)) = 64.0
  	dm = pow2r*(pow2r - 1); // dm = (2^r)*(2^r - 1) ; log2(dm) = 2*r
  	
  	if (dm==0 || 2*r>RMAX) { // unsigned integer overflow = wrap
  			printf("unsigned integer overflow. Use  GMP with precision = 2*r \n"); 
  			
  			}
  		else {
  			nm = dw+2; // principal_M(dm, nw1, nw2, dw); // it must be inside wake 
  			std::cout << "Mis " << nm << "/" << dm << "\t"; // lowest angle of the principal Misiurewicz point
  	
  			// angle of the critical point on the dynamical plane  z = 0
  			nz1 = nm;
  			dz = dm*2;
  			nz2 = nz1 +dm; 
  			std::cout << "zcr " << nz1 << " ; " << nz2 << "\t/" << dz << "\t"; //
  	
  	
  			period = period_landing; // here always = 1 
  			preperiod = r;
  			// 
  			std::cout.precision( 16 ); 
   			result_find = find(plane, preperiod,period,cre,cim); // find misiurewicz point 
  			std::cout << "c " << cre << " ; " << cim << "\n"; //
  			} // else
  	

  	} //
 
   
   return 0;
}
