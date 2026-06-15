class Node {
    public:
    Node* children[26];
    bool isLeaf;
    Node(){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isLeaf = 0;
    }
};
class WordDictionary {
    Node*root;
public:
    WordDictionary() {
        root = new Node();     
    }
    void addWord(string word) {
        Node*node = root;
        for(char ch:word){
            int idx = ch-'a';
            if(node->children[idx]==NULL){
                node->children[idx] = new Node();
            }
            node = node->children[idx];
        }
        node->isLeaf = 1;    
    }
    bool DictionarySearch(Node*root,string word,int depth){
        // Base Condition.
        if(depth==word.size()){
            if(word[depth]=='.') return true;
            return root->isLeaf;
        }
        // Normal Condition;
        if(word[depth]=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i]){
                    if(DictionarySearch(root->children[i],word,depth+1)) return true;
                }
            }
            return false;
        }
        int index = word[depth]-'a';
        if(root->children[index]==NULL) return false;
        return DictionarySearch(root->children[index],word,depth+1);
    }
    bool search(string word) {
        return DictionarySearch(root,word,0);   
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */