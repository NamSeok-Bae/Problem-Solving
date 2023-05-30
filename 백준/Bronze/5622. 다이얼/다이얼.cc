#include <iostream>
#include <map>

using namespace std;

int main() {
    string s;
    cin>>s;
    
    map<char, int> m;
    
    m['A'] = m['B'] = m['C'] = 2;
    m['D'] = m['E'] = m['F'] = 3;
    m['G'] = m['H'] = m['I'] = 4;
    m['J'] = m['K'] = m['L'] = 5;
    m['M'] = m['N'] = m['O'] = 6;
    m['P'] = m['Q'] = m['R'] = m['S'] = 7;
    m['T'] = m['U'] = m['V'] = 8;
    m['W'] = m['X'] = m['Y'] = m['Z'] = 9;
    
    int sum = 0;
    for(int i=0;i<s.size();i++) {
        sum += m[s[i]];
        sum++;
    }
    cout<<sum;
}
