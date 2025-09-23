# Write your MySQL query statement below

SELECT 'Low Salary' as category, count(income) accounts_count FROM Accounts 
WHERE income<20000
UNION
SELECT 'Average Salary' as category, count(income) accounts_count FROM Accounts 
WHERE income>=20000 AND income<=50000
UNION
SELECT 'High Salary' as category, count(income) accounts_count FROM Accounts 
WHERE income>50000;


