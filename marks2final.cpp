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

void CreateFinal(){
	ifstream tester("final.csv");
	if(!tester.fail()){
		tester.close();
		return;
	}

	ofstream fout("final.csv");
	fout<<"TeamName,Score"<<endl;
	for(auto o:pool){
		fout<<o<<","<<0<<endl;
	}
	fout.close();
}

map<string,long double> mapp;

void ReadCurrent(){
	ifstream fin("final.csv");
	string tmp,name;
	long double score;

	getline(fin,tmp); // wasted

	while(getline(fin,tmp)){
		name="";
		int i;
		for(i=0;i<tmp.size();++i){
			if(tmp[i]==',') break;
			name+=tmp[i];
		}

		++i;
		score=read(tmp,i);

		mapp[name]=score;
	}
}

void UpdateFinal(){
	string tmp,name;
	long double score;
	int cnt=0;

	getline(cin,tmp);

	while(getline(cin,tmp)){
		name="";
		score=0;

		int i=0;
		cnt=0;
		while(tmp[i]!=','){
			name+=tmp[i];
			++i;
		}

		while(cnt<4){
			if(tmp[i]==',') ++cnt;
			++i;
		}

		score=read(tmp,i);
		
		mapp[name]+=score;
	}
}

void WriteFinal(){
	ofstream fout("final.csv");
	fout<<"TeamName,Score"<<endl;
	for(auto o:mapp){
		fout<<o.first<<","<<setprecision(10)<<o.second<<endl;
	}
	fout.close();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	ReadPool();
	CreateFinal();
	ReadCurrent();
	UpdateFinal();
	WriteFinal();

	return 0;
}