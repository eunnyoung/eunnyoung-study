//#include <iostream>
#include <stdio.h>
//using namespace std;
struct Node
{
	int data;
	Node* link;
	Node(int d) :data(d), link(NULL) {}
};


int main()
{
	Node* h = NULL;
	Node* t = NULL;

	h = t = new Node(0xfffffff); //dummy node
	//////////////////////////////////////////////
	//���� ���
	t->link = new Node(10);
	t = t->link;

	t->link = new Node(20);
	t = t->link;

	t->link = new Node(30);
	t = t->link;

	for (Node* p = h->link; p != NULL; p = p->link)
		printf("%d\n", p->data);

	///////////////////////////
	Node* cur = h;
	Node* next = cur->link;
	delete cur;

	cur = next;
	next = cur->link;
	delete cur;

	cur = next;
	next = cur->link;
	delete cur;

	cur = next;
	next = cur->link;
	delete cur;
}

////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//	Node(int d) :data(d), link(NULL) {}
//};
//
//
//int main()
//{
//	Node* h = NULL;
//	Node* t = NULL;
//
//	h = t = new Node(0xfffffff); //dummy node
//	//////////////////////////////////////////////
//	//���� ���
//	t->link = new Node(10);
//	t = t->link;
//
//	t->link = new Node(20);
//	t = t->link;
//
//	t->link = new Node(30);
//	t = t->link;
//
//	t->link = new Node(40);
//	t = t->link;
//
//	t->link = new Node(50);
//	t = t->link;
//
//	for (Node* p = h->link; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}

/////////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//}; //  ��� ����(�ڱ���������ü)
//
//Node* AllocNode(int data)
//{
//	Node* n = new Node;
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//int main()
//{
//	Node* h = NULL;
//	Node* t = NULL;
//
//	h = t = AllocNode(0x0); //dummy node
//	//////////////////////////////////////////////
//	//���� ���
//	t->link = AllocNode(10);
//	t = t->link;
//
//	t->link = AllocNode(20);
//	t = t->link;
//
//	t->link = AllocNode(30);
//	t = t->link;
//
//	t->link = AllocNode(40);
//	t = t->link;
//
//	t->link = AllocNode(50);
//	t = t->link;
//
//	for (Node* p = h->link; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}

////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//}; // ��� ����(�ڱ���������ü)
//
//Node* AllocNode(int data)
//{
//	Node* n = new Node;
//	n->data = 10;
//	n->link = NULL;
//
//	return n;
//}
//int main()
//{
//	Node* h = NULL;
//
//	h = AllocNode(10);
//	h->link = AllocNode(20);
//	h->link->link = AllocNode(30);
//	h->link->link->link = AllocNode(40);
//	h->link->link->link->link = AllocNode(50);
//
//	for (Node* p = h; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}

/*
//#include <iostream>
#include <stdio.h>
//using namespace std;
struct Node
{
	int data;
	Node* link;
}; //  ��� ����(�ڱ���������ü)
int main()
{
	Node* h = NULL;

	h = new Node;
	h->data = 10;
	h->link = NULL;

	h->link = new Node;
	h->link->data = 20;
	h->link->link = NULL;

	h->link->link = new Node;
	h->link->link->data = 30;
	h->link->link->link = NULL;

	h->link->link->link = new Node;
	h->link->link->link->data = 40;
	h->link->link->link->link = NULL;

	h->link->link->link->link = new Node;
	h->link->link->link->link->data = 50;
	h->link->link->link->link->link = NULL;

	for (Node* p = h; p != NULL; p = p->link)
		printf("%d\n", p->data);
}
*/

