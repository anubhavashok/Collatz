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
// isPowerTwo
// ------------

bool isPowerTwo (unsigned int x)
{
  return ((x != 0) && ((x & (~x + 1)) == x));
}
// ------------
// cycle_length
// ------------

int cycle_length(int n)
{
	int count=1;
	while(n!=1)
	{
		//printf("%d ", n);
		if(n%2!=0)
			n=3*n+1;
		else{
			if(isPowerTwo(n))
			{
				
			}
			n=n/2;
		    }
		count++;
	}
	return (count);
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    int v = 1;
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
