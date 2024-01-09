#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
//Variaveis Globais:
vector<int> freq;
vector<char> key;
vector<string> codificado(16);
vector<int> preT;
vector<int> simT;
int tmp_int=200;
//Funcoes:
int busca(char chave){
    for(int i=0;i<key.size();i++){
        if(key[i]==chave){
            return i;
        }
    }
    return -1;
}
//Classes:
class no{
    public:
    //Atributos:
    char key;
    int freq;
    int rotulo;
    string code;
    no* esq;
    no* dir;
    //Metodos:
    //Construtores:
    no(int f,char chave,string codigo,int rtl):freq(f),key(chave),code(codigo),rotulo(rtl){
        esq=NULL;
        dir=NULL;
    }
    no():freq(0),key('\0'),code(""),rotulo(0){
        esq=NULL;
        dir=NULL;
    }
};
struct cmp{
    bool operator()(const no* n1,const no* n2) const{
        return n1->freq > n2->freq;
    };
};
class HuffmanTree{
    public:
    //1-)Atributos:
    no* raiz;
    //2-)Metodos:
    //2.1-)Construtores:
    tree(){
        raiz=NULL;
    }
    //2.2-)Funcoes da classe:
    //Montar a Arvore:
    void setTree(priority_queue<no*,vector<no*>,cmp> &h){
       while(h.size()!=0){
        if(h.size()==1){
        raiz=h.top();
       }
        no* N1=h.top();
        h.pop();
        no* N2=h.top();
        h.pop();
        no *N3= new no((N1->freq + N2->freq),'\0',"",tmp_int); //A escolha da chave do novo no ser 'n' foi uma estrategia mandrake para diferencia os nos que tem caracter nulo
        tmp_int++;
        N3->dir=N1;
        N3->esq=N2;
        h.push(N3);
       }
    }
    //Codificar minha mensagem:
    void dfs(no* root,string &s){
        if(root!=NULL){
            if(root->esq==NULL && root->dir==NULL){
            root->code=s;
            int tmp=busca(root->key);
            codificado[tmp]=s;
            }
            if(root->esq!=NULL){
            s+="0";
            dfs(root->esq,s);
            s.pop_back();
            }
            if(root->dir!=NULL){
            s+="1";
            dfs(root->dir,s);
            s.pop_back();
            }   
        }
    }
    void codifica(string &msg_codificada,string msg_original){
        for(int i=0;i<msg_original.size();i++){
            int tmp=busca(msg_original[i]);
            msg_codificada+=codificado[tmp];
        }

    }
    //percursos:
    void pre(no* root){ //Monta meu vector de pre ordem
        if(root!=NULL){
            preT.push_back(root->rotulo);
            pre(root->esq);
            pre(root->dir);
        }
    }
    //Printa as folhas
    void pos(no* root){
        if(root!=NULL){
            pos(root->esq);
            pos(root->dir);
            if(root->dir==NULL && root->esq==NULL){
                cout <<"chave: "<< root->key<<" codigo: "<<root->code<<"\n";
            }
        }
    }
    void sim(no* root){ //Monta meu vector de ordem simetrica
        if(root!=NULL){
            sim(root->esq);
            simT.push_back(root->rotulo);
            sim(root->dir);
        }
    }
};
int main(){
    //lER MEU ARQUIVO PARA GERAR MEU VECTOR DE CHAVES E O DE FREQUENCIA:
    ifstream arq;
    string mensagem;
    arq.open( "input.txt" , ios::in );
    if (!arq.is_open()){
        return 0;
    }
    getline(arq,mensagem);
    arq.close( );
    for(int i=0;i<mensagem.size();i++){
        if(freq.size()==0){
            freq.push_back(1);
            char idk=mensagem[i];
            key.push_back(idk);
        }
        else{
            int a=busca(mensagem[i]);
            if(a==-1){
                char idk=mensagem[i];
                key.push_back(idk);
                freq.push_back(1);
            }
            else{
                freq[a]++;
            }
        }
    }
    /*  Verificar o print do meu vector de key
    for(int i=0;i<key.size();i++){
        cout << "chave: "<< key[i] << " " << "freq: " << freq[i] << "\n";  
    } */
    //Criar meus nos/folhas:
    //Criar meu heap:
    vector <no*> folhas;
    priority_queue<no*,vector<no*>,cmp> heap;
    for(int i=0;i<key.size();i++){
        no* no_tmp=new no(freq[i],key[i],"",key[i]);
        folhas.push_back(no_tmp);
        heap.push(no_tmp);
    }
    //testar o print do heap:
   /* cout <<"\n";
   for(int i=0;i<16;i++){
    cout << "chave: " << heap.top()->key << " freq: " << heap.top()->freq << "\n";
    heap.pop();
   }*/
    //Finalmente:
    //Montar minha arvore de huff
    HuffmanTree t;
    t.setTree(heap);
    no* aux=t.raiz;
    string s= "";
    //Codificar cada folha
    t.dfs(aux,s);
    //Passar todos os codigos para minha string codificada 's'
    t.codifica(s,mensagem);
    //Pre ordem e ordem Simetrica para recuperar a arvore:
    t.pre(aux);
    t.sim(aux);
    //Gerar meu arquivo de saida:
    ofstream file;
    file.open( "output.txt" , ios::out );
    if (!file.is_open()){
        return 0;
    }
    file << s << ".";
    for(int i=0;i<preT.size();i++){
        file << preT[i] <<" ";
    }
    file << 0 <<" ";
    for(int i=0;i<simT.size();i++){
        file << simT[i] << " ";
    }
    file.close(); 
}