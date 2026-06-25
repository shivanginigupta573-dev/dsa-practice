struct TrieNode{
    TrieNode* child[26]={nullptr};
    bool isEnd=false;//marks the end if the trie

};
class Trie {
public:
TrieNode* root;
    Trie() {
        root=new TrieNode ();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(char c:word)
        {
            int i=c-'a';
            if(!node->child[i])//then insert
            node->child[i]=new TrieNode();
            node=node->child[i];//move the pointer
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(char c:word)
        {
            int i=c-'a';
            if(!node->child[i])
            return false;
            node=node->child[i];
        }
        return node->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix)
        {
            int i=c-'a';
            if(!node->child[i])
            return false;
            node=node->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */