/**
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:

输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2

对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0
10 - 2
11 - 3
01 - 1
示例 2:

输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code

**/



class Solution {
public:
    vector<int> grayCode(int n) {
    //计算n+1位时数组中已经包含了n位结果，只需要在其最高位补1然后镜像对称加入数组即可
    vector<int > res = {0};
		int bitCnt = 0;
		int bitMax = 1;
		while(bitCnt < n){
			for (int i = res.size()-1; i >= 0; --i)
			{
				res.push_back(res[i] + bitMax);
			}
			bitMax = bitMax << 1;
			bitCnt++;
		}
		return res;
    }
};
