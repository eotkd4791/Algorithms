const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
const initialMoney = Number(input[0]);
const stockPrices = input[1].split(' ').map(Number);

const winner = (bnp, timing) => 
  bnp === timing 
    ? 'SAMESAME'
    : bnp > timing
    ? 'BNP'
    : 'TIMING';
    
const getBnp = (initMoney) => {
  let countStock = 0;
  let myMoney = initMoney;

  for(let i=0; i<stockPrices.length; i++) {
    while(myMoney >= stockPrices[i]) {
      myMoney -= stockPrices[i];
      countStock++;
    }
  }
  return myMoney + (countStock * stockPrices.slice(-1));
};

const getTiming = (initMoney) => {
  let countStock = 0;
  let myMoney = initMoney;
  let moreThanPrev = 0;
  let lessThanPrev = 0;

  for(let i=1; i<stockPrices.length; i++) {
    if(stockPrices[i] > stockPrices[i-1]) {
      lessThanPrev = 0;
      moreThanPrev++;
    }
    else if(stockPrices[i] < stockPrices[i-1]) {
      lessThanPrev++;
      moreThanPrev = 0;
    }
    else {
      moreThanPrev = 0;
      lessThanPrev = 0;
    }

    if(moreThanPrev >= 3) {
      myMoney += countStock * stockPrices[i];
      countStock = 0;
    }

    if(lessThanPrev >= 3) {
      while(myMoney >= stockPrices[i]) {
        myMoney -= stockPrices[i];
        countStock++;
      }
    }
  }
  return myMoney + (countStock * stockPrices.slice(-1));
};

(() => {
  console.log(
    winner(getBnp(initialMoney), getTiming(initialMoney))
  );
})();