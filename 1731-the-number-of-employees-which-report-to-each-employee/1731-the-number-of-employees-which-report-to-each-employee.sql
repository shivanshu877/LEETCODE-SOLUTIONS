SELECT
    e.employee_id,
    e.name,
    (SELECT COUNT(*) FROM Employees e1 WHERE e1.reports_to = e.employee_id) AS reports_count,
    (SELECT ROUND(AVG(age)) FROM Employees e2 WHERE e2.reports_to = e.employee_id) AS average_age
FROM Employees e
HAVING reports_count <> 0
ORDER BY e.employee_id;
