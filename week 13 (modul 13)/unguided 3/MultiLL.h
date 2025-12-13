#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
#include <string>
using namespace std;
struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};
struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};
typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;
struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};
struct listChild {
    NodeChild first;
    NodeChild last;
};
struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};
struct listParent {
    NodeParent first;
    NodeParent last;
};
bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);
void createListParent(listParent &L);
void createListChild(listChild &L);
NodeParent allocNodeParent(string id, string nama);
NodeChild allocNodeChild(string id, string nama, string hab, bool ekor, float brt);
void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &C);
void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Pre);
void deleteParent(listParent &L, string id);
void insertFirstChild(listChild &L, NodeChild C);
void insertLastChild(listChild &L, NodeChild C);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Pre);
void deleteListChild(listChild &L);
void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);
#endif