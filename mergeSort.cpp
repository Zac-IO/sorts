#include <iostream>
#include <vector>




void Merge(std::vector<int>& array, int l, int m, int r){
    std::vector<int> left;
    std::vector<int> right;
    for(int i = l; i <= m; i++){
        left.push_back(array[i]);
    }
    for(int i = m + 1; i <= r; i++){
        right.push_back(array[i]);
    }
    int iLeft = 0;
    int iRight = 0;
    int index = l;
    while(iLeft < left.size() && iRight < right.size()){
        if (left[iLeft] < right[iRight]){
            array[index] = left[iLeft];
            iLeft++;
        } else{
            array[index] = right[iRight];
            iRight++;
        }       \
        index++;        //Keep track of array index
    }
    if(left.empty()){
        for (auto& x : right){
            array[index] = x;
            index++;
        }
    }
    else{
        for(auto& x: left){
            array[index] = x;
            index++;
        }
    }
}

void MergeSort(std::vector<int>& array, int l, int r){
    if (l < r){
        int middle = (l+r) / 2;
        MergeSort(array, l, middle);
        MergeSort(array,middle + 1, r);
        Merge(array,l,middle,r);
    }
}


int main(){
    std::vector<int> toSort{5,4,3,2,1};
    MergeSort(toSort, 0, toSort.size() - 1);
    for (auto& x: toSort){
        std::cout << x << std::endl;
    }


    return 0;
}
