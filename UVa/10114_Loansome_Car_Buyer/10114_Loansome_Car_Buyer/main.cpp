#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	setbuf(stdout, 0);

	int month, num_depre;
	double down_pay, loan, depre[101];

	while (1) {
		cin >> month >> down_pay >> loan >> num_depre;
		if (month < 0)
			break;

		int n;
		double p;
		while (num_depre--) {
			cin >> n >> p;
			for (int i = n; i < 101; ++i) {
				depre[i] = p;
			}
		}

		double cur_val = (down_pay + loan) * (1 - depre[0]);
		double cur_loan = loan;
		double monthly_pay = loan / (double)month;

		int ret = 0;
		while (cur_val <= cur_loan) {
			ret++;
			cur_val *= (1 - depre[ret]);
			cur_loan -= monthly_pay;
		}
		cout << ret << " month";
		if (ret > 1)
			cout << "s";
		cout << "\n";
	}

	return 0;
}