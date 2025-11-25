#ifndef QUEUE_H
#define QUEUE_H
#include<string>
using namespace std;
CONST int MAX = 5;
struct paket {
    string kodeResi;
    string namaPengirim;
    int beratBarang;
    string tujuan;
}
struct Queue {
    paket dataPaket[MAX];
    int head;
    int tail;
};

