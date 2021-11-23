
//Author :-> Aman Izardar
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define phi 3.1415926536
#define mod 1000000007
using namespace std;

ofstream fout("pagefaultdata.txt");


//Code Section : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : :

class page
{
public:
    int pageno;
    unsigned int  counter;
    

    page(int pageno)
    {
        pageno=pageno;
        counter=1 << ((sizeof(int)*8)-1);
    }
};


void aging(int totalframes,vector<int>&pages,int &pagefault,int &pagehit)
{
    unordered_set<int>frames;  //contains page that are in MM
    unordered_map<int,page*>map;  //page to page class 

    for(int i=0;i<pages.size();i++)
    {
        if(frames.size()<totalframes)
        {
            if(frames.find(pages[i])==frames.end())  //Page is not Present and space available
            {
                // Decreamenting counter of other page frames
                for(auto p:map)
                {
                    p.second->counter>>=1;
                }
                frames.insert(pages[i]);
                map[pages[i]]=new page(pages[i]);
                pagefault++;
            }
            else   //Page is already present in the MM
            {
                for(auto p:map)
                {
                    if(p.first==pages[i])
                    {
                        p.second->counter>>=1;
                        p.second->counter |=  1 << ((sizeof(int)*8)-1); //Setting msb as 1
                        continue;
                    }
                    p.second->counter>>=1;
                }
                pagehit++;
            }
        }
        else  //No space for new pages in MM
        {
            if(frames.find(pages[i])!=frames.end())  //Page already in MM
            {
                for(auto p:map)
                {
                    if(p.first==pages[i])
                    {
                        p.second->counter>>=1;
                        p.second->counter |=  1 << ((sizeof(int)*8)-1); //Setting msb as 1
                        continue;
                    }
                    p.second->counter>>=1;
                }
                pagehit++;
            }
            else
            {
                //Page Replacement
                int page_to_be_replaced;
                unsigned int mincounter=INT_MAX;
                for(auto p :map)
                {
                    if(p.second->counter<mincounter)
                    {
                        mincounter=p.second->counter;
                        page_to_be_replaced=p.first;
                    }
                }
                frames.erase(page_to_be_replaced);
                frames.insert(pages[i]);
                map.erase(page_to_be_replaced);
                for(auto p:map)
                {
                    p.second->counter>>=1;
                }
                
                map[pages[i]]=new page(pages[i]);

                pagefault++;
                
            }
        }
    }


}


void solve()
{

cout<<"Please Enter No of Frames in The Main Memory: ";
int totalframes;
cin>>totalframes;

cout<<"Please Enter Size of the Page stream: ";
int totalpages;
cin>>totalpages;


cout<<"Now Enter The Page Stream "<<endl;
vector<int>pages(totalpages);
for(int i=0;i<totalpages;i++)
{
    cin>>pages[i];
}


//   for(auto p : pages)
//   cout<<p<<" ";

//     int a;
// while(cin>>a)
// {
//     pages.pb(a);
// }


int pagehit=0;
int pagefault=0;
float hitratio;
float missratio;


aging(totalframes,pages,pagefault,pagehit);


cout<<"total Page faults "<<pagefault<<endl;
cout<<"total Page hit "<<pagehit<<endl;

hitratio = pagehit*1.0/totalpages;
missratio=pagefault*1.0/totalpages;

cout<<"hit ratio is "<<hitratio<<endl;
cout<<"miss ratio is "<<missratio<<endl;


fout<<totalframes;
fout<<" ";
fout<<missratio;
fout<<endl;


}









int main()
{

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
ll t=1;
cin>>t;
while(t--)
{
    solve();
}
return 0;
}
