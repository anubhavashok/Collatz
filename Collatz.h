// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h
#define _CACHE_SIZE 524289
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

#endif // Collatz_h
