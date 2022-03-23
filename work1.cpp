/*


约瑟夫环问题：设编号为1，2，3，……，n的n(n>0)个人按顺时针方向围坐一圈，
m为任意一个正整数。从第一个人开始顺时针方向自1起顺序报数，报到m时停止并且报m的人出列，
再从他的下一个人开始重新从1报数，报到m时停止并且报m的人出列。如此下去，直到所有人全部出列为止。
要求设计一个程序模拟此过程，对任意给定的m和n，求出出列编号序列。
实验要求：用顺序表实现。

3 6 9 2 7 1 8 5 10 4 

*/
#include<iostream>
using namespace std;

class ArrayList{
public:
    int *array;
    int length;
    ArrayList(){
        array=nullptr;
        length=0;
    }

    ArrayList(int a[],int len){
        length = len;
        array=new int[length];
        for(int i=0;i<length;i++){
            array[i]=a[i];
        }
    }

    void pop(int pos){              //删除索引位置的元素，所有元素前移一位
        for(int i=pos;i<length-1;i++){
            array[i]=array[i+1];
        }
        length--;
    }

    ~ArrayList(){
        // delete[]array;
    }
};
ostream & operator << (ostream &os,const ArrayList & a){
    for(int i=0;i<a.length;i++){
        os<<a.array[i]<<" ";
    }
    return os;
}

int find_pos(ArrayList a,int stop_num,int start_num){          //寻找每次叫m的同学的索引值  
    if(a.length==1){
        return 0;
    }
    if(start_num+stop_num>a.length-1){
        return (start_num+stop_num)%(a.length);
    }
    return start_num+stop_num;
}

ArrayList solution(int p_num,int stop_num){
    int a[p_num];
    for(int i=0;i<p_num;i++){
        a[i]=i+1;
    }
    ArrayList tool(a,p_num);
    int target[p_num];
    int num=0,start_num=0;
    while(num!=p_num){
        int pos=find_pos(tool,stop_num,start_num);
        target[num]=tool.array[pos];
        tool.pop(pos);
        num++,start_num=pos;   //索引位置元素删除之后，该索引位置的新元素从一开始报数。
    }
    ArrayList tar(target,p_num);
    return tar;
}


int main(){
    //输入总人数n,报数报到id为m的人出列;        从1开始叫到m,m出列，所以目标索引值=初始索引值+m-1;所以传入的stop_num还得减1;
    int p_num,stop_num;
    cin>>p_num>>stop_num;
    //定义一个解决函数，返回值为一个大小为n的数组用于输出最终的出列编号序列
    ArrayList a=solution(p_num,stop_num-1);
    cout<<a<<endl;

}
































