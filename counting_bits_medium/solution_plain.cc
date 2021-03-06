/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 10 May 2016 11:21:32 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> countBits(int num) 
		{
			vector<int> result;
			int count = 0;
			int tmp = 0;
			for (int i = 0; i <= num; ++i)
			{
				tmp = i;
				while ( tmp != 0)
				{
					if ((tmp & 1) != 0)
					{
						count++;
					}
					tmp = tmp >> 1;
				}
				result.push_back(count);
				count = 0;
				tmp = 0;
			}

			return result;
		}
};

int main(void)
{
	Solution solution;

	vector<int> result = solution.countBits(5);
	for (auto i : result)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
