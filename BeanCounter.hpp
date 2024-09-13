#ifndef BEANCOUNTER_HPP
#define BEANCOUNTER_HPP

#include <iostream>
using namespace std;

class BeanCounter{
public:
  BeanCounter(int n);
  // Precondition: n > 0
  // Initializes BeanCounter object with
  //  n counting slots

  BeanCounter();
  // Default constructor, counter size 2

  ~BeanCounter();
  // destructor

  void tick(int i);
  // add one to counter index i, if i is a legal index

  void maxReset();
  // reset all counter indexes to 0 except
  // the one(s) with the highest count

  int *getCounter() const { return counter;}
  // getter to return the array counter

  void setCounter(int* new_counter);
  // setter to set the array counter

  int getLength() const {return length;}
  // getter to return the array length

  BeanCounter(const BeanCounter &b);
  // copy constructor

  BeanCounter &operator=(const BeanCounter &b);
  // assignment operator

private:
  // dynamic array for counters
  int *counter;
  int length;
};

ostream &operator<<(ostream &out, const BeanCounter &b);
// overloaded << operator
BeanCounter operator+(const BeanCounter &first, const BeanCounter &second);
// overloaded + operator

#endif