#include<iostream>
using namespace std;

struct File{
	string name;
	int size;
	string time;
	File* next;
};

struct Folder{
	File* head;
};

void sapXep(Folder& D){
	File* dau = D.head;
	for(File* i = dau; i->next != NULL; i = i->next){
		for(File* j = i->next; j != NULL; j = j->next){
			if(j->time < i->time){
				swap(j->name, i->name);
				swap(j->size, i->size);
				swap(j->time, i->time);
			}
		}
	}
}

void copy(Folder& D, File* x){
	x->next = D.head;
	D.head = x;
	sapXep(D);
}

void sapXepTheoCo(Folder& D){
	File* dau = D.head;
	for(File* i = dau; i->next != NULL; i = i->next){
		for(File* j = i->next; j != NULL; j = j->next){
			if(j->size > i->size){
				swap(j->name, i->name);
				swap(j->size, i->size);
				swap(j->time, i->time);
			}
		}
	}
}

void luuVaoUSB(Folder& D){
	sapXepTheoCo(D);
	int size = 0;
	File* head = D.head;
	while(head != NULL){
		if(size += head->size >= 32000){
			head->next = NULL;
			return;
		}
		else{
			size += head->size;
		}
		head = head->next;
	}
}

int tinhCo(Folder D){
	File* head = D.head;
	int size = 0;
	while(head != NULL){
		size += head->size;
		head = head->next;
	}
	return size;
}

void in(Folder D){
	File* head = D.head;
	while(head != NULL){
		cout << head->time <<  ' ';
		head = head->next;
	}
}

int main(){
	File* a = new File();
	a->name = "test.txt";
	a->size = 123;
	a->time = "1/2/3";
	a->next = NULL;
	
	File* b = new File();
	b->name = "test1.txt";
	b->size = 13;
	b->time = "1/2/2";
	b->next = NULL;
	
	File* c = new File();
	c->name = "test3.txt";
	c->size = 32;
	c->time = "1/2/4";
	c->next = NULL;
	
	Folder D;
	D.head = NULL;
	copy(D, a);
	copy(D, b);
	copy(D, c);
	in(D);
	cout << endl << tinhCo(D) << endl;
	sapXepTheoCo(D);
	in(D);
	return 0;
}