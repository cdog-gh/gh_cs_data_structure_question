#include <stdio.h>
#include <vector>
using namespace std;
vector <int> capacity_set;
int main(void)
{
    vector <int> v;
    int prev_capacity = v.capacity();
    for(int i=1; i<=1000000; i++)
    {
        v.push_back(1);
        int cur_capacity = v.capacity();
        //원소가 추가되고 난 후에 capacity 값이 바뀌었다면, expand 연산이 호출된 것
        if(prev_capacity != cur_capacity)
            capacity_set.push_back((int)v.capacity());
        prev_capacity = cur_capacity;
    }
    
    //capacity가 어떻게 변했는지 capacity_set에 저장된다.
    for(int i=0; i<(int)capacity_set.size(); i++)
        printf("%d\n",capacity_set[i]);
}