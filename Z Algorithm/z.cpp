#include <bits/stdc++.h>

using namespace std;
 
void getZ(string str, int Z[]);

void print(vector<int> v){
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<"  ";
    cout<<endl;
}

vector<int> search(string text, string pattern){
    string concat = pattern + "$" + text;
    int l = concat.length();
    vector<int> v;

    int Z[l];
    getZ(concat, Z);
 
    for (int i = 0; i < l; ++i){
        if (Z[i] == pattern.length())
            v.push_back(i-pattern.length()-1);
    }
    return v;
}
 
void getZ(string str, int Z[]){
    int n = str.length();
    int L, R, k;
 
    L = R = 0;
    for (int i=1;i<n;++i){
        if (i>R){
            L=R=i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
 
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
 
            else{
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
 
int main(){
    string text = "seivt478eno397n98seivwerwo3b789ob79seiseivesyisor";
    string pattern = "seiv";
    print(search(text, pattern));
    return 0;
}