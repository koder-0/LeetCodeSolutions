class Solution {
     /*
     * idea is referred from solution.
     * to avoid TLE or MLE, we must create graph and
     * traverse it for solution sequences separately
     * a directed graph is created edge from newWord to oldWord.
     * Reason being, there could be numerous paths covered while
     * finding path from beginWord to endWord not necessarily
     * reaching the endWord.
     * Hence, we have more paths than the solution while creating graph.
     * So, traversing backwards, we will traverse on the solution paths only.
     */
typedef vector<string> levelT;
typedef vector<levelT> resT;
typedef unordered_map<string, levelT> graphT;
resT res;
graphT graph;
levelT currLevel;
unordered_set<string> wordSet;
bool endWordFound = false;
public:
    void dfs(const graphT& graph, string word, resT& res, vector<string>& tmp) {
        if(!graph.count(word)) return;
        tmp.push_back(word);
        if(graph.at(word).empty()) {
            reverse(begin(tmp), end(tmp));
            res.push_back(tmp);
            reverse(begin(tmp), end(tmp));
        }
        else {
            for(auto child: graph.at(word)) {
                dfs(graph, child, res, tmp);
            }
        }
        tmp.pop_back();
        return;   
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        res.clear();
        wordSet.clear();
        currLevel.clear();
        endWordFound = false;
        int n = beginWord.size();
        //build Set
        for(auto word: wordList) {
            wordSet.insert(word);
        }
        //build Graph
        currLevel = {beginWord};
        wordSet.erase(beginWord);
        graph[beginWord] = {};
        while(!currLevel.empty() && !endWordFound) {
            levelT newLevel;
            for(auto word: currLevel) {
                auto newWord = word;
                for(int i = 0; i < n; ++i) {
                    char x = word[i];
                    for(char y = 'a'; y <= 'z'; ++y) {
                        if(x == y) continue;
                        newWord[i] = y;
                        if(wordSet.count(newWord)) {
                            if(!graph.count(newWord)) {
                                newLevel.push_back(newWord);
                            }
                            if(newWord == endWord) endWordFound = true;
                            graph[newWord].push_back(word);
                        }
                    }
                    newWord[i] = x;
                }
            }
            currLevel.clear();
            currLevel = newLevel;
            for(auto word: currLevel) {
                wordSet.erase(word);
            }
        }
        //build result
        vector<string> tmp;
        dfs(graph, endWord, res, tmp);
        return res;
    }
};