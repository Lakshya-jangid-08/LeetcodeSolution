# Last updated: 6/29/2026, 10:21:53 AM
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mp = {}
        mp['b'] = 0
        mp['a'] = 1
        mp['l'] = 2
        mp['o'] = 3
        mp['n'] = 4
        
        count = [0] * 5

        for s in text:
            if s in mp:
                count[mp[s]] += 1
        
        count[mp['l']] //= 2
        count[mp['o']] //= 2

        return min(count)