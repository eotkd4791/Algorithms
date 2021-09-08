function solution(record) {
  const users = {};
  let result = [];

  record.forEach((info) => {
    const [status, uid, nickname] = info.split(' ');

    if (status !== 'Leave') {
      users[uid] = nickname;
    }

    if (status !== 'Change') {
      const message = status === 'Enter' ? '들어왔습니다.' : '나갔습니다.';
      result.push({ message: `${uid}님이 ${message}`, uid });
    }
  });

  return result.map(({ message, uid }) => message.replace(uid, users[uid]));
}

console.log(
  solution(['Enter uid1234 Muzi', 'Enter uid4567 Prodo', 'Leave uid1234', 'Enter uid1234 Prodo', 'Change uid4567 Ryan'])
);
