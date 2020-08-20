#!/usr/bin/node

const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`, function (
  error,
  response,
  body
) {
  if (error) {
    console.error('error:', error);
    return;
  }
  const characters = [];
  const filmData = JSON.parse(body);
  for (const characterUrl of filmData.characters) {
    characters.push(
      new Promise((resolve, reject) => {
        request(characterUrl, function (error, resp, body) {
          error ? reject(error) : resolve(JSON.parse(body).name);
        });
      })
    );
  }
  Promise.all(characters).then((chars) => {
    for (const ch of chars) {
      console.log(ch);
    }
  });
});
