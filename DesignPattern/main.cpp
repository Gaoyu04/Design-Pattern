#include "Director.h"
#include "icon.h"
#include "StyleNode.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
    int ch;
    string path = "test.json";
    string style = "rectangle";
    string icontype = "music";

    while ((ch = getopt(argc, argv, "f::s::i::")) != -1)
    {
        cout << char(ch) << optarg << endl;
        switch (ch) 
        {
            case 'f':
                path = optarg;
                break;
            case 's':
                style = optarg;
                break;
            case 'i':
                icontype = optarg;
                break;
        }
    }

    JsonFactoryRegistry r;
    Director d;
    shared_ptr<JsonCompositeFactory> f = r.get_factory(style);
    shared_ptr<icon> i = make_shared<icon>(icontype);

    d.RenderJson(path, f, i);
}