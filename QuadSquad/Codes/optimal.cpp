//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;
// ofstream fout("pagefaultdata.txt");
ofstream fout("pagefaultdata_optimal.txt", ios_base::app);
// void space_separated_words(string input, vector<int> &token)
// {

//     string word = "";
//     for (auto x : input)
//     {
//         if (x == ' ')
//         {
//             token.push_back(stoi(word));
//             cout << word << endl;
//             word = "";
//         }
//         else
//         {
//             word = word + x;
//         }
//     }
//     token.push_back(stoi(word));
//     cout << word << endl;
// }

void space_separated_words(string input, vector<int> &token, vector<int> &dirty)
{

    string word = "";
    bool isdirtystarted = false;

    for (auto x : input)
    {
        if (x == ' ')
        {
            if (word.size() == 0)
            {
                continue;
            }

            if (!isdirtystarted)
                token.push_back(stoi(word));

            else
                dirty.push_back(stoi(word));
            // cout << word << endl;
            word = "";
        }
        else if (x == ',')
        {
            isdirtystarted = true;
        }
        else
        {
            word = word + x;
        }
    }
    cout << word << endl;
    dirty.push_back(stoi(word));
}

// bool search(int key, vector<int> &fr)
// {
//     for (int i = 0; i < fr.size(); i++)
//         if (fr[i] == key)
//             return true;
//     return false;
// }

int predict(vector<int> pages,int n, vector<int> &fr, int index, int i)
{

    int res = -1;
    int last = i + 1;
    int temp;
    for (int i = 0; i < fr.size(); i++)
    {
        int j;
        temp = j;
        for (j = index; j < n; j++)
        {

            if (fr[i] == pages[j])
            {
                if (j > last)
                {
                    last = j;
                    res = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    if (res == -1)
    {
        return 0;
    }
    else
    {
        return res;
    }
}

void optimalPage(vector<int> pages, int pn, int fn, int &hit)
{
    int pagefault=0;

    vector<int> fr;

    hit = 0;
    for (int i = 0; i < pn; i++)
    {

        if (find(fr.begin(), fr.end(), pages[i]) != fr.end())
        {
           
            continue;
        }

        if (fr.size() < fn)
        {
            pagefault++;
            fr.push_back(pages[i]);
        }

        else
        {
            pagefault++;
            int j = predict(pages, pn, fr, i + 1, i);

            fr[j] = pages[i];
        }

    }

    hit=pn-pagefault;
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
            space_separated_words(tp, token, dirty);

            int pagehit = 0;
            int pagefault = 0;
            float hitratio;
            float missratio;
            int capacity = token[0];
            int n = token.size() - 1;
            token.erase(token.begin());

            // lru(totalframes, pages, pagefault, pagehit);

            // pageFaults(token, n, capacity, pagefault);
            optimalPage(token, n, capacity, pagehit);

            cout << "total Page faults " << n - pagehit << endl;
            cout << "total Page hit " << pagehit << endl;
            pagefault = n - pagehit;
            // hitratio = pagehit * 1.0 / n;
            missratio = pagefault * 1.0 / n;
            hitratio = 1.0 - missratio;
            cout << "hit ratio is " << hitratio << endl;
            cout << "miss ratio is " << missratio << endl;

            fout << capacity;
            fout << " ";
            fout << n;
            fout << " ";
            fout << pagefault;
            fout << endl;

            // cout << pageFaults(pages, n, capacity);
        }

        newfile.close(); //close the file object.
    }

    return 0;
}
