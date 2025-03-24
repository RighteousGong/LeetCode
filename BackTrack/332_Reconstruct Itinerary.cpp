/*
332. 重新安排行程
困难

给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

示例 1：
输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]

示例 2：
输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 
提示：
1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi 和 toi 由大写英文字母组成
fromi != toi
*/
#include <vector>
#include <string>
#include <map>

class Solution 
{
    std::vector<std::string> result;
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
    {
        std::vector<bool> used(tickets.size(), false);
        std::string str = "JFK";
        backTracking(tickets, used, str);
        return result;
    }

    void backTracking(std::vector<std::vector<std::string>>& tickets, std::vector<bool>& used, std::string& nextSation)
    {
        if (result.size() == 0)
            result.emplace_back(nextSation);

        std::vector<std::string> sVec;
        int minStation = -1;
        std::string minStationStr;
        for (int i = 0; i <  tickets.size(); ++i)
        {
            std::vector<std::string> tmp = tickets[i];
            if (used[i] || tmp[0] != nextSation)
                continue;
            sVec.push_back(tmp[1]);
            if (minStationStr.empty())
            {
                minStationStr = tmp[1];
                minStation = i;
            }
            else if (tmp[1] < minStationStr)
            {
                minStationStr = tmp[1];
                minStation = i;
            }
        }

        if (minStation == -1)
            return;

        for (int i = 1; i <= sVec.size(); ++ i)
        {
            result.push_back(minStationStr);
            backTracking(tickets, used, result.back());
            int count = 0;
            for (auto b : used)
            {
                if (b)
                    ++count;
            }
            if (count == tickets.size())
                return;
            result.pop_back();
            used[minStation] = false;
            std::string odd = minStationStr;
            for (int j = 0; j < sVec.size(); ++j)
            {
                if (sVec[j] == odd)
                    continue;
                if (sVec[j] < minStationStr)
                {
                    minStationStr = sVec[j];
                }
            }
            for (int index = 0; index < tickets.size(); ++index)
            {
                std::vector<std::string> ticket = tickets[index];
                if (ticket.size() >= 2)
                {
                    if (ticket[0].compare(nextSation) == 0 && ticket[1].compare(minStationStr) == 0)
                        minStation = index;
                }
            }
        }
    }
};