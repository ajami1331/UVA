#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <vector>
#ifndef PolyHash_h
#define PolyHash_h 1
namespace library
{
constexpr unsigned long long mod = (1ULL << 61) - 1;
const unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
const unsigned long long base = std::mt19937_64(seed)() % (mod / 3) + (mod / 3);
long long ModMul(unsigned long long a, unsigned long long b)
{
    unsigned long long l1 = (unsigned int)a, h1 = a >> 32, l2 = (unsigned int)b, h2 = b >> 32;
    unsigned long long l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    unsigned long long ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}
template <size_t MAXLEN> struct PolyHash
{
    std::vector<long long> pref;
#ifdef IMPLEMENT_REV_HASH
    std::vector<long long> suff;
#endif
    inline static unsigned long long base_pow[MAXLEN];
    PolyHash()
    {
    }
    template <typename T> PolyHash(const std::vector<T> &ar)
    {
        if (!base_pow[0])
            init();
        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = ModMul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod)
                pref[i] -= mod;
        }
#ifdef IMPLEMENT_REV_HASH
        suff.resize(n + 3, 0);
        for (int i = n; i >= 1; i--)
        {
            suff[i] = ModMul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod)
                suff[i] -= mod;
        }
#endif
    }
    PolyHash(const char *str) : PolyHash(std::vector<char>(str, str + strlen(str)))
    {
    }
    unsigned long long GetHash(int l, int r)
    {
        long long h = pref[r + 1] - ModMul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }
#ifdef IMPLEMENT_REV_HASH
    unsigned long long ReverseHash(int l, int r)
    {
        long long h = suff[l + 1] - ModMul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
#endif
    unsigned long long GetHash(int l, int r, int x, int y)
    {
        return (ModMul(GetHash(l, r), base_pow[y - x + 1]) + GetHash(x, y)) % mod;
    }
    void init()
    {
        base_pow[0] = 1;
        for (int i = 1; i < MAXLEN; i++)
        {
            base_pow[i] = ModMul(base_pow[i - 1], base);
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
using ll = long long;
const int sz = 2e6 + 10;
int sLen, tLen;
char s[sz], t[sz];
struct block
{
    int l, r;
    char c;
    block(int l, int r, char c) : l(l), r(r), c(c)
    {
    }
};
vector<block> blocks;
void Solve()
{
    while (scanf("%s\n%s\n", t, s) == 2)
    {
        library::PolyHash<sz> hash1(s);
        library::PolyHash<sz> hash2(t);
        sLen = strlen(s);
        tLen = strlen(t);
        blocks.clear();
        for (int i = 0; i < sLen; i++)
        {
            if (s[i] == '?')
            {
                int j = i;
                while (j < sLen && s[j] == '?')
                    j++;
                blocks.emplace_back(i, j - 1, '?');
                i = j - 1;
                continue;
            }
            int j = i;
            while (j < sLen && s[j] != '?')
                j++;
            blocks.emplace_back(i, j - 1, s[i]);
            i = j - 1;
        }
        int ans = 0;
        for (int i = 0; i < tLen; i++)
        {
            if (i + sLen - 1 >= tLen)
                break;
            bool ok = true;
            for (auto &b : blocks)
            {
                if (b.c == '?')
                    continue;
                if (hash1.GetHash(b.l, b.r) != hash2.GetHash(i + b.l, i + b.r))
                {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        printf("%d\n", ans);
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
