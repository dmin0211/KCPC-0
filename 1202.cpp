#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, k;
multimap<int, int> jewelry;
multiset<int> back;

int main() {
    FIO;
    cin >> n >> k;
    unsigned int weight, price;
    for (int i = 0; i < n; ++i) {
        cin >> weight >> price;
        jewelry.insert({weight, price});
    }
    for (int i = 0; i < k; ++i) {
        cin >> weight;
        back.insert(weight);
    }
    long long answer = 0;
    priority_queue<int> pq;
    auto j_it = jewelry.begin();
    for (auto it = back.begin(); it != back.end(); it++) {
        while(j_it!=jewelry.end() && (*j_it).first <= *it){
            pq.push((*j_it).second);
            j_it++;
        }
        if(pq.empty()) continue;
        answer += pq.top();
        pq.pop();
    }
    cout<<answer<<endl;
}