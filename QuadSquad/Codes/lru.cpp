//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;
// ofstream fout("pagefaultdata.txt");
ofstream fout("pagefaultdata_lru.txt",ios_base::app);
unordered_map<int, int> indexes;
unordered_map<int, int> final;
void store_the_lru_info(int page, int index)
{
    indexes[page] = index;
}
bool compare(std::pair<int, int> i, pair<int, int> j)
{
    return i.second < j.second;
}
int find_the_lru_page(vector<int> s)
{

    final.clear();
    for (auto x : s)
    {
        final[x] = indexes[x];
    }

    std::pair<int, int> min = *min_element(final.begin(), final.end(), compare);
    return min.first;
}
// void space_separated_words(string input, vector<int> &token)
// {

//     string word = "";
//     for (auto x : input)
//     {
//         if (x == ' ')
//         {
//             token.push_back(stoi(word));
//             // cout << word << endl;
//             word = "";
//         }
//         else
//         {
//             word = word + x;
//         }
//     }
//     token.push_back(stoi(word));
// }



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

int pageFaults(vector<int> pages, int n, int capacity, int &page_faults)
{
    

    vector<int> s;

    
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            
            if (find(s.begin(), s.end(), pages[i]) == s.end())
            {
                s.push_back(pages[i]);

                // increment page fault
                page_faults++;
            }

            

            store_the_lru_info(pages[i], i);
        }

      
        else
        {
            
            if (find(s.begin(), s.end(), pages[i]) == s.end())
            {
                
                int val = find_the_lru_page(s);
                // cout << "The value of val is: " << val << endl;

                auto it = find(s.begin(), s.end(), val);
                // Remove the indexes page
                if (it == s.end())
                {
                    cout << "null" << endl;
                }
                else
                {
                    s.erase(it);
                }

                
                s.push_back(pages[i]);

                
                page_faults++;
            }

           
            indexes[pages[i]] = i;
        }
    }
    
    return 0;
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

            // lru(totalframes, pages, pagefault, pagehit);

            pageFaults(token, n, capacity, pagefault);

            // hitratio = pagehit * 1.0 / n;
            missratio = pagefault * 1.0 / n;
            hitratio = 1.0 - missratio;

            fout << capacity;
            fout << " ";
            fout<<n;
            fout<<" ";
            fout << pagefault;
            fout << endl;

            // cout << pageFaults(pages, n, capacity);
        }

        newfile.close(); //close the file object.
    }

    return 0;
}
