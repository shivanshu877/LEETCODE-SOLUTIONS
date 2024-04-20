select project_id ,  round(avg(experience_years),2)  as average_years
from Project p left join Employee e USING(employee_id)  group by p.project_id;
