class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;

        if (s.size() < total_len) return res;

        unordered_map<string, int> word_count;
        for (string& word : words) word_count[word]++;

        for (int i = 0; i < word_len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int j = i; j + word_len <= s.size(); j += word_len) {
                string word = s.substr(j, word_len);

                if (word_count.find(word) != word_count.end()) {
                    window[word]++;
                    count++;

                    while (window[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window[left_word]--;
                        count--;
                        left += word_len;
                    }

                    if (count == num_words) res.push_back(left);
                } else {
                    window.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        return res;
    }
};