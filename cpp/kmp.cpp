#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//c++11 new charactor, return a vector rvalue
vector<int> get_next(const char * pat) {
    int i = 0;
    int j = -1;

    int patlen = strlen(pat);
    vector<int> next;
    next.reserve(patlen);

    for (int i = 0; i < patlen; ++i) {
        next.push_back(-1);
    }


    while(i < patlen) {
        if(j == -1 || pat[i] == pat[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            --j;
        }
    }
    return next;
}

void print(const char * src, int i) {
    cout << src << endl;
    for (int k = 0; k < i; ++k) {
        cout << " ";
    }
    cout << "^" << endl;
}

void print(const char * src, const char * pat, int i, int j) {
    cout << "i=" << i << ", j="  << j << endl;
    if(j == -1) return;

    print(src, i);

    for (int k = 0; k < i - j; ++k) {
        cout << " ";
    }

    cout << pat << endl;

    for (int k = 0; k < i; ++k) {
        cout << " ";
    }
    cout << "^" << endl;
}

int kmp_search(const char * src, const char * pat) {
    int srclen = strlen(src);
    int patlen = strlen(pat);

    vector<int> next = get_next(pat);

    cout << "next:";
    for(int a : next) {
        cout << a << " ";
    }
    cout << endl;

    int i = -1;
    int j = -1;
    while(i < srclen) {
        print(src, pat, i, j);
        //printf("%s  \n", src + i);
        if(j == -1 || src[i] == pat[j]) {
            ++i;
            ++j;
            if(j == patlen) {
                return i - patlen;
            }
        } else {
            j = next[j];
        }
    }


    return -1;
}

int main(int argc, char * argv[]) {
    //string src("ababcdabc");
    //string pat("abcd");

    const char * src = "BBC ABCDAB ABCDABCDABDE";
    const char * pat = "ABCDABD";

    int idx = kmp_search(src, pat);

    cout << "idx:" << idx << endl;
    print(src, idx);
}
