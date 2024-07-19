#include <iostream>
#include <array>
using namespace std;
class SelectionSort{
public:
    void Sort(int arr[]){
        for(int i=0;i<5;i++){
            int min=arr[i],pos=i,t;
            for(int j=i;j<6-1;j++){
                if(arr[j]<min){
                    min=arr[j+1];
                    pos=j+1;
                }
            }
            t=arr[pos];
            arr[pos]=arr[i];
            arr[i]=t;
        }
    }
    void print(int arr[]){
        for(int i=0;i<6;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    SelectionSort s;
    int arr[]={3,2,6,4,1,7};
    s.Sort(arr);
    s.print(arr);
}