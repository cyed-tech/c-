#include<iostreaM>
#include<vector>
#include<string>
using namespace std;
 
// vector<int> stack(10);
// int sp = 0;
// void push(int value){
//     stack[sp++] = value;
// }
// int pop(){
//     return stack[--sp];
// }

class stack{
    private:
        int stacking[10];
        int sp;
    public:
    stack(){
        sp = 0;
    }
        void push(int val);
        int pop(); 
};
    void stack::push(int val){
        stacking[sp++] = val;
    }
    int stack::pop(){
        return stacking[--sp];
    }
class sub_stack : stack{
    private:
        int sum;
    public:
    sub_stack(){
            sum = 0;
        }
        void push(int val);
        int pop();
        int get_sum();
};
void sub_stack::push(int val){
    sum +=val;
    stack::push(val);
}
int sub_stack::pop(){
    int val = stack::pop();
    sum -=val;
    return val;
}
int sub_stack::get_sum(){
    return sum;
}

class animal{
    private:
       vector<string> mammals;
       int total;
    public:
        animal(){
            total = 10;
        }
        void entries1();
        void entries2();
        int return_type();
};
void animal::entries1(){
    for(int i = 0;i<10; i++){
        string x;
        cout<<"Enter name of domesticated Mammmals: ";
        getline(cin,x);
        mammals.push_back(x);
    }
}
void animal::entries2(){
    for(int i = 0;i<10; i++){
        string x;
        cout<<"Enter name of Wild Mammmals: ";
        getline(cin,x);
        mammals.push_back(x);
    }
}
int animal::return_type(){
    return 1;
}
class sub_class : animal{
    private:
    public:
    void category(char c);
};
void sub_class::category(char f){
    switch(f){
        case 'A':
            animal::entries1();
        case 'B':
            animal::entries2();
        default:
            animal::return_type();
    }
}
int main(){
    char c;
    cout<<"Enter Category of the mammals (A for Domesticated Mammals B for Wild Mammals):";
    cin>>c;
    sub_class a;
    a.category(c);
    // sub_stack a,b,c;
    // a.push(3);
    // b.push(a.pop() + 3);
    // cout<<b.pop();
}