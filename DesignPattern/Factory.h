#ifndef Factory_H
#define Factory_H
#include "StyleNode.h"

// 工厂方法生成node
class JsonCompositeFactory {
    public:
    virtual shared_ptr<JsonComposite> create(string name, int level) = 0;
};

class TreeJsonCompositeFactory : public JsonCompositeFactory {
    public:
    shared_ptr<JsonComposite> create(string name, int level) {
        return make_shared<TreeJsonComposite>(name, level);
    }
};

class RectangleJsonCompositeFactory: public JsonCompositeFactory {
    public:
    shared_ptr<JsonComposite> create(string name, int level) {
        return make_shared<RectangleJsonComposite>(name, level);
    }
};

class JsonFactoryRegistry {
    public:
    shared_ptr<JsonCompositeFactory> get_factory(string type) {
        if(type == "tree") return make_shared<TreeJsonCompositeFactory>();
        else if(type == "rectangle") return make_shared<RectangleJsonCompositeFactory>();
    }
};

#endif