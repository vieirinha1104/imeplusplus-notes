#include <iostream>

using namespace std;

class bufferCircular{
private:
int sz;
int cap;
int *arr;
int inicio;
int fim;

public:
//Construtor:
bufferCircular(int tam):cap(tam),sz(0),fim(0),inicio(0){
    arr= new int[tam]; 
}
//Destrutor:
~bufferCircular(){
    cout << "Vieira\n";
    delete[] arr;
}
//Metodos:

bool cheio(){
    if(sz==cap){
        cout<< "Buffer Cheio\n";
        return true;
    }
    else{
        return false;
    }
}

bool vazio(){
    if(sz==0){
        cout << "Buffer Vazio\n";
        return true;
    }
    else{
        return false;
    }
}


//Acesso:
int acessar(int pos){
   bool verifica=vazio();
   if(verifica==true){
    return -1;
   }
   else{
    return arr[inicio + pos%sz];
   }
}
//Remocao:
bool pop(){
bool verifica=vazio();
if(verifica==true){
    return false;
}
else{
    if(inicio==cap-1){
        inicio=0;
        sz--;
        return true;
    }
    else{
    inicio++;
    sz--;
    return true;
    }
}
}
//Insercao:
bool push(int y){
   bool verifica;
   verifica =cheio();
   if(verifica==true){
    return false;
   }
   else{
    if(fim==cap){
        fim=0;
        arr[fim]=y;
        fim++;
        return true;
    }
    else{
    arr[fim]=y;
    fim++;
    sz++;
    return true;
   }
}
}

};


int main(){
    bufferCircular arr(6);
    for(int i=1;i<7;i++){
        arr.push(i);
    }
    arr.pop();
    arr.pop();
    arr.push(1);
    for(int i=0;i<8;i++){
        cout << arr.acessar(i)<< "\n";
    }
}