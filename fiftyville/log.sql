-- Keep a log of any SQL queries you execute as you solve the mystery
--July 28,2021 (7/28/2021) , Humphrey Street
--SELECT * FROM crime_scene_reports;
--SELECT * FROM bakery_security_logs;
--SELECT * FROM people;

--SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28
--UNION
--SELECT license plate IN people ORDER BY lincese_plate;

SELECT license_plate FROM bakery_security_logs WHERE license_plate IN people;
