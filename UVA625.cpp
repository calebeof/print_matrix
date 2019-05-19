#include <bits/stdc++.h>

using namespace std;

//PERMUTATION THAT HAVE MOST NUMBERS AND THE MAXIMUM SUM

int k, n, better;
vector<int> sol;


int getSum(vector<int> s){
	int r = 0;
	for(int i=0; i<s.size(); i++) r+=s[i];
	return r;
}

void permut (vector<int> vetor, vector<int> newOne, int left){
	int s = getSum(newOne);
	
	if(s<=k){
		if(s>better){
			better = s;
			sol = newOne;
		}
		else if(s==better and sol.size()<newOne.size()){
			sol = newOne;
			better = s;
		}
	}else return;
	
	for(int i=left; i<vetor.size(); i++){
		newOne.push_back(vetor[i]);
		permut(vetor, newOne, i+1);
		newOne.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	while(cin >> k){
		cin >> n;
		better = 0;
		vector<int> vetor(n);
		sol.clear();
		
		for(int i=0; i<n; i++) cin >> vetor[i];
		vector<int> nada;
		for(int i=0; i<n; i++)
			permut(vetor, nada, i);
		
		for(int i=0; i<sol.size(); i++) cout << sol[i] << " ";
		cout << "sum:" << better << endl;
	}
	return 0;
}
