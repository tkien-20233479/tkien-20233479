#include<iostream>
#include<sstream>
using namespace std;

struct Node{
	string tu;
	int dem;
	Node* next;
};

void themTu(Node*& head, string s){
	Node* tmp = head;
	while(tmp->next != NULL){
		if(tmp->tu == s){
			tmp->dem++;
			return;
		}
		tmp = tmp->next;
	}
	if(tmp->tu == s){
		tmp->dem++;
	}
	else{
		Node* tuMoi = new Node;
		tuMoi->tu = s;
		tuMoi->dem = 1;
		tuMoi->next = NULL;
		tmp->next = tuMoi;
	}
}

void taoDanhSachTuCau(Node*& head, string s){
	stringstream ss(s);
	string tach;
	while(ss >> tach){
		themTu(head, tach);
	}
}

string XhNhieuNhat(Node* head){
	Node* tmp = head;
	Node* res = tmp;
	while(tmp != NULL){
		if(res->dem < tmp->dem) res = tmp;
		tmp = tmp->next;
	}
	return res->tu;
}


int soTu(Node* head){
	int cnt = 0;
	while(head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

int main(){
	
	return 0;
}