////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//}; // ��� ����(�ڱ���������ü)
//int main()
//{
//	Node* h = NULL;
//
//	h = new Node;
//	h->data = 10;
//	h->link = NULL;
//
//	h->link = new Node;
//	h->link->data = 30;
//	h->link->link = NULL;
//
//	h->link->link = new Node;
//	h->link->link->data = 30;
//	h->link->link->link = NULL;
//
//	h->link->link->link = new Node;
//	h->link->link->link->data = 40;
//	h->link->link->link->link = NULL;
//
//	h->link->link->link->link = new Node;
//	h->link->link->link->link->data = 50;
//	h->link->link->link->link->link = NULL;
//
//	printf("%d %d %d\n", h->data, h->link->data, h->link->link->data,
//		h->link->link->link->data, h->link->link->link->link->data);
//}

/*
//#include <iostream>
#include <stdio.h>
//using namespace std;
struct Node
{
	int data;
	Node* link;
}; //  ��� ����(�ڱ���������ü)
int main()
{
	Node* h = NULL;

	h = new Node;
	h->data = 10;
	h->link = NULL;

	h->link = new Node;
	h->link->data = 20;
	h->link->link = NULL;

	h->link->link = new Node;
	h->link->link->data = 30;
	h->link->link->link = NULL;

	printf("%d %d %d\n", h->data, h->link->data, h->link->link->data);
}
*/

////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//}; // ��� ����(�ڱ���������ü)
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node* h = &n1;
//	// n1.link = &n2;
//	// ����ü ������ ���� ������ �����ϰ� ���ش�.
//	h->link = &n2;
//
//	// n2.link = &n3;
//	h->link->link = &n3;
//
//	printf("%d %d %d\n", n1.data, n2.data, n3.data);
//	printf("%d %d %d\n", h->data, h->link->data, h->link->link->data);
//}

