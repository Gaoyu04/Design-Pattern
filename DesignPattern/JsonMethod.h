#ifndef JsonMethod_H
#define JsonMethod_H

#include <iostream>
#include "Factory.h"
#include <string>
#include <stack>
#include <algorithm>
#include <fstream>
#include "icon.h"

using namespace std;

class JsonMethod {
    public:

    string json2str(string path) {
        std::ifstream in(path);
        std::istreambuf_iterator<char> beg(in), end; 
        string str(beg, end);

        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        str.erase(remove(str.begin(), str.end(), '"'), str.end());
        str.erase(remove(str.begin(), str.end(), '\n'), str.end());
        str = str.substr(1, str.size() - 2);
        return str;
    }

    shared_ptr<JsonComposite> str2node(string& data, shared_ptr<JsonCompositeFactory> f) {
        stack<shared_ptr<JsonComposite>> father;
        father.push(f->create("root", 0));
        data += ',';
        int depth = 1;
        string token;
        for(int i = 0; i < data.size(); ++i) {
            if(data[i] == ',') {
                if(token.size() > 4 && token.substr(token.size()-4, 4) == "null") {
                    token = token.substr(0, token.size()-5);
                }
                if(token != "")  father.top()->add(f->create(token, depth));
                token.clear();
            }
            else if((data[i] == '{') || (data[i] == '[')) {
                auto t = f->create(token.substr(0, token.size()-1), depth);
                father.top()->add(t);
                father.push(t);
                depth += 1;
                token.clear();
            }
            else if((data[i] == '}') || (data[i] == ']')) {
                if(token != "") father.top()->add(f->create(token, depth));
                father.pop();
                depth -= 1;
                token.clear();
            }
            else token += data[i];
        }
        return father.top();   
    }
};



#endif