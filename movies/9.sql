SELECT distinct(name) FROM ratings, directors, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id and year = 2004 ORDER BY birth;