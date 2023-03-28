#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void compare(int input); // 문자열을 비교해서 출력하는 함수
int change(char* name);
void main()
{
    int input; // 비교할 문자열 수 지정
    char data[30] = { 0 }; // 한 줄씩 입력받아 비교할 배열
    char filename[30]; // 파일이름 입력받기 위한 배열
    ifstream fin; //파일을 읽기로 스트림 생성
    cout << "input file name : ";
    cin >> filename; //파일 이름 입력
    while (1) // 파일 이름 똑바로 칠 때까지 무한반복
    {
        if (strcmp("filename_list.txt", filename) == 0) // 이름이 일치하면 파일 열기
        {
            fin.open("filename_list.txt");
            break;
        }
        else
            cout << "파일명을 다시 입력해주세요 : ";
    }
    if (!fin) //파일이 안 열렸을 때 no 출력
    {
        cout << " no " << endl;
    }

    cin >> input; // 반복횟수 정해주기
    compare(input); // 문자열을 비교해서 출력하는 함수
    fin.close();
}

void compare(int input)//문자열 비교함수
{
    int q; //?의 존재 판단
    int cnt = 0; //finalname의 열을 가르키는 변수
    int change1;
    char finalname[15][30] = { 0 }; // 최종적으로 출력할 배열
    char data[30] = { 0 }; // 한 줄씩 입력받아 비교할 배열
    char name[30]; //비교할 문자열을 입력받을 배열
    ifstream fin; //스트림 생성

    for (int i = 0; i < input; i++)// 입력받은 횟수만큼 반복
    {
        fin.open("filename_list.txt"); // 파일 열기
        cin >> name; // 비교할 문자열 입력받기
        change1 = change(name); // *과 ?의 경우 고려해주기
        while (!fin.eof()) //파일 끝까지 모든 글자를 data에 담기.
        {
            q = 0;
            fin.getline(data, 30);
            if (change1 >= 0 && strncmp(data, name, change1) == 0) //*이 있거나 혹은 아무것도 없는 경우.
            {
                strcpy(finalname[cnt], data); //조건에 해당되는 글을 그대로 배열에 저장
                cnt++;
            }
            else if (change1 == -1) //?가 있는 경우 ?는 넘기고 한 글자씩 복사
            {
                for (int i = 0; i < strlen(name); i++)
                {
                    if (name[i] == '?') // ?가 있는 인덱스의 배열은 넘기기
                        continue;
                    else if (name[i] == data[i] && strlen(name) == strlen(data))// 배열의 모든 길이가 맞고 ?를 제외한 모든 배열인덱스가 똑같을 때
                        q++;
                }
                if (q == strlen(name) - 1) // ?를 제외한 모든 글자가 맞다면 복사
                {
                    strcpy(finalname[cnt], data); //조건에 해당되는 글을 그대로 배열에 저장
                    cnt++;
                }

            }
        }
        fin.close();
    }
    cout << endl;
    for (int i = 0; i < cnt; i++) // finalname 출력
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
int change(char* name) // *과 ? 고려해주기
{
    int star = 0;
    for (int i = 0; i < 30; i++)
    {
        if (name[i] != '*')
            star++;
        else if (name[i] == '*' || name[i] == NULL) //아무것도 없는 경우도 포함
            return star;
        if (name[i] == '?')
            return -1;

    }
}