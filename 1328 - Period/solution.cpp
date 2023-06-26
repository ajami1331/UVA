#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
#ifndef KnuthMorrisPrattMatcher_h
#define KnuthMorrisPrattMatcher_h 1
template <size_t MAXLEN> struct KnuthMorrisPrattMatcher
{
    char m[MAXLEN];
    int table[MAXLEN], lenM;
    void Init(const char *str, int n)
    {
        strncpy(m, str, n);
        lenM = n;
        table[0] = 0;
        int i = 1, j = 0;
        while (i < lenM)
        {
            if (m[i] == m[j])
            {
                j++;
                table[i] = j;
                i++;
            }
            else
            {
                if (j)
                {
                    j = table[j - 1];
                }
                else
                {
                    table[i] = 0;
                    i++;
                }
            }
        }
    }
    std::vector<int> MatchString(const char *s, int lenS)
    {
        int i = 0, j = 0;
        std::vector <int> matches;
        while (i < lenS)
        {
            while (i < lenS && j < lenM && s[i] == m[j])
            {
                i++;
                j++;
            }
            if (j == lenM)
            {
                j = table[j - 1];
                matches.emplace_back(i - lenM);
            }
            else if (i < lenS && s[i] != m[j])
            {
                if (j)
                {
                    j = table[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return matches;
    }
};
#endif
#ifndef solution_h
#define solution_h 1
namespace solution
{
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int sz = 1e6 + 10;
int n;
char s[sz];
void Solve()
{
    int cs = 0;
    while (cin >> n && n > 0)
    {
        cin >> s;
        KnuthMorrisPrattMatcher<sz> matcher;
        matcher.Init(s, n);
        cout << "Test case #" << (++cs) << "\n";
        for (int i = 0; i < n; i++)
        {
            int len = i + 1 - matcher.table[i];
            if ((i + 1) % len == 0 && (i + 1) / len > 1)
            {
                cout << (i + 1) << " " << (i + 1) / len << "\n";
            }
        }
        cout << "\n";
    }
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char *argv[])
{
    solution::Solve();
    return 0;
}
