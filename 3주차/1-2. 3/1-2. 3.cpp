#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void compare(int input); // ���ڿ��� ���ؼ� ����ϴ� �Լ�
int change(char* name);
void main()
{
    int input; // ���� ���ڿ� �� ����
    char data[30] = { 0 }; // �� �پ� �Է¹޾� ���� �迭
    char filename[30]; // �����̸� �Է¹ޱ� ���� �迭
    ifstream fin; //������ �б�� ��Ʈ�� ����
    cout << "input file name : ";
    cin >> filename; //���� �̸� �Է�
    while (1) // ���� �̸� �ȹٷ� ĥ ������ ���ѹݺ�
    {
        if (strcmp("filename_list.txt", filename) == 0) // �̸��� ��ġ�ϸ� ���� ����
        {
            fin.open("filename_list.txt");
            break;
        }
        else
            cout << "���ϸ��� �ٽ� �Է����ּ��� : ";
    }
    if (!fin) //������ �� ������ �� no ���
    {
        cout << " no " << endl;
    }

    cin >> input; // �ݺ�Ƚ�� �����ֱ�
    compare(input); // ���ڿ��� ���ؼ� ����ϴ� �Լ�
    fin.close();
}

void compare(int input)//���ڿ� ���Լ�
{
    int q; //?�� ���� �Ǵ�
    int cnt = 0; //finalname�� ���� ����Ű�� ����
    int change1;
    char finalname[15][30] = { 0 }; // ���������� ����� �迭
    char data[30] = { 0 }; // �� �پ� �Է¹޾� ���� �迭
    char name[30]; //���� ���ڿ��� �Է¹��� �迭
    ifstream fin; //��Ʈ�� ����

    for (int i = 0; i < input; i++)// �Է¹��� Ƚ����ŭ �ݺ�
    {
        fin.open("filename_list.txt"); // ���� ����
        cin >> name; // ���� ���ڿ� �Է¹ޱ�
        change1 = change(name); // *�� ?�� ��� ������ֱ�
        while (!fin.eof()) //���� ������ ��� ���ڸ� data�� ���.
        {
            q = 0;
            fin.getline(data, 30);
            if (change1 >= 0 && strncmp(data, name, change1) == 0) //*�� �ְų� Ȥ�� �ƹ��͵� ���� ���.
            {
                strcpy(finalname[cnt], data); //���ǿ� �ش�Ǵ� ���� �״�� �迭�� ����
                cnt++;
            }
            else if (change1 == -1) //?�� �ִ� ��� ?�� �ѱ�� �� ���ھ� ����
            {
                for (int i = 0; i < strlen(name); i++)
                {
                    if (name[i] == '?') // ?�� �ִ� �ε����� �迭�� �ѱ��
                        continue;
                    else if (name[i] == data[i] && strlen(name) == strlen(data))// �迭�� ��� ���̰� �°� ?�� ������ ��� �迭�ε����� �Ȱ��� ��
                        q++;
                }
                if (q == strlen(name) - 1) // ?�� ������ ��� ���ڰ� �´ٸ� ����
                {
                    strcpy(finalname[cnt], data); //���ǿ� �ش�Ǵ� ���� �״�� �迭�� ����
                    cnt++;
                }

            }
        }
        fin.close();
    }
    cout << endl;
    for (int i = 0; i < cnt; i++) // finalname ���
    {
        for (int j = 0; j < 30; j++)
        {
            if (finalname[i][j] == 0)
                break;
            else
                cout << finalname[i][j];
        }
        cout << endl;
    }
}
int change(char* name) // *�� ? ������ֱ�
{
    int star = 0;
    for (int i = 0; i < 30; i++)
    {
        if (name[i] != '*')
            star++;
        else if (name[i] == '*' || name[i] == NULL) //�ƹ��͵� ���� ��쵵 ����
            return star;
        if (name[i] == '?')
            return -1;

    }
}