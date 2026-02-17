#include <iostream>
using namespace std;

class Trie {
private:
    struct TrieNode
    {
        // 有多少子樹分支
        TrieNode* child[26];
        // 是否結尾
        bool isEnd;
        
        // 初始化
        TrieNode() : isEnd(false)
        {
            for(int i = 0; i<26; i++)
            {
                child[i] = nullptr;
            }
        }
    };
    
    // 樹根
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(char c : word)
        {
            int index = c - 'a';
            if(!node->child[index])
            {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEnd = true;
    }

    // 找字
    bool search(string word) {
        
        TrieNode* node = find(word);
        return node != nullptr && node->isEnd;
    }
    
    // 是否為前墜
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    // 返回單字最後一個字的節點
    TrieNode* find(string word)
    {
        TrieNode* node = root;
        
        for(char c : word)
        {
            int index = c - 'a';
            if(!node->child[index])
            {
                return nullptr;
            }
            node = node->child[index];
        }
        return node;
    }
};

int main()
{
    
}

