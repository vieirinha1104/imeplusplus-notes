#include <iostream>

using namespace std;

class vector{
    //Atributos
    protected:
    int *arr;
    int sz;
    public:
    //Construtor:
    vector(){
        sz=0;
        arr=new int[sz+1];
    }
    //Metodos de acesso
    int acessarArr(int x){
        if(x<=sz-1){
            return arr[x];
        }
        else{
            return -1;
        }
    }
    int size(){
        return sz;
    }
    //Metodo de insercao:
    bool push_back(int y){
        if(sz==0){
        arr[sz]=y;
        sz++;
        return true;
        }
        else{
            int *tmp=new int[sz+1];
            for(int i=0;i<sz;i++){
                tmp[i]=arr[i];
            }
            tmp[sz]=y;
            sz++;
            delete[] arr;
            arr=tmp;
            return true;

        }
    }
    int& operator[](int i){
        return arr[i];
    }
    void operator++(vector &v){
        v.sz++;
       
    }
};

class stack : public vector{
    public:
    //Metodo de Remocao:
    bool pop(){
        if(sz==0){
            return false;
        }
        else{
            sz--;
            return true;
        }
    }
    //Construtor:
    stack():vector(){};
};

class queue : public vector{
    public:
    //Construtor:
    queue():vector(){};
    //Metodo de Remocao:
    bool pop(){
        if(sz==0){
            return false;
        }
        else if(sz==1){
            sz--;
            return true;
        }
        else{
            int* aux= new int[sz-1];
            for(int i=1;i<sz;i++){
                aux[i-1]=arr[i];
            }
            delete[] arr;
            arr=aux;
            sz--;
        }
    }
};
int main(){
    queue d;
    d.push_back(1);
    d.pop();
    cout << d.size() << "\n";
    d.pop();
    d.push_back(1);
    d.push_back(2);
    d.pop();
    cout << d.acessarArr(1) << "\n";
    cout << d.size() << "\n";
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.pop();
   for(int i=0;i<d.size();i++){
    cout << d.acessarArr(i) << "\n";
   }
   cout << d.size() << "\n";
   d.push_back(4);
   for(int i=0;i<d.size();i++){
    cout << d.acessarArr(i) << "\n";
   }
   cout << d.size() << "\n";
   d.pop();
   for(int i=0;i<d.size();i++){
    cout << d.acessarArr(i) << "\n";
   }
      cout << d.size() << "\n";
    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    cout << d.acessarArr(0) << " " << d[0] << "\n";
    cout << v.size() << "\n";
    v++;
    cout << v.size() << "\n";

}   