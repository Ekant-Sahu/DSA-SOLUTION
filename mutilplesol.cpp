#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include<math.h>
#include<algorithm>
#include<numeric>
 
 
//int main()
//{
//    int n;
//    int s = 1;
//    cin >> n;
//    int arr[n];
//    int sum = 1;
//    int x;
//    for (int i = 0; i < n - 1; i++) {
//        cin >> arr[i];
//        sum = sum ^ arr[i];
//    }
//    for (int i = 1; i <= n; i++) {
//        s = s ^ i;
//    }
//    x = sum ^ s;
//    cout << x;
//    return 0;
//}
 
//int main() {
//	string b;
//	cin >> b;
//	int co = 0;
//	int best = 0;
//	int n = b.length();
//	for (int i = 0; i < n; i++) {
//			if (b[i] == b[i+1]) { ++co; }
//			else { co = 0; continue; }
//		best = max(best, co);
//	}
//	cout << best+1;
//	return 0;
//}
 
//int main() {
//	const int m = 200000;
//	int n;
//	cin>>n;
//	long long move = 0;
//	int arr[m];
//	for (int i = 0; i < n; i++) { cin >> arr[i]; }
//	for (int i = 0; i < n - 1; i++) {
//		if (arr[i] > arr[i + 1]) { move = move + (arr[i] - arr[i + 1]); arr[i + 1] = arr[i]; }
//		else{continue;}
//	}
//	cout << move;
//}
 
//bool pwer(int k) {
//	if (k == 1) { return true; }
//	else if (k % 2 != 0) { return false; }
//	else {
//		k = k / 2;
//		pwer(k);	
//	}
//}
//int main() {
//	cout<<pwer(8);
//}
 
 
//int main() {
//	int n;
//	deque<int> sol = {3,1,4,2};
//	cin >> n;
//	if (n == 1) { cout << 1; }
//	else if (n == 2 or n == 3) { cout << "NO SOLUTION"; }
//	else if(n == 4){
//		for (int i = 0; i < sol.size(); i++) {
//			cout << sol[i] << " ";
//		}
//	}
//	else {
//		for (int i = 5; i <= n; i++) {
//			if (i % 2) { sol.push_back(i); }
//			else { sol.push_front(i); }
//		}
//		for (int i = 0; i < sol.size(); i++) {
//			cout << sol[i] << " ";
//		}
//	}
//}
 
 
 
//int factor(int n) 
//{
//	static int count = 0;
//	if (n == 5)return count += 1;
//	else if (n < 5 and n>0)return count;
//	else {
//		count += n / 5;
//		factor(n / 5);
//		
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << factor(n);
//	return 0;
//}
 
 
//const unsigned int m = 1000000007;
//long long int power(int a) {
//	if (a == 0) { return 1;}
//	else {
//		return (2* power(a - 1)%m);
//	}
//}
//
//int main() {
//	int a;
//	cin >> a;
//	cout << (power(a));
//	return 0;
//}
//int n = 7;
//int sum = 14;
//vector<int> subset;
//void search(int k) {
//	if (k == n + 1) {
//		int s = 0;
//		for (auto i = subset.begin(); i != subset.end(); ++i) {
//			s = s + *i;
//			cout << s<<endl;
//		}
//		if (sum == s) {return;}
//	}
//	else {
//		// include k in the subset
//		subset.push_back(k);
//		search(k + 1);
//		subset.pop_back();
//		// don�t include k in the subset
//		search(k + 1);
//	}
//}
//
//int main() {
//	search(1);
//	for (auto i = subset.begin(); i != subset.end(); ++i) {
//		cout<<*i;
//	}
//}
 
//int sum(vector<int> ans) {
//	int sum = 0;
//	for (auto i = ans.begin(); i != ans.end(); ++i) {
//		sum = sum + *i;
//	}
//	return sum;
//}
//
//
//
//int n = 7;
//
//void search(int k=1) {
//	static vector<int> ans;
//	if (sum(ans) == 14) {
//		for (auto i = ans.begin(); i != ans.end(); ++i) {
//			cout << *i << " ";
//		}
//		cout << endl;
//		return; }
//	else if (k == n + 1) { return; }
//	else {
//		ans.push_back(k);
//		//cout << sum(ans) << endl;
//		search(k + 1);
//		ans.pop_back();
//		//cout << sum(ans) << endl;
//		search(k + 1);
//	}
//}
 
 
 
