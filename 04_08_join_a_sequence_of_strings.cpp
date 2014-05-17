#include <string>
#include <iostream>
#include <vector>

using namespace std;

// join a C-style string sequence

const static int MAGIC_NUMBER = 4;

template<typename T>
void join_string(T* seq_string[], size_t n, T c, basic_string<T>& s) {
    
    s.clear();
    
    for (int i = 0; i < n; ++i) {
        if (seq_string[i] != NULL)
            s += seq_string[i];     //string += C-style string (char*)
        if (i < n - 1)
            s += c;
    }
}

void join(const vector<string>& v, char c, string& s) {
    
    s.clear();
    
    for (vector<string>::const_iterator p = v.begin(); p != v.end(); ++p) {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }
}

void main_0408() {
    
    vector<string> v;
    
    v.push_back(string("keep"));
    v.push_back(string("running"));
    v.push_back(string("everyday"));
    
    string result;
    
    join(v, ' ', result);
    
    cout << result << endl;
    
    // test genetic join
    wchar_t* seq[MAGIC_NUMBER];
    seq[0] = L"you";
    seq[1] = L"drank";
    seq[2] = L"iced";
    seq[3] = L"lemontea";
    
    wstring ws;
    
    join_string(seq, MAGIC_NUMBER, L'/', ws);
    
    wcout << ws << endl;
}
