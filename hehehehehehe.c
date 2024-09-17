#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10001

int main() {
	int arr1[N], arr2[N], arr3[N+N];
    char c;
    int i, v, a = 0, b = 0, tmp, k, d, e;
    while (1){
        scanf ("%c", c);
        if (c == '#' ) break;
        scanf(" %d %d\n", &i, &v);
        if (c == 'I') {
        	if(i == 1){
        		if (a==0){ 
				arr1[0] = v;
        		a++;
				} else{
        		for (k = a; k > 0; k--){
        			arr1[k] = arr1[k-1];
				}
				arr1[0] = v;
        		a++;
			}
			}
			if(i == 2){
				if (b==0){ 
				arr2[0] = v;
        		b++;
				} else{
        		for (k = b; k > 0; k--){
        			arr2[k] = arr2[k-1];
				}
				arr2[0] = v;
        		b++;
			}
			}
		}
		if (c == 'A'){
			if (i == 1){
				arr1[a] = v;
				a++;
			}
			if (i == 2){
				arr2[b] = v;
				b++;
			}
		}
        
    }
    int h = 0;
    k = 0;
    d = a + b - 1;
    for (e = 1; e <= d; e++){
    	if(e%2 == 1 && h!= a){
    		printf("%d ", arr1[h]);
    		h++;
		}
		if(e%2 == 0 && h!= b){
			printf("%d ", arr2[k]);
			k++;
		}
	}
    
    return 0;
}
