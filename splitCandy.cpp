//C++ 
#include <bits/stdc++.h>

void inItI(){
	
}

int count, n, M, f;
void solution(){
    if (f==M) {
        count ++;
    }
}

void TRY(int k){
    int v;
    for(v = 1; v <= (M-f-(t[n]-t[k]))/a[k]; v++){
        X[k]=v;
        f+=a[k]*X[k];
        if(k==n){
            solution();
        } else{
            TRY(k+1);
        }
        f-= a[k]*X[k];
    }
}



int main() 
{ 

}
