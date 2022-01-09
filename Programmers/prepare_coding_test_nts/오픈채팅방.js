function solution(record) {
    const userMap = {};
    const jsonArr = record.map(r => {
        const [status, id, nickname] = r.split(' ');
        return {status, id, nickname};
    });
    
    jsonArr.forEach(({status, id, nickname}) => {
        if(status === 'Enter' || status === 'Change') {
            userMap[id] = nickname;
        }
    });
    
    return jsonArr
        .map(r => {
            if(r.status === 'Enter') {
                return `${userMap[r.id]}님이 들어왔습니다.`;
            } else if(r.status === 'Leave') {
                return `${userMap[r.id]}님이 나갔습니다.`;
            }
            return false;
        })
        .filter(Boolean);
}
