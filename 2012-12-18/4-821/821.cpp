
//uva821
#include <iostream>
#include <cstdio>
 
using namespace std;
 
const unsigned int MAX = 101;
unsigned int arr[MAX][MAX];
void reset(){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            arr[i][j] = 101;
}
 
bool set(){    
    int a, b;
    cin >> a >> b;
    if(a == 0 && b == 0)
        return false;
    reset();
    arr[a][b] = 1;
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        arr[a][b] = 1;
    }
    return true; 
}
double count(){
    int sum = 0, path = 0;
    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < MAX; j++){
            if(arr[i][j] <= 100 && i != j){
                sum += arr[i][j];
                path++;
            }
        }   
    }
    return (double)sum / path;
}
 
int main(){
    for(int I = 1; set(); I++){
        for(int k = 0; k < MAX; k++){
            for(int i = 0; i < MAX; i++){
                for(int j = 0; j < MAX; j++){
                    if(arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }        
            }           
        }
        printf("Case %d: average length between pages = %.3f clicks\n", I, count());
    }
    return 0;
}