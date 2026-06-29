-- Last updated: 6/29/2026, 10:23:13 AM
# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1 
) AS SecondHighestSalary 