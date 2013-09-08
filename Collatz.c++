// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

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


// ------------
// fill_cache_pwr2
// ------------

void fill_cache_pwr2(short* cache)
{
	//register int index=1;
	register int index[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
	for(int i=0;i<21;i++)
	{
		//index<<=1;
		assert(i>=0);
		assert(index[i]>=0);
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
	{
		assert(n<_CACHE_SIZE);
		if (cache[n] != 0)
		return cache[n];
	}

	//inline for if(n%2==1) return 3*n+1; else return n*2;
	register unsigned int next=(n%2==1)? 3*n+1 : n>>1;
	assert(n>0);
	register short length = 1 + cycle_length(next);
	
	//add n to cache
	if (n < _CACHE_SIZE){
		assert(n<_CACHE_SIZE);
		cache[n] = length;
	}
 	assert(length>0);
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
