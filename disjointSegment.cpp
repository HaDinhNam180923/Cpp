#include<bits/stdc++.h>
using namespace std;


#define max 1000000
int n;
int arr[max][2];

void swap(int a, int b){
    int temp[2];
    temp[0] = arr[a][0];
    temp[1] = arr[a][1];
    arr[a][0] = arr[b][0];
    arr[a][1] = arr[b][1];
    arr[b][0] = temp[0];
    arr[b][1] = temp[1];
}

//quick sort
//------------------------------------
int partition(int low, int high){
	int left = low;
	int pivot = arr[high][1];
	int right = high - 1;
	
	while(true){
		while(arr[left][1]<pivot && left<=right) left++;
		while(arr[right][1]>pivot && right>=left) right--;
		if(left>=right) break;
		swap(left,right);
		left++;
		right--;
	}
	swap(left,high);
	return left;
}

void quicksort(int low, int high){
	if(low<high){
		int pi = partition(low,high);
		quicksort(low,pi-1);
		quicksort(pi+1,high);
	}
}
///// ------------------------------------

//Sap xep mang theo thu tu tang dan cua diem ket thuc
// void sort_arr(){
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i][1] > arr[j][1]){
//                 swap(i, j);
//             }
//         }
//     }
// }

int disjoint_segment(){
    int last=-1;
    int Count = 0;
    int i=0;
    while(i<n){
        if(arr[i][0] > last){
            Count++;
            last = arr[i][1];
        }
        i++;
    }
    return Count;
}

// bool cmp(int a, int b){
//     return arr[a][1] < arr[b][1];
// }

int main(){
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    quicksort(0,n-1);

    //sort_arr();
    // sort(arr[0][1],arr[n-1][1],cmp);

    // for(int i=0; i<n; i++){
        
    //     printf("%d %d \n",arr[i][0],arr[i][1]);
    // }
        
    
    int result = disjoint_segment();

    printf("%d",result);
    return 0;
}
