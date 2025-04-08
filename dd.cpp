#include <iostream>
using namespace std;
int d[1000001];
int p[1000001];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	p[1] = 0;
	p[2] = 1;
	p[3] = 1;

	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		p[i] = i - 1;
		if (i % 2 == 0){
			if (d[i / 2] + 1 < d[i]) {
				d[i] = d[i / 2] + 1;
				p[i] = i / 2;
			}
		}
		if (i % 3 == 0){
			if (d[i / 3] + 1 < d[i]) {
				d[i] = d[i / 3] + 1;
				p[i] = i / 3;
			}
		}
	}
	cout << d[n] << '\n';
	while (n > 0) {
		cout << n << ' ';
		n = p[n];
	}
}
/*
	���� '1�� �����'�������� ��� �����ϴ� �κ��� �߰��� ����.
	������ '1�� �����'�ڵ�δ� ��� ������ �ϱⰡ ����. �� ���� ������ �� �߰��� ������ ���� ���� �ɱ�..

*/