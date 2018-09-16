#include <bits/stdc++.h>

using namespace std;

void showGrafo(vector<vector<int> >& grafo, int tam){
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			cout << grafo[i][j] << ' ';
		}
		cout << endl;
	}
}

void find(vector<vector<int> >& g, int m, int n, int t, int& cont, int& win, int flag){
	int vizinho=0;
	cont++;
	g[m][n]=0;
	if(flag==1){
		if(n==t-1){
			win=1;
		}
	}
	else{
		if(m==t-1){
			win=1;
		}
	}
	if(m!=0){
		if(g[m-1][n]){//cima
			vizinho=1;
			find(g, m-1, n, t, cont, win, flag);
		}
	}
	if(n!=t-1){	
		if(g[m][n+1]){//dir
			vizinho=1;
			find(g, m, n+1, t, cont, win, flag);
		}
	}
	if(n!=0){
		if(g[m][n-1]){//esq
			vizinho=1;
			find(g, m, n-1, t, cont, win, flag);
		}
	}
	if(m!=t-1){
		if(g[m+1][n]){//baixo
			vizinho=1;
			find(g, m+1, n, t, cont, win, flag);
		}
	}
	if(m!=t-1 && n!=0){
		if(g[m+1][n-1]){//diag.baixo
			vizinho=1;
			find(g, m+1, n-1, t, cont, win, flag);
		}
	}
	if(m!=0 && n!=t-1){
		if(g[m-1][n+1]){//diag.cima
			vizinho=1;
			find(g, m-1, n+1, t, cont, win, flag);
		}
	}
}

void checkB(vector<vector<int> > g, int n, int& cont, int& win, int& val){
	for(int i=0; i<n; i++){
		if(g[i][0]){
			find(g, i, 0, n, cont, win, 1);
			if(win){
				//cout << cont << endl;
				val=cont;
				cont=0;
				break;
			}
			else
				cont=0;
		}
	}
}

void checkW(vector<vector<int> > g, int n, int& cont, int& win, int& val){
	for(int i=0; i<n; i++){
		if(g[0][i]){
			find(g, 0, i, n, cont, win, 0);
			if(win){
				//cout << cont << endl;
				val=cont;
				cont=0;
				break;
			}
			else
				cont=0;
		}
	}
}

int convert(string s){
	int r;
	if(s.length()==1){
		r = s.at(0) - 48;
	}
	else if(s.length()==2){
		r = (s.at(0)-48)*10+(s.at(1)-48);
	}
	else if(s.length()==3){
		r = ((s.at(0)-48)*100)+((s.at(1)-48)*10)+(s.at(2)-48);
	}
	return r;
}

int main(){
	int n, v, a, count=0, cont=0, win=0, bw=0, ww=0, val, caso=0, x=0;
	char c;
	string lb, vs, as;
	vector<vector<int> > black, white, p;
	while(cin>>n){
		cin >> c;
		for(int i=0; i<n; i++){
			vector<int> row;
			row.resize(n, 0);
			black.push_back(row);
		}
		for(int i=0; i<n; i++){
			vector<int> row;
			row.resize(n, 0);
			white.push_back(row);
		}
		for(int i=0; i<n; i++){
			vector<int> row;
			row.resize(n, 0);
			p.push_back(row);
		}
		cin.ignore();
		getline(cin, lb);
		while(!lb.empty()){
			while(lb.at(x)!=' '){
				vs+=lb.at(x);
				x++;
			}
			x++;
			while(x<lb.length()){
				as+=lb.at(x);
				x++;
			}
			x=0;
			v = convert(vs);
			a = convert(as);
			if(c=='B'){
				if(count%2==0){
					if(a<n && v<n)
						black[v][a] = 1;
				}
				else{
					if(a<n && v<n)
						white[v][a] = 1;
				}
			}
			else if(c=='W'){
				if(count%2!=0){
					if(a<n && v<n)
						black[v][a] = 1;
				}
				else{
					if(a<n && v<n)
						white[v][a] = 1;	
				}
			}
			else
				cout << "ERRO";
			count++;
			lb.clear();
			as.clear();
			vs.clear();
			getline(cin, lb);
		}
		/*showGrafo(black, n);
		cout << endl;
		showGrafo(white, n);*/
		checkB(black, black[0].size(), cont, win, val);
		if(win){
			cout << "caso " << caso << ": B " << val << endl << endl;
			win=0;
		}
		else{
			checkW(white, white[0].size(), cont, win, val);
			cout << "caso " << caso << ": W " << val << endl << endl;
			win=0;	
		}
		//showGrafo(black, n);
		black.clear();
		white.clear();
		lb.clear();
		n=0;
		count = 0;
		caso++;
	}
}
