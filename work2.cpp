/*
    一元多项式求和
    例如：a+bx^+cx^2+......和另一个类似的多项式相加

    思路:用链表结构实现，用两个链表分别存储两个输入的多项式，还用一个链表存储两个多项式相加的结果。
    索引代表x的指数，node里面存储的int 为x的系数; 计算为相应索引的node里面的数据相加
*/
#include<iostream>
using namespace std;
const int Max = 10;
class LinkedList {
public:

    LinkedList& operator +(const LinkedList& l) {
        Node* tool1 = this->head->next;
        Node* tool2 = l.head->next;
        int a[Max];
        int i = 0;
        //两个node都不为空的时候
        while (tool1 != nullptr && tool2 != nullptr) {
            //相应结点的系数相加
            a[i] = tool1->data + tool2->data;
            i++;
            tool1 = tool1->next;
            tool2 = tool2->next;
        }
        //有一方为空或者两方都为空退出循环
        Node* not_null = l.length > this->length ? tool2 : tool1;
        while (not_null != nullptr) {
            a[i] = not_null->data;
            i++;
            not_null = not_null->next;
        }
        LinkedList *Target = new LinkedList(a, i);
        return *Target;
    }


    struct Node {
        int index;          //x的指数
        int data;           //x的系数
        Node* next;
        Node(int a = 0, int b = 0) :index(a), data(b), next(nullptr) {}
    };
    Node* head;
    int length;
    LinkedList() {
        head = new Node;
        length = 0;
    }
    LinkedList(int a[], int len) {            //输入赋值给数组，数组再复制给链表
        head = new Node;
        Node* tool = head;
        for (int i = 0; i < len; i++) {
            Node* new_node = new Node;
            new_node->index = i;
            new_node->data = a[i];
            tool->next = new_node;
            tool = new_node;
        }
        length = len;
    }
    ~LinkedList() {
        Node* tool = head->next;
        while (tool != nullptr) {
            Node* tool2 = tool->next;
            delete tool;
            tool = tool2;
        }
    }
};
ostream& operator<<(ostream& os, const LinkedList& l) {
    LinkedList::Node* tool = l.head->next;
    while (tool != nullptr) {
        //不输入的情况
        if (tool->data == 0) {
            tool = tool->next;
            continue;
        }
        //索引为0的时候而且data不等于0的时候，可以直接写，因为data=0走不到下面的判断
        if (tool->index == 0) {
            os << tool->data << "+";
            tool = tool->next;
            continue;
        }
        //如果下一个node为null的话则不输出“+”；
        if(tool->next==nullptr){
            os << tool->data << "x^" << tool->index;
             tool = tool->next;
        }
        else{
            os << tool->data << "x^" << tool->index << "+";
             tool = tool->next;
        }
        
    }
    return os;
}
void solution() {
    //分别输入两个多项式，先输入总共输入的项数，然后再从指数为0开始输入系数
    cout << "请输入第一个行列式的项数:" << endl;
    int line_num1;
    cin >> line_num1;
    int a1[Max];
    for (int i = 0; i < line_num1; i++) {
        cout << "请输入指数为" << i << "的x的系数:" << endl;
        cin >> a1[i];
    }
    cout << "请输入第二个行列式的项数:" << endl;
    int line_num2;
    cin >> line_num2;
    int a2[Max];
    for (int i = 0; i < line_num2; i++) {
        cout << "请输入指数为" << i << "的x的系数:" << endl;
        cin >> a2[i];
    }
    LinkedList l1(a1, line_num1); LinkedList l2(a2, line_num2);
    cout << l1 + l2 << endl;
}

int main() {
    solution();
    return 0;
}