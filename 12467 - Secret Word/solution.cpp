#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#ifndef ZAlgo_H
#define ZAlgo_H 1
namespace library
{
template <typename T, size_t MAXLEN, T outOfBound> struct ZAlgo
{
public:
    T s[MAXLEN];
    int z[MAXLEN];
    int occurrence[MAXLEN];
    int n;
    int maxZ;
    void Init(const T *a, int aLen, const T *b, int bLen)
    {
        n = 0;
        for (int i = 0; i < aLen; i++)
            s[n++] = a[i];
        s[n++] = outOfBound;
        for (int i = 0; i < bLen; i++)
            s[n++] = b[i];
        maxZ = 0;
        memset(occurrence, 0, sizeof(occurrence));
        memset(z, 0, sizeof(z));
        Compute();
    }
private:
    void Compute()
    {
        int l = 0;
        int r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && s[r - l] == s[r])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
            else
            {
                int k = i - l;
                if (z[k] < r - i + 1)
                {
                    z[i] = z[k];
                }
                else
                {
                    l = i;
                    while (r < n && s[r - l] == s[r])
                    {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }
        int iter = 0;
        while (s[iter] != outOfBound)
            iter++;
        for (int i = iter + 1; i < n; i++)
        {
            maxZ = std::max(maxZ, z[i]);
            occurrence[z[i]]++;
        }
    }
};
} // namespace library
#endif
#ifndef solution_h
#define solution_h 1
namespace solution
{
using namespace std;
const int sz = 1e6 + 10;
int n;
char s[sz];
char t[sz];
library::ZAlgo<char, sz + sz + sz, '$'> z;
void Solve()
{
    scanf("%d", &n);
    while (n-- && scanf("%s", s))
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            t[i] = s[len - i - 1];
        }
        z.Init(s, len, t, len);
        for (int i = len + 1; i < z.n; i++)
        {
            if (z.z[i] == z.maxZ)
            {
                for (int j = i + z.maxZ - 1; j >= i; j--)
                {
                    putchar(z.s[j]);
                }
                putchar('\n');
                break;
            }
        }
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
