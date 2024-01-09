#include <iostream>

using namespace std;

enum modoDeque {front=0,back};
class deque{

protected:
int sz;
int cap;
int *arr;

public:
//Metodos de Acesso:
int getSize(){
    return sz;
}
int getCap(){
    return cap;
}
int getArr(int pos){
    if(pos<0){
        return -1;
    }
    else{
    return arr[pos];
    }
}

//Impressao:
void printArr(){
    for(int i=0;i<sz;i++){
        cout << getArr(i) << " ";
    }
    cout << "\n";
    return;
}
//Insercao:
bool push(const enum modoDeque &b,int x){
    if(b==back){
        if(sz<cap){
            arr[sz]=x;
            sz++;
            return true;
        }
        else{
            cout <<"Deque Cheio\n";
            return false;
        }
    }
    else{
        if(sz<cap){
        int *tmp=new int[cap];
            tmp[0]=x;
        for(int i=0;i<sz;i++){
            tmp[i+1]=arr[i];
        }
        delete[] arr;
        arr=tmp;   
        sz++;
        return true;
        }
        else{
            cout <<"Deque Cheio\n";
            return false;
        }      
    }

}

//Remocao:
bool pop(const enum modoDeque &b){
    if(b==front){
        if(sz==0){
            cout << "Deque Vazio\n";
            return false;
        }
        else{
            int *tmp=new int[cap];
            for(int i=1;i<sz;i++){
                tmp[i-1]=arr[i];
            }
            delete[] arr;
            arr=tmp;
            sz--;
            return true;
        }

    }
    else{
        if(sz==0){
            cout << "Deque Vazio\n";
            return false;
        }
        else{
            sz--;
            return true;
        }

    }
}
//Construtor:

//Parametro:
deque(int tam):cap(tam),sz(0){
    arr = new int[tam];
}
//Default:
deque():cap(2),sz(0){
    arr=new int[2];
}
//Copia:
deque(const deque &d){
    this->sz=d.sz;
    this->cap=d.cap;
    this->arr=new int[d.cap];
    for(int i=0;i<d.sz;i++){
        this->arr[i]=d.arr[i];
    }
}

//Destrutor:
~deque(){
    delete[] arr;
    cout << "vieira\n";
}

};

class queue : public deque{
    public:
    //Construtores:
    queue():deque(){};
    queue(const queue &d):deque(d){};
    queue(int tam):deque(tam){};
    public:
    bool push(int x){
        enum modoDeque b=back;
        this->deque::push(b,x);
    }
    bool pop(){
        enum modoDeque f=front;
        this->deque::pop(f);
    }

};
int main(){
    enum modoDeque f,b;
    f=front;
    b=back;
 queue q(10);
 q.push(1);
 q.push(2);
 q.push(3);
 q.printArr();
 q.pop();
 q.printArr();
 
}