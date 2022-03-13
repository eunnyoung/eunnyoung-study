#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int row = 3;
	int col = 5;
	// 크기가 자동으로 늘어나고 줄어드는 배열
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

/*
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int row = 3;
	int col = 5;
	// 크기가 자동으로 늘어나고 줄어드는 배열
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
	// 크기가 자동으로 늘어나고 줄어드는 배열
	vector< vector<int> > va;

	for (int i = 0; i < 5; ++i)
		//벡터 맨 뒤에 값을 넣는다.
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
	// 크기가 자동으로 늘어나고 줄어드는 배열
	vector<int> arr;

	for (int i = 0; i < 5; ++i)
		//벡터 맨 뒤에 값을 넣는다.
		arr.push_back(i + 1);

	for (int i = 0; i < 5; ++i)
		printf("%5d", arr[i]);
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

	printf(" 행 입력:");
	scanf_s("%d", &row);
	printf(" 열 입력:");
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
// 표준 스트림에서 읽기, 쓰기를 제어하는 개체를 선언한다.
#include <iostream>

using namespace std;

int main()
{

	// 표준 출력에 대한 삽입을 바이트 스트림으로 제어한다.
	// cout 는 "console output" 을 의미한다.
	// endl 은 "end line" 을 의미한다.
	cout << "Hello!" << ',' << 100 << endl;
	printf("hello!,%d\n", 100);

	return 0;
}
*/