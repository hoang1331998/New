#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	
	int data;
	node *next;
};

struct list{
	
	node *first;
	node *last;
};

list l;

void create(list &l){
	
	l.first = NULL;
	l.last = NULL;
}

node *createNode(int x){
	
	node *p = (node*)malloc(sizeof(node));
	p->data = x;
	p->next = NULL;
	return p;
}
void add(list &l,node *p){
	
	if(l.first == NULL){
		l.first = l.last = p;
	}
	else{
		l.last->next = p;//cho con tro cua last lket voi node p
		l.last = p;		// cap nhat lai p la node last
	}	
}
void printList(list &l){
	
	for(node *k = l.first; k != NULL; k = k->next){
		cout << k->data<<" ";
	}
}
int searchMax(list l){
	
	int max = l.first->data;
	for(node *k = l.first->next; k != NULL; k = k->next){
		if(max < k->data){
			max = k->data;// cap nhat lai gia tri max
		}
	}
	return max;
}
int search0(list l){
	
	int dem = 0;
	for(node *k = l.first; k != NULL; k = k->next){
		if(k->data==0){
			dem++;
		}
	}
	return dem;
}
void sortRed(list &l){
	
	int tg;
	for(node *k = l.first; k != NULL; k = k->next){
		for(node *h = l.first; h != NULL; h = h->next){
			if(h->data < k->data){
				tg = k->data;
				k->data = h->data;
				h->data = tg;
			}
		}
	}
	printList(l);
}
void searchData(list l,int a){

	for(node *k = l.first; k != NULL; k = k->next){
		if(k->data > a){
	     cout<<k->data<<" ";	    	 
	    }
	}
}
void delHead(list &l){
	
	if(l.first == NULL){
		return;
	}
	node *p = l.first;
	l.first = l.first->next;
	delete p;//phan tu dau can xoa
	printList(l);
}
void delTail(list &l){
	if(l.first == NULL){
		return;
	}
	for(node *k = l.first; k!= NULL; k=k->next){
		if(k->next == l.last){
			delete l.last;
			k->next = NULL;
			l.last = k;
		}
	}
	printList(l);
}
	

void del(list &l,node *q){
	
    for(node *k = l.first; k!=NULL; k = k->next){
    	if(k->data == q->data){
    		node *g = k->next;// node dang sau q
    		k->next = g->next;
    		delete g;
    		return;
		}
	}
}
void delM(list &l,int m){
	
	if(l.first == NULL){
		return;
	}
	if(l.first->data ==m ){
		delHead(l);
		return;
	}
	if(l.last->data ==m ){
		delTail(l);
		return;
	}
	else{	
	    node *g = new node;
	    for(node *k = l.first; k!=NULL; k=k->next){
	     	if(k->data == m){			
             	g->next = k->next;
            	delete k; 
				return;  
            }
           g = k;
	    }
	    
   } 
	printList(l);
}
void addX(list &l,node *p){
	
	int x;
	cout<<"\nNhap phan tu can them: ";
	cin>>x;
	node *q = createNode(x);
	for(node *k=l.first; k!=NULL; k=k->next){
		if(q->data == k->data){
			node *g = k->next;
			
		
	}
}
}
void reverseList(list l){
	//Tach tung node ra roi cho con tro next cua moi node tro nguoc lai node trc do cho den khi gap l.last
	node *p1 = l.first;
	node *p2 = l.first->next;
	l.first = p2->next;
	p1->next = NULL;
	p2->next = p1;
	while(l.first->next != NULL){
		p1 = p2;
		p2 = l.first;
		l.first = l.first->next;
		p2->next = p1;
	}
	l.first->next = p2;
	printList(l);
}

int main(){
	list l;
	create(l);
	int n,x;
	cout<<"Nhap so luong phan tu can them: ";
	cin>>n;
	for(int i=1; i <= n; i++){
		cout<<"Nhap phan tu thu "<<i<<" :";
		cin>>x;
		node *p = createNode(x);
		add(l,p);
	}
	cout<<" Danh sach la: ";
	printList(l);
	cout<<"\n Phan tu lon nhat la: "<<searchMax(l)<<endl;
	cout<<" Co "<<search0(l)<<" phan tu 0";
	cout<<"\nDanh sach duoc sap xep giam dan la: ";
	sortRed(l);
	int a;
	cout<<"\nNhap a: ";
	cin>>a;
	cout<<"\nDanh sach phan tu lon hon "<<a<<" la: ";
	searchData(l,a);
    cout<<"\nDanh sach duoc dao nguoc lai la: ";
    reverseList(l);
    int m;
    cout<<"\nNhap vi tri phan tu can xoa: ";
    cin>> m;
    
    cout<<"\nDanh sach sau khi xoa la: ";
    delM(l,m);
	return 0;
}