////#include <iostream>
//#include <stdio.h>
////using namespace std;
//struct Node
//{
//	int data;
//	Node* link;
//}; // ��� ����(�ڱ���������ü)
//int main()
//{
//	Node n1 = {10, NULL};
//}

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int row = 3;
	int col = 5;
	// ũ�Ⱑ �ڵ����� �þ�� �پ��� �迭
	vector< vector<int> > va;

	for (int i = 0; i < row; ++i) {
		va.push_back(vector<int>());
		for (int j = 0; j < col; ++j)
			va[i].push_back(i * 100 + j);
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			printf("%5d", va[i][j]);
		printf("\n");
	}
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	// ũ�Ⱑ �ڵ����� �þ�� �پ��� �迭
	vector< vector<int> > va;

	for (int i = 0; i < 5; ++i)
		//���� �� �ڿ� ���� �ִ´�.
		va.push_back( vector<int>() );

	//va[0] ~ va[2]
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j)
			va[i].push_back(i * 100 + j);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j)
			printf("%5d", va[i][j]);
		printf("\n");
	}
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
   vector< vector<int> > va;

   for (int i = 0; i < 3; ++i)
	  va.push_back( vector<int>() );

   //va[0]~va[2]
   for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < 5; ++j)
		 va[i].push_back(j + 1);
   }

   for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < 5; ++j)
		 printf("%5d", va[i][j]);
	  printf("\n");
   }
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	vector< vector<int> > va;

	for (int i = 0; i < 3; ++i)
		va.push_back(vector<int>());

	//va[0]~va[2]
	va[0].push_back(1);
	va[0].push_back(2);
	va[0].push_back(3);
	va[0].push_back(4);
	va[0].push_back(5);
	va[1].push_back(1);
	va[1].push_back(2);
	va[1].push_back(3);
	va[1].push_back(4);
	va[1].push_back(5);
	va[2].push_back(1);
	va[2].push_back(2);
	va[2].push_back(3);
	va[2].push_back(4);
	va[2].push_back(5);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j)
			printf("%5d", va[i][j]);
		printf("\n");
	}
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	// ũ�Ⱑ �ڵ����� �þ�� �پ��� �迭
	vector<int> arr;

	for (int i = 0; i < 5; ++i)
		//���� �� �ڿ� ���� �ִ´�.
		arr.push_back(i + 1);

	for (int i = 0; i < 5; ++i)
		printf("%5d", arr[i]);
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;
void CreateArray(int**& pa, int row, int col)
{
   pa = new int* [row];
   for (int i = 0; i < row; ++i)
	  pa[i] = new int[col];
}
void FreeArray(int** pa, int row, int col)
{
   for (int i = 0; i < row; ++i)
	  delete[] pa[i];

   delete[] pa;
}
void PrintArray(int** pa, int row, int col)
{
   for (int i = 0; i < row; ++i) {
	  for (int j = 0; j < col; ++j) {
		 printf("%5d", pa[i][j]);
	  }
	  printf("\n");
   }
}
void InitArray(int** pa, int row, int col)
{
   for (int i = 0; i < row; ++i)
	  for (int j = 0; j < col; ++j)
		 pa[i][j] = i * 100 + j;
}
int main()
{
   int row = 10;
   int col = 5;
   int** pa = NULL;

   printf(" �� �Է�:");
   scanf_s("%d", &row);
   printf(" �� �Է�:");
   scanf_s("%d", &col);

   CreateArray(pa, row, col);
   InitArray(pa, row, col);
   PrintArray(pa, row, col);
   FreeArray(pa, row, col);
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;
int** CreateArray(int row, int col)
{
	int** pa = new int* [row];
	for (int i = 0; i < row; ++i)
		pa[i] = new int[col];

	return pa;
}
void FreeArray(int** pa, int row, int col)
{
	for (int i = 0; i < row; ++i)
		delete[] pa[i];

	delete[] pa;
}
int main()
{
	int row = 10;
	int col = 5;
	int** pa = NULL;

	printf(" �� �Է�:");
	scanf_s("%d", &row);
	printf(" �� �Է�:");
	scanf_s("%d", &col);

	pa = CreateArray(row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pa[i][j] = i * 100 + j;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}

	FreeArray(pa, row, col);
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
   int row = 10;
   int col = 5;
   int** pa = NULL;

   printf(" �� �Է�:");
   scanf_s("%d", &row);
   printf(" �� �Է�:");
   scanf_s("%d", &col);

   pa = new int* [row];
   for (int i = 0; i < row; ++i)
	  pa[i] = new int[col];

   for (int i = 0; i < row; ++i)
	  for (int j = 0; j < col; ++j)
		 pa[i][j] = i * 100 + j;

   for (int i = 0; i < row; ++i) {
	  for (int j = 0; j < col; ++j) {
		 printf("%5d", pa[i][j]);
	  }
	  printf("\n");
   }

   for (int i = 0; i < row; ++i)
	  delete[] pa[i];

   delete[] pa;
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int row = 5;
	int col = 5;
	int** pa = NULL;
	pa = new int* [row];

	for (int i = 0; i < 5; ++i)
		pa[i] = new int[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pa[i][j] = i * 100 + j;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; ++i)
		delete[] pa[i];

	delete[] pa;
}
*/


/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int pa[5][5];

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			pa[i][j] = i * 100 + j;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}		
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int* pa = new int[10];

	for (int i = 0; i < 10; ++i)
		pa[i] = i + 1;

	for (int i = 0; i < 10; ++i)
		printf("%5d", pa[i]);

	delete[] pa;
}
*/

/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n = 100;
	int* p = &n;

	printf("%d %d\n", n, *p);
	printf("%p %p\n", &n, p);
}
*/

/*
// ǥ�� ��Ʈ������ �б�, ���⸦ �����ϴ� ��ü�� �����Ѵ�.
#include <iostream>

using namespace std;

int main()
{

	// ǥ�� ��¿� ���� ������ ����Ʈ ��Ʈ������ �����Ѵ�.
	// cout �� "console output" �� �ǹ��Ѵ�.
	// endl �� "end line" �� �ǹ��Ѵ�.
	cout << "Hello!" << ',' << 100 << endl;
	printf("hello!,%d\n", 100);

	return 0;
}
*/