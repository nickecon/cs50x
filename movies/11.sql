SELECT title FROM movies, ratings, people
WHERE movies.id = ratings.movie_id
AND movies.i= people.id
AND name = "Chadwick Boseman";