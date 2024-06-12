#ifndef TreeNode_H
#define  TreeNode_H

#include <iostream>
#include <string>
#include <vector>
#include "icon.h"
#include <memory>
using namespace std;

//组合模式

class Node {
    public:
    string name;
    int level;

    Node(string n, int l) : name(n), level(l){}
};

class JsonComposite : public Node{
    public:
    bool isroot = false, islast = false;
    static shared_ptr<icon> i;
    string out;
    vector<shared_ptr<JsonComposite>> children;

    public:
    virtual void render_root() {};
    virtual string render_subtree(string& s) {};
    JsonComposite(string n, int l) : Node(n, l) {};
    void set_icon(shared_ptr<icon> i) {
        this->i = i;
    }
    void add(shared_ptr<JsonComposite> n);
    string getresult() {
        return out;
    }
};

void JsonComposite::add(shared_ptr<JsonComposite> n) {
    children.push_back(n);
}

shared_ptr<icon> JsonComposite::i = NULL;

#endif