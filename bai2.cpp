#include<bits/stdc++.h>
using namespace std;

const int SIZE = 10001;

long long blum[SIZE];

bool checkSNT(long long n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

bool binarySearch(long long a[], int n, int x){
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(a[m] == x) return true;
		else if(a[m] < x) l = m + 1;
		else r = m - 1;
	}
	return false;
}

int main(){
	int n; cin >> n;
	int idx = 0;
	int cnt = 0; //Lưu số lượng số nửa nguyên tố nhỏ hơn n
	int prime[SIZE]; //mảng lưu các số nguyên tố
	for(int i = 0; i < SIZE; i++){
		if(checkSNT(i)) prime[idx++] = i;
	}
	for(int i = 0; i < idx; i++){
		for(int j = i; j < idx; j++){
			int so_nua_nt = prime[i] * prime[j];
			if(so_nua_nt <= n) blum[cnt++] = so_nua_nt;
			else break;
		}
	}
	//Tao ra mang cac so Blum
	sort(blum, blum + cnt);
	for(int i = 0; i < cnt; i++){
		cout << blum[i] << ' ';
	}

	//Tim ra cac cap so Blum co tong cung la 1 so Blum nho hon n

	for(int i = 0; i < cnt; i++){
		for(int j = i + 1; j < cnt; j++){
			int x = blum[i] + blum[j];
			if(binarySearch(blum, cnt, x)) cout << blum[i] << ' ' << blum[j] << endl;
		}
	}

	//Kiem tra xem 1 so Blum M co ton tai trong day so Blum duoc tao ra hay khong
	int m; cin >> m;
	if(binarySearch(blum, cnt, m)) cout << "YES";
	else cout << "NO";
	return 0;
}