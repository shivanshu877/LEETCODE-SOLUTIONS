select score ,
            DENSE_RANK () OVER (ORDER BY score DESC) as "rank"
        from Scores order by score desc ;
