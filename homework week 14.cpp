#include<iostream>
using namespace std;
struct node{
	string data;
	node* left;
	node* right; 
};
struct tree{
	node* root;
};
void khoitaocay(tree* tree){
	tree->root = NULL;
}
//Ham kiem tra rong
bool isEmpty(tree* tree){
	return tree->root == NULL;
}
void tao_cay(tree* tree){
	cout<<"Nhap data cho goc:"<<endl;
	string data;
	cin>>data;
	node* newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	tree->root = newnode;
}
void nhap_node_trai(node* root){
	if (root == NULL) {
        cout << "Root chua duoc khoi tao!" << endl;
        return;
    }
	string data;
	cout<<"Nhap data node trai:"<<endl;
	cin>>data;
	node* leftnode = new node;
	root->left = leftnode;
	leftnode->data = data;
	leftnode->left = NULL;
	leftnode->right = NULL;
}
void nhap_node_phai(node* root){
	if (root == NULL) {
        cout << "Root chua duoc khoi tao!" << endl;
        return;
    }
    string data;
    cout<<"Nhap data node phai:"<<endl;
    cin>>data;
	node* rightnode = new node;
	root->right = rightnode;
	rightnode->data = data;
	rightnode->left = NULL;
	rightnode->right = NULL;
}
void incay(tree* tree){
	cout<<"                        "<<tree->root->data<<endl;
	cout<<"                     /     \\"<<endl;
	cout<<"                    "<<tree->root->left->data<<"         "<<tree->root->right->data<<endl;
	cout<<"                  /   \\     /    \\"<<endl;
	cout<<"                 "<<tree->root->left->left->data<<"    "<<tree->root->left->right->data<<"     "<<tree->root->right->left->data<<"      "<<tree->root->right->right->data<<endl;
	cout<<"               /  \\   /\\    /\\     /\\"<<endl;
	cout<<"              "<<tree->root->left->left->left->data<<"    "<<tree->root->left->left->right->data<<"  "<<tree->root->left->right->left->data<<" "<<tree->root->left->right->right->data<<"   "<<tree->root->right->left->left->data<<" ";
	cout<<tree->root->right->left->right->data<<"    "<<tree->root->right->right->left->data<<" "<<tree->root->right->right->right->data<<endl;
	cout<<"                        /\\           /\\"<<endl;
	cout<<"                       "<<tree->root->left->right->right->left->data<<"  "<<tree->root->left->right->right->right->data;
	cout<<"          "<<tree->root->right->right->right->left->data<<" "<<tree->root->right->right->right->right->data<<endl;
	cout<<"                          /\\"<<endl;
	cout<<"                         "<<tree->root->left->right->right->right->left->data<<" "<<tree->root->left->right->right->right->right->data<<endl;
}
void trungto(node* root){//trai->goc->phai
	if(root != NULL){
		trungto(root->left);
		cout<<root->data;
		trungto(root->right);
	}
}
void hauto(node* root){//trai->phai->goc
	if(root!= NULL){
		hauto(root->left);
		hauto(root->right);
		cout<<root->data;
	}
}
void tiento(node* root){
	if(root != NULL){
		cout<<root->data;
		tiento(root->left);
		tiento(root->right);
	}
}
int main(){
	tree tree;
	khoitaocay(&tree);
	//a*5-b*c^6/d+(h-f)*e^1/2
	//                        1                     hang 1
	//                     /     \                  
	//                    2         3               hang 2
	//                  /   \     /    \            
	//                 4    5     6      7          hang 3
	//               /  \   /\    /\     /\   
	//              8   9  10 11 12 13  14 15       hang 4
	//                        /\           /\
	//                       16 17        18 19     hang 5
	//                          /\
	//                         20 21                hang 6
	//Nhap data cho hang 1(goc)
	cout<<"Nhap data cho hang 1(goc):"<<endl;
	tao_cay(&tree); //node 1
	//Nhap data cho hang 2
	cout<<"\nNhap data 2 node trai phai cua node 1"<<endl;
	nhap_node_trai(tree.root); //node 2
	nhap_node_phai(tree.root); //node 3
	//Nhap data cho hang 3
	cout<<"\nNhap data cho 2 node trai phai cua node 2"<<endl;
	nhap_node_trai(tree.root->left); //node 4
	nhap_node_phai(tree.root->left); //node 5
	cout<<"Nhap data cho 2 node trai phai cua node 3"<<endl;
	nhap_node_trai(tree.root->right); //node 6
	nhap_node_phai(tree.root->right); //node 7
	//Nhap data cho hang 4
	cout<<"Nhap data cho 2 node trai phai cua node 4"<<endl;
	nhap_node_trai(tree.root->left->left);//node 8
	nhap_node_phai(tree.root->left->left);//node 9
	cout<<"Nhap data cho 2 node trai phai cua node 5"<<endl;
	nhap_node_trai(tree.root->left->right);//node 10
	nhap_node_phai(tree.root->left->right);//node 11
	cout<<"Nhap data cho 2 node trai phai cua node 6"<<endl;
	nhap_node_trai(tree.root->right->left);//node 12
	nhap_node_phai(tree.root->right->left);//node 13
	cout<<"Nhap data cho 2 node trai phai cua node 7"<<endl;
	nhap_node_trai(tree.root->right->right);//node 14
	nhap_node_phai(tree.root->right->right);//node 15
	//Nhap data cho hang 5
	cout<<"Nhap data cho 2 node trai phai cua node 11"<<endl;
	nhap_node_trai(tree.root->left->right->right);//node 16
	nhap_node_phai(tree.root->left->right->right);//node 17
	cout<<"Nhap data cho 2 node trai phai cua node 15"<<endl;
	nhap_node_trai(tree.root->right->right->right);//node 18
	nhap_node_phai(tree.root->right->right->right);//node 19
	//Nhap data cho hang 6
	cout<<"Nhap data cho 2 node trai phai cua node 17"<<endl;
	nhap_node_trai(tree.root->left->right->right->right);//node 20
	nhap_node_phai(tree.root->left->right->right->right);//node 21
	cout<<"\nHinh cay:"<<endl;
	incay(&tree);
	cout<<"-------------------------------------------"<<endl;
    cout<<"Bieu thuc trung to:"<<endl;
	trungto(tree.root);
	cout<<"\nBieu thuc tien to:"<<endl;
	tiento(tree.root);
	cout<<"\nBieu thuc hau to:"<<endl;
	hauto(tree.root);
	return 0;
}