#define TEMPLATE_VERSION "v0.2 19/10/2020"
#include <bits/stdc++.h>

#define MOD (1000000007LL)
#define INF (INT_MAX)
#define LINF (LLONG_MAX)
#define TAM (1000000)
#define LL long long int 
#define ULL unsigned long long int
#define LD long double
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define si set<int>
#define qi queue<int>
#define sti stack<int>
#define vLL vector<LL>
#define pqi priority_queue<int>
#define pii pair<int, int> 
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define EPS 1e-9
#define loop( n ) for(int i=0; i<n; i++)
#define LOOP(k,n) for(int i=k; i<n; i++)
#define FIND(v, value) find(v.begin(), v.end(), value)
#define SORT( v ) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define endl '\n'

using namespace std;

#ifdef DEBUG
    template <template <class, class> class Container, class T, class Alloc = std::allocator<T> >
        std::ostream &operator<<(
            std::ostream &os,
            const Container<T, Alloc> &container)
        {
            const char *sep[] = {"", ", "};
            int s = 0;
            os << "[ ";
            for (const T &elt : container)
            {
                os << sep[s] << elt;
                s = 1;
            }
            return os << " ]";
        }

        template <typename T1, typename T2>
        std::ostream &operator<<(std::ostream &os,
                                const std::map<T1, T2> &m)
        {
            const char *sep[] = {"", ", "};
            int s = 0;
            os << "{ ";
            for (const auto &elt : m)
            {
                os << sep[s] << elt.first << ": " << elt.second;
                s = 1;
            }
            return os << " }";
        }

        template <typename T1>
        std::ostream &operator<<(std::ostream &os,
                                const std::set<T1> &m)
        {
            const char *sep[] = {"", ", "};
            int s = 0;
            os << "{ ";
            for (const auto &elt : m)
            {
                os << sep[s] << elt;
                s = 1;
            }
            return os << " }";
        }

        template <typename T1, typename T2>
        std::ostream &operator<<(
            std::ostream &os,
            const pair<T1, T2> p)
        {
            return cout << '<' << p.first << "," << p.second << ">";
        }

        #define debug_header()  cout << " (debug) " << setw(12) << __FUNCTION__ << ", " << setw(3) << __LINE__ << "    |    "
        #define variable(x)     #x << " = " << x
        #define debug1(x)       debug_header() << variable(x) << endl;
        #define debug2(x, y)    debug_header() << variable(x) << ", " << variable(y) << endl;
        #define debug3(x, y, z) debug_header() << variable(x) << ", " << variable(y) << ", " << variable(z) << endl;
#endif 

//compile: g++ -D DEBUG [arquivo.cpp] -o [arquivo] && ./[arquivo] < input.txt > output.txt

int main () {
    ios_base::sync_with_stdio(false);

    return 0;
}
