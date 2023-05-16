#include <vector>
#include <string>
#include <assert.h>

using namespace std;

class Trie {
    class TrieNode {
    public:    
        TrieNode() {
            for (int i=0; i<NUM; i++) {
                this->next[i] = nullptr;
            }
            
            isEnd = false;
        }
        
        static const int NUM=26;
        TrieNode* next[NUM];
        bool isEnd;
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                node->next[idx] = new TrieNode();
            }
            
            node = node->next[idx];
        }
        
        node->isEnd = true;
    }
    
    bool startWith(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                return false;
            }
            
            node = node->next[idx];
        }
        
        return true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                return false;
            }
            
            node = node->next[idx];
        }
        
        return node->isEnd;
    }
};

int main() {
    Trie trie;
    trie.insert("palindrom");
    assert(!trie.search("palin"));
    assert(trie.search("palindrom"));
    assert(trie.startWith("palin"));
    assert(!trie.startWith("test"));
}
