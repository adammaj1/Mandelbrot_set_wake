# Task

Compute q angles of the external rays that land the principal Misiurewicz point of the p/q wake of the Mandelbrot set for the complex quadratic map






# description
* [paper by Dusa McDuff and Melkana Brakalova](http://web.archive.org/web/20040212012317/http://www.math.stonybrook.edu/~melkana/wise0310.pdf)
* [wikibooks](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/wake)
* [ Geometry of the Antennas in the Mandelbrot Set by R L Devaney and M Moreno-Rocha, April 11, 2000](http://math.bu.edu/people/bob/papers/monica.pdf)


#notation

Extarnal angle as an infinite  [binary fraction](https://en.wikibooks.org/wiki/Fractals/Mathematics/binary):  
 
$`\theta = 0.b_1 b_2 b_3\dots = \frac{b_1}{2^1}  + \frac{b_2}{2^2} +\frac{b_3}{2^3}  + \dots = \sum_{i=1}^\infty \frac{b_i}{2^i} `$  

Infinite periodic binary fraction  

$`\theta_{-} = 0.(b_1 b_2 \dots b_{q-1} b_{q}) =  `$  

Infinite preperic binary fraction  





# steps
* input = p/q ( angle of the wake as a ratio of decimal integers in the lowest form)
* check if p/q is in the lowest form ( = irreducible)
* compute 2 periodic angles  of the wake ( period = length of the periodic pattern = q): 
  * 0.(s_)
  * 0.(s+)
* compute q preperiodic angles of rays that land on the principal Misiurewicz point of the wake p/q from 2 previous angles
  * the lowest angle of Misiureiwcz point is 0.s-(s+)
  * the highest angle of Misiureiwcz point is 0.s+(s-)
  * the rest (q-2) angles are computed using binary shift of b digits 
  
  
# to do  
* compute q-1 angles of the tips ( ends of arms)
* compute sequence of angles ending at [the Feigenbaum point](https://en.wikipedia.org/wiki/Feigenbaum_constants)
* compute c values of :
  * root point 
  * principal Misiurewicz point
  * root point of main satellite of the arm


Symbolic names of the angles: 

![](./images/mis1over3_600.png)


## substeps or procedures
* compute b = denominator of a/b, which is a smaller Farey parent of p/q. (it is needed for computing Misiurewicz angles)
* convert (pre)periodic binary string to decimal fraction:
  * [geometric series method](https://en.wikibooks.org/wiki/Fractals/Mathematics/Numbers#Geometric_series) 





# files
* [i.c](./src/i.c) c odde to check fraction irreducebility
* [b.hs](./src/b.hs) Haskell code by  Claude Heiland-Allen which does all !!!!
* [w.c](./src/w.c) 
* [p.cpp](./src/p.cpp)
* [f.c](./src/f.c) - Farey parents using int in c 
* [a list of Farye parents up to 100](./src/farey_parents100.txt)
* [ft.c](./src/ft.c) - c program for creating a list of values {p,q,b} for testing shift map
* [fp30.txt](./src/fp30.txt) - result of [ft.c](ft.c), it will be used by another program [t.c](t.c)
* [t.c](./src/t.c) - c program for computing angles of the external rays of Misiurewicz points, only in symbolic form
* [mis30.txt](./src/mis30.txt) - result of [t.c](t.c) = angles of the external rays of Misiurewicz points, only in symbolic form
* [s.c](./src/s.c) - binare left shift map  in c 
* c program for computing q angles rays landing on the principal Misurewicz point of the wake p/q
  * [prep.c](./src/prep.c) - old code
  * [principal.c](./src/principal.c) - new code
  * [34_89.txt](./src/34_89.txt) result for 34/89
  
  
  
  
# irreducible fractions 

Computed using [i.c program](./src/i.c) 

```
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
``` 


# angles of the wake using c and GMP

Result of [w.c](w.c) 


```bash

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
```

# Farey parents 
[Farey parents of p/q]( https://mathr.co.uk/blog/2016-10-31_finding_parents_in_the_farey_tree.html)  

Suppose a/b and c/d   
 
 0< a/b < c/d < 1   
 
 are the Farey parents of p/q  
 
 find a/b and c/d   
 
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





```bash
1/4294967295 > INT_MAX = 2 147 483 647  so gives input error 
Farey parents (1/2147483647) = 0/1  and  1/2147483646		0/1 < 1/2147483647 < 1/2147483646 	0.000000 < 0.0000000004656613 < 0.0000000004656613
Farey parents (1/100) = 0/1  and  1/99				0/1 < 1/100 < 1/99 	 		0.000000 < 0.010000 < 0.010101 
Farey parents (3/100) = 2/67  and  1/33				2/67 < 3/100 < 1/33 	 		0.029851 < 0.030000 < 0.030303 
Farey parents (1/3) = 0/1  and  1/2				0/1 < 1/3 < 1/2 	 		0.000000 < 0.333333 < 0.500000 
Farey parents (3/8) = 1/3  and  2/5				1/3 < 3/8 < 2/5 	 		0.333333 < 0.375000 < 0.400000 
Farey parents (2/5) = 1/3  and  1/2				1/3 < 2/5 < 1/2 	 		0.333333 < 0.400000 < 0.500000 
Farey parents (1/2) = 0/1  and  1/1				0/1 < 1/2 < 1/1 	 		0.000000 < 0.500000 < 1.000000 
Farey parents (2/3) = 1/2  and  1/1				1/2 < 2/3 < 1/1 	 		0.5000000000000000 < 0.6666666666666666 < 1.0000000000000000 
Farey parents (3/4) = 2/3  and  1/1				2/3 < 3/4 < 1/1 	 		0.666667 < 0.750000 < 1.000000 
```

List up to 10 : 

```bash
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
```

Here is [a list up to 100](./src/farey_parents100.txt)
                                                            
## angles of wake 1/n and principal misiurewicz points using cpp and unsigned long long int
made with [p.cpp](./src/p.cpp)


```bash

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
k/r = 1/31	wake 1 ; 2/2147483647		Mis 2147483649/4611686016279904256	zcr 2147483649/9223372032559808512 ; 4611686018427387905/9223372032559808512	c 1.29718610843552e-12 ; 0.9999999999974356
k/r = 1/32	wake 1 ; 2/4294967295		Mis 4294967297/18446744069414584320	zcr 4294967297/18446744065119617024 ; 1/18446744065119617024			c -1.084197223871117e-12 ; 0.9999999999994318  
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
```


# binary left shit map

[Shift map](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/def_cqp#Shift_map): binary left $`\sigma^n( s )`$ is shifting s string n places left 

where:
* n  is a number of digits ( places)
* s is an infinite binary string
* 

n = 1  

```math
\sigma^0( s ) = \sigma^0(00001)  =   00001\\ 
\sigma^1( s ) = \sigma^1(00001)  =   00010\\ 
\sigma^2( s ) = \sigma^2(00001)  =   00100\\ 
\sigma^3( s ) = \sigma^3(00001)  =   01000\\ 
\sigma^4( s ) = \sigma^4(00001)  =   10000\\
\sigma^5( s ) = \sigma^5(00001)  =   00001 
```

```bash
sIn	 0000000000000000000000010
sOut	 0000000000000000000000100 	 0
sOut	 0000000000000000000001000 	 0
sOut	 0000000000000000000010000 	 0
sOut	 0000000000000000000100000 	 0
sOut	 0000000000000000001000000 	 0
sOut	 0000000000000000010000000 	 0
sOut	 0000000000000000100000000 	 0
sOut	 0000000000000001000000000 	 0
sOut	 0000000000000010000000000 	 0
sOut	 0000000000000100000000000 	 0
sOut	 0000000000001000000000000 	 0
sOut	 0000000000010000000000000 	 0
sOut	 0000000000100000000000000 	 0
sOut	 0000000001000000000000000 	 0
sOut	 0000000010000000000000000 	 0
sOut	 0000000100000000000000000 	 0
sOut	 0000001000000000000000000 	 0
sOut	 0000010000000000000000000 	 0
sOut	 0000100000000000000000000 	 0
sOut	 0001000000000000000000000 	 0
sOut	 0010000000000000000000000 	 0
sOut	 0100000000000000000000000 	 0
sOut	 1000000000000000000000000 	 0
sOut	 0000000000000000000000001 	 0
sOut	 0000000000000000000000010 	 1
sOut	 0000000000000000000000100 	 1
sOut	 0000000000000000000001000 	 1
sOut	 0000000000000000000010000 	 1
sOut	 0000000000000000000100000 	 1
sOut	 0000000000000000001000000 	 1
sOut	 0000000000000000010000000 	 1
sOut	 0000000000000000100000000 	 1
sOut	 0000000000000001000000000 	 1
sOut	 0000000000000010000000000 	 1
sOut	 0000000000000100000000000 	 1
sOut	 0000000000001000000000000 	 1
sOut	 0000000000010000000000000 	 1
sOut	 0000000000100000000000000 	 1
sOut	 0000000001000000000000000 	 1
```

n = 3  

```bash
sIn	 0000000000000000000000010
sOut	 0000000000000000000010000 	 0
sOut	 0000000000000000010000000 	 0
sOut	 0000000000000010000000000 	 0
sOut	 0000000000010000000000000 	 0
sOut	 0000000010000000000000000 	 0
sOut	 0000010000000000000000000 	 0
sOut	 0010000000000000000000000 	 0
sOut	 0000000000000000000000001 	 0
sOut	 0000000000000000000001000 	 1
sOut	 0000000000000000001000000 	 1
sOut	 0000000000000001000000000 	 1
sOut	 0000000000001000000000000 	 1
sOut	 0000000001000000000000000 	 1
sOut	 0000001000000000000000000 	 1
sOut	 0001000000000000000000000 	 1
sOut	 1000000000000000000000000 	 1
sOut	 0000000000000000000000100 	 2
sOut	 0000000000000000000100000 	 2
sOut	 0000000000000000100000000 	 2
sOut	 0000000000000100000000000 	 2
sOut	 0000000000100000000000000 	 2
sOut	 0000000100000000000000000 	 2
sOut	 0000100000000000000000000 	 2
sOut	 0100000000000000000000000 	 2
sOut	 0000000000000000000000010 	 3
sOut	 0000000000000000000010000 	 3
sOut	 0000000000000000010000000 	 3
sOut	 0000000000000010000000000 	 3
sOut	 0000000000010000000000000 	 3
sOut	 0000000010000000000000000 	 3
sOut	 0000010000000000000000000 	 3
sOut	 0010000000000000000000000 	 3
sOut	 0000000000000000000000001 	 3
sOut	 0000000000000000000001000 	 4
sOut	 0000000000000000001000000 	 4
sOut	 0000000000000001000000000 	 4
sOut	 0000000000001000000000000 	 4
sOut	 0000000001000000000000000 	 4
sOut	 0000001000000000000000000 	 4
sOut	 0001000000000000000000000 	 4
sOut	 1000000000000000000000000 	 4
sOut	 0000000000000000000000100 	 5
sOut	 0000000000000000000100000 	 5
sOut	 0000000000000000100000000 	 5
sOut	 0000000000000100000000000 	 5
sOut	 0000000000100000000000000 	 5
```

# Angles ( in the symbolic form) of external rays landing on the principal Misiurewicz points of wake p/q 

Algorithm is based on the Theorem 5.3 in: [Geometry of the Antennas in the Mandelbrot Set by R L Devaney and M Moreno-Rocha, April 11, 2000](http://math.bu.edu/people/bob/papers/monica.pdf)  

See also:
*  [https://mathr.co.uk/blog/2013-02-01_navigating_by_spokes_in_the_mandelbrot_set.html](Navigating by spokes in the Mandelbrot set) by Claude Heiland-Allen
* [wikibooks](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/p_misiurewicz)



Files
* [t.c](./src/t.c) - c program for computing angles of the external rays of Misiurewicz points, only in symbolic form
* [mis30.txt](./src/mis30.txt) - result of [t.c](t.c) = angles of the external rays of Misiurewicz points, only in symbolic form


```bash



====================================
p/q = 1/2	b=1

(s-)
s-(s+)
s+(s-)
(s+)
==========================================

p/q = 1/3	b=1

(s-)
s-(s+)
s-(d^1(s+))
s+(s-)
(s+)
==========================================

p/q = 2/3	b=2

(s-)
s-(s+)
s+(d^2(s+))
s+(s-)
(s+)
==========================================

p/q = 1/4	b=1

(s-)
s-(s+)
s-(d^1(s+))
s-(d^2(s+))
s+(s-)
(s+)
==========================================

p/q = 3/4	b=3

(s-)
s-(s+)
s+(d^3(s+))
s+(d^2(s+))
s+(s-)
(s+)
==========================================

p/q = 1/5	b=1

(s-)
s-(s+)
s-(d^1(s+))
s-(d^2(s+))
s-(d^3(s+))
s+(s-)
(s+)
==========================================

p/q = 2/5	b=3

(s-)
s-(s+)
s-(d^3(s+))
s-(d^1(s+))
s+(d^4(s+))
s+(s-)
(s+)
==========================================

p/q = 3/5	b=2

(s-)
s-(s+)
s-(d^2(s+))
s+(d^4(s+))
s+(d^1(s+))
s+(s-)
(s+)
==========================================

p/q = 4/5	b=4

(s-)
s-(s+)
s+(d^4(s+))
s+(d^3(s+))
s+(d^2(s+))
s+(s-)
(s+)
==========================================
```

# Angles ( in the binary form) of external rays landing on the principal Misiurewicz points of wake p/q 

c program for computing q angles rays landing on the principal Misurewicz point of the wake p/q
* [prep.c](./src/prep.c) - old code
* [principal.c](./src/principal.c) - new code
* [34_89.txt](./src/34_89.txt) result for 34/89



```bash
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


```



# License

This project is licensed under [License GPL3+]( http://www.gnu.org/licenses/gpl.html)

# technical notes
GitLab uses:
* the Redcarpet Ruby library for [Markdown processing](https://gitlab.com/gitlab-org/gitlab-ce/blob/master/doc/user/markdown.md) see also [user doc](https://docs.gitlab.com/ee/user/markdown.html)
* KaTeX to render [math written with the LaTeX syntax](https://gitlab.com/gitlab-org/gitlab-ce/blob/master/doc/user/markdown.md), but [only subset](https://khan.github.io/KaTeX/function-support.html)




# Git
```
cd existing_folder
git init
git remote add origin git@gitlab.com:adammajewski/wake_gmp.git
git add .
git commit -m "Initial commit"
git push -u origin master
```

Local repo: ~/c/mandel/wake/wake_gmp
 
