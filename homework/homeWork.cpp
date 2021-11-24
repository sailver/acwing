#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//SwapInt������x��yָ����ڴ��ַ��ֵ
bool SwapInt(int* x, int* y);
// ��С����������
bool ThreeIntSort(int* x1, int* x2, int* x3);
bool FourIntSort(int* x1, int* x2, int* x3, int* x4);
bool FiveIntSort(int* x1, int* x2, int* x3, int* x4, int* x5);

int in=0; //����ͳ��ִ���˶��ٴαȽ�

bool Getline(ifstream &ifs,int *arr,int target);
void Countin(ifstream &ifs,string name,int target);

int main()
{
    // ��ȡ�ļ�
    ifstream ifs;

    // ͳ���������ȽϵĴ���
    Countin(ifs,"A3.txt",3);
    // ͳ���ĸ����ıȽϴ���
    Countin(ifs,"A4.txt",4);
    // ͳ��������ıȽϴ���
    Countin(ifs,"A5.txt",5);

    return 0;
}

// ͳ�ƱȽϴ����ĳ���,target��ʾͳ�Ƽ�������
void Countin(ifstream &ifs,string name,int target)
{
    int arr[5]={0}; // ���ÿ�����е���
    ifs.open(name,ios::in);
    float sum = 0.0; // ����ͳ��һ���ĺ�
    int max = 0,min = 10000;
    // ��ȡÿ�����е����ݣ�����ÿ�����еĵ�in

    // ��������ͳ��һ�����ֵĴ���
    int counts[30]={0};
    while(Getline(ifs,arr,target))
    {
        in = 0;

        // ����target��������ͳ�ƱȽϴ���
        if(target == 3)
        { ThreeIntSort(&arr[0],&arr[1],&arr[2]); }
        else if(target == 4)
        { FourIntSort(&arr[0],&arr[1],&arr[2],&arr[3]); }
        else
        { FiveIntSort(&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]); }

        // ��ÿ�����д�ӡ����
        // for(int i=0;i<target;i++) cout<<arr[i]<<" ";
        // cout<<" �ȽϵĴ�����"<<in<<endl;

        // �Ӻ�
        sum += in;
        // �õ������õ����
        max = (max<in)? in:max;
        min = (min>in)? in:min;

        // ͳ��in���ֵĴ���
        counts[in]++;
    }
    // ��ƽ����������ӡ���������
    if(target == 3) {cout<<"������������ƽ���Ƚϴ����ǣ�"<<sum/6<<" ��õ����������:"<<min<<" ����������:"<<max<<endl;}
    else if(target == 4){cout<<"�ĸ���������ƽ���Ƚϴ����ǣ�"<<sum/24<<" ��õ����������:"<<min<<" ����������:"<<max<<endl;}
    else {cout<<"�����������ƽ���Ƚϴ����ǣ�"<<sum/120<<" ��õ����������:"<<min<<" ����������:"<<max<<endl;}
    ifs.close();

    // ��ӡ����
    for(int i=0;i<20;i++)
    {
        if(! counts[i]) continue;
        printf("%d���ֵĴ�����:%d  ",i,counts[i]);
    }
    puts("\n");
}

// ��ȡÿ�����е�����
bool Getline(ifstream &ifs,int *arr,int target)
{
    for(int i=0;i<target;i++)
    {
        if(!(ifs>>arr[i])) return false;
    }
    return true;
}

bool ThreeIntSort(int* x1, int* x2, int* x3)
{
    // note: �����ں����ڲ�����in����Ϊ���������ĸ�����ʱ������ǰ��ģ������ᵼ������in����1��
    if((++in) && (*x1 > *x2)) SwapInt(x1,x2);
    if((++in) && (*x1 > *x3))
    {
        SwapInt(x1,x3);
        SwapInt(x2,x3);
    }
    else if( (++in) && (*x2 > *x3)) SwapInt(x2,x3);
    return true;
}
bool FourIntSort(int* x1, int* x2, int* x3, int* x4)
{
    if((++in) && ThreeIntSort(x1,x2,x3) )
    {
        // �����ź�ǰ����
        if( (++in) && ( *x1 > *x4 ) )
        {
            SwapInt(x1,x4);
            SwapInt(x2,x4);
            SwapInt(x3,x4);
        }
        else if((++in)&& (*x2 > *x4))
        {
            SwapInt(x2,x4);
            SwapInt(x3,x4);
        }
        else if( (++in)&& (*x3>*x4)) SwapInt(x3,x4);
        return true;
    }
    else return false;
}
bool FiveIntSort(int* x1, int* x2, int* x3, int* x4, int* x5)
{
    // �Ȱ�ǰ�ĸ�������
    if((++in)&& (FourIntSort(x1,x2,x3,x4) ))
    {
        if((++in)&& (*x1 > *x5))
        {
            SwapInt(x1,x5);
            SwapInt(x2,x5);
            SwapInt(x3,x5);
            SwapInt(x4,x5);
        }
        else if( (++in)&&( *x2>*x5))
        {
            SwapInt(x2,x5);
            SwapInt(x3,x5);
            SwapInt(x4,x5);
        }
        else if((++in)&& (*x3>*x5))
        {
            SwapInt(x3,x5);
            SwapInt(x4,x5);
        }
        else if((++in)&&(*x4>*x5)) SwapInt(x4,x5);
        return true;
    }
    else return false;
}

bool SwapInt(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return true;
}