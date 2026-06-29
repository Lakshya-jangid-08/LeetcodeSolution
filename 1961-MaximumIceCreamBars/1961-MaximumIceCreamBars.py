# Last updated: 6/29/2026, 10:21:28 AM
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        maxCost = max(costs)

        count = [0] * (maxCost + 1)

        for c in costs:
            count[c] += 1
        
        res = 0
        for i in range(1, maxCost + 1):
            if count[i] == 0:
                continue
            canbuy = coins // i

            if(canbuy <= count[i]):
                return res + canbuy
            
            res += count[i]
            coins -= count[i] * i
        
        return res
