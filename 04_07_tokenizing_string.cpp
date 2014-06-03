#include <string>
#include <iostream>

using namespace std;

/*
 Searches the string for the first character that matches any of the characters specified in its arguments.
 
 When pos is specified, the search only includes characters at or after position pos, ignoring any possible occurrences before pos.
 
 Notice that it is enough for one single character of the sequence to match (not all of them). See string::find for a function that matches entire sequences.
 */

class StringTokenizer {
public:
    
    StringTokenizer(const string&s, const char* delim = NULL):
    str_(s), count_(-1), begin_(0), end_(0) {
        if (!delim)
            delim_ = " \f\n\r\t\v";
        else
            delim_ = delim;
        
        // The first char not delim
        begin_ = str_.find_first_not_of(delim_);
        // The first delim char
        end_ = str_.find_first_of(delim_, begin_);
    }
    
    size_t countTokens() {
        if (count_ >= 0)
            return count_;
        
        string::size_type n = 0;
        string::size_type i = 0;
        
        for (;;) {
            if ((i = str_.find_first_not_of(delim_, i)) == string::npos)
                break;
            
            // find the next delimiter
            i = str_.find_first_of(delim_, i + 1);
            // add the count
            n++;
            if (i == string::npos)
                break;
        }
        
        // return (a=b) will return a;
        return (count_ = n);
    }
    
    bool hasMoreTokens() {
        return (begin_ != end_);
    }
    
    void nextToken(string& s) {
        // Update begin_ so hasMoreTokens() works
        if (begin_ != string::npos && end_ != string::npos) {
            s = str_.substr(begin_, end_ - begin_);
            begin_ = str_.find_first_not_of(delim_, end_);
            end_ = str_.find_first_of(delim_, begin_);
        } else if (begin_ != string::npos && end_ == string::npos) {
            s = str_.substr(begin_, str_.length() - begin_);
            begin_ = str_.find_first_not_of(delim_, end_);
        }
    }
    
private:
    StringTokenizer() {};
    string delim_;
    string str_;
    int count_;
    int begin_;
    int end_;
};

void main_0407() {
    string s= "  google    microsoft twitter   ";
    StringTokenizer st(s);
    
    cout << st.countTokens() << " tokens.\n";
    
    string tmp;
    while (st.hasMoreTokens()) {
        st.nextToken(tmp);
        cout << tmp << "\n";
    }
    
}