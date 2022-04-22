#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol544;
using namespace std;

/*takeaways
  - don't overthink this too much by over-analyzing the possible
    outcomes of each individual matches
  - just assuming the best team will be most likely to win by
    playing with the weakest team
  - round 1 (1,8),(2,7),(3,6),(4,5)
  - round 2
    - for the (1,8) match, team 8 might win, and you might
      start wondering how to separate the matches into two
      groups with the strongest playing the weakest
    - well if team 8 defeated team 1, that team 8 is the
      strongest after the match so it should play with
      the winner of (4,5), which will more likely to
      produce the weakest team if team 2, and team 3
      all won their matches
    - it might become so complex and you won't know
      what to do, so just assuming the better teams are
      going to win and you need to arrange the matches
      in a way to help they win
    - ((1,8),(4,5)),((2,7),(3,6))
    - or you can think this way: how to let the
      team 1 play with team 2 in the final

*/
string Solution::play(vector<string> &matches)
{
  const int N = matches.size();
  if (N == 1)
    return matches[0];

  auto nextRound = vector<string>();

  /* each round reduces the number of matches by half */
  for (auto i = 0; i < N / 2; i++)
    nextRound.push_back("(" + matches[i] + "," + matches[N - 1 - i] + ")");

  return play(nextRound);
}

string Solution::output(int n)
{
  auto matches = vector<string>();
  for (auto i = 0; i < n; i++)
    matches.push_back(to_string(i + 1));

  return play(matches);
}