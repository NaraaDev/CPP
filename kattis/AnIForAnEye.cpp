#include<bits/stdc++.h>

using namespace std;

int main() {

    map<string,string> mp;
    mp["at"] = "@";
    mp["and"] = "&";
    mp["one"] = "1";
    mp["won"] = "1";
    mp["to"] = "2";
    mp["too"] = "2";
    mp["two"] = "2";
    mp["for"] = "4";
    mp["four"] = "4";
    mp["bea"] = "b";
    mp["be"] = "b";
    mp["bee"] = "b";
    mp["sea"] = "c";
    mp["see"] = "c";
    mp["eye"] = "i";
    mp["owe"] = "o";
    mp["oh"] = "o";
    mp["are"] = "r";
    mp["you"] = "u";
    mp["why"] = "y";

    string t;
    getline(cin ,t);

    int num = 0;

    for(int i = 0; i < t.size(); i++) {
        num = num * 10 + (t[i] - '0');
    }

    while(num--) {
        string s;
        getline(cin, s);
        vector<string> words;
        vector<string> answers;
        
        string word="";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                word += s[i];
            } else{
                words.push_back(word);
                word = "";
            }
        }
        if(word.size() > 0)
            words.push_back(word);
        vector<int> isBig(words.size(), false);

        for(int i = 0; i < words.size(); i++) {
            if(words[i][0] >= 'A' && words[i][0] <= 'Z')
                isBig[i] = true;
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] >= 'A' && words[i][j] <= 'Z') {
                    words[i][j] += 32;
                }
            }
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].length(); j++) {
                for(int g = j + 1; g < words[i].length(); g++) {
                    string check = words[i].substr(j, g - j + 1);
                    if(mp.find(check) != mp.end()) {
                        string aa = words[i].substr(j, g - j + 2);
                        if(check == "be" && (aa == "bee" || aa == "bea")) {
                            words[i].replace(j, g - j + 2, mp[aa]);
                        } else if(check == "to" &&  aa == "too") {
                            words[i].replace(j,g - j + 2, mp[aa]);
                        }
                        else words[i].replace(j, g - j + 1, mp[check]);
                    }
                }
            }
        }

        for(int i = 0; i < words.size(); i++) {
            if(isBig[i] && words[i][0] >= 'a' && words[i][0] <= 'z') {
                words[i][0] -= 32;
            }
            cout << words[i] << ' ';
        }

        cout << '\n';
    }
}
/*
O say can u c
I do not underst& y u r so cranky just bcause Krl 1
4m@ion

*/