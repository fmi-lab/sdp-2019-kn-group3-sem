#include<iostream>
#include<stack>

using namespace std;

unsigned factoriel(int n){
    if(n <= 1){
        return 1;
    }
    return n*factoriel(n-1);
}

//unsigned fact_stack(int n){
//    stack<int> st;
//    st.push(n);
//    int result = 1;
//    while(!st.empty()){
//        int current = st.top();
//        st.pop();
//        if(current > 0){
//            result *= current;
//        }
//        st.push(current-1);
//    }
//    return result;
//}

void rec(int n){
    if(n<=0){
        return;
    }
    rec(n-1);
    cout<<n<<endl;
}

void stack_print(int n){
    stack<int> st;
    for(int i = 1; i<=n; i++){
        st.push(i);
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    cout<<factoriel(5)<<endl;
//    cout<<endl<<fact_stack(5);
    rec(10);
    stack_print(10);
}
