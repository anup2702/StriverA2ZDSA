pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int f = -1, c = -1;
	int l = 0, h = n - 1;
	while(l <= h){
		int m = (l + h)/2;
		if(a[m] == x){
			f = a[m];
			c = a[m];
			break;
		} else if(a[m] < x){
			f = a[m];
			l = m + 1;
		} else{
			c = a[m];
			h = m - 1;
		}
	}
	return {f, c};
}

// __ <= x floor
// __ >= x ceil