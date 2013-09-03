
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
// isPowerTwo
// ------------

bool isPowerTwo (unsigned int);
// ------------
// degree2
// ------------
/*
	returns position of leftmost 1 bit
	used to calculate what power of 2 a number is
	(if isPowerTwo is true)
*/
int degree2 (int);
// ------------
// cycle_length
// ------------

// ------------
// cycle_length
// ------------

int collatz_eval (int);


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

// ------------
// isPowerTwo
// ------------

bool isPowerTwo (unsigned int x)
{
  return ((x != 0) && ((x & (~x + 1)) == x));
}
// ------------
// degree2
// ------------

int degree2 (int a)
{
	int count=0;
	while(a>>=1) count++;
	return count;
/*
	unsigned int v=a; 
	static const unsigned int b[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 
		                         0xFF00FF00, 0xFFFF0000};
	register unsigned int r = (v & b[0]) != 0;
	for (int i = 4; i > 0; i--)
	{
	  r |= ((v & b[i]) != 0) << i;
	}
	return r;
*/

}
// ------------
// cycle_length
// ------------
static int cache[1000000]={0};


int cycle_length(int n)
{
	int count=1;
	int initial_n = n;
	while(n!=1)
	{
		if((n<1000000)&&(cache[n]!=0)) return count+cache[n]-1;
		if(n%2!=0)
			n=3*n+1;
		else{
			if(isPowerTwo(n))
			{
				count+=degree2(n);
				break;
			}
			n=n/2;
		    }
		count++;
	}
	cache[initial_n]=count;
	return (count);
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
