
// --------
// includes
// --------

#include <iostream> // istream, ostream

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream&, int&, int&);

// ------------
// fill_cache_pwr2
// ------------
/**
 * prefills cache with cycle lengths of all possible 2^n numbers under 1,000,000
 * @param cache a int array by reference
 */
void fill_cache_pwr2(short*);

// ------------
// cycle_length
// ------------
/**
 * recursively calls itself to return cycle lengths. reads cache for previous lengths
 * @param n an int 
 * @return length of cycle of n
 */
#define _CACHE_SIZE 524289
short cycle_length (unsigned int);


// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);


// --------
// includes
// --------

#include <cassert>  // assert



// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}


#include<stdio.h>
#include<iostream>
using namespace std;
// ------------
// fill_cache_pwr2
// ------------
void fill_cache_pwr2(short* cache)
{
	//register int index=1;
	register int index[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	for(int i=0;i<20;i++)
	{
		//index<<=1;
		cache[ index[i] ]=i+1;
	}

}
static short cache[_CACHE_SIZE];
// ------------
// cycle_length
// ------------

short cycle_length(unsigned int n)
{
	//base case
	//if(n==1) return 1;

	//check if n is in cache
	if (n < _CACHE_SIZE)
	if (cache[n] != 0)
	return cache[n];

	//inline for if(n%2==1) return 3*n+1; else return n*2;
	register unsigned int next=(n%2==1)? 3*n+1 : n>>1;
	register short length = 1 + cycle_length(next);
	
	//add n to cache
	if (n < _CACHE_SIZE)
	cache[n] = length;
 
	return length;
}


// ------------
// collatz_eval
// ------------
static short cycle_cache[] ={179,182,217,238,215,236,262,252,247,260,268,250,263,276,271,271,266,279,261,274,256,269,269,282,264,264,
308,259,259,272,272,285,267,267,311,324,249,306,244,306,288,257,288,270,270,314,283,314,296,296,278,309,
340,322,260,260,322,304,273,304,335,317,286,330,299,268,268,312,312,299,312,325,263,294,325,307,307,351,
338,307,320,320,320,289,320,302,302,333,333,315,315,333,315,284,315,328,297,297,284,328,341,310,310,248,
310,341,354,292,279,310,292,323,323,292,305,349,305,305,336,305,318,336,318,331,287,318,331,287,331,344,
331,300,331,313,300,344,313,331,313,313,344,326,375,282,326,295,357,295,326,326,370,295,308,308,352,308,
383,339,321,352,370,290,339,321,334,321,352,321,321,334,290,334,303,347,334,272,334,334,347,303,365,316,
334,254,316,329,347,329,316,360,329,329,347,329,342,360,298,285,329,329,342,311,342,311,311,355,373,311,
311,311,342,355,355,373,293,280,386,324,324,355,324,355,324,324,324,368,368,306,355,306,443,350,337,368,
381,306,337,350,306,350,368,275,319,337,275,319,332,350,288,350,332,319,319,332,363,288,332,345,301,345,
332,332,301,407,332,332,314,345,270,345,416,283,314,358,332,345,314,389,345,314,345,358,314,358,358,376,
314,327,398,345,327,327,340,358,296,358,327,327,371,327,371,296,340,340,340,265,309,309,371,340,371,309,
384,340,278,340,353,309,353,322,371,353,309,322,384,340,247,322,291,353,322,291,353,335,322,322,366,366,
335,366,304,335,353,335,304,441,348,322,335,366,304,379,335,304,348,379,348,304,379,348,419,348,361,317,
317,361,348,286,317,361,392,348,317,348,330,361,423,361,330,361,379,374,361,330,330,348,330,299,330,436,
361,330,299,361,405,312,330,330,374,299,374,387,268,343,343,414,361,268,312,312,449,330,343,374,374,312,
387,343,343,281,343,325,356,418,356,356,356,374,294,281,312,343,396,343,356,281,325,387,400,356,325,294,
356,338,325,338,325,325,369,369,387,307,294,369,338,338,356,338,307,307,307,444,369,325,338,369,369,413,
382,338,307,276,338,307,382,320,307,382,351,351,422,382,351,307,320,338,382,391,382,351,320,320,426,395,
351,320,320,289,351,395,364,320,426,320,364,364,382,364,377,364,333,470,333,351,364,395,302,333,439,364,
333,364,333,302,364,408,408,377,377,333,346,346,377,377,346,302,333,377,346,346,417,364,346,359,315,346,
452,377,333,315,346,377,315,346,421,390,346,315,315,284,359,328,359,328,421,328,359,359,359,359,377,359,
372,359,328,346,390,399,346,359,266,328,328,434,372,359,359,328,315,297,359,403,328,328,328,328,372,372,
341,372,372,403,297,297,372,341,328,341,412,359,341,354,310,310,310,447,372,372,310,341,372,372,310,354,
385,354,374,341,279,279,341,310,385,354,310,416,310,354,354,354,425,372,416,279,279,310,323,341,323,394,
341,336,354,385,323,385,429,354,398,354,323,323,292,292,367,398,323,367,323,292,323,323,367,336,367,385,
336,336,380,367,336,336,305,380,336,354,398,390,292,336,336,442,323,367,367,336,336,318,367,367,367,411,
380,349,369,380,305,349,349,336,380,380,411,380,305,305,380,349,336,349,420,367,411,349,362,305,349,318,
362,318,389,336,380,349,349,424,318,380,424,424,393,318,349,318,318,349,287,362,318,393,362,331,318,424,
318,362,362,331,362,362,380,362,331,375,362,331,331,468,331,402,349,344,393,362,331,437,331,393,437,362,
356,362,331,331,313,375,300,362,406,406,375,344,437,375,331,331,468,344,300,375,375,406,388,300,331,375,
344,406,331,344,415,287,362,375,313,357,344,344,450,357,450,375,369,375,326,344,313,419,313,375,344,419,
388,357,344,313,344,525,344,388,357,313,388,331,357,401,313,419,313,357,357,357,326,357,428,388,375,357,
370,295,357,326,326,344,326,397,326,344,357,388,326,432,326,326,388,432,370,401,326,357,326,326,313,370,
295,370,401,401,295,370,339,326,295,326,370,326,370,339,370,295,401,401,383,295,383,295,417,326,370,326,
476,383,410,357,370,339,339,393,339,432,339,339,445,308,370,339,370,476,383,339,370,308,370,370,414,414,
383,430,445,372,383,339,339,352,383,352,383,383,383,352,414,383,414,414,383,339,352,352,321,352,423,352,
383,414,352,321,365,308,321,352,458,352,321,383,392,391,383,334,383,334,427,321,383,383,352,427,352,396,
321,352,321,321,352,290,365,365,365,352,396,396};

#include <algorithm>    // std::swap

    using namespace std;
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    if(j<i) std::swap(i,j);
	    //make use of /2 rule
 	   int cur=i;
 	   if(j/2>i){
		i=j/2;
    		cur=i;
		}
	//check cycle cache
	int lb = i%1000 ? i+1000-i%1000 : i;
	int ub = j%1000 ? j-j%1000 : j;
	int length = 0;

	if(ub>lb)
	{
		for(int n=lb/1000; n<ub/1000; n++)
			length=(length<cycle_cache[n]) ? cycle_cache[n] : length;

		int llength = collatz_eval(i,lb); //length bounds on left of range
		int ulength = collatz_eval(ub,j); //length bounds on right of range

		length = length<llength ? llength : length;
		length = length<ulength ? ulength : length;
		return length;
	}




    short v = 1;
    fill_cache_pwr2(cache);
    for(cur;cur<=j;cur++)
    {
      short cl=cycle_length(cur);
      if(cl>v) 
	v=cl;
    }
    assert(v > 0);
    return v;}
// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz
    % valgrind RunCollatz < RunCollatz.in > RunCollatz.out

To configure Doxygen:
    % doxygen -g
That creates the file "Doxyfile".
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    % doxygen Doxyfile
*/

// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------



// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
