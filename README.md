
# description
* [paper by Dusa McDuff and Melkana Brakalova](http://web.archive.org/web/20040212012317/http://www.math.stonybrook.edu/~melkana/wise0310.pdf)
* [wikibooks](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/wake)



# files
* [w.c](w.c) 
* []()

## angles of the wake using GMP
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
                                                            





# License

This project is licensed under [License GPL3+]( http://www.gnu.org/licenses/gpl.html)

# technical notes
GitLab uses:
* the Redcarpet Ruby library for [Markdown processing](https://gitlab.com/gitlab-org/gitlab-ce/blob/master/doc/user/markdown.md) see also [user doc](https://docs.gitlab.com/ee/user/markdown.html)
* KaTeX to render [math written with the LaTeX syntax](https://gitlab.com/gitlab-org/gitlab-ce/blob/master/doc/user/markdown.md), but [only subset](https://khan.github.io/KaTeX/function-support.html)




## Git
```
cd existing_folder
git init
git remote add origin git@gitlab.com:adammajewski/wake_gmp.git
git add .
git commit -m "Initial commit"
git push -u origin master
```

Local repo: ~/c/mandel/wake/wake_gmp
 
