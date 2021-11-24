#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//SwapInt，交换x和y指向的内存地址的值
bool SwapInt(int* x, int* y);
// 从小到到大排序
bool ThreeIntSort(int* x1, int* x2, int* x3);
bool FourIntSort(int* x1, int* x2, int* x3, int* x4);
bool FiveIntSort(int* x1, int* x2, int* x3, int* x4, int* x5);

int in=0; //用于统计执行了多少次比较

bool Getline(ifstream &ifs,int *arr,int target);
void Countin(ifstream &ifs,string name,int target);

int main()
{
    // 获取文件
    ifstream ifs;

    // 统计三个数比较的次数
    Countin(ifs,"A3.txt",3);
    // 统计四个数的比较次数
    Countin(ifs,"A4.txt",4);
    // 统计五个数的比较次数
    Countin(ifs,"A5.txt",5);

    return 0;
}

// 统计比较次数的程序,target表示统计几个数的
void Countin(ifstream &ifs,string name,int target)
{
    int arr[5]={0}; // 存放每种排列的数
    ifs.open(name,ios::in);
    float sum = 0.0; // 用于统计一共的和
    int max = 0,min = 10000;
    // 读取每种排列的数据，计算每种排列的的in

    // 创建数组统计一共出现的次数
    int counts[30]={0};
    while(Getline(ifs,arr,target))
    {
        in = 0;

        // 按照target进行排序，统计比较次数
        if(target == 3)
        { ThreeIntSort(&arr[0],&arr[1],&arr[2]); }
        else if(target == 4)
        { FourIntSort(&arr[0],&arr[1],&arr[2],&arr[3]); }
        else
        { FiveIntSort(&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]); }

        // 把每种排列打印出来
        // for(int i=0;i<target;i++) cout<<arr[i]<<" ";
        // cout<<" 比较的次数："<<in<<endl;

        // 加和
        sum += in;
        // 得到最坏和最好的情况
        max = (max<in)? in:max;
        min = (min>in)? in:min;

        // 统计in出现的次数
        counts[in]++;
    }
    // 求平均次数并打印最好最坏的情况
    if(target == 3) {cout<<"三个数的排序平均比较次数是："<<sum/6<<" 最好的情况次数是:"<<min<<" 最坏情况次数是:"<<max<<endl;}
    else if(target == 4){cout<<"四个数的排序平均比较次数是："<<sum/24<<" 最好的情况次数是:"<<min<<" 最坏情况次数是:"<<max<<endl;}
    else {cout<<"五个数的排序平均比较次数是："<<sum/120<<" 最好的情况次数是:"<<min<<" 最坏情况次数是:"<<max<<endl;}
    ifs.close();

    // 打印次数
    for(int i=0;i<20;i++)
    {
        if(! counts[i]) continue;
        printf("%d出现的次数是:%d  ",i,counts[i]);
    }
    puts("\n");
}

// 读取每行排列的数据
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
    // note: 不能在函数内部重置in，因为后面排序四个数的时候会调用前面的，这样会导致整个in减少1个
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
        // 优先排好前三个
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
    // 先把前四个都排序
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