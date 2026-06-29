-- Last updated: 6/29/2026, 10:23:14 AM
# Write your MySQL query statement below
SELECT firstName, lastName, city, state from Person LEFT JOIN Address ON Person.personId = Address.personId