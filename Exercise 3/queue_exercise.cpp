#include<iostream>
#include<queue>

using namespace std;

template<typename T>
void min_el_queue(queue<T> q, T& min_el, queue<T>& q_accumulate)
{
    T x;
    min_el = q.front();
    q.pop();
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(x < min_el)
        {
            q_accumulate.push(min_el);
            min_el = x;
        }
        else
        {
            q_accumulate.push(x);
        }
    }
}

template <typename T>
void sort_queue(queue<T> q, queue<T>& newq)
{
    while(!q.empty())
    {
        T min_el;
        queue<T> q1;
        min_el_queue(q, min_el, q1);
        newq.push(min_el);
        q = q1;
    }
}

template <typename T>
void print_queue(queue<T> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}

template <typename T>
void merge_queues(queue<T> q1, queue<T> q2, queue<T>& merged)
{
    while(!q1.empty() && !q2.empty())
    {
        T top1 = q1.front();
        T top2 = q2.front();

        T x;
        if (top1 < top2)
        {
            x = top1;
            q1.pop();
        }
        else
        {
            x = top2;
            q2.pop();
        }
        merged.push(x);
    }

    while(!q1.empty()){
        merged.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){
        merged.push(q1.front());
        q2.pop();
    }
}

int main()
{
    queue<int> qi;
    qi.push(5);
    qi.push(4);
    qi.push(54);
    qi.push(2);
    qi.push(10);
    qi.push(43);
    queue<int> sorted_qi;
    sort_queue(qi, sorted_qi);

    print_queue(sorted_qi);

    queue<int> qi2;
    qi2.push(3);
    qi2.push(2);
    qi2.push(4);
    qi2.push(-5);
    qi2.push(1);
    qi2.push(30);
    qi2.push(21);

    queue<int> sorted_qi2;
    sort_queue(qi2, sorted_qi2);
    cout<<"***********************\n";
    print_queue(sorted_qi2);

    cout<<"***********************\n";

    queue<int> merged;
    merge_queues(sorted_qi, sorted_qi2, merged);

    print_queue(merged);

}
