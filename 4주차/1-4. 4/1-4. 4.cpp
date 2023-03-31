#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h> //시간 측정을 위한 헤더파일
using namespace std;
void insertion(int sort[], int n);
void bubble(int sort[], int n);
void quick(int sort[], int start, int n);
void merge(int sorted[], int sort[], int m, int n);
void merge_sort(int sorted[], int sort[], int m, int n);

int main()
{
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    int input;
    int n;
    while (1)
    {
        cin >> n;
        if (n % 2 == 0)
            cout << "n은 홀수여야 합니다. 숫자를 다시 입력해주세요 : ";
        else
            break;
    }
    int* sort = new int[n];
    int* sorted = new int[n]; //임시 저장할 배열
    for (int i = 0; i < n; i++)
    {
        cin >> sort[i];
    }
    cout << endl << "1. bubble sort  2. insertion sort  3. merge sort  4. quick sort : ";
    while (1)
    {
        cin >> input;
        if (input == 1) {
            QueryPerformanceFrequency(&ticksPerSec); // 함수 호출 전 시간 측정
            QueryPerformanceCounter(&start);
            bubble(sort, n);
            break;
        }
        else if (input == 2) {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            insertion(sort, n);
            break;
        }

        else if (input == 3) {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            merge_sort(sorted, sort, 0, n - 1);
            break;

        }

        else if (input == 4) {
            QueryPerformanceFrequency(&ticksPerSec);
            QueryPerformanceCounter(&start);
            quick(sort, 0, n - 1);
            break;
        }

        else
            cout << "유효하지 않은 숫자입니다. 숫자를 다시 입력해주세요 : ";

    }

    cout << "sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
    cout << endl << "median number: ";
    cout << sort[n / 2] << endl;
    QueryPerformanceCounter(&end); // 출력 끝낸 후까지 시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
    delete[] sort;
    delete[] sorted;
    return 0;
}
//bubble sort
void bubble(int sort[], int n)
{
    int temp; //숫자를 교환할 때 필요한 빈 그릇
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (sort[j] > sort[j + 1]) //다음 인덱스 배열의 숫자가 더 작다면 temp 변수를 이용하여 교환
            {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
}
//insertion sort
void insertion(int sort[], int n)
{
    int temp = 0; //숫자를 담아두고 비교할 그릇
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = sort[i]; //i번째 숫자를 temp 변수에 담아두고
        for (j = i - 1; j >= 0; j--) // i앞 모든 인덱스의 배열과 하나씩 비교
        {
            if (sort[j] > temp)
                sort[j + 1] = sort[j];
            else
                break;
        }
        sort[j + 1] = temp; // 비교해서 해당 인덱스를 찾으면 거기에 삽입
    }
}
void quick(int sort[], int start, int n)
{
    if (start >= n) //원소가 1개인 경우
    {
        return;
    }
    int pivot = start; // 피봇 설정
    int i = pivot + 1;
    int j = n;
    int temp; //바꿔줄 때 필요한 그릇
    while (i <= j)// 포인터가 만날 때까지 반복
    {
        while (i <= n && sort[i] <= sort[pivot])  // 
        {
            i++;
        }
        while (j > start && sort[j] >= sort[pivot])
        {
            j--;
        }
        if (i > j)
        {
            //엇갈린 경우
            temp = sort[j];
            sort[j] = sort[pivot];
            sort[pivot] = temp;
        }
        else
        {
            //i번째와 j번째 스왑
            temp = sort[i];
            sort[i] = sort[j];
            sort[j] = temp;
        }
    }
    quick(sort, start, j - 1);
    quick(sort, j + 1, n);
}
void merge(int sorted[], int sort[], int m, int mid, int n)
{
    int i = m;
    int j = mid + 1;
    int k = m;
    while (i <= mid && j <= n)
    {
        //항상 i랑 j랑 비교해서 더 작은 값을 k에 넣기
        if (sort[i] <= sort[j])
        {
            sorted[k] = sort[i];
            i++;
        }
        else
        {
            sorted[k] = sort[j];
            j++;
        }
        //k값 증가
        k++;
    }
    // 한 쪽이 끝까지 갔을 때 남은 데이터도 삽입
    // i가 먼저 끝난 경우
    if (i > mid)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = sort[t];
            k++;
        }
    }
    else // j가 먼저 끝난 경우
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = sort[t];
            k++;
        }
    }
    // sort 배열에 삽입
    for (int t = m; t <= n; t++)
    {
        sort[t] = sorted[t];
    }
}

void merge_sort(int sorted[], int sort[], int m, int n) {
    //크기가 1보다 큰 경우만 분할
    if (m < n) {
        int mid = (m + n) / 2;
        merge_sort(sorted, sort, m, mid); // 왼쪽으로 병합정렬 수행
        merge_sort(sorted, sort, mid + 1, n); // 오른쪽으로 병합정렬 수행
        merge(sorted, sort, m, mid, n);
    }
}