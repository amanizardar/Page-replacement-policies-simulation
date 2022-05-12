#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("pagefaultdata_NRU.txt","w",stdout);
	ifstream fin;
	fin.open("input.txt");

	int n,m;
	// cin>>n;//no. of frames
	// cin>>m;// no. of pages

	string str;

	while(getline(fin,str))
	{
		if(str.size()==0)
		{
			break;
		}

		stringstream ss(str);
		string word;

		ss>>word;
		n = atoi(&word[0]);

		vector<int> v;
		int p;

		while(1)
		{
			ss>>word;
			if(word==",")break;
			int x = atoi(&word[0]);
			v.push_back(x);
		}

		p=v.size();

		vector<int> pf;

		while(ss>>word)
		{
			if(word=="\n")break;
			int x = atoi(&word[0]);
			pf.push_back(x);
		}

		m = v.size();
		set< pair<pair<int,int>,int> > s;
		// pair< <refered,modified> , page number >
		
		// n -> no. of frames
		// m -> no. of pages
	
		vector<int> pages(m),modi(m);
		pages = v;
		modi = pf;
		// for(int i=0;i<m;i++)
		// {
		// 	cin>>pages[i];
		// }
	
		// for(int i=0;i<m;i++)
		// {
		// 	cin>>modi[i];
		// }
	
		int page_fault = 0;
	
	
		for(int i=0;i<m;i++)
		{
			// cout<<pages[i]<<" "<<modi[i]<<endl;
	
			if(i%4==0)
			{
				set< pair<pair<int,int>,int> > ss;
				for( auto x : s)
				{
					x.first.first = 0;
					ss.insert(x);
				}
	
				s.clear();
	
				for(auto x : ss)
				{
					s.insert(x);
				}
			}
	
			bool found = false;
	
			for( auto x : s )
			{
				if(x.second==pages[i])
				{
					found = true;
					if(modi[i]==1)
					{
						s.erase(s.find(x));
						x.first.second = 1;
						s.insert(x);
					}
					
					s.erase(s.find(x));
					x.first.first = 1;
					s.insert(x);
				}
			}
	
			
			// if(found)
			// {
			// 	for( auto x : s )
			// 	{
			// 		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
			// 	}
			// 	cout<<"######################################"<<endl;
			// }
			if(found) continue;
	
	
			page_fault++;
	
	
			if(s.size()==n)
			{
				s.erase(s.begin());
			}
			s.insert({{1,modi[i]},pages[i]});
	
	
			// if(1)
			// {
			// 	for( auto x : s )
			// 	{
			// 		cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<endl;
			// 	}
			// 	cout<<"######################################"<<endl;
			// }
	
			
		}
	
		cout<<n<<" "<<m<<" "<<page_fault<<endl;
	}



}