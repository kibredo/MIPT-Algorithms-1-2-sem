#include <bits/stdc++.h> 
using namespace std;

int minVal(int x, int y) { return (x < y)? x: y; }
int getMid(int s, int e) { return s + (e - s)/2; }
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && qe >= se) {
        return st[index];
    }
    if (se < qs || ss > qe) {
        return INT_MAX;
    }
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}
int RMQ(int *st, int n, int qs, int qe) {
    if (qs < 0 || qe > n-1 || qs > qe) {  
        cout<<"Invalid Input";  
        return -1;  
    }   
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if (ss == se) {  
        st[si] = arr[ss];  
        return arr[ss];  
    }
    int mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}
int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);  
    return st;  
} 
int main() {
    int size = 0;
    int the_x = 0;
    int the_y = 0;
    int the_k = 0;
    int the_l = 0;
    std::cin >> size;
    int arr[size];
    for (int tmp = 0; tmp < size; ++tmp) {
        std::cin >> arr[tmp];
    }
    int n = sizeof(arr)/sizeof(arr[0]); 
    int *st = constructST(arr, n);  
    int qs = 1;
    int qe = 5; 
    std::cin >> qs >> qe;
    --qs;
    --qe;
    cout<<"Minimum of values in range ["<<qs + 1<<", "<<qe + 1<<"] "<< 
    "is = "<<RMQ(st, n, qs, qe)<<endl;

    return 0;  
}
