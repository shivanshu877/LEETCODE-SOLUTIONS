SELECT e.employee_id AS employee_id
FROM Employees e
LEFT JOIN Salaries s ON e.employee_id = s.employee_id
WHERE e.name IS NULL OR s.salary IS NULL

UNION

SELECT s.employee_id AS employee_id
FROM Employees e
RIGHT JOIN Salaries s ON e.employee_id = s.employee_id
WHERE e.name IS NULL OR s.salary IS NULL
ORDER BY employee_id;
