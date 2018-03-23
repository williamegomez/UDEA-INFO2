#include <iostream>

using namespace std;

int main()
{
    int i;

    char letraultim='Z';
    int renglones=letraultim-'A'+1;
    for(i=0;i<renglones;i++){
        int j;
        char letra='A';
        for(j=0;j<=i;j++){
            cout << letra;
            letra++;
        }

        for(j=(2*renglones-3)-2*i;j>=1;j--){
            cout << " ";
        }

        letra--;
        for(j=0;j<=i;j++){
            if(letra != letraultim){
                cout << letra;
            }
            letra--;
        }
        cout << endl;
    }
}
