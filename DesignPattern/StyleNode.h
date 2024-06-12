#ifndef StyleNode_H
#define StyleNode_H

#include "Node.h"
#include "icon.h"
#include "JsonMethod.h"
using namespace std;

class TreeJsonComposite : public JsonComposite {
    public:
    TreeJsonComposite(string n, int l) : JsonComposite(n, l) {};

    void render_root() {
        children[0]->isroot = true;
        children[children.size()-1]->islast = true;
        for(auto a : children) {
            string temp = "";
            out += a->render_subtree(temp);
        }
    }

    string render_subtree(string& prefix) {
        string next_prefix(prefix);
        render_node(prefix, next_prefix);
        render_children(next_prefix);
        return out;
    }

    void render_node(string& prefix, string& next_prefix) {
        out += prefix;
        if(islast) {
            out += "└─";
            next_prefix += "   ";
        }
        else {
            out += "├─";
            next_prefix += "│  ";
        }
        if(children.size()) out += i->get_node_icon();
        else out += i->get_leaf_icon();
        out += name + " \n";
    }

    void render_children(string& next_prefix) {
        if(children.size()) {
            children[children.size()-1]->islast = true;
        }
        for(auto c : children) {
            c->render_subtree(next_prefix);
            out += c->getresult();
        }
    }
};

class RectangleJsonComposite : public JsonComposite {
    public:
    int len = 100;
    RectangleJsonComposite(string n, int l) : JsonComposite(n, l) {};
    void render_root() {
        children[0]->isroot = true;
        children[children.size()-1]->islast = true;
        for(auto a : children) {
            string temp = "";
            out += a->render_subtree(temp);
        }
    }

    string render_subtree(string& out) {
        if(islast && children.size()) {
            islast = false;
            children[children.size()-1]->islast = true;
        }
        
        render_node(out);
        render_children(out);
        return out;
    }

    void render_node(string& out) {
        if(isroot) out += "┌─";
        else if(islast) {
            out += "└─";
            for(int i =1; i < level; ++i) {
                out += "─┴─";
            }
        }
        else {
            for(int i = 1; i < level; ++i) {
                out += "│  ";
            }
            out += "├─";
        }
        if(children.size()) out += i->get_node_icon();
        else out += i->get_leaf_icon();
        out += name;
        int k = len - name.size() - level * 3;
        for(int i = 0; i < k; ++i) {
            out += "─";
        }
        if(isroot) {
            out += "┐";
        }
        else if(islast) out += "┘";
        else out += "┤";
        out += "\n";
    }

    void render_children(string& out) {
        for(auto c : children) {
            c->render_subtree(out);
        }
    }
};



#endif