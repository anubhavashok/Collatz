
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
#define _CACHE_SIZE 1000000
unsigned int cycle_length (unsigned int);


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
	register unsigned int index[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	for(short i=0;i<20;i++)
	{
		//index<<=1;
		cache[ index[i] ]=i+1;
	}

}
static short cache[1000001];
// ------------
// cycle_length
// ------------

unsigned int cycle_length(unsigned int n)
{
	//base case
	//if(n==1) return 1;

	//check if n is in cache
	if (n < _CACHE_SIZE)
	if (cache[n] != 0)
	return cache[n];

	//inline for if(n%2==1) return 3*n+1; else return n*2;
	unsigned int next=(n&1)? 3*n+1 : n>>1;
	register short length = 1 + cycle_length(next);
	
	//add n to cache
	if (n < _CACHE_SIZE)
	cache[n] = length;
 
	return length;
}

// ------------
// collatz_eval
// ------------
#include <algorithm>    // std::swap

    using namespace std;
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    if(j<i) std::swap(i,j);
    short v = 1;
    fill_cache_pwr2(cache);
    for(int cur=i;cur<=j;cur++)
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
