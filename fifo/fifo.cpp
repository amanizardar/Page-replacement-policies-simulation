#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int fifo_pf(vector<int>ref, int n, int frames){
	
	int i,pf=0;
	queue<int> q;
	unordered_set<int>s;
	
	for(i=0;i<n;i++){
		if(q.size()<frames){
			
			if(s.find(ref[i]) == s.end()){
				//not found
				pf+=1;
				
				s.insert(ref[i]);
				q.push(ref[i]);
			}	
		} else{
			
			if(s.find(ref[i])==s.end()){
				//not present
				
				s.erase(q.front());
				q.pop();
				
				pf+=1;
				
				s.insert(ref[i]);
				q.push(ref[i]);
			}
		}	
	}
	
	
	
	
	return pf;
}


void space_seperated_words(string input, vector<int> &token)
{

    string word = "";
    for (auto x : input)
    {
        if (x == ' ')
        {
            token.push_back(stoi(word));
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    token.push_back(stoi(word));
}

int main(){
	
	int i,n,num,frames=0,page_hit,page_fault;
	string reference;
	float hit_r,miss_r;
	vector<int> cont;
	
	//cout<<"Enter reference string length";
	//cin>>n;
	//cout<<endl<<"Enter string:";
	
	ifstream ifile;
	ifile.open("input.txt");
	
	ofstream ofile;
	ofile.open("fifo_output.txt");
	
	string st;
	while(getline(ifile,st)){
		
		space_seperated_words(st,cont);
		frames=cont[0];
		
		vector<int>ref(cont.begin()+1,cont.end());
		n=ref.size();
		
		page_fault=fifo_pf(ref,n,frames);
		page_hit=n-page_fault;
		
		miss_r=(float)(page_fault/(n*1.0));
		hit_r=1-miss_r;
		
		
		cout<<endl<<"Number of page faults:"<<page_fault;
		cout<<endl<<"Number of page hits:"<<page_hit;
		
		cout<<endl<<"Hit ratio:"<<hit_r;
		cout<<endl<<"Miss ratio:"<<miss_r;
		cout<<endl;
		
		ofile<<frames<<" "<<miss_r<<endl;
		
		cont.clear();
		
	}
	
	ifile.close();
	
}
