#include "iostream"
#include "ctime"
#include "string"

using namespace std;

int generar_numero_random(int min, int max){
    int range = max + 1  - min;  
    return min + ( rand() % range);
}


int main(){
    srand( (unsigned)time(0) );
    for(int i = 0; i < 10; i++){
        cout << generar_numero_random(1,10)<<endl;
    }
    string hola;
    srand( (unsigned)time(0) );
    cin>>hola;
    for(int i = 0; i < 10; i++){
        cout << generar_numero_random(1,10)<<endl;
    }
 
}