//Cameron Nagle
//4/27/2023
//hw7 this program takes in the number of counters to help them count different types of beans
#include <iostream>
#include "BeanCounter.hpp"    //include the function definitions BeanCounter class
using namespace std;

BeanCounter::BeanCounter(int n) {   //create a new BeanCounter of size n
    if(n > 0) {
    counter = new int [n];
    length = n;                     //set length to n
    }
  }

  BeanCounter::BeanCounter() {    //if no int is specified create the counter of size 2
    counter = new int [2];
    length = 2;
  }

BeanCounter::~BeanCounter() {     //at the end of BeanCounter delete the counter
    delete [] counter;
  }

  void BeanCounter::tick(int i) {   //tick function to increase the number in the array spot of the int
    if(i <= length && i >=0) {
      counter[i] += 1;
    }
  }

  void BeanCounter::maxReset() {    //set all the values to 0 excpet for the largest value
    int i;
    int maxValue = 0;
    for(i = 0; i < length; ++i) {
      if(maxValue < counter[i]) {
        maxValue = counter[i];
      }
    }

    for(i = 0; i < length; ++i) {
      if(counter[i] != maxValue) {
      counter[i] = 0;
      }
    }
  }
  void BeanCounter::setCounter(int* new_counter) {    //set the counter array to new_counter
      int i;

      for(i = 0; i < this->getLength(); ++i) {
        counter[i] = new_counter[i];
      }
      
  }

  BeanCounter::BeanCounter(const BeanCounter &b) {    //the copy contructor that copies data into a new BeanCounter object
    int i;

    this->length = b.length;
     
    counter= new int [this->length];

      for(i = 0; i < this->length; ++i) {
       counter[i] = b.getCounter()[i];
      }
  }

  ostream &operator<<(ostream &out, const BeanCounter &b) {   //overload the insertion operator and format the counter variables
int i;
int *pointer = b.getCounter();
out << "<" << pointer[0];
for(i = 1; i < b.getLength(); ++i)  {
out << ", " << pointer[i];
}
out << ">";

return out;
}

BeanCounter operator+(const BeanCounter &first, const BeanCounter &second) {   //Add the corresponding index values together
  int longer, shorter, i;
  if(first.getLength() > second.getLength()) {
  longer = first.getLength();
  shorter = second.getLength();

  int* sum = new int[longer];   

BeanCounter counter(longer);    ////create a new BeanCounter object that has as many counter indexes as the largest of the two input BeanCounters 

for(i = 0; i < shorter; ++i) {
    sum[i] = first.getCounter()[i] + second.getCounter()[i];
  }

  for(i = shorter; i < longer; ++i) {
    sum[i] = first.getCounter()[i];
  }

  counter.setCounter(sum);
  return counter;
  }
  else {
    longer = second.getLength();
    shorter = first.getLength();

  int* sum = new int[longer];   //create a new BeanCounter object that has as many counter indexes as the largest of the two input BeanCounters 

BeanCounter counter(longer);

    for(i = 0; i < shorter; ++i) {
    sum[i] = first.getCounter()[i] + second.getCounter()[i];
  }

  for(i = shorter; i < longer; ++i) {
    sum[i] = second.getCounter()[i];
  }

counter.setCounter(sum);

return counter;
  }

}

BeanCounter& BeanCounter::operator=(const BeanCounter &b) {   //overload the assignment operator for the new counter
  int i;
    this->length = b.length;

    delete this->counter;                  // 2. Delete old counter
        counter = new int [this->length];               // 3. Allocate new counter
    for(i = 0; i < this->length; ++i) {
       counter[i] = b.getCounter()[i];
      }

        return *this;
}