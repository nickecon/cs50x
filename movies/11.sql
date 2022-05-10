SELECT title FROM movies, ratings, stars, people
WHERE movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND ratings.movie_id = people.id
AND name = "Chadwick Boseman";