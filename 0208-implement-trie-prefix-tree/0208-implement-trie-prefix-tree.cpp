class Trie {
public:
    struct trieNode{
        trieNode* children[26];
        bool isEndOfWord;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for(int i=0; i<26; i++)
        {
            newNode->children[i] = nullptr;
        }

        return newNode;

    }
    
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(int i =0; i<word.length(); i++)
        {
            int idx = word[i] - 'a';

            if(!crawler->children[idx])
                crawler->children[idx] = getNode();

            crawler = crawler->children[idx];
        }

        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;

        for(int i =0; i<word.length(); i++)
        {
            int idx = word[i] - 'a';

            if(!crawler->children[idx])
                return false;

            crawler = crawler->children[idx];
        }

        return (crawler != nullptr && crawler->isEndOfWord);

    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        int i = 0;
        for(; i<prefix.length(); i++)
        {
            int idx = prefix[i] - 'a';

            if(!crawler->children[idx])
                return false;

            crawler = crawler->children[idx];
        }

        return (i == prefix.length());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */