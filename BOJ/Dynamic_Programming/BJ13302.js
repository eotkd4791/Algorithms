const fs = require('fs');
const ONE_DAY = 10_000;
const THREE_DAY = 25_000;
const FIVE_DAY = 37_000;
const INFINITY = 987_654_321;

function input() {
  const [NM, notGoing] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  const [N, M] = NM.split(' ').map(Number);
  const daysNotGoing = M > 0 ? notGoing.split(' ').map(Number) : [];
  return [N, daysNotGoing];
}

function solution() {
  const [N, daysNotGoing] = input();
  const days = markNotGoingDays();
  const dp = initializeTable();
  return minimalCost(1, 0);

  function minimalCost(day, coupon) {
    if (day > N) {
      return 0;
    }

    if (dp[day][coupon] !== INFINITY) {
      return dp[day][coupon];
    }

    if (!days[day]) {
      return (dp[day][coupon] = minimalCost(day + 1, coupon));
    }

    dp[day][coupon] = Math.min(
      ...[
        dp[day][coupon],
        minimalCost(day + 1, coupon) + ONE_DAY,
        minimalCost(day + 3, coupon + 1) + THREE_DAY,
        minimalCost(day + 5, coupon + 2) + FIVE_DAY
      ]
    );

    if (coupon >= 3) {
      dp[day][coupon] = Math.min(dp[day][coupon], minimalCost(day + 1, coupon - 3));
    }
    return dp[day][coupon];
  }

  function initializeTable() {
    return JSON.parse(JSON.stringify(new Array(N + 1).fill(new Array(N + 1).fill(INFINITY))));
  }

  function markNotGoingDays() {
    const days = Array(N + 1).fill(true);
    daysNotGoing.forEach((day) => (days[day] = false));
    return days;
  }
}

console.log(solution());
