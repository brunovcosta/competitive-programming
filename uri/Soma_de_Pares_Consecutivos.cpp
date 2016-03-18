#include<iostream>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    while (n){
        cout << 5*(n + n*n % 2)+20<<endl;
        cin >> n;
    }
    return 0;
}