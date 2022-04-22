#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol544;

/*
Input: 2
Output: (1,2)
Explanation:
Initially, we have the team 1 and the team 2, placed like: 1,2.
Then we pair the team (1,2) together with '(', ')' and ',', which is the final answer.
*/

tuple<int, string> testFixture1()
{
  return make_tuple(2, "(1,2)");
}

/*
Input: 4
Output: ((1,4),(2,3))
Explanation:
In the first round, we pair the team 1 and 4, the team 2 and 3 together,
as we need to make the strong team and weak team together.
And we got (1,4),(2,3).
In the second round, the winners of (1,4) and (2,3) need to play again to
generate the final winner, so you need to add the paratheses outside them.
And we got the final answer ((1,4),(2,3)).
*/

tuple<int, string> testFixture2()
{
  return make_tuple(4, "((1,4),(2,3))");
}
/*
Input: 8
Output: (((1,8),(4,5)),((2,7),(3,6)))
Explanation:
First round: (1,8),(2,7),(3,6),(4,5)
Second round: ((1,8),(4,5)),((2,7),(3,6))
Third round: (((1,8),(4,5)),((2,7),(3,6)))
Since the third round will generate the final winner,
you need to output the answer (((1,8),(4,5)),((2,7),(3,6))).
*/

tuple<int, string> testFixture3()
{
  return make_tuple(8, "(((1,8),(4,5)),((2,7),(3,6)))");
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.output(get<0>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.output(get<0>(f)) << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.output(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}