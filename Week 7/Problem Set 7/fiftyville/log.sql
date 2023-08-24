-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Find transcript of interviews
SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';

-- Find out about activity, license_plate and name of people exiting
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name
FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year  = 2021
AND   bakery_security_logs.month = 7
AND   bakery_security_logs.day   = 28
AND   bakery_security_logs.hour  = 10
AND   bakery_security_logs.minute >= 15
AND   bakery_security_logs.minute <= 25;

-- Find names of people who withdraw money From ATM at Leggett Street
SELECT name FROM people
WHERE id IN (SELECT person_id FROM bank_accounts
             WHERE account_number IN(SELECT account_number FROM atm_transactions
                                     WHERE year = 2021 AND month = 7 AND day = 28
                                     AND atm_location = 'Leggett Street'
                                     AND transaction_type = 'withdraw'));

-- Bruce, Diana, Luca, Iman

-- Find people who called
UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

SELECT caller, caller_name, receiver, receiver_name
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60;

-- Bruce, Diana

-- Find origin_airport and destination_airport
SELECT id, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29
ORDER BY hour
LIMIT 1;

SELECT full_name, city FROM airports
WHERE id = 4;

SELECT flights.destination_airport_id, name, phone_number, license_plate
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flight_id = 36
ORDER BY flights.hour ASC;

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flight_id = 36 AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29
AND name IN (SELECT phone_calls.caller_name FROM phone_calls
             WHERE year = 2021 AND month = 7 AND day = 28
             AND duration < 60)
AND name IN (SELECT name FROM people
            WHERE id IN (SELECT person_id FROM bank_accounts
                        WHERE account_number IN(SELECT account_number FROM atm_transactions
                                                WHERE year = 2021 AND month = 7 AND day = 28
                                                AND atm_location = 'Leggett Street'
                                                AND transaction_type = 'withdraw'))
AND name IN (SELECT people.name FROM people
            JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
            WHERE bakery_security_logs.year  = 2021
            AND   bakery_security_logs.month = 7
            AND   bakery_security_logs.day   = 28
            AND   bakery_security_logs.hour  = 10
            AND   bakery_security_logs.minute >= 15
            AND   bakery_security_logs.minute <= 25));