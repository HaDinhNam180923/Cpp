#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
}Node;

Node* makeNode(int v){
	Node* p = (Node*)malloc(sizeof(Node));
	p -> value = v;
	p -> next = NULL;
	return p;
}

Node* insertLast(Node* h, int v){
	Node* p = h;
	if (h == NULL){
		return makeNode(v);
	}
	while(p -> next != NULL) p = p -> next;
	
	Node* q = makeNode(v);
	p -> next = q;
	return h;
}
Node* insertLastRecursive(Node* h, int v){
	if(h == NULL) return makeNode(v);
	h -> next = insertLastRecursive(h -> next, v);
	return h;
}
Node* removeNode(Node* h, int v){
	Node* p = h;
	if (h == NULL) return NULL;
	if (h -> value == v){
		Node* tmp = h;
		h = h -> next;
		free(tmp); return h;
	}
	while (p -> next != NULL){
		if(p -> next -> value == v) break;
		p = p -> next;
	}
	if(p->next != NULL){
		Node* q = p->next;
		p->next = q->next; free(q);
	}
	return h;
}
Node* removeNodeRecursive(Node* h, int v){
	if(h == NULL) return NULL;
	if (h->value == v){
		Node* tmp = h; h = h->next; free(tmp); return h;
	}
	h->next = removeNodeRecursive(h->next, v);
	return h;
}
int main(){
	int v=1;
	Node *h, *L;
	L=NULL;
	printf("Nhap gia tri node, ket thuc khi nhap so 0");
	while(v!=0){
		printf("\nNhap gia tri node: ");
		scanf("%d", &v);
		h = makeNode(v);
		L = insertLast(L, v);
	}
	h = L;
	printf("\nHien thi danh sach: ");
	if(h!=NULL){
	while(h!=NULL){
		printf("%d ", h->value);
		h=h->next;
	}
	}else{
		printf("HaiNam");
	}
	return 0;
}
