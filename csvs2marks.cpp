#include<bits/stdc++.h>
using namespace std;

vector<string> pool;

int check(string &now){
	for(int i=0;i<pool.size();++i){
		if(now.find(pool[i])!=string::npos){
			return i;
		}
	}
	return -1;
}

struct info{
	int name,solved,rank,teamrank;
	long double score;
	info(int name,int solved,int rank,int teamrank=0,long double score=0){
		this->name=name;
		this->solved=solved;
		this->rank=rank;
		this->teamrank=teamrank;
		this->score=score;
	}
	bool operator < (info kkk) const {
		return rank<kkk.rank;
	}
};
vector<info> teams;

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

void SpawnStep(){
	string tmp;
	int MaxSolved=0;

	while(getline(cin,tmp)){
		int ret=check(tmp);
		if(ret==-1) continue;

		int cnt=0,solved=0,rank=0;
		for(int i=0;i<tmp.size();++i){
			if(tmp[i]==','){
				cnt++;
			}
			if(cnt==0){ // label_1: rank
				while(isdigit(tmp[i])){
					rank=rank*10+tmp[i]-'0';
					if(isdigit(tmp[i+1])){
						++i;
					}
					else break;
				}
			}
			if(cnt==2){ // label_3:
				while(isdigit(tmp[i])){
					solved=solved*10+tmp[i]-'0';
					if(isdigit(tmp[i+1])){
						++i;
					}
					else break;
				}
			}
			
		}

		MaxSolved=max(MaxSolved,solved);
		teams.push_back(info(ret,solved,rank));
	}

	sort(teams.begin(),teams.end());

	cout<<"Name,Rank,Solved,Score,LockedMark,"<<MaxSolved<<endl;

	int teamrank=0;
	for(auto o:teams){
		o.teamrank=++teamrank;
		cout<<pool[o.name]<<","<<o.teamrank<<","<<o.solved<<",";
		cout<<"=200*("<<teams.size()<<"-B"<<o.teamrank+1<<"+1)/"<<teams.size()<<"*C"<<o.teamrank+1<<"/F1"<<",";
		o.score=200.0l*(teams.size()-o.teamrank+1)/teams.size()*o.solved/MaxSolved;
		cout<<fixed<<setprecision(10)<<o.score<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	ReadPool();
	SpawnStep();
	return 0;
}