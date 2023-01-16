#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
}*front = NULL, *rear = NULL;


void enqueue(int s) {
    struct Dugum* yenidugum;
    yenidugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    yenidugum->veri = s;
    yenidugum->sonraki = NULL;

    if (front == NULL && rear == NULL) {
       front = rear = yenidugum;
    }
    else {
        rear->sonraki = yenidugum;
        rear = yenidugum;
    }
    printf("%d elemani kuyruga eklendi\n", s);
}

void dequeue() {
    struct Dugum* temp;
    if (front == NULL) {
        printf("kuyruk bos!!!\n");
    }
    else {
        temp = front;
        front = front->sonraki;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void printList() {
    struct Dugum* p=front;
    while (p!=NULL)
    {
        printf("%d ", p->veri);
        p = p->sonraki;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    printList();
}


