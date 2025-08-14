class Solution {
public:
    string largestGoodInteger(string num) {
        string answer="";
        for(int i=0; i<num.size()-2; i++){
            if(num[i]==num[i+1]&& num[i]==num[i+2]){
               answer= max(answer, num.substr(i,3));
            }
        }
        return answer;
    }
};