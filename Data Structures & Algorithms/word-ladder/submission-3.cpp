class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;
        int length = 0;
        unordered_set<string> words;
        for(string s: wordList) {
            words.insert(s);
        }

        if(!words.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);

        while(!q.empty()) {
            int len = q.size();
            length++;

            for(int i = 0; i < len; i++) {
                string node = q.front();
                q.pop();

                if(node == endWord) return length;

                for(int j = 0; j < node.size(); j++) {
                    char original = node[j];

                    for(char c = 'a'; c <= 'z'; c++) {
                        node[j] = c;
                        if(words.count(node)) {
                            q.push(node);
                            words.erase(node);
                        }
                    }

                    node[j] = original;
                }
            }
        }

        return 0;
    }
};