#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* left;
    Node* right;
    Node(int n): nilai(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int nilai) {
    if (!root) return new Node(nilai);
    if (nilai < root->nilai) root->left = insertNode(root->left, nilai);
    else if (nilai > root->nilai) root->right = insertNode(root->right, nilai);
    return root;
}

bool searchNode(Node* root, int nilai) {
    if (!root) return false;
    if (root->nilai == nilai) return true;
    if (nilai < root->nilai) return searchNode(root->left, nilai);
    return searchNode(root->right, nilai);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->nilai << " ";
    inorder(root->right);
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(Node* root) {
    if (!root) return 0;
    return root->nilai + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, nilai;

    do {
        cout << "\n=== Manajemen Nilai Ujian Siswa (BST) ===\n";
        cout << "1. Tambah Nilai\n";
        cout << "2. Cari Nilai\n";
        cout << "3. Tampilkan Nilai (Inorder)\n";
        cout << "4. Jumlah Data Nilai\n";
        cout << "5. Total Semua Nilai\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan nilai siswa: ";
            cin >> nilai;
            root = insertNode(root, nilai);
        } else if (pilih == 2) {
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> nilai;
            cout << (searchNode(root, nilai) ? "Nilai ditemukan\n" : "Nilai tidak ditemukan\n");
        } else if (pilih == 3) {
            cout << "Urutan nilai (terkecil-ke-terbesar): ";
            inorder(root);
            cout << endl;
        } else if (pilih == 4) {
            cout << "Jumlah data nilai: " << countNodes(root) << endl;
        } else if (pilih == 5) {
            cout << "Total semua nilai: " << sumNodes(root) << endl;
        }
    } while (pilih != 6);

    return 0;
}
