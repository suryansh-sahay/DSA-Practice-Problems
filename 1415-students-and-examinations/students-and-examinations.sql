# Write your MySQL query statement below


SELECT a.student_id, a.student_name, s.subject_name, 
        count(b.student_id) as attended_exams
FROM Students as a
CROSS JOIN Subjects as s
LEFT JOIN Examinations as b
    ON a.student_id=b.student_id 
    AND s.subject_name=b.subject_name
GROUP BY a.student_id, a.student_name, s.subject_name
ORDER BY a.student_id, s.subject_name;
 



-- GROUP BY student_id, subject_name