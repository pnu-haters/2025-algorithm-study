#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int *result = new int[n];
    int *input = new int[n];
    for(int i =0; i<n; i++)result[i] = 0;
    for(int i = 0; i<n; i++) cin>>input[i];

    for(int i = 0; i<n; i++){
        int k = 0;// 0 count,남은자리
        int p = 0;//실제 위치
        while(k!=input[i]+1){
            if(result[p]==0){
                k++;
            }
            p++;
        }

        result[p-1]=i+1;
        for(int i=0; i<n; i++){
        cout<<result[i]<<' ';
        }
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        cout<<result[i]<<' ';
        }



    return 0;
}
