bool check(int val);

int Binary_search(int max_v, int min_v){
    while(max_v >= min_v){
        int mid = (max_v + min_v) / 2;
        if(check(mid)){
            min_v = mid + 1;
        }else{
            max_v = mid - 1;
        }
    }
    // choose one to return~
    return max_v;
    return min_v;
}
