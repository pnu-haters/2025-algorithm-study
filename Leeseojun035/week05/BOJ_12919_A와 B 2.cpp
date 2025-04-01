#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

string target;
int targetA, targetB;

int strSearch(string start){
    int total_A = count(start.begin(),start.end(),'A');
    int total_B = count(start.begin(),start.end(),'B');

    if((total_A>targetA)&&(total_B>targetB)) return 0;

    if(start.length()==target.length()){
        if(start==target)return 1;
        else return 0;
    }//재귀 종료

    string tmp = start+'B';
    string str1;
    for(auto it = tmp.rbegin(); it!=tmp.rend(); ++it )
        str1.push_back(*it);


    return strSearch(start+'A')||strSearch(str1);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string start;

    cin>>start>>target;
    targetA = count(target.begin(),target.end(),'A');
    targetB = count(target.begin(),target.end(),'B');

    cout<<strSearch(start);
}
