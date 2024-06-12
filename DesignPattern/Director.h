#ifndef Director_H
#define Director_H

#include "JsonMethod.h"
#include "StyleNode.h"
#include "Factory.h"
#include "icon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <locale>


// 建造者模式进行渲染
class Director{
    public:
    
    template <class T>
    void RenderJson(string path, T factory, shared_ptr<icon> i) {
        JsonMethod b;
        string str = b.json2str(path);
        auto root = b.str2node(str, factory);
        root->set_icon(i);
        root->render_root();
        cout << root->getresult();
    }
};

#endif