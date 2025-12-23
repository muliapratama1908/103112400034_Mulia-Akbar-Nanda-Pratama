#include "BST.h"
int main() {
    createTree();
    float b[] = {60, 50, 65, 47, 56, 70, 52, 68, 81};
    string n[] = {"Rizkina Azizah", "Hakan Ismail", "Olivia Saevali", "Felix Pedrosa", "Gamel Al Ghifari", "Hanif Al Faiz", "Mutiara Fauziah", "Davi Ilyas", "Abdad Mubarok"};
    string t[] = {"Basic", "Bronze", "Silver", "Gold", "Platinum", "Basic", "Bronze", "Silver", "Gold"};
    for(int i=0; i<9; i++) root = insertNode(root, n[i], b[i], t[i]);
    cout << "traversal indOrder\n"; inOrder(root); cout << endl;
    mostLeft(); mostRight(); cout << endl;
    searchByBeratBadan(70);
    return 0;
}