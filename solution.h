
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol544
{
  class Solution
  {
  private:
    string play(vector<string> &matches);

  public:
    string output(int n);
  };
}
#endif