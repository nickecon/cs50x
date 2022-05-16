-- Keep a log of any SQL queries you execute as you solve the mystery
--July 28,2021 (7/28/2021) , Humphrey Street

--check crime scene
--SELECT * FROM crime_scene_reports;

--check bakery security logs
--SELECT * FROM bakery_security_logs;

--check people & total number of initial suspects
--SELECT * FROM people; COUNT = 200

--start checking the license plates of day crime occured (failed to find connections)
--SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28
--UNION
--SELECT license plate IN people ORDER BY lincese_plate;

--join bakery logs w/ people and license plates
--SELECT * FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate;

--grab count of individuals who were at bakery on the date of crime
--SELECT COUNT(*) FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28; COUNT = 74 (37 individual persons)

--same as above , different order
--SELECT * FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28 ORDER BY license_plate;

--failed code
--SELECT * FROM passengers JOIN people ON passengers.passport_number = people.passport_number JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28;

--cross check passengers with the 37 from above, brought back one passport number
--SELECT * FROM passengers WHERE passport_number = (SELECT passport_number FROM bakery_security_logs JOIN people ON bakery_security_logs.license_plate = people.license_plate WHERE month = 7 and day = 28);

--check info of passport number , alice id:809194
--SELECT * FROM people WHERE passport_number = 1679711307;

--check flights from passport number, flight 16,(seat 3A) & flight 52,(seat 5B)
--SELECT * FROM passengers WHERE passport_number = 1679711307;

--check flights
--SELECT * FROM flights WHERE id = 16; (origin, 8),(dest, 2)
--SELECT * FROM flights WHERE id = 52; (o, 3) (dest, 8)

-- 8 = fiftyville , 2 = beijing, 3 = lax
--SELECT * FROM airports WHERE id = 8;
--SELECT * FROM airports WHERE id = 2;
--SELECT * FROM airports WHERE id = 3;

--SELECT * FROM interviews WHERE name = "Alice";

SELECT * FROM atm_transactions;