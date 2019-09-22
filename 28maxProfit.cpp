/**

**/

/**
执行用时 :
8 ms, 在所有 C++ 提交中击败了87.57%

内存消耗 :
9.5 MB  在所有 C++ 提交中击败了 35.59%
**/
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int max = 0;
        int min = prices[0];
        for(int i = 1;i < prices.size();++i){
            if(prices[i]<min)
                min = prices[i];
            int earn = prices[i] - min;
            if(earn > max){
                max = earn;
            }
        }
        return max;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int pro = 0;
        int last = 0;
        for(int i = 0;i<prices.size()-1;i++){
            last = max(0,last + prices[i+1] - prices[i]);
            pro = max(last,pro);
        }
        return pro;
    }
};
