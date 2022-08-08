// N-Step Scan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct difference
{
    int dif;
    int index;
};

bool r_comp(difference& a, difference& b)
{
    return a.dif < b.dif;
}

int main()
{
    int n = 0, x = 0, N = 0, p = 0, track = 0, totalTracks = -1;
    queue<int> requests;
    cout << "Enter the size of the disk e.g.100: ";
    cin >> n;
    n--;
    cout << "Enter N: ";
    cin >> N;
    
    cout << "Enter the number of element: ";
    cin >> x;
    cout << "Enter the sequence of elements e.g.15 50 24 .....: ";
    for (int i = 0; i < x; i++)
    {
        cin >> p;
        requests.push(p);
    }
    p = requests.front();

    while (requests.size())
    {
        vector<int>subrequests;

        //preparing a subsequence of requests
        for (int i = 0; i < N; i++)
        {
            if (requests.size())
            {
                subrequests.push_back(requests.front());
                requests.pop();
            }
            else
                break;
        }

        
        /*for (int i = 0; i < subrequests.size(); i++)
            cout << subrequests[i] << " ";
        cout << endl;*/

        //execute the subsequence
        for (int i = 0; i <= subrequests.size(); i++)
        {
                vector<difference>differences(subrequests.size());
                vector<int>::iterator it = subrequests.begin();
                for (int j = 0; j < subrequests.size(); j++)
                {
                    if (*it >= track)
                    {
                        differences[j].dif = *it - track;
                        differences[j].index = j;
                    }
                    else
                    {
                        differences[j].dif = (n - track) + (n - *it);
                        differences[j].index = j;
                    }

                    it++;
                }
                sort(differences.begin(), differences.end(), r_comp);

                //execute the first request in differences and remove this request from the subsequence
                if (totalTracks == -1)
                    totalTracks = 0;
                else
                    totalTracks += differences[0].dif;
                it = subrequests.begin();
                for (int j = 0; j < differences[0].index; j++)
                    it++;
                track = *it;
                cout << track << " -> ";
                subrequests.erase(it);   
        }

    }
    cout << endl;
    cout << "Total Tracks = " << totalTracks << endl;
    
}

