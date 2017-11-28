void print(vector<int> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"  ";
	cout<<endl;
}

void print(vector<long long> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"  ";
	cout<<endl;
}

int binarySearch(vector<int> v, int x, int l=-1, int r=-1){ 
	if(r==-1 && l==-1){
		l=0;
		r=v.size()-1;
	}

	if(r>=l){
		int mid=l+(r-l)/2;
		
		if(v[mid]==x)
			return mid;
		
		if(v[mid]>x) 
			return binarySearch(v,x,l,mid-1);

		return binarySearch(v,x,mid+1,r);
	}
 
	return -1;
}

bool find(vector<int> v, int x, int l=-1, int r=-1){ 
	if(r==-1 && l==-1){
		l=0;
		r=v.size()-1;
	}

	if(r>=l){
		int mid=l+(r-l)/2;
		
		if(v[mid]==x)
			return true;
		
		if(v[mid]>x) 
			return binarySearch(v,x,l,mid-1);

		return binarySearch(v,x,mid+1,r);
	}
 
	return false;
}

