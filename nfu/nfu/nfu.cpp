#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

/*
void printt(){
	
		cout<<"REF BIT - FREQ"<<endl;
		for(auto it=freq.begin();it!=freq.end();it++){
			cout<<it->first<<" : "<<it->second<<endl;
		}
		
		cout<<"COUNT in each freq"<<endl;
		for(auto it=count.begin(); it!=count.end(); it++){
			cout<<it->first<<" : ";
			vector<int>v=it->second;
			
			for(auto j=0; j<v.size();j++){
				cout<<v[j]<<" ";	
			}
			cout<<endl;
		}
		cout<<endl;
}

*/

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


int nfu(vector<int>ref, int frames){
	map<int,int>freq;
	map<int,vector<int> >count;
	
	queue<int>q;
	unordered_set<int> s;
	int pf=0,i;
	
	for(i=0;i<ref.size();i++){
		
		if(q.size()<frames){
			
			//not present
			if(s.find(ref[i])==s.end()){
				q.push(ref[i]);
				s.insert(ref[i]);
				pf++;
				freq[ref[i]]=1;
				
				count[freq[ref[i]]].push_back(ref[i]);
			}
			//present
			else{
				freq[ref[i]]++;
				vector<int>r=count[freq[ref[i]]-1];
				r.erase(remove(r.begin(), r.end(),ref[i]), r.end());
				count[freq[ref[i]]-1]=r;
				count[freq[ref[i]]].push_back(ref[i]);
			}
			
		} else{
			
			vector<int> v;
			int item;
			
			//not present
			if(s.find(ref[i])==s.end()){
				//find min freq pgs
				
				for(auto it=count.begin(); it!=count.end(); it++){
					v.clear();
					v=it->second;
					
					if(v.size()>0){
						item=v[0];
						v.erase(v.begin());	
						count[it->first]=v;						
						break;
					}
				}
				
				
				//use queue to remove the least page, and erase from set and q
				//cout<<"item "<<item<<" q "<<q.front()<<endl;
				s.erase(item);
				pf++;
				
				
				//set that page freq to 0
				freq[item]=0;
				
				//set new page freq to 1, add to queue, set
				//q.push(ref[i]);
				s.insert(ref[i]);
				freq[ref[i]]=1;
				
				count[freq[ref[i]]].push_back(ref[i]);
				
			}
			//present
			else{
				
				freq[ref[i]]++;
				vector<int>r=count[freq[ref[i]]-1];
				r.erase(remove(r.begin(), r.end(),ref[i]), r.end());
				count[freq[ref[i]]-1]=r;
				count[freq[ref[i]]].push_back(ref[i]);
				
			}
			
		}
		
		//printt();
		
	}
	
	return pf;
	
}

int main(){
	
	vector<int>ref;
	
	int i,n,num,len,frames=0,page_hit,page_fault;
	string reference;
	float hit_r,miss_r;
	vector<int> cont;
	
	ifstream ifile;
	ifile.open("input.txt");
	
	ofstream ofile;
	ofile.open("nfu_output.txt");
	
	string st;
	while(getline(ifile,st)){
		
		space_seperated_words(st,cont);
		frames=cont[0];
		
		vector<int>ref(cont.begin()+1,cont.end());
		n=ref.size();
		
		page_fault=nfu(ref,frames);

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

