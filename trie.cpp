/* Implements a Prefix-Tree aka Trie data structure */
#include <string>
#include <unordered_map>   
#include <iostream>

class Trie
{
private:
    
    struct Node
    {
        std::unordered_map<char, Node*> children;
        char label;
        Node(char label) :  label(label) {}
        bool isTerminal() { return label == '*'; }
    };

    Node* root;
    const char STRING_TERMINATION = '*';

    void addTerminalNode(Node* node) {
        Node* endNode = new Node(STRING_TERMINATION);
        node->children[STRING_TERMINATION] = endNode;
        return;
    }

public: 

    Trie () {
        root = new Node('\0');
    }

    void insert(const std::string& word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                Node* node = new Node(c);
                curr->children[c] = node;
            }
            curr = curr->children[c];
        }

        if (!curr->children.contains(STRING_TERMINATION))
            addTerminalNode(curr);
    }

    bool search(std::string word) {
        Node* curr = root;
        for (const char c : word) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->children.contains(STRING_TERMINATION); // Check for terminal node
    }

    bool startsWith(std::string prefix) {
        Node* curr = root;
        for (const char c : prefix) {
            if (!curr->children.contains(c)) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};


int main() {
    Trie trie;
    trie.insert("apple");
    std::cout << trie.search("apple") << std::endl;    // Output: 1 (true)
    std::cout << trie.search("app") << std::endl;      // Output: 0 (false)
    std::cout << trie.startsWith("app") << std::endl;  // Output: 1 (true)
    trie.insert("app");
    std::cout << trie.search("app") << std::endl;      // Output: 1 (true)
    return 0;
}