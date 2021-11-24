//C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;
ofstream fout("pagefaultdata.txt");
void space_separated_words(string input, vector<int> &token)
{

    string word = "";
    for (auto x : input)
    {
        if (x == ' ')
        {
            token.push_back(stoi(word));
            cout << word << endl;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    token.push_back(stoi(word));
}

auto select_random(unordered_set<int> &s, size_t n)
{
    auto it = s.begin();

    std::advance(it, n);
    return it;
}

void random(vector<int> pages, int n, int capacity, int &page_faults)
{

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {

        if (s.size() < capacity)
        {

            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                page_faults++;
            }
        }

        else
        {

            if (s.find(pages[i]) == s.end())
            {

                auto it = s.begin();

                int random = rand() % s.size();
                // Remove the indexes page
                auto n = *select_random(s, random);
                s.erase(n);

                // insert the current page
                s.insert(pages[i]);

                // Increment page faults
                page_faults++;
            }
        }
    }
}

// Driver code
int main()
{

    vector<int> token;

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
            space_separated_words(tp, token);

            int pagehit = 0;
            int pagefault = 0;
            float hitratio;
            float missratio;
            int capacity = token[0];
            int n = token.size() - 1;
            token.erase(token.begin());

            random(token, n, capacity, pagefault);

            // hitratio = pagehit * 1.0 / n;
            missratio = pagefault * 1.0 / n;
            hitratio = 1.0 - missratio;

            fout << capacity;
            fout << " ";
            fout << missratio;
            fout << endl;

            // cout << pageFaults(pages, n, capacity);
        }

        newfile.close(); //close the file object.
    }

    return 0;
}
