# Write your MySQL query statement below

SELECT a.product_id, ROUND(IFNULL(SUM(price*units)/SUM(units),0), 2) as average_price FROM Prices as a
LEFT JOIN UnitsSold as b
ON a.product_id=b.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY a.product_id;