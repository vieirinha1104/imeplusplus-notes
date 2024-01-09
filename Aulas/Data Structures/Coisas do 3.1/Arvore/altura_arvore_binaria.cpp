 #include <iostream>
 #include <map>
 using namespace std;
char preT[]={'C','B','A','E','D','F'};
char simT[]={'A','B','C','D','E','F'};
map<char,int> m;
class no{
    public:
    char key;
    no* esq;
    no* dir;
    no(char chave):key(chave){
        esq=NULL;
        dir=NULL;
    }
    no():key('\0'){
        esq=NULL;
        dir=NULL;
    }
};

class tree{
    public:
    no* raiz;
    tree(){
        raiz=NULL;
    }
    void setTree(no* &root,int iP,int fP,int iS,int fS){
        no* tmp = new no(preT[iP]);
        root=tmp; 
        int i=iS;
        while(i<=fS && simT[i]!=preT[iP]){
            i++;
        }
        if(i!=iS){
            setTree(root->esq,iP+1,iP+i-iS,iS,i-1);
        }
        if(i!=fS){
            setTree(root->dir,iP+i-iS+1,fP,i+1,fS);
        }
    }
    //Calcula a altura de cada no, veja que eu fiz o percurso em pos ordem, e na hora de fazer a visita, 
    //usei meu algoritmo para calcular a altura
    void pos(no* root){
        if(root!=NULL){
            pos(root->esq);
            pos(root->dir);   
           if(root->esq==NULL && root->dir==NULL){
                m.insert({root->key,1});
           }
           else{
                if(root->dir==NULL){
                    m[root->key]=m[(root->esq)->key]+1;
                }
                else if(root->esq==NULL){
                    m[root->key]=m[(root->dir)->key]+1;
                }
                else{
                    if(m[(root->esq)->key]>m[(root->dir)->key]){
                        m[(root)->key]=m[(root->esq)->key]+1;
                    }
                    else if(m[(root->esq)->key]<m[(root->dir)->key]){
                        m[(root)->key]=m[(root->dir)->key]+1;
                    }
                    else{
                        m[(root)->key]=m[(root->dir)->key]+1;
                    }
                }
           }
        }
    }
};

//Esse seria o recurso em pos ordem da arvore
void pos(no* root){
    if(root!=NULL){
        pos(root->esq);
        pos(root->dir);
        cout << root->key << ": "<<m[root->key]<<" ";
    }
} 


int main(){
    tree arvore;
    arvore.setTree(arvore.raiz,0,5,0,5);
    arvore.pos(arvore.raiz);
    cout << m[(arvore.raiz)->key] << "\n";
    pos(arvore.raiz);
    
}
