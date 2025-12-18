# <h1 align="center"> Laporan Praktikum Modul 14 - Graph  </h1>
<p align="center">Mulia Akbar Nanda Pratama - 103112400034</p>

## Dasar Teori
Graph merupakan salah satu struktur data non linear yang digunakan untuk merepresentasikan hubungan atau relasi antar objek. Secara matermatis, graph didefinisikan sebagai pasangan terurut ( G = (V, E) ), di mana ( V ) adalah himpunan simpul (vertex/node) dan ( E ) adalah himpunan sisi (edge) yang menghubungkan pasangan simpul tertentu. Setiap sisi menunjukkan adanya hubungan antara dua simpul dalam graf tersebut [1]. Menurut Harary (1969), graf adalah representasi abstrak yang sangat fleksibel untuk memodelkan berbagai permasalahan dunia nyata, seperti jaringan komputer, sistem transportasi, jaringan sosial, dan struktur organisasi [1].

Ada beberapa jenis graph, meliputi:
1. raf Tak Berarah (Undirected Graph)
Graf yang tidak memiliki arah pada sisinya, sehingga hubungan antar simpul bersifat dua arah.

2. Graf Berarah (Directed Graph / Digraph)
Graf yang setiap sisinya memiliki arah tertentu, menunjukkan relasi dari satu simpul ke simpul lainnya.

3. Graf Berbobot (Weighted Graph)
Graf yang setiap sisinya memiliki nilai bobot tertentu, seperti jarak, biaya, atau waktu.

3. Graf Tak Berbobot (Unweighted Graph)
Graf yang tidak memiliki bobot pada sisinya dan hanya menunjukkan keberadaan hubungan antar simpul.
Klasifikasi ini berpengaruh langsung terhadap pemilihan algoritma graf yang digunakan dalam penyelesaian masalah [2].

### Representasi Graph
Graf dapat direpresentasikan dalam struktur data dengan beberapa metode utama, antara lain:

1. Adjacency Matrix
Menggunakan matriks dua dimensi berukuran ( |V| \times |V| ), di mana setiap elemen matriks menunjukkan ada atau tidaknya sisi antara dua simpul.

2. Adjacency List
Menggunakan daftar yang menyimpan simpul-simpul yang bersebelahan dengan setiap simpul utama.

Menurut Sedgewick dan Wayne, adjacency list lebih efisien dalam penggunaan memori dan sangat cocok untuk graf yang bersifat jarang (sparse graph) [3].

### Algoritma pada Graph
Beberapa algoritma penting yang sering digunakan pada graf meliputi:
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Algoritma Dijkstra
- Algoritma Bellman-Ford
- Algoritma Prim dan Kruskal

Algoritma-algoritma tersebut digunakan untuk pencarian jalur terpendek, traversal graf, serta pembentukan minimum spanning tree [4].

### Penerapan Graph
Graf banyak diterapkan dalam berbagai bidang, seperti:
- Jaringan komputer dan internet
- Sistem navigasi dan transportasi
- Jejaring sosial
- Bioinformatika
- Sistem rekomendasi

Newman menyatakan bahwa graf merupakan fondasi utama dalam analisis jaringan kompleks yang berkembang pesat dalam ilmu komputer modern [5].

## Guided
### 1. 

### grapH_print.cpp
```c++
#include "graph.h"

void printGraph(graph G) {
    adrNode P = G.first;
    while (P!=NULL){
        cout<<"Node"<<P->info<<"terhubung ke:";
        adrEdge E=P->firstEdge;
        while(E!=NULL){
            cout<<E->node->info<<" ";
            E=E->next;
        }
        cout<<endl;
        P=P->next;
    }
}
```
### graph_edge.cpp
```c++
#include "graph.h"

adrNode findNode (graph G, infoGraph x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p -> info == x) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

void connectNode (graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new elmEdge;
        newEdge -> node = pEnd;
        newEdge -> next = pStart -> firstEdge;
        pStart -> firstEdge = newEdge;
    }
}
```
### graph_init.cpp
```c++
#include "graph.h"

void createGraph (graph &G) {
    G.first = NULL;
}

adrNode allocateNode (infoGraph x) {
    adrNode P = new elmNode;
    P -> info = x;
    P -> visited = false;
    P -> firstEdge = NULL;
    P -> next = NULL;
    return P;
}

void insertNode (graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}
```
### graph.h
```c++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct graph {
    adrNode first;
};

void createGraph(graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(graph &G, infoGraph x);
void connectNode(graph &G, infoGraph start, infoGraph end);
void printGraph(graph G);

#endif
```
### main.cpp
```c++
#include "graph.h"
#include <iostream>    

using namespace std;

int main() {
    graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "isi graph : " << endl;
    printGraph(G);

    return 0;
}
```
Program ini merupakan implementasi ADT Graph tidak berarah untuk merepresentasikan hubungan antar simpul. Setiap simpul menyimpan informasi data, status kunjungan, serta daftar sisi yang terhubung dengannya, sedangkan setiap sisi merepresentasikan hubungan dua arah antar simpul. Struktur graf dikelola melalui pointer ke simpul pertama, sehingga memungkinkan penambahan simpul dan penghubungan simpul secara dinamis. Program menyediakan operasi dasar seperti inisialisasi graf, penambahan node, penghubungan antar node, dan penampilan isi graf dalam bentuk adjacency list, serta diuji menggunakan ilustrasi graf sesuai dengan yang diberikan pada soal.

## Unguided 

### 1. 

### graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode temp = G.first;
    while (temp != NULL) {
        if (temp->info == X) {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

void addEdge(adrNode N1, adrNode N2) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        addEdge(N1, N2);
        addEdge(N2, N1);
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}
```

### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif
```

### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'G'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'E'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'G'), FindNode(G, 'H'));

    PrintInfoGraph(G);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided1_1](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided1.png)

Program tersebut mengimplementasikan strukdat graph tidak berarah dengan menggunakan metode pendekatan adjacency list atau multilist. Struktur ini dibangun menggunakan elemen simpul atau ElmNode yang menyimpan informasi, dan elemen sisi atau ElmEdge yang berfungsi sebagai penghubung antar simpul. Pada file graph.cpp, program memungkinkan pembuatan graf secara dinamis, penyisipan simpul baru, serta pembentukan relasi dua arah antar simpul melalui prosedur ConnectNode.




### 2. 

### graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode temp = G.first;
    while (temp != NULL) {
        if (temp->info == X) {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

void addEdge(adrNode N1, adrNode N2) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        addEdge(N1, N2);
        addEdge(N2, N1);
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }
    cout << N->info << " ";
    N->visited = 1;
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}
```

### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

#endif
```

### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'G'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'E'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'G'), FindNode(G, 'H'));

    cout << "Struktur Graph:" << endl;
    PrintInfoGraph(G);

    cout << "\nHasil Penelusuran DFS (mulai dari Node A):" << endl;
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)

Program tersebut merupakan implementasi dari graph tidak berarah yang menggunakan adjacency list. Melalui penggunaan elemen simpul (ElmNode) dan simpul sisi (ElmEdge), program dapat menyimpan data secara dinamis serta membangun relasi dua arah antar simpul melalui prosedur ConnectNode. Selain fungsi dasar untuk membangun dan menampilkan struktur hubungan graf, program ini menyertakan prosedur PrintDFS yang berfungsi untuk menelusuri setiap simpul sedalam mungkin menggunakan logika rekursif. Implementasi akhir pada program utama berhasil merepresentasikan jaringan simpul A sampai H sesuai ilustrasi dan menampilkan urutan penelusuran simpul menggunakan algoritma Depth First Search (DFS).



### 3. 

### graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if (G.first == NULL) {
        G.first = newNode;
    } else {
        adrNode temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode temp = G.first;
    while (temp != NULL) {
        if (temp->info == X) {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

void addEdge(adrNode N1, adrNode N2) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        addEdge(N1, N2);
        addEdge(N2, N1);
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }
    cout << N->info << " ";
    N->visited = 1;
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) {
        return;
    }
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}
```

### graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);
void ResetVisited(Graph &G);

#endif
```

### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'F'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'G'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'E'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'F'), FindNode(G, 'H'));
    ConnectNode(FindNode(G, 'G'), FindNode(G, 'H'));

    cout << "Struktur Graph (Adjacency List):" << endl;
    PrintInfoGraph(G);

    cout << "\nHasil Penelusuran DFS (mulai dari A):" << endl;
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\nHasil Penelusuran BFS (mulai dari A):" << endl;
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    cout << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided2](https://github.com/AchmadZulvan/103112400070_Achmad-Zulvan-Nur-Hakim/blob/main/Week3/Screenshot%20Output%20Unguided2.png)

program tersebut merupakan implementasi struktur data Graf dengan representasi Adjacency List. gGaph.h yang mendefinisikan struktur data simpul (node) dan sisi (edge), graph.cpp yang mengimplementasikan fungsi-fungsi operasional seperti pembuatan graf, penambahan simpul, penyambungan antar-simpul secara undirected, serta algoritma penelusuran DFS (Depth First Search) dan BFS (Breadth First Search), dan main.cpp sebagai program utama. Dalam skenario yang dijalankan, program membangun sebuah graf yang terdiri dari delapan simpul (A hingga H) yang saling terhubung, kemudian menampilkan struktur keterhubungannya dan mencetak urutan kunjungan simpul berdasarkan metode penelusuran DFS dan BFS mulai dari simpul 'A'.

## Kesimpulan
Graph merupakan struktur data non-linear yang sangat krusial untuk memodelkan hubungan atau relasi antar objek dalam berbagai sistem dunia nyata, seperti jaringan komputer, transportasi, dan sosial. Implementasi graf melalui metode Adjacency List menggunakan representasi multilist terbukti lebih efisien dalam penggunaan memori dibandingkan matriks, terutama untuk jenis graf yang bersifat jarang (sparse graph). Melalui pengerjaan tugas guided dan unguided, telah berhasil diwujudkan fungsi-fungsi dasar seperti pembuatan simpul (node), penghubungan sisi (edge) secara dinamis, serta pemanfaatan algoritma penelusuran Depth First Search (DFS) dan Breadth First Search (BFS). Algoritma DFS bekerja secara rekursif untuk menelusuri simpul sedalam mungkin, sementara BFS menggunakan bantuan queue untuk menelusuri simpul secara melebar. Secara keseluruhan, praktikum ini memberikan pemahaman mendalam mengenai fleksibilitas struktur graf dalam menangani data dinamis dan pentingnya pemilihan algoritma yang tepat untuk analisis jaringan kompleks.



## Referensi
<br>[1] Harary, F. (1969). Graph Theory. Addison-Wesley Publishing Company.
<br> [2] Newman, M. E. J. (2010). Networks: An Introduction. Oxford University Press.
<br> [3] R. Sedgewick and K. Wayne, Algorithms, 4th ed., Addison-Wesley, 2011.
<br> [4] J. L. Gross and J. Yellen, Graph Theory and Its Applications, CRC Press, 2005.
<br> [5] M. E. J. Newman, Networks: An Introduction, Oxford University Press, 2010.