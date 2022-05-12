//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;

ofstream fout("pagefaultdata_aging.txt",ios_base::app);
#define MAX_WINDOW_SIZE 7

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
// Driver code
int main()
{

    vector<int> token;
    vector<int >dirty;

    fstream newfile;

    int count = 0;
    newfile.open("input.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;

        while (getline(newfile, tp))
        {
            //  cout << tp << "hello";
            //  count++;
            token.clear();
            dirty.clear();
            space_separated_words(tp, token,dirty);

            int pagehit = 0;
            int pagefault = 0;
            float hitratio;
            float missratio;
            int capacity = token[0];
            int n = token.size() - 1;
            token.erase(token.begin());

            // // Debug 

            // cout<<"Pages are "<<endl;
            // for(auto i:token)
            // cout<<i<<" ";
            // cout<<endl;

            // cout<<"dirty bit info "<<endl;
            // for(auto i:dirty)
            // cout<<i<<" ";
            // cout<<endl;


            // // end of Debug

            // again(token, n, capacity, pagefault,dirty);
            aging(capacity,token,pagefault,pagehit);

            cout << "total Page faults " << pagefault << endl;
            cout << "total Page hit " << n - pagefault << endl;

            // hitratio = pagehit * 1.0 / n;
            missratio = pagefault * 1.0 / n;
            hitratio = 1.0 - missratio;
            cout << "hit ratio is " << hitratio << endl;
            cout << "miss ratio is " << missratio << endl;

            fout << capacity;
            fout << " ";
            fout<<n;
            fout << " ";
            fout<<pagefault;

            // fout << missratio;
            fout << endl;

            // cout << pageFaults(pages, n, capacity);
        }

        newfile.close(); //close the file object.
    }

    return 0;
}