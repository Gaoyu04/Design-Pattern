#ifndef Icon_H
#define Icon_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class icon {
    public:
    string node_icon;
    string leaf_icon;

    icon() = default;
    icon(string type) {
        if(type == "space") {
            node_icon = " ";
            leaf_icon = " ";
        }
        else if(type == "funny") {
            node_icon = " ♡ ";
            leaf_icon = " ♢ ";
        }
        else if(type == "music") {
            node_icon = " ♫ ";
            leaf_icon = " ♪ ";
        }
    }
    string get_node_icon() {
        return node_icon;
    }

    string get_leaf_icon() {
        return leaf_icon;
    }
};



#endif