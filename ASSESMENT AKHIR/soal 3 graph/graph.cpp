#include <iostream>
#include <string>
using namespace std;
struct Node;
struct Edge {
    Node* tujuan;
    Edge* nextEdge;
};
struct Node {
    string nama;
    bool dikunjungi;
    bool terkunci; 
    Edge* firstEdge;
    Node* nextNode;
};
struct Graph {
    Node* head;
};
void tambahNode(Graph& g, string nama) {
    Node* newNode = new Node{nama, false, false, nullptr, nullptr};
    if (!g.head) {
        g.head = newNode;
    } else {
        Node* temp = g.head;
        while (temp->nextNode) temp = temp->nextNode;
        temp->nextNode = newNode;
    }
}
Node* cariNode(Graph& g, string nama) {
    Node* temp = g.head;
    while (temp) {
        if (temp->nama == nama) return temp;
        temp = temp->nextNode;
    }
    return nullptr;
}
void tambahEdge(Graph& g, string src, string dst) {
    Node* s = cariNode(g, src);
    Node* d = cariNode(g, dst);
    if (s && d) {
        s->firstEdge = new Edge{d, s->firstEdge};
        d->firstEdge = new Edge{s, d->firstEdge};
    }
}
void DFS(Node* current, int& count) {
    current->dikunjungi = true;
    count++;
    Edge* e = current->firstEdge;
    while (e) {
        if (!e->tujuan->dikunjungi && !e->tujuan->terkunci) {
            DFS(e->tujuan, count);
        }
        e = e->nextEdge;
    }
}

int main() {
    Graph g = {nullptr};
    cout << "membangun jaringan distribusi vaksin" << endl;
    tambahNode(g, "A"); tambahNode(g, "B"); tambahNode(g, "C");
    tambahNode(g, "D"); tambahNode(g, "E");
    tambahEdge(g, "A", "B");
    tambahEdge(g, "B", "E");
    tambahEdge(g, "B", "C");
    tambahEdge(g, "C", "D");
    Node* curr = g.head;
    while (curr) {
        cout << "node " << curr->nama << " terhubung ke: ";
        Edge* e = curr->firstEdge;
        while (e) {
            cout << e->tujuan->nama << " ";
            e = e->nextEdge;
        }
        cout << endl;
        curr = curr->nextNode;
    }
    cout << "\n analisis kota kritis" << endl;
    int totalNodes = 0;
    for (Node* t = g.head; t; t = t->nextNode) totalNodes++;
    Node* testNode = g.head;
    while (testNode) {
        for (Node* r = g.head; r; r = r->nextNode) r->dikunjungi = false;
        testNode->terkunci = true;
        Node* start = (testNode == g.head) ? g.head->nextNode : g.head;
        int reached = 0;
        if (start) DFS(start, reached);
        if (reached < (totalNodes - 1)) {
            cout << "[PERINGATAN] kota " << testNode->nama << " adalah KOTA KRITIS!" << endl;
            cout << "-> jika " << testNode->nama << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "kota " << testNode->nama << " aman (redundansi oke)." << endl;
        }

        testNode->terkunci = false; 
        testNode = testNode->nextNode;
    }

    return 0;
}