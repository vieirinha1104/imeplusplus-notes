#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
//Variaveis globais:
vector<int> preT;
vector<int> simT;
string s="";
int aux=0;
//Classes:
class no{
    public:
    //Atributos:
    int key;
    no* esq;
    no* dir;
    //Metodos:
    //Construtores:
    no(int rotulo):key(rotulo){
        esq=NULL;
        dir=NULL;
    }
};
class tree{
    public:
    //1-)Atributos:
    no* raiz;
    //2-)Metodos:
    //2.1-)Construtores:
    tree(){
        raiz=NULL;
    }
    //2.2-)Funcoes da classe:
    //Recuperar a minha Arvore:
    void setTree(no* &root,int iP,int fP,int iS,int fS){
        //Criacao da raiz:
        no* tmp = new no(preT[iP]);
        root=tmp; 
        //Busca da raiz na ordem simetrica:
        int i=iS;
        while(i<=fS && simT[i]!=preT[iP]){
            i++;
        }
        if(i!=iS){ //Verificar se a sub arvore a esq nao eh vazia
            setTree(root->esq,iP+1,iP+i-iS,iS,i-1);
        }
        if(i!=fS){
            setTree(root->dir,iP+i-iS+1,fP,i+1,fS);
        }
    }
    void decodifica(no* root,string s,int &i){
        if(i==s.size()+1){
            return;
        }
        else{
                if(root->esq==NULL && root->dir==NULL){
                    char char_tmp=root->key;
                    cout<<char_tmp;
                    decodifica(raiz,s,i);
                }
                else{
                    if(s[i]=='0'){
                    i++;
                    decodifica(root->esq,s,i);
                    }
                    if(s[i]=='1'){
                    i++;
                    decodifica(root->dir,s,i);
                    }
                }
    }
    }
    //percursos:
    void pre(no* root){
        if(root!=NULL){
            cout<<root->key;
            pre(root->esq);
            pre(root->dir);
        }
    }
    //Printa as folhas
    void sim(no* root){
        if(root!=NULL){
            sim(root->esq);
            cout<<root->key;
            sim(root->dir);
        }
    }
};
int main(){
    //lER MEU ARQUIVO PARA GERAR MINHA STRING CODIFICADA
    //E GERAR MEUS VECTOR DE PRE ORDEM E ORDEM SIMETRICA
    ifstream arq;
    char data;
    int dt;
    arq.open( "output.txt" , ios::in );
    if (!arq.is_open()){
        return 0;
    }
    do {
        arq >> data;
       if(data=='.'){
            break;
        }
        s+=data;
    } while (!arq.eof( ));
    do {
        arq >> dt;
       if(dt==0){
            break;
        }
        preT.push_back(dt);
    } while (!arq.eof( ));
    do {
        arq >> dt;
       if(arq.eof()){
            break;
        }
        simT.push_back(dt);
    } while (!arq.eof( ));   
    arq.close( );
    //Recuperar minha arvore
    tree t;
    t.setTree(t.raiz,0,preT.size()-1,0,simT.size()-1);
    //Printar minha msg decodificada na tela:
    t.decodifica(t.raiz,s,aux);
  
}