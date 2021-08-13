#!/usr/bin/node

const request = require('request');
const filmUrl = 'https://swapi-api.hbtn.io/api/films/';
const episode = parseInt(process.argv[2]);

if (episode > 0 && episode < 8) {
  request(filmUrl, function (error, response, body) {
    if (error) {
      console.log(error);
    }

    const json = JSON.parse(body);
    const characters = json.results[episode - 1].characters;

    for (const i in characters) {
      request(characters[i], function (error, response, body) {
        if (error) {
          console.log(error);
        }
        const person = JSON.parse(body);
        console.log(person.name);
      });
    }
  });
} else {
  // pass
}
