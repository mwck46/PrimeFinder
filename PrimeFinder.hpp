#pragma once

#include <vector>


class PrimeFinder
{
private:
  int iter;
  std::vector<int> prime;

public:
  PrimeFinder()
  {
    prime.push_back(2);
    prime.push_back(3);
    iter = 0;
  }

  bool isPrime(int candidate)
  {
    for (int p : prime)
    {
      if (candidate % p == 0)
        return false;
    }
    return true;
  }

  int findNextPrime(int lastPrime)
  {
    int i = lastPrime + 2;
    while (!isPrime(i))
      i += 2;

    return i;
  }

  int nextPrime()
  {
    if (prime.size() <= iter)
    {
      int next = findNextPrime(prime.back());
      prime.push_back(next);
    }

    return prime[iter++];
  }

  void top()
  {
    iter = 0;
  }
};

