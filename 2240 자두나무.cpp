#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[1001][31];
int t, w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> w;
	vector<int> jadu;
	int cur = 1, sm = 0;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		if (num != cur) {
			jadu.push_back(sm);
			cur = num;
			sm = 1;
		}
		else sm++;
	}
	jadu.push_back(sm);
	int l = jadu.size();
	/*
	자두(인간)가 어떤 나무에 서 있든 자두가 연속적으로 내려올 때 위치를 바꾸는 것은 항상 손해라고 생각해서
	연속적으로 내려오는 자두들끼리 묶어서 계산을 하려고 했습니다.

	jadu 배열에 인덱스 0은 1번 나무에서 내려 오는 자두, 1은 2번 나무에서 내려오는 자두, 2는 1번 나무, 3은 2번 나무..입니다.
	즉, 인덱스가 짝수면 1번 나무, 홀 수면 2번 나무 입니다.

	첫 자두가 2번 나무에서 떨어지면 jadu[0]은 0으로 나오게 했습니다.
	*/

	d[0][0] = jadu[0];
	if (l > 1) {
		d[1][0] = jadu[0];
		d[1][1] = jadu[1] + jadu[0];
	}

	for (int i = 2; i < l; i++) {
		for (int j = 0; j <= w; j++) {
			int a = 0;
			if (j == 0) d[i][0] = d[i - 1][0] + jadu[i];
			else {
				// 자두가 움직인 횟수가 홀수일 경우 2번 나무, 짝수일 경우 1번 나무에 가게 된다.
				if (i % 2 == j % 2) a = jadu[i];
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a;
			}
		}
	}
	cout << *max_element(d[l - 1], d[l - 1] + w + 1);

	/*
	테이블은 d[i][j] j번 이동하고 i시점(자두 한 뭉탱이 당 1초씩 내려온다고 문제를 재정의 했습니다.
	인간 자두의 이동이 시간에 영향을 받지 않는 다고 판단해서 이렇게 재정의 해봤습니다.)까지 왔을 때
	가질 수 있는 최대 자두의 수 입니다.
	*/

	
	/*
	[복기]
	1. 문제에 대해서 더 깊이 생각해보고 코딩을 시작하자.
	2. DP문제를 풀 때 테이블을 어떻게 잡으면 좋을 지 먼저 생각하자.
	*/