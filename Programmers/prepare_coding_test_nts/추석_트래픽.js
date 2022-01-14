/**
 * @param {string[]} lines
 * @description line: YYYY-MM-DD hh:mm:ss.sss {s}s
 * @returns {number} answer: 초당 최대 처리량
 *
 * ? 문제 설명
 * 초당 최대 처리량을 구해서 반환
 * 초당 최대 처리량: 1초(1000밀리초)간 처리하는 요청의 최대 갯수를 의미
 * 9/15일 하루 동안의 로그를 분석함.
 * 응답완료시간을 기준으로 오름차순 정렬되어있음.
 *
 * ! 주의할 점 및 제약사항
 * line배열의 길이는 최대 2000
 * 처리 시간은 시작시간과 끝시간을 포함한다.
 * 처리 시간 T: 0.001 <= T <= 3.000
 *
 * * 문제 풀이
 * 하루 동안의 로그를 1초 단위로 분석 (60 * 60 * 24) = 86400초
 * [응답 처리 시작시간, 응답 처리 완료시간] 형태로 데이터 가공
 * 시-분-초로 구성되어 있는 데이터를 통일하기 위해서 밀리초로 변환
 * 밀리초로 변환한 값에서 밀리초로 변환한 처리 시간을 빼서 위의 형태로 가공
 *
 * ! 밀리초로 변환하는 경우에는 편의를 위해서 Date객체의 parse메소드를
 * ! 이용한다.
 *
 * ==============================================================
 * 응답 시작 시간: 응답 완료 시간(ms) - 처리시간(ms) + 1ms
 *
 * ! case 2도 2개의 작업을 처리한 것임.
 * 따라서 계산의 편의를 위해서 응답 완료시간에 1000ms(1s)를 더해준다.
 * 응답 완료 시간: 응답 완료 시간 + 1000(ms)
 * ==============================================================
 *
 * 응답 완료 시간을 기준으로 오름차순으로 정렬되어 있으니
 * for loop을 돌면서 기준이 되는 인덱스 응답 완료 시간
 *
 * case 1)
 *        A     B              A: 원래의 완료시간 B: 1초 더한 구간
 * |------+-----|
 *              |--------|
 *     |------|
 *
 * case 2)
 * |---|    |---------|
 *   ^_________^ 1초 간격이 이렇게 되면 2개의 응답을 처리한 것.
 */
function solution(lines) {
  let answer = 0;

  const times = lines.map((line) => {
    const [date, completeTime, processTime] = line.split(' ');
    const completeTimeMs = Date.parse(`${date} ${completeTime}`);
    const processTimeMs = Number(processTime.slice(0, -1)) * 1000;
    return [completeTimeMs - processTimeMs + 1, completeTimeMs + 1000];
  });

  const n = lines.length;
  for (let i = 0; i < n; i++) {
    // 기준점
    let processCountWithinOneSecond = 0;
    for (let j = i; j < n; j++) {
      // 비교하고자 하는 인덱스
      if (times[i][1] > times[j][0]) {
        processCountWithinOneSecond++;
      }
    }
    answer = Math.max(answer, processCountWithinOneSecond);
  }
  return answer;
}
