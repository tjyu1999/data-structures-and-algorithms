# include <iostream>

# define MAX_LENGTH 100

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    i++;
    swap(&arr[i], &arr[high]);
    
    return i;
}

void quicksort(int *arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main(){
    char c;
    int val;
    int length = 0;
    int arr[MAX_LENGTH];
    
    while(cin.get(c) && c != '\n'){
        cin.putback(c);
        cin >> val;
        arr[length++] = val;
    }
    
    quicksort(arr, 0, length - 1);
    for(int i = 0; i < length; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
