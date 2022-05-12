//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;

ofstream fout("pagefaultdata_workingset.txt",ios_base::app);
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
    unsigned int  last_access;
    

    page(int pageno,int t)
    {
        pageno=pageno;
        last_access=t;
    }
};



void Working_set(vector<int> pages, int n, int capacity, int &pagefault)
{

    unordered_set<int>frames;  //contains page that are in MM
    unordered_map<int,page*>map;  //page to page class 
    vector<int> current_window_size;


    for (size_t i = 0; i < pages.size(); i++)
    {
        cout << pages[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < pages.size(); i++)
    {
        if(frames.find(pages[i])==frames.end())  //Page is not Present and space available
            {
                vector<int>pages_to_be_deleted;
                for(auto k:map)
                {
                    if((i-k.second->last_access)>capacity)
                    {
                        // pages_to_be_deleted.push_back(k.first);
                        map.erase(map.find(k.first));
                        frames.erase(k.first);
                      
                    }
                }

                // for(int zz=0;zz<pages_to_be_deleted.size();zz++)
                // {
                //       map.erase(map.find(pages_to_be_deleted[i]));
                //         frames.erase(pages_to_be_deleted[i]);
                // }

                // current_window_size.push_back(frames.size());
                
                frames.insert(pages[i]);
                map[pages[i]]=new page(pages[i],i+1);
                
                // current_window_size.push_back(frames.size());
                // current_window_size.push_back(1);
                

                // cout<<frames.size()<<endl;

                pagefault++;
               
            }
            else   //Page is already present in the MM
            {
                map[pages[i]]->last_access=i+1;
             

            }
              
                

    }



 

    //   cout<<"Avg no. of Page Frames Required in the Working Set are "<<accumulate(current_window_size.begin(),current_window_size.end(),0)*1.0/current_window_size.size()<<endl;
    // cout<<accumulate(current_window_size.begin(),current_window_size.end(),0)<<endl;
    // cout<<current_window_size.size()<<endl;
    cout << "hi ";
    for (auto i : current_window_size)
        cout << i << " ";
    cout << endl;
}

// Driver code
int main()
{

    vector<int> token;
    vector<int> dirty;
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

            Working_set(token, n, capacity, pagefault);

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