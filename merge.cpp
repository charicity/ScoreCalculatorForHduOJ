#include<bits/stdc++.h>
using namespace std;

vector<string> pool;

void ReadPool(){
	ifstream fin("pool.txt");  
	if(!fin.is_open()){
		cout<<"ERROR: pool.txt is not existed!"<<endl;
		exit(0);
	}
	string tmp;
	while(getline(fin,tmp)){
		if(tmp.empty()) continue;
		pool.push_back(tmp);
	}
}

long double read(string &s,int pos){
	int cnt=0,flag=0;
	long double num=0;
	while(pos<s.size()){
		if(num-1e15>1e-8) break;
		if(!isdigit(s[pos])){
			if(s[pos]=='.'){
				if(flag) break;
				flag=1;
				pos++;
				continue;
			}
			else break;
		}
		num=num*10+s[pos]-'0';
		cnt+=flag;
		++pos;
	}
	while(cnt){
		cnt--;
		num/=10;
	}
	return num;
}

void CreateMerge(){
	ifstream tester("MERGE.csv");
	if(!tester.fail()){
		tester.close();
		return;
	}

	ofstream fout("MERGE.csv");
	fout<<"TeamName"<<endl;
	for(auto o:pool){
		fout<<o<<endl;
	}
	fout.close();
}

map<string,string> table;
string header;

void ReadCurrent(){
	ifstream fin("MERGE.csv");
	string tmp,name;
	long double score;

	getline(fin,header);

	while(getline(fin,tmp)){
		name="";
		int i;
		for(i=0;i<tmp.size();++i){
			if(tmp[i]==',') break;
			name+=tmp[i];
		}
		
		table[name]=tmp;
	}
}

void UpdateFinal(){
	string tmp,name,res;
	int cnt=0;

	getline(cin,tmp);

	while(getline(cin,tmp)){
		name="";res="";

		int i=0;
		cnt=0;
		while(tmp[i]!=','){
			name+=tmp[i];
			++i;
		}
		while(i<tmp.size()){
			if(tmp[i]==',') ++cnt;
			if(cnt==4) res+=tmp[i];
			++i;
		}

		table[name]+=res;
	}
}

void WriteFinal(){
	ofstream fout("MERGE.csv");
	fout<<header<<",Match"<<endl;
	for(auto o:table){
		fout<<o.second<<endl;
	}
	fout.close();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	ReadPool();
	CreateMerge();
	ReadCurrent();
	UpdateFinal();
	WriteFinal();

	return 0;
}