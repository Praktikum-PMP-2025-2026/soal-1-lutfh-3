/*============================================================
 *  EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul                : 04 - Dynamic Structure
 *   Hari dan Tanggal     : Rabu  6 Mei 2026
 *   Nama (NIM)           : Lutfi Hasan (13224091)
 *   Nama File            : soal1.c
 *   Deskripsi            : Input berupa nama dan waktu dan output berupang urutan queue dan menampilkan total waktu yang diperlukan di antrian
 *   */

// Source - https://stackoverflow.com/q/2262949
// Posted by shinjuo, modified by community. See post 'Timeline' for change history
// Retrieved 2026-05-06, License - CC BY-SA 2.5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id[20];
    int duration;
    struct Node *next;
} node;

typedef struct Queue {
    node *front;
    node *rear;
} queue;

node *createNode(char* id, int duration) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        return NULL;
    }
    strcpy(newNode->id, id);
    newNode->duration = duration;
    newNode->next = NULL;

    return newNode;
}

queue *createQueue() {
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    
    return newQueue;
}

void enqueue(queue *q, char* id, int duration) {
    node *newNode = createNode(id, duration);

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int main() {
    int n;
    int Ttotal = 0;
    int Tsekarang = 0; 
    
    scanf("%d", &n);

    queue *q = createQueue();

    char id[20];
    int duration;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", id, &duration);
        enqueue(q, id, duration);
    }

    printf("ORDER");
    node *temp = q->front;
    while (temp != NULL) {
        printf(" %s", temp->id);
        temp = temp->next;
    }

    printf("\n");

    temp = q->front;
    while (temp != NULL) {
        Ttotal += Tsekarang;
        Tsekarang += temp->duration; 
        temp = temp->next;
    }
    
    printf("WAIT %d\n", Ttotal);

    return 0;
}
