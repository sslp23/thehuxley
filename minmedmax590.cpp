#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void bubble_upMax(vector<int>& tad){
	int i;
	i=(tad.size()-1);
	while(i>0 && tad[i]>=tad[floor((i-1)/2)]){
		int aux = tad[i];
		tad[i] = tad[floor((i-1)/2)];
		tad[floor((i-1)/2)] = aux;
		i = floor((i-1)/2);
	}
}

void bubble_upMin(vector<int>& tad){
	int i;
	i=(tad.size()-1);
	while(i>0 && tad[i]<=tad[floor((i-1)/2)]){
		int aux = tad[i];
		tad[i] = tad[floor((i-1)/2)];
		tad[floor((i-1)/2)] = aux;
		i = floor((i-1)/2);
	}
}

void heapInsertMax(vector<int>& tad, int v){
	tad.push_back(v);			
	bubble_upMax(tad);
}

void heapInsertMin(vector<int>& tad, int v){
	tad.push_back(v);
	bubble_upMin(tad);
}

void heapifyMin(vector<int>& tad, int i){
	int m, l , r;
	m = i;
	l = (2*i+1);
	r = (2*i+2);
	if(l<tad.size() && tad[l]<=tad[m]){
		m = l;
	}
	if(r<tad.size() && tad[r]<=tad[m]){
		m = r;
	}
	if(m!=i){
		int aux = tad[i];
		tad[i] = tad[m];
		tad[m] = aux;
		heapifyMin(tad, m);
	}
}

int heapExtractMin(vector<int>& tad){
	int aux, r;
	r = tad[0];
	aux = tad[0];
	tad[0] = tad[tad.size()-1];
	tad[tad.size()-1] = aux;
	tad.resize(tad.size()-1);
	if(tad.size()>0){
		heapifyMin(tad, 0);
	}
	return r;
}

void heapifyMax(vector<int>& tad, int i){
	int m, l , r;
	m = i;
	l = (2*i+1);
	r = (2*i+2);
	if(l<tad.size() && tad[l]>=tad[m]){
		m = l;
	}
	if(r<tad.size() && tad[r]>=tad[m]){
		m = r;
	}
	if(m!=i){
		int aux = tad[i];
		tad[i] = tad[m];
		tad[m] = aux;
		heapifyMax(tad, m);
	}
}

int heapExtractMax(vector<int>& tad){
	int aux, r;
	r = tad[0];
	aux = tad[0];
	tad[0] = tad[tad.size()-1];
	tad[tad.size()-1] = aux;
	tad.resize(tad.size()-1);
	if(tad.size()>0){
		heapifyMax(tad, 0);
	}
	return r;
}

int main(){
	string valor;
	vector<int> max, min;
	int v, menor=-1, maior=-1, med;
	while(cin>>valor){
		if(valor=="ADD"){
			cin >> v;
			if(v>maior || maior==-1)
				maior=v;
			if(v<menor || menor==-1)
				menor=v;
			if(min.empty()){
				heapInsertMin(min, v);
			}
			else if(v>min[0]){
				heapInsertMin(min, v);
			}
			else{
				heapInsertMax(max, v);
			}
			if(max.size()+min.size()%2==0){
				if(max.size()>min.size())
					heapInsertMin(min, heapExtractMax(max));	
				else
					heapInsertMax(max, heapExtractMin(min));	
			}
			else{
				if(max.size()>min.size()){
					heapInsertMin(min, heapExtractMax(max));
				}
				else if(min.size()>max.size()+1){
					heapInsertMax(max, heapExtractMin(min));
				}
			}
			cout << menor << ' ';
			cout << min[0] << ' ';			
			cout << maior << endl;
		}
		if(valor=="MAX"){
			cout << maior << endl;
		}
		if(valor=="MIN"){
			cout << menor << endl;
		}
		if(valor=="MED"){
			if(min.empty())
				cout << -1 << endl;
			else
				cout << min[0] << endl;
		}
		if(valor=="RES"){
			menor =-1;
			maior =-1;
			cout << max.size()+min.size() << endl;
			max.clear();
			min.clear();
		}
	}
	return 0;
}
