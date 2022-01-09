function solution(lottos, winNums) {
  let matchedCount = 0;

  for (const lotto of lottos) {
    for (const winNum of winNums) {
      if (lotto === winNum) {
        matchedCount++;
      }
    }
  }

  return [getRank(matchedCount + getZeroCount(lottos)), getRank(matchedCount)];
}

function getRank(matchingCount) {
  switch (matchingCount) {
    case 6:
      return 1;
    case 5:
      return 2;
    case 4:
      return 3;
    case 3:
      return 4;
    case 2:
      return 5;
    default:
      return 6;
  }
}

function getZeroCount(lottos) {
  return lottos.filter((lotto) => lotto === 0).length;
}
