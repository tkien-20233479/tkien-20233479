#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Cấu trúc Node biểu diễn một mục trong sách
struct Node {
    string title;                  // Tên mục
    int startPage;                 // Trang bắt đầu
    int endPage;                   // Trang kết thúc
    vector<Node*> subSections;     // Danh sách các mục con

    Node(string t, int start, int end) : title(t), startPage(start), endPage(end) {}
};

// Hàm đếm số chương trong cây
int countChapters(Node* root) {
    if (!root) return 0; // Nếu node rỗng, trả về 0

    int count = 0;

    // Kiểm tra nếu node hiện tại là "chapter"
    if (root->title.find("Chapter") == 0) { // Tên bắt đầu bằng "Chapter"
        count = 1;
    }

    // Đệ quy đếm các chương trong các mục con
    for (auto sub : root->subSections) {
        count += countChapters(sub);
    }

    return count;
}

// Hàm tìm chương dài nhất
Node* findLongestChapter(Node* root, Node* longestChapter = nullptr) {
    if (!root) return longestChapter;

    // Duyệt tất cả các chương và cập nhật chương dài nhất
    if (root->title.find("Chapter") == 0) { // Kiểm tra nếu là chương
        int length = root->endPage - root->startPage + 1;
        if (!longestChapter || length > (longestChapter->endPage - longestChapter->startPage + 1)) {
            longestChapter = root;
        }
    }

    // Đệ quy qua các mục con
    for (auto sub : root->subSections) {
        longestChapter = findLongestChapter(sub, longestChapter);
    }

    return longestChapter;
}

// Hàm tìm và xóa một mục khỏi cây
bool deleteSection(Node* root, const string& title) {
    if (!root) return false;
    for (auto it = root->subSections.begin(); it != root->subSections.end(); ++it) {
        if ((*it)->title == title) {
            delete *it; // Giải phóng bộ nhớ
            root->subSections.erase(it);
            return true;
        }
        if (deleteSection(*it, title)) {
            return true;
        }
    }
    return false;
}

// Hàm hiển thị cây mục lục
void printTree(Node* root, int depth = 0) {
    if (!root) return;
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << root->title << " (" << root->startPage << "-" << root->endPage << ")" << endl;
    for (auto sub : root->subSections) {
        printTree(sub, depth + 1);
    }
}

int main() {
    // Tạo cây mục lục
    Node* root = new Node("Science Book", 1, 300);

    // Tạo các chương
    Node* chapter1 = new Node("Chapter 1: Physics", 1, 50);
    Node* chapter2 = new Node("Chapter 2: Chemistry", 51, 120);
    Node* chapter3 = new Node("Chapter 3: Biology", 121, 210);
    Node* chapter4 = new Node("Chapter 4: Astronomy", 211, 240);
    Node* chapter5 = new Node("Chapter 5: Geology", 241, 300);

    // Tạo các mục con trong Chapter 2 (Chemistry)
    Node* section21 = new Node("Section 2.1: Atomic Structure", 51, 80);
    Node* section22 = new Node("Section 2.2: Chemical Reactions", 81, 100);
    Node* section23 = new Node("Section 2.3: Organic Chemistry", 101, 120);

    // Tạo các mục con trong Chapter 3 (Biology)
    Node* section31 = new Node("Section 3.1: Cell Biology", 121, 140);
    Node* section32 = new Node("Section 3.2: Genetics", 141, 160);
    Node* section33 = new Node("Section 3.3: Evolution", 161, 210);

    // Gắn các mục con vào các chương
    chapter2->subSections.push_back(section21);
    chapter2->subSections.push_back(section22);
    chapter2->subSections.push_back(section23);

    chapter3->subSections.push_back(section31);
    chapter3->subSections.push_back(section32);
    chapter3->subSections.push_back(section33);

    // Gắn các chương vào cây mục lục
    root->subSections.push_back(chapter1);
    root->subSections.push_back(chapter2);
    root->subSections.push_back(chapter3);
    root->subSections.push_back(chapter4);
    root->subSections.push_back(chapter5);

    // Hiển thị cây mục lục ban đầu
    cout << "---- Initial Table of Contents ----" << endl;
    printTree(root);

    // Đếm số chương trong sách
    cout << "\nNumber of chapters: " << countChapters(root) << endl;

    // Tìm chương dài nhất
    Node* longestChapter = findLongestChapter(root);
    cout << "\nLongest Chapter: " << longestChapter->title << " (" 
         << longestChapter->startPage << "-" << longestChapter->endPage << ")" << endl;

    // Thực hiện xóa một mục con
    string sectionToDelete = "Section 3.2: Genetics";
    cout << "\nDeleting '" << sectionToDelete << "'..." << endl;
    if (deleteSection(root, sectionToDelete)) {
        cout << "'" << sectionToDelete << "' has been deleted." << endl;
    } else {
        cout << "Could not delete '" << sectionToDelete << "'." << endl;
    }

    // Hiển thị cây sau khi xóa mục con
    cout << "\n---- Table of Contents After Deletion ----" << endl;
    printTree(root);

    // Giải phóng bộ nhớ
    delete root;

    return 0;
}

