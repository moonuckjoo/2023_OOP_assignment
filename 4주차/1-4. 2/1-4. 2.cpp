#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
using namespace std;
void DC(int R1, int R2, int Vs);// 직렬
void VC(int R1, int R2, int Rload, int Vs);// 병렬
int main()
{
    int V = 0, I = 0, R = 0;
    int Rload = 0;
    int R1 = 0, R2 = 0, Vout = 0, Vs = 0;
    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> Rload;
    if (Rload == 0) // Rload가 0이면 직렬만 고려
    {
        DC(R1, R2, Vs);
    }
    else // Rload가 0이 아니면 병렬까지 고려
    {
        VC(R1, R2, Rload, Vs);
    }
}
void DC(int R1, int R2, int Vs)
{
    cout << "Vout: " << Vs * R2 << "/" << R1 + R2 << "=" << (float)Vs * R2 / (R1 + R2);
}
void VC(int R1, int R2, int Rload, int Vs)
{
    float R2llRload = R2 * Rload / (R2 + Rload); //R2 Rload병렬저항 계산
    float Ps = Vs * Vs / (R1 + R2llRload);
    float VL = Vs * R2llRload / (R1 + R2llRload);
    float Pload = VL * VL / Rload;
    cout << "Vout: " << Vs * R2llRload << "/" << R1 + R2llRload << "=" << Vs * (R2llRload / (R1 + R2llRload)) << endl;
    cout << "Load_power_ratio: " << (Pload / Ps) * 100 << "%";
}