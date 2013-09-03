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
void fill_cache_pwr2(int* cache)
{
	int index=1;
	for(int i=1;i<19;i++)
	{
		index<<=1;
		cache[index]=i+1;
	}
}

static int cache[1000000];
// ------------
// cycle_length
// ------------
unsigned int cycle_length(unsigned int n)
{
	if(n==1) return 1;
	if (n < 1000000 && cache[n] != 0)
	return cache[n];
	
	//if(!(n & (n-1))) return degree2(n)+1;
	
	int next=(n&1)? 3*n+1 : n>>1;
	int length = 1 + cycle_length(next);
	
	if (n < 1000000)
	cache[n] = length;
 
	return length;
}


// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    int v = 1;
    fill_cache_pwr2(cache);
    for(int cur=i;cur<=j;cur++)
    {
      int cl=cycle_length(cur);
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
