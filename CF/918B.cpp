#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, vector<pair<string,string>>& servers, vector<pair<string,string>>& commands)
{
    // hashmap1 [ip -> name]
    unordered_map<string, string> ip_to_name;

    // build map: store ip , name
    for(int i = 0; i < n; i++) {
        string name = servers[i].first;
        string ip = servers[i].second;
        ip_to_name[ip] = name;
    }

    // loop commands, match ip and concat name
    for(int i = 0; i < m; i++) {
        string cmd = commands[i].first;
        string ip_with_semicolon = commands[i].second;

        // remove ';' from ip
        string ip = ip_with_semicolon;
        ip.pop_back();

        string name = ip_to_name[ip];
        cout << cmd << " " << ip_with_semicolon << " #" << name << "\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<string,string>> servers(n);
    for(int i = 0; i < n; i++) {
        cin >> servers[i].first >> servers[i].second; // name ip
    }

    vector<pair<string,string>> commands(m);
    for(int i = 0; i < m; i++) {
        cin >> commands[i].first >> commands[i].second; // command ip;
    }

    solve(n, m, servers, commands);
}