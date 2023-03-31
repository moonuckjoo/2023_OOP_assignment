#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h> //�ð� ������ ���� �������
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
            cout << "n�� Ȧ������ �մϴ�. ���ڸ� �ٽ� �Է����ּ��� : ";
        else
            break;
    }
    int* sort = new int[n];
    int* sorted = new int[n]; //�ӽ� ������ �迭
    for (int i = 0; i < n; i++)
    {
        cin >> sort[i];
    }
    cout << endl << "1. bubble sort  2. insertion sort  3. merge sort  4. quick sort : ";
    while (1)
    {
        cin >> input;
        if (input == 1) {
            QueryPerformanceFrequency(&ticksPerSec); // �Լ� ȣ�� �� �ð� ����
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
            cout << "��ȿ���� ���� �����Դϴ�. ���ڸ� �ٽ� �Է����ּ��� : ";

    }

    cout << "sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
    cout << endl << "median number: ";
    cout << sort[n / 2] << endl;
    QueryPerformanceCounter(&end); // ��� ���� �ı��� �ð� ���
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
    delete[] sort;
    delete[] sorted;
    return 0;
}
//bubble sort
void bubble(int sort[], int n)
{
    int temp; //���ڸ� ��ȯ�� �� �ʿ��� �� �׸�
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (sort[j] > sort[j + 1]) //���� �ε��� �迭�� ���ڰ� �� �۴ٸ� temp ������ �̿��Ͽ� ��ȯ
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
    int temp = 0; //���ڸ� ��Ƶΰ� ���� �׸�
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = sort[i]; //i��° ���ڸ� temp ������ ��Ƶΰ�
        for (j = i - 1; j >= 0; j--) // i�� ��� �ε����� �迭�� �ϳ��� ��
        {
            if (sort[j] > temp)
                sort[j + 1] = sort[j];
            else
                break;
        }
        sort[j + 1] = temp; // ���ؼ� �ش� �ε����� ã���� �ű⿡ ����
    }
}
void quick(int sort[], int start, int n)
{
    if (start >= n) //���Ұ� 1���� ���
    {
        return;
    }
    int pivot = start; // �Ǻ� ����
    int i = pivot + 1;
    int j = n;
    int temp; //�ٲ��� �� �ʿ��� �׸�
    while (i <= j)// �����Ͱ� ���� ������ �ݺ�
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
            //������ ���
            temp = sort[j];
            sort[j] = sort[pivot];
            sort[pivot] = temp;
        }
        else
        {
            //i��°�� j��° ����
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
        //�׻� i�� j�� ���ؼ� �� ���� ���� k�� �ֱ�
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
        //k�� ����
        k++;
    }
    // �� ���� ������ ���� �� ���� �����͵� ����
    // i�� ���� ���� ���
    if (i > mid)
    {
        for (int t = j; t <= n; t++)
        {
            sorted[k] = sort[t];
            k++;
        }
    }
    else // j�� ���� ���� ���
    {
        for (int t = i; t <= mid; t++)
        {
            sorted[k] = sort[t];
            k++;
        }
    }
    // sort �迭�� ����
    for (int t = m; t <= n; t++)
    {
        sort[t] = sorted[t];
    }
}

void merge_sort(int sorted[], int sort[], int m, int n) {
    //ũ�Ⱑ 1���� ū ��츸 ����
    if (m < n) {
        int mid = (m + n) / 2;
        merge_sort(sorted, sort, m, mid); // �������� �������� ����
        merge_sort(sorted, sort, mid + 1, n); // ���������� �������� ����
        merge(sorted, sort, m, mid, n);
    }
}