#!/usr/bin/node

const request = require('request');
const episode = process.argv[2];
const filmUrl = 'https://swapi-api.hbtn.io/api/films/' + episode;

request(filmUrl, function (error, response, body) {
  if (error) {
    // pass
  } else {
    const json = JSON.parse(body);
    const characters = json.characters;

    for (const i in characters) {
      request(characters[i], function (error, response, body) {
        if (error) {
          // pass
        } else {
          const person = JSON.parse(body);
          console.log(person.name);
        }
      });
    }
  }
});
