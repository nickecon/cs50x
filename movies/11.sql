SELECT title FROM movies, ratings, people
WHERE movies.id = ratings.movie_id
AND ratings.movie_id = people.id
AND name = "Chadwick Boseman";