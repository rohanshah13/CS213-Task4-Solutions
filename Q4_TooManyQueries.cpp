#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	int s = sqrt(n+q)+2;
	list<int> blocks[s];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		blocks[i/s].push_back(a);
	}
	list<int>::iterator it;
	while (q--) {
		char type;
		cin >> type;
		if (type == 'I') {
			int i, x;
			cin >> i >> x;
			i--;
			int block_index = i/s;
			int inner_index = i%s;
			it = blocks[block_index].begin();
			advance(it, inner_index);
			blocks[block_index].insert(it, x);

			while (blocks[block_index].size() == s+1) {
				int last = blocks[block_index].back();
				blocks[block_index].pop_back();
				block_index++;
				blocks[block_index].push_front(last);
			}
		}
		else if (type == 'D') {
			int i;
			cin >> i;
			i--;
			int block_index = i/s;
			int inner_index = i%s;
			it = blocks[block_index].begin();
			advance(it, inner_index);
			blocks[block_index].erase(it);

			while (blocks[block_index+1].size() > 0) {
				block_index++;
				int first = blocks[block_index].front();
				blocks[block_index].pop_front();
				blocks[block_index-1].push_back(first);
			}
		}
		else if (type == 'R') {
			int c; cin >> c;
			int current_block = 0;
			int removed;
			if (c == 1) {
				while (blocks[current_block].size() > 1) {
					removed = blocks[current_block].back();
					blocks[current_block].pop_back();
					blocks[current_block+1].push_front(removed);
					current_block++;
				}
				removed = blocks[current_block].back();
				blocks[current_block].pop_back();
				blocks[0].push_front(removed);
			}
			else {
				while (blocks[current_block+1].size() > 0) {
					removed = blocks[current_block+1].front();
					blocks[current_block+1].pop_front();
					blocks[current_block].push_back(removed);
					current_block++;
				}
				removed = blocks[0].front();
				blocks[0].pop_front();
				blocks[current_block].push_back(removed);
			}
		}
		else if (type == 'P') {
			int i;
			cin >> i;
			i--;
			int block_index = i/s;
			int inner_index = i%s;
			it = blocks[block_index].begin();
			advance(it, inner_index);
			cout << *it << '\n';
		}
	}
}