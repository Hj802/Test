#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string p[1002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> arr(n);
	vector<int> d(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		p[i] = to_string(arr[i]) + " ";
	}
	fill(d.begin(), d.end(), 1);


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = p[j] + to_string(arr[i]) + " ";
			}
		}
	}

	int ans_idx = max_element(d.begin(), d.end()) - d.begin();
	cout << d[ans_idx] << '\n' << p[ans_idx];
}

/*
	문자열을 생각한 부분이 좋았다.
*/