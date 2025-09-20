# Write your MySQL query statement below

SELECT ROUND(COUNT(player_id)/(SELECT count(DISTINCT player_id) FROM Activity),2) as fraction
FROM Activity
WHERE (player_id, event_date) IN (
     SELECT player_id, DATE_ADD(MIN(event_date), INTERVAL 1 DAY )
     FROM Activity 
    GROUP BY player_id
    ); 
