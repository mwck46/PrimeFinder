// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "PrimeFinder.hpp"

using namespace std;
vector<int> findPrimeFactor(int n, PrimeFinder& pf)
{
  vector<int> rst;

  int f1 = 1;
  int f2 = 1;
  pf.top();
  while (1)
  {
    int i = pf.nextPrime();
    if (n % i == 0)
    {
      f1 = i;
      break;
    }
  }

  f2 = n / f1;
  if (f2 == 1)
  {
    rst.push_back(f1);
  }
  else
  {
    vector<int> factors = findPrimeFactor(f1, pf);
    rst.insert(
      rst.end(),
      std::make_move_iterator(factors.begin()),
      std::make_move_iterator(factors.end())
    );

    factors = findPrimeFactor(f2, pf);
    rst.insert(
      rst.end(),
      std::make_move_iterator(factors.begin()),
      std::make_move_iterator(factors.end())
    );
  }
  return rst;
}

int main()
{
  PrimeFinder pf;
  vector<int> rst = findPrimeFactor(9901, pf);
}
