#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	bool ref;
	int page;
	node* next;

	node(int x)
	{
		ref = false;
		page = x;
		next = NULL;
	}

	node()
	{
		ref=false;
	}
};

int main()
{
	freopen("pagefaultdata_FIFOwithSecondChance.txt","w",stdout);
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

		stringstream s(str);
		string word;

		s>>word;
		n = atoi(&word[0]);
	
		vector<int> v;
		int p;

		while(1)
		{
			s>>word;
			if(word==",")break;
			int x = atoi(&word[0]);
			v.push_back(x);
		}

		p = v.size();

		vector<int> pf;

		while(s>>word)
		{
			if(word=="\n")break;
			int x = atoi(&word[0]);
			pf.push_back(x);
		}


		m = v.size();
	
		// cin>>v[0];
	
		node* temp = new node(v[0]);
	
		node* head = temp;
		node* tail = temp;
	
		int frames_filled = 1;
		int page_faults = 1;
	
		int i;
		for(i=1;i<m;i++)
		{
			
			//// looking if page already present
			node* temp = head;
			bool found = false;
			while(temp)
			{
				if(temp->page == v[i])
				{
					found = true;
					temp->ref = true;
					break;
				}
				temp = temp->next;
			}
	
			// if(found) cout<<" Hurrreeee"<<endl;
			if(found) continue;
			
			page_faults++;
			// cout<<" page_faults"<<endl;
	
			// if page not found
	
			if( frames_filled < n )
			{
				node* new_node = new node(v[i]);
				tail->next = new_node;
				tail = tail->next;
				frames_filled++;
				
			}
			else
			{
	
				while(head->ref)
				{
					head->ref = false;
					tail->next = head;
					tail = head;
					head = head->next;
					tail->next = NULL;
				}
	
				node* new_node = new node(v[i]);
				tail->next = new_node;
				tail = tail->next; 
	
				node* head1 = head;
	
				head = head->next;
	
				delete head1;
	
			}
	
	
		}
	
		float a,b,c;
		b=page_faults;
		c=m;
		a=b/c;
		// cout<<n<<" "<<a<<endl;;
		cout<<n<<" "<<m<<" "<<page_faults<<endl;
	}
	return 1;
}