#include <iostream>
#include <map>

using namespace std;

int n;
long long l;
map<long long, long long> pool;

int main() {
    cin >> n >> l;
    long long x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pool[x] = y;
    }
    long long prev_x = 0, first_x = 0, answer = 0;
    for (auto it = pool.begin(); it != pool.end(); it++) {
        if(prev_x>=(*it).second) continue;
        if((*it).first < prev_x) first_x = prev_x;
        else first_x = (*it).first;
        long long cnt = ((*it).second - first_x) / l;
        if (((*it).second - first_x) % l != 0) cnt++;
        prev_x = first_x + cnt * l;
        answer += cnt;
    }
    cout<<answer<<endl;
}