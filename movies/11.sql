SELECT title FROM movies, ratings, people
WHERE movies.id = ratings.movie_id
AND movies.id = ratings.movie_id
AND name = "Chadwick Boseman" ORDER BY rating;