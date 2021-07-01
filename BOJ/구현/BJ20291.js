const fs = require('fs');
const [, ...fileNames] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const listOfExtentions = {};

fileNames.forEach(fileName => {
  const [, extension] = fileName.split('.');

  if (listOfExtentions.hasOwnProperty(extension)) {
    listOfExtentions[extension]++;
  } else {
    listOfExtentions[extension] = 1;
  }
});

const result = Object.entries(listOfExtentions)
  .sort()
  .reduce((acc, [nameOfExtension, usedCount]) =>
    acc.concat(`${nameOfExtension} ${usedCount}\n`),
    ''
  );
console.log(result);