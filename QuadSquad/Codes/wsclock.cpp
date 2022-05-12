//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;

ofstream fout("pagefaultdata_wsclock.txt",ios_base::app);
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
    unsigned int last_access;
    bool M;
    bool R;

    page(int pageno, int t,bool M1)
    {
        pageno = pageno;
        last_access = t;
        M = M1;
        R = false;
    }
};

void WSClock(vector<int> &pages, int n, int capacity, int &pagefault,vector<int> &dirty)
{

    unordered_set<int> frames;      //contains page that are in MM
    unordered_map<int, page *> map; //page to page class
    vector<int> current_frames;

    auto hand = current_frames.begin();

    for (size_t i = 0; i < pages.size(); i++)
    {
        cout << pages[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < pages.size(); i++)
    {

        // if(frames.size()==0)
        // {
        //         current_frames.push_back(pages[i]);
        //         frames.insert(pages[i]);
        //         map[pages[i]] = new page(pages[i], i + 1);
        //         continue;
        // }

        if (frames.find(pages[i]) == frames.end()) //Page is not Present and space available
        {

            auto temphand = hand;

            bool isinserted = false;

            // while (temphand +1!=hand)
            while (temphand !=current_frames.end())

            {
                if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == false and map[*temphand]->M == false)
                {
                    cout << "##########################################################\n";

                    map.erase(map.find(*temphand));
                    frames.erase(*temphand);
                    current_frames.erase(temphand);

                    frames.insert(pages[i]);
                    map[pages[i]] = new page(pages[i], i + 1,dirty[i]);
                    current_frames[*temphand] = pages[i];
                    isinserted = true;

                    if (hand == current_frames.end())
                    {
                        hand = current_frames.begin();
                    }
                    else
                        hand = hand + 1;
                    break;
                }
                else if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == false and map[*temphand]->M == true)
                {
                    // Write This page to The Disk
                    map[*temphand]->M == false;
                    continue;
                }
                else if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == true)
                {
                    // This page is Used previously Since Refer bit is set to 1
                    map[*temphand]->R == false;
                    continue;
                }
                // if (temphand == current_frames.end())
                //     temphand = current_frames.begin();
                // else
                //     temphand++;
            }

            if (isinserted == false)
            {
                // cout << "##########################################################\n";
                temphand = hand;

                // while (temphand +1!=hand)
                while (temphand != current_frames.end())
                {
                    if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == false and map[*temphand]->M == false)
                    {

                        map.erase(map.find(*temphand));
                        frames.erase(*temphand);
                        current_frames.erase(temphand);

                        frames.insert(pages[i]);
                        map[pages[i]] = new page(pages[i], i + 1,dirty[i]);
                        current_frames[*temphand] = pages[i];

                        isinserted = true;
                        if (hand == current_frames.end())
                        {
                            hand = current_frames.begin();
                        }
                        else
                            hand = hand + 1;

                        break;
                    }
                    else if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == false and map[*temphand]->M == true)
                    {
                        // Write This page to The Disk
                        map[*temphand]->M == false;
                        continue;
                    }
                    else if ((i - map[*temphand]->last_access) > capacity and map[*temphand]->R == true)
                    {
                        // This page is Used previously Since Refer bit is set to 1
                        map[*temphand]->R == false;
                        continue;
                    }
                    // if (temphand == current_frames.end())
                    //     temphand = current_frames.begin();
                    // else
                    //     temphand++;
                }
            }

            // for (auto k : map)
            // {
            //     if ((i - k.second->last_access) > capacity)
            //     {
            //         // pages_to_be_deleted.push_back(k.first);
            //         map.erase(map.find(k.first));
            //         frames.erase(k.first);
            //         break;
            //     }
            // }

            if (isinserted == false)
            {
                // current_frames.push_back(pages[i]);

                // cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

                frames.insert(pages[i]);
                map[pages[i]] = new page(pages[i], i + 1,dirty[i]);
            }

            pagefault++;
        }
        else //Page is already present in the MM
        {
            map[pages[i]]->last_access = i + 1;
            map[pages[i]]->R = true;
        }
    }

    //   cout<<"Avg no. of Page Frames Required in the Working Set are "<<accumulate(current_window_size.begin(),current_window_size.end(),0)*1.0/current_window_size.size()<<endl;
    // cout<<accumulate(current_window_size.begin(),current_window_size.end(),0)<<endl;
    // cout<<current_window_size.size()<<endl;
    // cout << "hi ";
    // for (auto i : current_window_size)
    //     cout << i << " ";
    // cout << endl;
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

            WSClock(token, n, capacity, pagefault,dirty);

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
