int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1, max_platforms = 1;
    int i = 1, j = 0;

    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            platforms++;  // New train arrives before last one departs
            i++;
        } else {
            platforms--;  // A train departs
            j++;
        }
        max_platforms = max(max_platforms, platforms);
    }

    return max_platforms;
}
