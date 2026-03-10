#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Node
{

public:
    string name;

    Node(string name)
    {
        this->name = name;
    }

    virtual void info() = 0;
};

class File : public Node
{
public:
    int size;

    File(string name, int size) : Node(name)
    {
        this->size = size;
    }

    void info() override
    {
        cout << name << " (" << size << " bytes)" << endl;
    }
};

class Folder : public Node
{
public:
    map<string, Node *> children;

    Folder(string name) : Node(name) {}

    void add(Node *node)
    {
        children[node->name] = node;
    }

    void info() override
    {
        cout << "Folder: " << name << endl;
    }

    void list()
    {
        for (auto &item : children)
        {
            item.second->info();
        }
    }
};

class FileSystem
{
public:
    Folder *root;
    Folder *current;

    FileSystem()
    {
        root = new Folder("root");
        current = root;
    }

    void createFile(string name, int size)
    {
        current->add(new File(name, size));
    }

    void createFolder(string name)
    {
        current->add(new Folder(name));
    }

    void ls()
    {
        current->list();
    }
};

int main()
{

    FileSystem fs;

    fs.createFile("Hi.txt", 100);
    fs.createFolder("docs");
    fs.ls();
}