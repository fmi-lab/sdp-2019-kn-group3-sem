#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
using namespace std;

int mazeM[8][8] =
{
    {0,1,0,0,0,1,0,0},
    {0,1,0,0,0,1,0,0},
    {0,1,0,0,1,1,1,1},
    {0,1,0,1,0,0,0,0},
    {0,1,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,0,1},
    {0,1,0,1,1,0,0,0}
};

bool walkable(int maze[8][8], int targetX, int targetY)
{
    if(targetX < 0 || targetX > 7 ||
            targetY < 0 || targetY > 7 ||
            maze[targetX][targetY] != 0)
    {
        return false;
    }
    return true;
}

bool isWay(int maze[8][8], int startX, int startY, int endX, int endY)
{
    maze[startX][startY] = 2;
    if(startX == endX && startY == endY)
    {
        return true;
    }
    bool result = false;
    if(walkable(maze, startX + 1, startY))
    {
        result = isWay(maze, startX + 1, startY, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX, startY + 1))
    {
        result = isWay(maze, startX, startY + 1, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX - 1, startY))
    {
        result = isWay(maze, startX - 1, startY, endX, endY);
        if(result)
        {
            return result;
        }
    }
    if(walkable(maze, startX, startY - 1))
    {
        result = isWay(maze, startX, startY - 1, endX, endY);
        if(result)
        {
            return result;
        }
    }
    return false;
}

bool is_way_stack(int maze[8][8], int startX, int startY, int endX, int endY){
    stack<pair<int, int> > s;
    s.push(pair<int, int>(startX, startY));

    while(!s.empty()){
        pair<int, int> current(s.top());
        s.pop();

        maze[current.first][current.second] = 2;

        if(current == pair<int, int>(endX, endY)){
           return true;
        }

        cout<<current.first<<" "<<current.second<<endl;
        if(walkable(maze, current.first + 1, current.second)){
            cout<<"down\n";
            s.push(pair<int, int>(current.first + 1, current.second));
        }
        if(walkable(maze, current.first, current.second + 1)){
            cout<<"right\n";
            s.push(pair<int, int>(current.first, current.second + 1));
        }
        if(walkable(maze, current.first - 1, current.second)){
            cout<<"up\n";
            s.push(pair<int, int>(current.first - 1, current.second));
        }
        if(walkable(maze, current.first, current.second - 1)){
            cout<<"left\n";
            s.push(pair<int, int>(current.first, current.second - 1));
        }

        cout<<"stack_size = "<<s.size()<<endl;
    }
    return false;
}

bool is_way_queue(int maze[8][8], int startX, int startY, int endX, int endY){
    queue<pair<int, int> > s;
    s.push(pair<int, int>(startX, startY));

    while(!s.empty()){
        pair<int, int> current(s.front());
        s.pop();

        maze[current.first][current.second] = 2;

        if(current == pair<int, int>(endX, endY)){
           return true;
        }

        cout<<current.first<<" "<<current.second<<endl;
        if(walkable(maze, current.first + 1, current.second)){
            cout<<"down\n";
            s.push(pair<int, int>(current.first + 1, current.second));
        }
        if(walkable(maze, current.first, current.second + 1)){
            cout<<"right\n";
            s.push(pair<int, int>(current.first, current.second + 1));
        }
        if(walkable(maze, current.first - 1, current.second)){
            cout<<"up\n";
            s.push(pair<int, int>(current.first - 1, current.second));
        }
        if(walkable(maze, current.first, current.second - 1)){
            cout<<"left\n";
            s.push(pair<int, int>(current.first, current.second - 1));
        }

        cout<<"stack_size = "<<s.size()<<endl;
    }
    return false;
}

void printMaze(int maze[8][8]){
    for(short i = 0; i<8; i++){
        for(short j = 0; j<8; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
}




int main(){
//    cout<<isWay(mazeM, 0, 0, 7, 0)<<endl;


//    cout<<"RESULT = "<<is_way_stack(mazeM, 0, 0, 4, 2)<<endl;
    cout<<"RESULT = "<<is_way_queue(mazeM, 0, 0, 4, 2)<<endl;
    printMaze(mazeM);

}