//digit quries
//typedef long long as ll;
//int main()
//{
//	int q;
//	cin >> q;
//	vector<long long> powerOfTen(19, 1);
//	for (int i = 1; i < 19; i++) powerOfTen[i] = powerOfTen[i - 1] * 10;
//	while (q--) 
//	{
//		long long index;
//		cin >> index;
//		long long digitsSoFar = 0;
//		long long digitsBeforeActualBlock = 0;
//		int numberOfDigit;
//		for (int i = 1; i <= 18; i++) 
//		{
//			digitsSoFar += (powerOfTen[i] - powerOfTen[i - 1]) * i;
//			if (digitsSoFar >= index) { numberOfDigit = i; break; }
//			digitsBeforeActualBlock += (powerOfTen[i] - powerOfTen[i - 1] * i);
//		}
//		long long smalestValue = powerOfTen[numberOfDigit - 1];
//		long long largestValue = powerOfTen[numberOfDigit] - 1;
//		long long bestValue = 0;
//		long long startingPsistionOfBestValue;
//		while (smalestValue <= largestValue) 
//		{
//			long long actualValue = (smalestValue + largestValue) / 2;
//			long long staringPositionOfActualValue = 1 + digitsBeforeActualBlock + (actualValue - powerOfTen[numberOfDigit]) * numberOfDigit;
//			if (startingPsistionOfBestValue <= index)
//			{
//				if (actualValue > bestValue) {
//					bestValue = actualValue;
//					startingPsistionOfBestValue = staringPositionOfActualValue;
//				}
//				smalestValue = actualValue + 1;
//			}
//			else
//				largestValue = actualValue - 1;
//		}
//		string number = to_string(bestValue);
//		cout << number[index - startingPsistionOfBestValue] << endl;
//		
//	}
//
//
//	return 0;
//}
 
 
//int main() 
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (a > 2 * b or b > 2 * a) { cout << "NO"<<endl; }
//		else if ((a + b) % 3 == 0) { cout << "YES"<<endl; }
//		else { cout << "NO"<<endl; }
//		}
//}
 
 
//vector<int> ans;
//vector<vector<int>> v;
//
//int sum(vector<int> ans) {
//	int sum = 0;
//	for (auto i = ans.begin(); i != ans.end(); ++i) {
//		sum = sum + *i;
//	}
//	return sum;
//}
//
//
//void search(int k, int n) {
//
//	int s = n * (n + 1) / 4;
//	if (sum(ans) == s) {
//		v.push_back(ans);
//		return;
//	}
//	else if (k == n + 1) { return;j}
//	else {
//		ans.push_back(k);
//		search(k + 1, n);
//		ans.pop_back();
//		search(k + 1, n);
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	if (n * (n + 1) % 4 == 0) {
//		cout << "YES"<<endl;
//		search(1, n);
//		cout << v[0].size() << endl;
//		for (auto i = v[0].begin(); i != v[0].end(); ++i) {
//			cout << *i << " ";
//		}
//		cout << endl;
//		cout << v[v.size() - 1].size() << endl;
//		for (auto i = v[v.size() - 1].begin(); i != v[v.size() - 1].end(); ++i) {
//			cout << *i << " ";
//		}
//	}
//	else { cout << "NO"<<endl; }
//}
 
 
//string ans = "";
//bool chosen[100000];
//vector<string> contain;
//
//bool check(string str) 
//{
//	for (int i = 0; i < contain.size(); i++)
//	{
//		if (contain[i] == str) { return true; }
//		else { continue; }
//	}
//	return false;
//}
//
//void search(string str) {
//	if (ans.length() == str.length() and !check(ans)) {
//		contain.push_back(ans);
//		return;
//		
//	}
//	else {
//		for (int i = 0; i < str.length(); i++) {
//			if (chosen[i]) continue;
//			chosen[i] = true;
//			ans.push_back(str[i]);
//			search(str);
//			chosen[i] = false;
//			ans.pop_back();
//		}
//	}
//}
//
//
//int main() 
//{
//	string str;
//	cin >> str;
//	vector<string> permutations;
//	sort(str.begin(), str.end());
//	do 
//	{
//		permutations.push_back(str);
//	} while (next_permutation(str.begin(), str.end()));
//	cout << permutations.size() << endl;
//	for (string i : permutations)
//		cout << i << endl;
//	
//	return 0;
//}
 
 
//tower of hannoi
 
 
 
//vector<int> ans;
//
//void hannoi(int n, int start, int end) 
//{
//
//	if (n == 1) { 
//	//cout << start << " " << end << endl;
//	ans.push_back(start); ans.push_back(end); return; }
//	else 
//	{
//		int other = 6 - (start + end);
//		hannoi(n - 1,start, other);
//		//cout << start << " " << end<<endl;
//		ans.push_back(start); ans.push_back(end);
//		hannoi(n - 1, other, end);
//	}
//}
//
//int main() 
//{	
//	int n;
//	cin >> n;
//	hannoi(n, 1, 3);
//	cout << ans.size()/2<<endl;
//	for (int i = 0; i < ans.size() ; i = i + 2) { cout << ans[i]<<" " << ans[i + 1] << endl; }
//	return 0;
//}
 
//vector<int> subset;
//vector<int> v = { 3,2,7,4,1 };
//void search(int k = 0) {
//	static int m = INFINITY;
//	if (k == v.size()) {
//		for (auto& i : subset) { cout << i <<" "; }
//		cout << endl;
//	}
//
//	else 
//	{
//		subset.push_back(v[k]);
//		search(k+1);
//		subset.pop_back();
//		search(k+1);
//	}
//}
//
//int main()
//{
//	search();
//}
 
 
//int main()
//{
//	int n, m, k, count = 0;
//	vector<long long> desired;
//	vector<long long> available;
//	cin >> n >> m >> k;
//	for (int i = 0; i < n; i++)
//	{
//		long long a;
//		cin >> a;
//		desired.push_back(a);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		long long a;
//		cin >> a;
//		available.push_back(a);
//	}
//	sort(desired.begin(), desired.end());
//	sort(available.begin(), available.end());
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (abs(desired[i]-available[j])<=k) { count++; break; }
//		}
//	}
//	cout << count;
//	return 0;
//}
 
 
//int main()
//{
//	int n, x;
//	vector<int> w;
//	cin >> n >> x;
//	for (int i = 0; i < n; i++) {
//		int a;
//		cin >> a;
//		w.push_back(a);
//	}
//	sort(w.rbegin(), w.rend());
//	int i = 0;
//	int j = n - 1;
//	int count = 0;
//	while (i <= j)
//	{
//		if (w[i] + w[j] <= x)
//		{
//			count++;
//			i++;
//			j--;
//		}
//		else {
//			count++;
//			i++;
//		}
//	}
//	cout << count;
//}
 
 
 
//int main() {
//
//	vector<pair<int, int>> event;
//	int n;
//	int m = 0;
//	int count = 0;
//	cin >> n;
//	for (int i = 0; i < 2*n; i += 2)
//	{
//		int a;
//		int b;
//		cin >> a >> b;
//		event.push_back(make_pair(a, 1));
//		event.push_back(make_pair(b, -1));
//	}
//
//
//	sort(event.begin(), event.end());
//
//	for (int i = 0; i < 2*n; i++) {
//		count += event[i].second ;
//		m = max(count, m);
//	}
//	cout << m ;
//
//
//
//	return 0;
//}
 
 
//movie
 
 
 
//
 
 
 
// sum of two number
 
 
// int main() 
// {
// 	vector<int> arr;
// 	long long n,x;
// 	bool y = false;
// 	cin >> n >> x;
// 	for (int i = 0; i < n; i ++)
// 	{
// 		int a;
// 		cin >> a ;
// 		arr.push_back(a);
// 	}
// 	for (int i = 0; i < n; i++) 
// 	{
// 		for (int j = i + 1; j < n; j++) 
// 		{
// 			if (arr[i] + arr[j] == x) { cout << i+1<< " " << j + 1 << endl; y = true; break; }
// 		}
// 	}
// 	if (!y) { cout << "IMPOSSIBLE"; }
// }

// stick length

int main()
{
	int n;
	long long cost = 0;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) 
	{
		long long a;
		cin >> a;
		v.push_back(a);
	}
    sort(v.begin(),v.end());
	long long medium = v[n / 2];
	for(int i = 0; i<n; i++)
	{
		cost += abs(v[i] - medium);
	}
	cout << cost;
}