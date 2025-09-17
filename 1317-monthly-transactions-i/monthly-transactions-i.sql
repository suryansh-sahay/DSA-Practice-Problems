# Write your MySQL query statement below

SELECT DATE_FORMAT(trans_date, '%Y-%m') as month,
    country, 
    count(id) as trans_count, 
    SUM(state='approved') as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(IF(state='approved', amount, 0)) as approved_total_amount 
FROM Transactions t
GROUP BY country, YEAR(trans_date), MONTH(trans_date);


