SELECT distinct(name) FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND year = 2004 ORDER BY birth;

SELECT distinct(name) FROM movies, ratings, directors, people
WHERE movies.id = directors.movie_id
AND movies.id = ratings.movie_id
AND directors.person_id = people.id
AND name = "Chadwick Boseman" ORDER BY rating;