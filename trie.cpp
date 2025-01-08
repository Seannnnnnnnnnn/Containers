/* Implements a Prefix-Tree aka Trie data structure */
#include <string>
#include <vector>


class Trie
{
private:
    struct Node
    {
        std::string label;
        std::string val;
        std::vector<Node*> children;
        bool isTerminal;
        Node(std::string label, std::string val) :  label(label), val(val), isTerminal(false) {}
    };

public: 

    Trie () {

    }

    void insert(std::string word)
    {

    }

    bool search(std::string word)
    {

    }

    bool startsWith(std::string prefix)
    {

    }
};