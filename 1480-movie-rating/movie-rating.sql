# Write your MySQL query statement below

(SELECT u.name as results
FROM Users u
JOIN MovieRating mr
ON u.user_id=mr.user_id
GROUP BY u.user_id, u.name
ORDER BY COUNT(u.user_id) DESC, u.name ASC
LIMIT 1)

UNION ALL

(SELECT results
FROM(
    SELECT m.title as results, AVG(rating) as avg
    FROM Movies m
    JOIN MovieRating mr
    ON m.movie_id=mr.movie_id
    WHERE MONTH(created_at)=2 AND YEAR(created_at)=2020
    GROUP BY m.movie_id
    ORDER BY avg DESC, m.title ASC
) as results
LIMIT 1);