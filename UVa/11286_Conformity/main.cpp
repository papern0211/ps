// My solution

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
/*
	freopen("input.txt", "r", stdin);
	setbuf(stdout, 0);
*/
	int num_student;
	int max_students = 0;
	map<string, int> stats;
	stats.clear();

	while (cin >> num_student, num_student != 0) {
		for (register int n = 0; n < num_student; ++n) {
			vector<int> v;
			v.reserve(5);
			for (register int i = 0; i < 5; ++i) {
				int x; cin >> x; v.push_back(x);
			}
			sort(v.begin(), v.end());
			string s;
			for (register int i = 0; i < 5; ++i) {
				s += to_string(v[i]);
			}
			stats[s]++;
			if (stats[s] > max_students)
				max_students = stats[s];
		}
		int total = 0;
		map<string, int>::iterator it;
		for (it = stats.begin(); it != stats.end(); ++it) {
			if (it->second == max_students)
				total += max_students;
		}
		cout << total << "\n";
		stats.clear();
		max_students = 0;
	}

	return 0;
}

// other's solution

/*11286 - Conformity*/
//
//#include <iostream>
//#include <map>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//
//	int n;
//
//	while (cin >> n and n) {
//
//		int maximo = 0;
//
//		map <vector<int>, int> frosh;
//		vector <int> arr(5);
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				cin >> arr[j];
//			}
//
//			sort(arr.begin(), arr.end());
//
//			if (frosh.count(arr) == 1) {
//				frosh[arr]++;
//			}
//			else {
//				frosh[arr] = 1;
//			}
//
//		}
//
//		map<vector<int>, int>::iterator i;
//
//		for (i = frosh.begin(); i != frosh.end(); ++i)
//		{
//			if ((i->second) > maximo)
//				maximo = i->second;
//		}
//
//		int cont = 0;
//
//		for (i = frosh.begin(); i != frosh.end(); ++i)
//		{
//			if ((i->second) == maximo)
//				cont++;
//
//		}
//		maximo = maximo * cont;
//
//
//		cout << maximo << '\n';
//
//		frosh.clear();
//
//	}
//
//	return 0;
//}

