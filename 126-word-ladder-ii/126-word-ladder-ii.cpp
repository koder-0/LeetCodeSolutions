class Solution {
     /*
    *   Input: beginWord: string, endWord: string, wordList: vector<string>
    *   Output: res: vector<vector<string>>
    *   beginWord: 
    *       contains only lowercase english alphabets(ASCII 97-122)
    *       length: 1-5
    *   endWord:
    *       contains only lowercase english alphabets(ASCII 97-122)
    *       length: same as beginWord's lenght
    *       endWord and beginWord are never same
    *   wordList:
    *       contains unique words of equal length. (length is same as beginWord)
    *       contains endWord but not beginWord
    *       length: 1-500
    *   res:
    *       Definition: list of all unique shortest transformation sequences.
    *       length: sum of all sequences does not exceed 10^5.
    *   Approach:
    *   we need to find shortest transformation sequence from beginWord to endWord
    *   It synonymous to finding shortest path between start node and endnode.
    *   we need to visualise it as  graph.
    *   nodes represent a word and transformation represents an edge.
    *   transformation constitutes replacement of 1 letter to another.
    *   so basically all edges are of same weight.
    *   so We can use bfs for that.
    *   since we don't have a graph like structure as input.
    *   we need to build our own.
    *   How to build?
    *   Node of a graph basically contains a word.
    *   How to find its children?
    *   we replace each letter of a word with other 25 letters of the alphabet
    *   and see if the newWord is in the wordList.
    *   If yes, newWord becomes child of word else not. 
    *   This might create cycle, so we must remove newWord from wordList.
    *   But what if newWord can be achieved to other word also.
    *   I am thinking about middle level where more than 1 word has proliferated from beginWord
    *   and newWord can be achieved from 2 or more of them.
    *   I this case, since we must traverse in bfs manner.
    *   we would remove the word after a level is done transforming.
    *   so, basically after a level is done transforming, the whole level would be 
    *   swiped off from the wordList.
    *   This way, we would create the graph till the level where endWord is achieved.
    *   Since we are traversing to create, can we store the info for output at the same
    *   time.
    *   I need to devise algo to see it.
    *   Algo:
    *   map<string, vector<vector<string>>> oldLevel;
    *   shortestSeq[beginWord] = {{beginWord}};
    *   while(!endWordFound)
    *       for(auto entry: oldLevel)
    *           word = entry.first; seqList = entry.second;
    *           newWord = word;
    *           for(int i = 0; i < word.length; ++i)
    *               for(char c = 'a'; c <= 'z'; ++c)
    *                   if(c == word[i]) continue;
    *                   newWord[i] = c;
    *                   if(newWord is in wordList)
    *                       if(newWord is endWord) endWordFound = true;
    *                       writeNewSeq(oldLevel, newLevel, word, newWord);
    *                   newWord = word;
    *       oldLevel = newLevel;
    *   return res = oldLevel[endWord];
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