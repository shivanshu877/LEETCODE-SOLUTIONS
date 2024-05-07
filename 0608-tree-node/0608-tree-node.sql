SELECT id,
       IF(p_id IS NULL, "Root",
          IF( id IN  (SELECT  p_id FROM Tree group by p_id having count(*) > 0 ) , 
         "Inner", "Leaf")) AS type
FROM Tree;
