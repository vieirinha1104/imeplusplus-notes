#include <stdio.h>

void merge(int *v,int p,int q,int r){
  int aux[r-p+1];
  int left_v[q-p+1];
  int right_v[r-q];
  for(int i=p;i<q+1;i++){
    left_v[i-p]=v[i];
  }
   for(int j=q+1;j<r+1;j++){
    right_v[j-q-1]=v[j];
  }
  int a=0;
  int b=0;
  for(int k=0;k<(r-p+1);k++){
    if(left_v[a]<right_v[b]){
        aux[k]=left_v[a];
        a++;
    }
    else{
        aux[k]=right_v[b];
        b++;
    }
  }
  for(int i=p;i<r+1;i++){
        v[i]=aux[i-p];
 }
}
void sort(int *v, int p, int q){
    int aux;
    if(v[p]>v[q]){
        aux=v[p];
        v[p]=v[q];
        v[q]=aux;
    }
    else{
        return;
    }
}
void merge_sort(int *v,int inicio,int fim){
    
    int mid=((inicio+fim+1)/2);

    if(inicio==fim){
        return;
    }
    else if(fim-inicio==1){
         sort(v,inicio,fim);
        
    }
    else if(fim-inicio==2){
        sort(v,inicio+1,fim);
        merge(v,inicio,inicio,fim);
    }
    else{
        merge_sort(v,inicio,mid-1);
        merge_sort(v,mid,fim);
        merge(v,inicio,mid-1,fim);
        

    }
}
    int main(){
        int vector[10]={10,5,3,4,7,9,2,8,1,6};




}
        merge_sort(vector,0,9);
        for(int i=0;i<10;i++){
            printf("%d ",vector[i]);
        }
        }
    
