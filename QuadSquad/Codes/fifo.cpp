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
				pf++;
				
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



void space_separated_words(string input, vector<int> &token,vector<int> &dirty)
{

    string word = "";
    bool isdirtystarted=false;

    for (auto x : input)
    {
        if (x == ' ')
        {
            if(word.size()==0)
            {
                continue;
            }
            

            if(!isdirtystarted)
            token.push_back(stoi(word));

            else
            dirty.push_back(stoi(word));
            // cout << word << endl;
            word = "";
        }
        else if(x==',')
        {
            isdirtystarted=true;
        }
        else
        {
            word = word + x;
        }
    }
    cout << word << endl;
    dirty.push_back(stoi(word));
}


int main(){
	
	int i,n,num,frames=0,page_hit,page_fault;
	string reference;
	float hit_r,miss_r;
	vector<int> cont;
	
	ifstream ifile;
	ifile.open("input.txt");
	
	ofstream ofile;
	ofile.open("pagefaultdata_fifo.txt");
	
	string st;
	while(getline(ifile,st)){
		
		vector<int>dirty;
		space_separated_words(st,cont,dirty);
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
		
		ofile << frames<<" "<<n<<" "<<page_fault<< endl;
		
		cont.clear();
		
	}
	
	ifile.close();
	
}
