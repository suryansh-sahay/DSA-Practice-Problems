# Write your MySQL query statement below

select round(SUM(IF(order_date=customer_pref_delivery_date,1,0))*100/count(distinct customer_id),2) as immediate_percentage FROM delivery
WHERE (customer_id, order_date) IN (SELECT customer_id,min(order_date) FROM Delivery GROUP BY customer_id);





























-- SELECT  ROUND(SUM(IF(order_date=customer_pref_delivery_date,1,0))* 100/count(distinct customer_id),2) as immediate_percentage FROM delivery
-- WHERE (customer_id, order_date) in 
--     (SELECT customer_id, MIN(order_date) 
--     FROM delivery
--     GROUP BY customer_id
--     );

# Write your MySQL query statement below
-- select 
--     ROUND(Sum(IF(order_date = customer_pref_delivery_date, 1 ,0))*100/Count(distinct customer_id), 2)
--     as immediate_percentage
-- from delivery
-- where(customer_id, order_date) in
--     (
--         select customer_id, MIN(order_date)
--         from delivery
--         group by customer_id
--     )
